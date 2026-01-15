ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/log/lib.mk
include $(ETSHELL_DIR)/ta/lib.mk
include $(ETSHELL_DIR)/marked-files-in/lib.mk
include $(ETSHELL_DIR)/marked-files-out/lib.mk

test: tasplit
	# done

include tasplit.d

tasplit: tasplit.o $(LIBS)

clean:
	$(RM) tasplit tasplit.o .mdp_run

dist: $(DIST_DIR)/tasplit
