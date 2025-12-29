#include <iostream>

#include "csv/csv.h"
#include "ttsv/ttsv.h"

int main(void) {
	csv::istream in { std::cin };
	ttsv::ostream out { std::cout };

	for (;;) {
		int ch;
		while ((ch = in.get()) >= 0) { out.put(ch); }
		out.close_cell();
		if (in.next_cell()) { continue; }
		out.close_line();
		if (in.next_line()) { continue; }
		break;
	}
	return EXIT_SUCCESS;
}
