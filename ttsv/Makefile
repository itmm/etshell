ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/log/lib.mk
include lib.mk

include ttsv.d
include t_ttsv.d

t_ttsv: $(LIBS)

test: t_ttsv
	./t_ttsv

$(LIB): $(LIB)(ttsv.o)

clean:
	$(RM) libttsv.a ttsv.o t_ttsv t_ttsv.o
