include ../Makefile.base
include ../log/Makefile.lib
include Makefile.lib

t_md5: t_md5.o $(LIBS)

include t_md5.d

test: t_md5
	./t_md5

.PHONY: x
x:
	# $(LIBS)

clean:
	$(RM) libmd5.a md5.o t_md5.o t_md5
