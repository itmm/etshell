ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/md5/lib.mk
include $(ETSHELL_DIR)/marked-files-out/lib.mk
include $(ETSHELL_DIR)/log/lib.mk

test: md5add
	# done

md5add: md5add.o $(LIBS)

include md5add.d

clean:
	$(RM) md5add md5add.o .mdp_run

dist: $(DIST_DIR)/md5add
