#include "csv/csv.h"
#include "log/log.h"

#include <sstream>

void assert_cell(csv::istream& in, const std::string expected) {
	int ch;
	std::string got;
	while ((ch = in.get()) >= 0) { got += (char) ch; }
	if (got != expected) {
		log_fatal(expected.c_str(), got.c_str());
	}
}

void assert_next_cell(csv::istream& in) {
	if (! in.next_cell()) { log_fatal("keine weitere Zelle", ""); }
}

void assert_no_next_cell(csv::istream& in) {
	if (in.next_cell()) { log_fatal("zu viele Zellen", ""); }
}

void assert_next_line(csv::istream& in) {
	if (! in.next_line()) { log_fatal("keine weitere Zeile", ""); }
}

void assert_no_next_line(csv::istream& in) {
	if (in.next_line()) { log_fatal("zu viele Zeilen", ""); }
}

int main() {
	try {
		std::istringstream in {
			"a,b,c\r\n"
			"\"1\",\"\"\"2\"\"\",\"\n3\n\"\r\n"
		};
		csv::istream reader { in };
		assert_cell(reader, "a");
		assert_next_cell(reader);
		assert_cell(reader, "b");
		assert_next_cell(reader);
		assert_cell(reader, "c");
		assert_no_next_cell(reader);

		assert_next_line(reader);
		assert_cell(reader, "1");
		assert_next_cell(reader);
		assert_cell(reader, "\"2\"");
		assert_next_cell(reader);
		assert_cell(reader, "\n3\n");
		assert_no_next_cell(reader);
		assert_no_next_line(reader);

	} catch (const terminate_exception& ex) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
