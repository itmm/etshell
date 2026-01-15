ETSHELL_DIR ?= ..
DIR = $(ETSHELL_DIR)/ttsv
LIB = libttsv.a
FULL_LIB = $(DIR)/$(LIB)

$(FULL_LIB): $(DIR)/ttsv.cpp $(DIR)/ttsv.h $(ETSHELL_DIR)/log/log.h
	$(MAKE) -C $(DIR) $(LIB)

LIBS += $(FULL_LIB)
