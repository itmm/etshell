include ../Makefile.base
include ../md5/Makefile.lib
include ../marked-files.old/Makefile.lib
include ../log/Makefile.lib

test: md5chk
	@#$(MAKE) sub_test

md5chk: md5chk.o ../md5/libmd5.a ../marked-files.old/libmarked-files-old.a ../log/liblog.a
	@echo building $@
	@$(CXX) md5chk.o -L../md5 -lmd5 -L../marked-files.old -lmarked-files-old -L../log -llog -o $@

md5chk.o: ../md5/md5.h ../marked-files.old/marked-files.h ../log/log.h

clean:
	@rm -f md5chk md5chk.o .mdp_run
