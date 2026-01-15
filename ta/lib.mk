ETSHELL_DIR ?= ..
DIR = $(ETSHELL_DIR)/ta
LIB = libta.a
FULL_LIB = $(DIR)/$(LIB)

$(FULL_LIB): $(DIR)/ta.h $(DIR)/ta.cpp $(ETSHELL_DIR)/log/log.h \
		 $(ETSHELL_DIR)/marked-files-in/marked-files-in.h \
		 $(ETSHELL_DIR)/marked-files-out/marked-files-out.h
	$(MAKE) -C $(DIR) $(LIB)

LIBS += $(FULL_LIB)
