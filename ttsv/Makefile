include ../Makefile.base
include Makefile.deps

../ttsv/libttsv.a: ../ttsv/ttsv.o
	@echo building $@
	@$(AR) -rc $@ $^

test: ../ttsv/libttsv.a
	@#$(MAKE) sub_test

clean:
	@rm -f libttsv.a ttsv.o
	@#$(MAKE) sub_test_clean
