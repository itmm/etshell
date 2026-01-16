#include <fstream>
#include <iostream>
#include <set>
#include "log/log.h"
#include "ta/ta.h"

static std::set<std::string> filter_in;
static std::set<std::string> filter_out;

static inline void parse_arguments(int argc, const char* argv[]) {
	const std::string FILTER_PREFIX { "--filter=" };
	const std::string FILTER_OUT_PREFIX { "--filter-out=" };

	for (int i = 1; i < argc; ++i) {
		std::string arg { argv[i] };
		if (arg.find(FILTER_PREFIX) == 0) {
			filter_in.insert(arg.substr(FILTER_PREFIX.size())); continue;
		}
		if (arg.find(FILTER_OUT_PREFIX) == 0) {
			filter_out.insert(arg.substr(FILTER_OUT_PREFIX.size())); continue;
		}
		log_fatal("Unbekanntes Argument", arg.c_str());
	}
}

static inline bool process_file(const std::string& path) {
	if (! filter_in.empty()) {
		bool found { false };
		for (const std::string& pattern : filter_in) {
			if (path.find(pattern) != std::string::npos) { found = true; break; }
		}
		if (! found) { return false; }
	}	
	for (const std::string& pattern : filter_out) {
		if (path.find(pattern) != std::string::npos) { return false; }
	}
	return true;
}

int main(int argc, const char* argv[]) {
	try {
		parse_arguments(argc, argv);
		ta::istream in { std::cin };

		while (auto name = in.open_next_file()) {
			std::cout << *name;
			if (process_file(*name)) {
				std::cout << " ... ";
				std::ofstream out { name->c_str() };
				char ch;
				while (in.get(ch)) { out.put(ch); }
				std::cout << "ok\n";
			} else { std::cout << " [skipping]\n"; }
		}
		return EXIT_SUCCESS;
	} catch (const terminate_exception&) {
		return EXIT_FAILURE;
	}
}
