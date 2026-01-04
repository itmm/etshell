#include <iostream>

#include "marked-files-out/marked-files-out.h"
#include "md5/md5.h"

int main() {
	marked_files::ostream escaper { std::cout };
	md5::ostream out { escaper };
	int ch;
	while ((ch = std::cin.get()) >= 0) {
		out.put(ch);
	}
	auto digest { out.finish() };
	escaper.open_command("md5-digest");
	escaper << digest;
	escaper.close_command();
}
