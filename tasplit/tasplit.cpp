#include <fstream>
#include <iostream>
#include "log/log.h"
#include "ta/ta.h"

int main() {
	try {
		ta::istream in { std::cin };

		while (auto name = in.open_next_file()) {
			std::cout << *name << " ... ";
			std::ofstream out { name->c_str() };
			char ch;
			while (in.get(ch)) { out.put(ch); }
			std::cout << "ok\n";
		}
		return EXIT_SUCCESS;
	} catch (const terminate_exception&) {
		return EXIT_FAILURE;
	}
}
