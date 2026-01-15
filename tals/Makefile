ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/log/lib.mk
include $(ETSHELL_DIR)/ta/lib.mk
include $(ETSHELL_DIR)/marked-files-in/lib.mk
include $(ETSHELL_DIR)/marked-files-out/lib.mk

test: tals
	# done

tals: tals.o $(LIBS)

include tals.d

clean:
	$(RM) tals tals.o
