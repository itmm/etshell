# lazy Schreiben in Dateien

Die Bau-Umgebung ist in [build.md](build.md) beschrieben.

Die eigentliche Funktionalität ist in eine Bibliothek gepackt. Das eigentliche
Programm in `main.cpp` wird dadurch sehr übersichtlich:

```c++
#include "lazy.h"
#include "log/log.h"

int main(int argc, const char* argv[]) {
	try {
		if (argc != 2) { log_fatal("Syntax", "lazy <file path>"); }
		Lazy lazy { std::cin, argv[1] };
		lazy.process();
		return EXIT_SUCCESS;
	} catch (const terminate_exception& ex) {
		return EXIT_FAILURE;
	}
}
```

Der Header zur Bibliothek in `lazy.h` exportiert eine Klasse mit einer
öffentlichen Methode:

```c++
#if !defined(lazy_h)
#define lazy_h

	#include <cstdint>
	#include <fstream>
	#include <iostream>
	#include <string>

	class Lazy {
			std::istream& in_;
			const std::string out_path_;
			std::fstream out_;
			int ch_ { ' ' };
			std::uintmax_t offset_ { 0 };

			void match_prefix_();
			void overwrite_rest_();
			void truncate_file_();

		public:
			Lazy(std::istream& in, const std::string& out_path);
			void process();
	};

#endif
```

Aber dahinter verbergen sich in `lazy.cpp` mehrere Schritte:

```c++
#include "lazy.h"
#include "log/log.h"

#include <filesystem>

Lazy::Lazy(std::istream& in, const std::string& out_path):
	in_ { in }, out_path_ { out_path }, out_ { }
{ }

void Lazy::match_prefix_() {
	for (;;) {
		ch_ = in_.get();
		if (! in_) { break; }
		int should = out_.get();
		if (should != ch_) { break; }
		++offset_;
	}
}

void Lazy::overwrite_rest_() {
	out_.seekp(offset_);
	for (;;) {
		if (! in_) { break; }
		out_.put(ch_);
		++offset_;
		ch_ = in_.get();
	}
}

void Lazy::truncate_file_() {
	out_.close();
	if (offset_ == 0) {
		std::ofstream f { out_path_, std::ios_base::trunc | std::ios_base::out };
		return;
	}

	auto cur { std::filesystem::file_size(out_path_) };
	if (cur != offset_) {
		std::filesystem::resize_file(out_path_, offset_);
	}
}

void Lazy::process() {
	try {
		if (std::filesystem::exists(out_path_)) {
			out_.open(out_path_.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::binary);
			out_.exceptions(std::ios_base::failbit | std::ios_base::badbit);
			match_prefix_();
		} else {
			out_.open(out_path_.c_str(), std::ios_base::out | std::ios_base::binary);
			out_.exceptions(std::ios_base::failbit | std::ios_base::badbit);
			ch_ = in_.get();
		}
		overwrite_rest_();
		truncate_file_();
	} catch (const std::ios_base::failure& ex) {
		log_fatal("Lazy Fehler", ex.what());
	}
	// trim file length
}
```

