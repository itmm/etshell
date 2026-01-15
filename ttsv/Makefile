ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/log/lib.mk
include lib.mk

include ttsv.d

test: $(LIBS)
	# done

$(LIB): $(LIB)(ttsv.o)

clean:
	$(RM) libttsv.a ttsv.o
