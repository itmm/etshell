include ../Makefile.base
include ../md5/Makefile.lib

test: md5add
	@#$(MAKE) sub_test

md5add: md5add.o ../md5/libmd5.a
	@echo building $@
	@$(CXX) md5add.o -L../md5 -lmd5 -o $@

md5add.o: ../md5/md5.h

clean:
	@rm -f md5add md5add.o .mdp_run
