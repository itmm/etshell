#include <iostream>
#include <cstdint>

#include "log/log.h"
#include "ta/ta.h"

int main(int argc, const char* argv[]) {
	try {
		if (argc != 3) { log_fatal("Syntax", "tamv <from> <to>"); }
		const std::string from { argv[1] };
		const std::string to { argv[2] };

		int result_code = EXIT_FAILURE;
		ta::istream in { std::cin };
		ta::ostream out { std::cout };
		std::string name;
		while (auto name = in.open_next_file()) {
			if (name == from) {
				name = to; result_code = EXIT_SUCCESS;
			}

			int ch;
			out.open_next_file(*name);
			while ((ch = in.get()) >= 0) { out.put(ch); }
		}
		return result_code;
	} catch (const terminate_exception&) {
		return EXIT_FAILURE;
	}
}
