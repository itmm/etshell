include ../Makefile.base
include Makefile.deps

../ta/libta.a: ../ta/ta.o
	@echo building $@
	@$(AR) -rc $@ $^

test: ../ta/libta.a
	@#$(MAKE) sub_test

clean:
	@rm -f libta.a ta.o
	@#$(MAKE) sub_test_clean
