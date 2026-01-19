#include "ttsv/ttsv.h"
#include "log/log.h"

#include <sstream>

void assert_eq(const std::string& expected, const std::string& got) {
	if (expected != got) {
		log_fatal("Test fehlgeschlagen", (expected + " != " + got).c_str());
	}
}

void assert_cell(ttsv::istream& in, const std::string& expected) {
	int ch;
	std::string got;
	while ((ch = in.get()) >= 0) { got += (char) ch; }
	assert_eq(expected, got);
}

void assert_next_cell(ttsv::istream& in) {
	if (! in.next_cell()) { log_fatal("keine weitere Zelle", ""); }
}

void assert_no_next_cell(ttsv::istream& in) {
	if (in.next_cell()) { log_fatal("zu viele Zellen", ""); }
}

void assert_next_line(ttsv::istream& in) {
	if (! in.next_line()) { log_fatal("keine weitere Zeile", ""); }
}

void assert_no_next_line(ttsv::istream& in) {
	if (in.next_line()) { log_fatal("zu viele Zeilen", ""); }
}

int main() {
	try {
		std::istringstream in {
			"a\tb\tc\n"
			"1\t\\32\t\\09\\0a3\\09\\0a\n"
		};
		ttsv::istream reader { in };
		assert_cell(reader, "a");
		assert_next_cell(reader);
		assert_cell(reader, "b");
		assert_next_cell(reader);
		assert_cell(reader, "c");
		assert_no_next_cell(reader);

		assert_next_line(reader);
		assert_cell(reader, "1");
		assert_next_cell(reader);
		assert_cell(reader, "2");
		assert_next_cell(reader);
		assert_cell(reader, "\t\n3\t\n");
		assert_no_next_cell(reader);
		assert_no_next_line(reader);
	} catch (const terminate_exception& ex) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
