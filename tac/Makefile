ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/log/lib.mk
include $(ETSHELL_DIR)/ta/lib.mk
include $(ETSHELL_DIR)/marked-files-in/lib.mk
include $(ETSHELL_DIR)/marked-files-out/lib.mk

test: tac
	$(MAKE) sub_test

include tac.d

tac: tac.o $(LIBS)

clean:
	$(RM) tac tac.o .mdp_run
	$(MAKE) sub_test_clean
