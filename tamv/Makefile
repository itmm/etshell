include ../Makefile.base
include ../log/Makefile.lib
include ../ta/Makefile.lib

test: tamv
	@#$(MAKE) sub_test

tamv: tamv.o ../ta/libta.a ../log/liblog.a
	@echo building $@
	@$(CXX) tamv.o -L../ta -lta -L../log -llog -o $@

tamv.o: ../ta/ta.h ../log/log.h

clean:
	@rm -f tamv tamv.o
	@#$(MAKE) sub_test_clean
