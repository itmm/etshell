#line 31 "README.md"
#include "log.h"

#line 95
#include <errno.h>
#line 44
#include <stdio.h>
#line 61
#include <stdlib.h>
#line 98
#include <string.h>
#line 45

#line 33
void log_fatal(const char* message, const char* reason) {
	if (! message) { message = "NULL"; }
	if (! reason) { reason = "NULL"; }
#line 50
	fprintf(stderr, "%s: %s\n", message, reason);
#line 66
	exit(EXIT_FAILURE);
#line 36
}
#line 100

void log_fatal_errno(const char* message) {
	log_fatal(message, strerror(errno));
}
