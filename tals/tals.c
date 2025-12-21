#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int ch;

bool match(const char* p) {
	while (*p) {
		if (ch != *p) { return false; }
		++p;
		ch = getchar();
	}
	return true;
}

void list_file(void) {
	if (! match("file ")) {
		fprintf(stderr, "Datei in ta-Archiv erwartet\n"); exit(10);
	}

	while (ch != EOF && ch != '\n') {
		putchar(ch); ch = getchar();
	}
	putchar(' ');

	if (ch != EOF) { ch = getchar(); }

	off_t size = 0;
	bool last_is_newline = true;

	for (;;) {
		while ((! last_is_newline || ch != '%') && ch != EOF) {
			last_is_newline = (ch == '\n');
			ch = getchar();
			++size;
		}
		
		if (ch == EOF) { break; }

		ch = getchar();
		if (ch != '%') { break; }
	}

	printf("%lld\n", size);
}

int main(void) {
	ch = getchar(); if (ch == EOF) { return 0; }
	if (ch != '%') { fprintf(stderr, "Kein ta-Archiv\n"); exit(10); }
	ch = getchar();
	do {
		list_file();
	} while (ch != EOF);
}
