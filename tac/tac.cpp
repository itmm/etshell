#include <fstream>
#include <iostream>
#include "log/log.h"

static inline void process(const char* path) {
	std::cout << "%file " << path << "\n";
	std::ifstream f { path };
	if (! f) { log_fatal("Kann Datei nicht öffnen", ""); }

	bool last_is_newline = true;
	int ch;
	while ((ch = f.get()) >= 0) {
		if (last_is_newline) {
			if (ch == '%') { putchar(ch); }
		}
		std::cout.put(ch);
		last_is_newline = (ch == '\n');
	}
	if (! last_is_newline) { std::cout.put('\n'); }
}

int main(int argc, const char *argv[]) {
	try {
		const char** path = argv + 1;
		for (int i = argc - 1; i; --i) {
			process(*path++);
		}
		return EXIT_SUCCESS;
	} catch (const terminate_exception&) {
		return EXIT_FAILURE;
	}
}
