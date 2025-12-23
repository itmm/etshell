#line 29 "README.md"
#include "log.h"

#line 93
#include <errno.h>
#line 42
#include <stdio.h>
#line 59
#include <stdlib.h>
#line 96
#include <string.h>
#line 43

#line 31
void log_fatal(const char* message, const char* reason) {
	if (! message) { message = "NULL"; }
	if (! reason) { reason = "NULL"; }
#line 48
	fprintf(stderr, "%s: %s\n", message, reason);
#line 64
	exit(EXIT_FAILURE);
#line 34
}
#line 98

void log_fatal_errno(const char* message) {
	log_fatal(message, strerror(errno));
}
