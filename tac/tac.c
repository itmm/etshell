#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void process(const char* path) {
	printf("%%file %s\n", path);
	FILE *f = fopen(path, "r");
	if (! f) {
		fprintf(stderr, "Kann Datei nicht öffnen: %s\n", strerror(errno));
		exit(10);
	}

	bool last_is_newline = true;
	int ch;
	while ((ch = fgetc(f)) != EOF) {
		if (last_is_newline) {
			if (ch == '%') { putchar(ch); }
		}
		putchar(ch);
		last_is_newline = (ch == '\n');
	}
	if (ferror(f)) {
		fprintf(stderr, "Kann Datei nicht lesen: %s\n", strerror(errno));
		exit(10);
	}
	if (! last_is_newline) { putchar('\n'); }

	fclose(f);
}

int main(int argc, const char *argv[]) {
	const char** path = argv + 1;
	for (int i = argc - 1; i; --i) {
		process(*path++);
	}
}
