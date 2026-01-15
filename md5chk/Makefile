ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/md5/lib.mk
include $(ETSHELL_DIR)/marked-files-in/lib.mk
include $(ETSHELL_DIR)/log/lib.mk

test: md5chk
	# done

md5chk: md5chk.o $(LIBS)

include md5chk.d

clean:
	$(RM) md5chk md5chk.o .mdp_run

dist: $(DIST_DIR)/md5chk
