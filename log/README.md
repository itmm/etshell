# Ein einfaches Log-Konzept

## Wer soll sich um Log-Dateien kümmern?

Die Programme loggen alle über die Standard-Fehlerausgabe. Das System, welches
die Programme aufruft, muss sicherstellen, dass die Ausgabe in Dateien
archiviert wird. Und ebenso, dass diese Dateien nicht zu groß werden.

## Basisfunktion

Im Header `log.h` wird zunächst die Basisfunktion definiert, um eine einzige
Nachricht zu loggen und das Programm zu beenden:

```c
#if !defined(log_h)
#define log_h

	void log_fatal(const char* message, const char* reason);

#endif
```

Eine Log-Nachricht besteht aus der eigentlichen Nachricht und einem Grund.
Fangen wir mit der Implementierung in `log.c` an. Beide Parameter können leer
bleiben, um die Funktion robuster zu machen:

```c
#include "log.h"

void log_fatal(const char* message, const char* reason) {
	if (! message) { message = "NULL"; }
	if (! reason) { reason = "NULL"; }
}
```

Die Ausgabe erfolgt erst einmal ganz einfach über den Fehler-Kanal:

```c
// ...

#include <stdio.h>

// ...
void log_fatal(const char* message, const char* reason) {
	// ...
	if (! reason) { reason = "NULL"; }
	fprintf(stderr, "%s: %s\n", message, reason);
// ...
}
// ...
```

Zusätzlich wird nach der Ausgabe das Programm beendet:

```c
// ...
#include <stdio.h>
#include <stdlib.h>
// ...
void log_fatal(const char* message, const char* reason) {
	// ...
	fprintf(stderr, "%s: %s\n", message, reason);
	exit(EXIT_FAILURE);
// ...
}
// ...
```

Damit ist ein rudimentäres Logging umgesetzt.


## Systemfehler loggen

Oft liefern Systemfunktionen bei einem Fehler eine spezifische Fehlernummer
in der globalen Variable `errno`. Diese kann für die Angabe eines Grundes
herangezogen werden.

Daher kommt eine weitere Funktion in `log.h` hinzu:

```c
// ...
	void log_fatal(const char* message, const char* reason);
	void log_fatal_errno(const char* message);
// ...
```

In `log.c` kann diese hinzugezogen werden, um die Begründung zu liefern.

```c
// ...

#include <errno.h>
// ...
#include <stdlib.h>
#include <string.h>
// ...2

void log_fatal_errno(const char* message) {
	log_fatal(message, strerror(errno));
}
```

In `./Makefile`:

```Makefile
include ../Makefile.base
include Makefile.deps

lib: ../log/liblog.a

../log/liblog.a: ../log/log.o
	@echo building $@
	@$(AR) -rc $@ $^

test: ../log/liblog.a
	@#$(MAKE) sub_test

clean:
	@rm -f liblog.a log.o
	@#$(MAKE) sub_test_clean
```

Und `Makefile.lib`:

```Makefile
../log/liblog.a: ../log/log.o
	$(MAKE) --quiet --directory=../log liblog.a

include ../log/Makefile.deps
```

Und `Makefile.deps`:

```Makefile
../log/log.o: ../log/log.h
```
