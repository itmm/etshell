include ../Makefile.base

test: tals
	@#$(MAKE) sub_test

tals: tals.o log_lib
	@echo building $@
	@$(CC) tals.o -L../log -llog -o $@

clean:
	@rm -f tals
	@#$(MAKE) sub_test_clean
