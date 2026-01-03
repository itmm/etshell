include ../Makefile.base
include ../log/Makefile.lib
include ../ta/Makefile.lib

test: tals
	@#$(MAKE) sub_test

tals: tals.o ../ta/libta.a ../log/liblog.a
	@echo building $@
	@$(CXX) tals.o -L../ta -lta -L../log -llog -o $@

tals.o: ../ta/ta.h

clean:
	@rm -f tals tals.o
	@#$(MAKE) sub_test_clean
