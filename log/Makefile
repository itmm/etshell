include ../Makefile.base
include Makefile.deps

../log/liblog.a: ../log/log.o
	@echo building $@
	@$(AR) -rc $@ $^

test: ../log/liblog.a

clean:
	@rm -f liblog.a log.o
