include ../Makefile.base
include ../log/Makefile.lib
include ../ta/Makefile.lib
include ../marked-files-out/Makefile.lib

test: tac
	@$(MAKE) sub_test

tac: tac.o ../log/liblog.a ../ta/libta.a ../marked-files-out/libmarked-files-out.a
	@echo building $@
	@$(CXX) tac.o -L../ta -lta -L../marked-files-out -lmarked-files-out -L../log -llog -o $@

tac.o: ../log/log.h ../ta/ta.h

clean:
	@rm -f tac tac.o .mdp_run
	@$(MAKE) sub_test_clean
