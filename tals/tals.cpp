#include <iostream>
#include <cstdint>

#include "log/log.h"
#include "ta/ta.h"

int main(void) {
	try {
		ta::Reader reader { std::cin };
		std::string name;
		while (reader.open_next_file(name)) {
			std::cout << name << ' ';
			uintmax_t size { 0 };
			while (reader.next_ch() >= 0) { ++size; }
			std::cout << size << '\n';
		}
		return EXIT_SUCCESS;
	} catch (const terminate_exception&) {
		return EXIT_FAILURE;
	}
}
