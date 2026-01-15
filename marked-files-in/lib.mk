ETSHELL_DIR ?= ..
DIR := $(ETSHELL_DIR)/marked-files-in
LIB := libmarked-files-in.a
FULL_LIB := $(DIR)/$(LIB)

$(FULL_LIB): $(DIR)/marked-files-in.h $(DIR)/marked-files-in.cpp \
		 $(ETSHELL_DIR)/log/log.h
	$(MAKE) -C $(DIR) $(LIB)

LIBS += $(FULL_LIB)
