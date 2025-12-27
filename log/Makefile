include ../Makefile.base
include Makefile.deps

../log/liblog.a: ../log/log.o
	@echo building $@
	@$(AR) -rc $@ $^

test: ../log/liblog.a
	@echo >/dev/null

clean:
	@rm -f liblog.a log.o
