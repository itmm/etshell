#include <cstdint>

#include "ta/ta.h"

int main(void) {
	try {
		ta::istream in { std::cin };
		std::string name;
		while (auto name = in.open_next_file()) {
			std::cout << *name << ' ';
			uintmax_t size { 0 };
			char ch;
			while (in.get(ch)) { ++size; }
			std::cout << size << '\n';
		}
		return EXIT_SUCCESS;
	} catch (const terminate_exception&) {
		return EXIT_FAILURE;
	}
}
