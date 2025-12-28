#include <iostream>
#include <cstdint>

#include "log/log.h"
#include "ta/ta.h"

int main(int argc, const char* argv[]) {
	try {
		int result_code = EXIT_FAILURE;
		ta::Reader reader { std::cin };
		ta::ostream out { std::cout };
		std::string name;
		while (reader.open_next_file(name)) {
			bool should_delete { false };
			for (int i = 1; i < argc; ++i) {
				if (name == argv[i]) { should_delete = true; break; }
			}

			int ch;
			if (should_delete) {
				while ((ch = reader.next_ch()) >= 0) { }
				result_code = EXIT_SUCCESS;
			} else {
				out.open_next_file(name);
				while ((ch = reader.next_ch()) >= 0) { out.put(ch); }
			}
		}
		return result_code;
	} catch (const terminate_exception&) {
		return EXIT_FAILURE;
	}
}
