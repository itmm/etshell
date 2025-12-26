#line 56 "README.md"
#include "lazy.h"

extern "C" {
	#include "log/log.h"
}

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
			match_prefix_();
		} else {
			out_.open(out_path_.c_str(), std::ios_base::out | std::ios_base::binary);
			ch_ = in_.get();
		}
		overwrite_rest_();
		truncate_file_();
	} catch (const std::ios_base::failure& ex) {
		log_fatal("Lazy Fehler", ex.what());
	}
	// trim file length
}
