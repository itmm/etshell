include ../Makefile.base

lib: libcsv.a

libcsv.a: csv.o
	@echo building $@
	@$(AR) -rc $@ $^

csv.o: csv.h ../log/log.h

test: libcsv.a
	@#$(MAKE) sub_test

clean:
	@rm -f libcsv.a csv.o
	@#$(MAKE) sub_test_clean
