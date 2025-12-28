#include <fstream>
#include <iostream>
#include "log/log.h"
#include "ta/ta.h"

static inline void process(ta::ostream& out, const char* path) {
	std::ifstream f { path };
	if (! f) { log_fatal("Kann Datei nicht öffnen", ""); }

	out.open_next_file(path);

	int ch;
	while ((ch = f.get()) >= 0) {
		out.put(ch);
	}
}

int main(int argc, const char *argv[]) {
	try {
		if (argc >= 2) {
			ta::ostream out { std::cout };
			const char** paths = argv + 1;
			for (int i = argc - 1; i; --i) {
				process(out, *paths++);
			}
		}
		return EXIT_SUCCESS;
	} catch (const terminate_exception&) {
		return EXIT_FAILURE;
	}
}
