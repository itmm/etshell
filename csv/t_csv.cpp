#include "csv/csv.h"
#include "log/log.h"

#include <sstream>

void assert_eq(const std::string& expected, const std::string& got) {
	if (expected != got) {
		log_fatal("Test fehlgeschlagen", (expected + " != " + got).c_str());
	}
}

void assert_cell(csv::istream& in, const std::string& expected) {
	int ch;
	std::string got;
	while ((ch = in.get()) >= 0) { got += (char) ch; }
	assert_eq(expected, got);
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

static inline void simple_write() {
	std::ostringstream out;
	csv::ostream writer { out };
	writer << "a"; writer.close_cell(); writer << "b"; writer.close_line();
	writer << 1; writer.close_cell(); writer << 2; writer.close_line();
	assert_eq("a,b\r\n1,2\r\n", out.str());
}

static inline void quoted_write() {
	std::ostringstream out;
	csv::ostream writer { out };
	writer << "\"1\""; writer.close_line();
	assert_eq("\"\"\"1\"\"\"\r\n", out.str());
}

static inline void write_with_newline() {
	std::ostringstream out;
	csv::ostream writer { out };
	writer << "\nx\n"; writer.close_line();
	assert_eq("\"\nx\n\"\r\n", out.str());
}

static inline void big_write() {
	std::ostringstream out;
	csv::ostream writer { out };
	std::string value = "1234567890";
	writer << value;
	for (int i = 7; i; --i) { writer << value; value += value;} 
	writer.close_line();
	assert_eq("\"" + value + "\"\r\n", out.str());
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

		simple_write();
		quoted_write();
		write_with_newline();
		big_write();
	} catch (const terminate_exception& ex) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
