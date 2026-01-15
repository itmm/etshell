ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/log/lib.mk
include $(ETSHELL_DIR)/marked-files-in/lib.mk
include $(ETSHELL_DIR)/marked-files-out/lib.mk
include lib.mk

include ta.d

test: $(LIBS)
	# done

$(LIB): $(LIB)(ta.o)

clean:
	$(RM) libta.a ta.o
