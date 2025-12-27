include ../Makefile.base
include Makefile.lib

lib: libta.a

libta.a: ta.o
	@echo building $@
	@$(AR) -rc $@ $^

test: libta.a
	@#$(MAKE) sub_test

clean:
	@rm -f libta.a ta.o
	@#$(MAKE) sub_test_clean
