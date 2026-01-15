ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/log/lib.mk
include $(ETSHELL_DIR)/ta/lib.mk
include $(ETSHELL_DIR)/marked-files-in/lib.mk
include $(ETSHELL_DIR)/marked-files-out/lib.mk

test: tacat
    # ok

tacat: tacat.o $(LIBS)

include tacat.d

clean:
	$(RM) tacat tacat.o

dist: $(DIST_DIR)/tacat
