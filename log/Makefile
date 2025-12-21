include ../Makefile.base

lib: liblog.a

liblog.a: log.o
	@echo building $@
	@$(AR) -rc $@ $^

log.o: log.h

test: liblog.a
	@#$(MAKE) sub_test

clean:
	@rm -f liblog.a log.o
	@#$(MAKE) sub_test_clean
