# Programm bauen

## Makefile

Im `./Makefile` werden die Grundlagen gelegt, um

```Makefile
include ../Makefile.base
include Makefile.deps

../log/liblog.a: ../log/log.o
	@echo building $@
	@$(AR) -rc $@ $^

test: ../log/liblog.a
	@echo >/dev/null

clean:
	@rm -f liblog.a log.o
```

Es gibt ausnahmsweise keine Testfälle für das Loggen: da es ständig verwendet
wird, kann es en passant mitgetestet werden.


## Makefile.lib

Ich baue eine statische Bibliothek. Um in anderen Makefiles diese zu verwenden,
kann die Datei `Makefile.lib` eingebunden werden:

```Makefile
../log/liblog.a: ../log/log.o
	$(MAKE) --directory=../log liblog.a

include ../log/Makefile.deps
```


## Makefile.deps

In der Datei `Makefile.deps` werden die Abhängigkeiten verwaltet. Da diese
sowohl vom `Makefile`, als auch in `Makefile.lib` verwendet wird, muss
`Makefile.deps` die Pfade über das Modul-Verzeichnis auflösen.

```Makefile
../log/log.o: ../log/log.h
```
