ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/log/lib.mk
include $(ETSHELL_DIR)/csv/lib.mk
include $(ETSHELL_DIR)/ttsv/lib.mk

test: ttsv2csv
	# done

ttsv2csv: ttsv2csv.o $(LIBS)

include ttsv2csv.d

clean:
	$(RM) ttsv2csv ttsv2csv.o
