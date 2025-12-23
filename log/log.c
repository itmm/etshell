#line 28 "README.md"
#include "log.h"

#line 92
#include <errno.h>
#line 41
#include <stdio.h>
#line 58
#include <stdlib.h>
#line 95
#include <string.h>
#line 42

#line 30
void log_fatal(const char* message, const char* reason) {
	if (! message) { message = "NULL"; }
	if (! reason) { reason = "NULL"; }
#line 47
	fprintf(stderr, "%s: %s\n", message, reason);
#line 63
	exit(EXIT_FAILURE);
#line 33
}
#line 97

void log_fatal_errno(const char* message) {
	log_fatal(message, strerror(errno));
}
