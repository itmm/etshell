include ../Makefile.base
include ../md5/Makefile.lib
include ../marked-files-in/Makefile.lib
include ../log/Makefile.lib

test: md5chk
	@#$(MAKE) sub_test

md5chk: md5chk.o ../md5/libmd5.a ../marked-files-in/libmarked-files-in.a ../log/liblog.a
	@echo building $@
	@$(CXX) md5chk.o -L../md5 -lmd5 -L../marked-files-in -lmarked-files-in -L../log -llog -o $@

md5chk.o: ../md5/md5.h ../marked-files-in/marked-files-in.h ../log/log.h

clean:
	@rm -f md5chk md5chk.o .mdp_run
