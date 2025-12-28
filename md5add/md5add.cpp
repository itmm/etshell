#include <iostream>
#include "md5/md5.h"

int main() {
	md5::ostream out { std::cout };
	bool last_was_nl { true };
	int ch;
	while ((ch = std::cin.get()) >= 0) {
		if (ch == '%' && last_was_nl) { out.put(ch); }
		out.put(ch);
		last_was_nl = (ch == '\n');
	}
	if (! last_was_nl) { out.put('\n'); }
	auto digest { out.finish() };
	out << "%digest: " << digest << '\n';
}
