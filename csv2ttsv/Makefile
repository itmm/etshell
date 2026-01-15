ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/log/lib.mk
include $(ETSHELL_DIR)/csv/lib.mk
include $(ETSHELL_DIR)/ttsv/lib.mk

test: csv2ttsv
	# done

csv2ttsv: csv2ttsv.o $(LIBS)

include csv2ttsv.d

clean:
	$(RM) csv2ttsv csv2ttsv.o
