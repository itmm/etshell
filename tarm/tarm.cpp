#include <iostream>
#include <cstdint>

#include "log/log.h"
#include "ta/ta.h"

int main(int argc, const char* argv[]) {
	try {
		int result_code = EXIT_FAILURE;
		ta::istream in { std::cin };
		ta::ostream out { std::cout };
		std::string name;
		while (auto name = in.open_next_file()) {
			bool should_delete { false };
			for (int i = 1; i < argc; ++i) {
				if (*name == argv[i]) { should_delete = true; break; }
			}

			if (should_delete) {
				result_code = EXIT_SUCCESS;
			} else {
				int ch;
				out.open_next_file(*name);
				while ((ch = in.get()) >= 0) { out.put(ch); }
			}
		}
		return result_code;
	} catch (const terminate_exception&) {
		return EXIT_FAILURE;
	}
}
