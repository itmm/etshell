ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/base.mk
include $(ETSHELL_DIR)/log/lib.mk
include lib.mk

test: $(LIBS)
	# done

$(LIB): $(LIB)(marked-files-in.o)

include marked-files-in.d

clean:
	$(RM) libmarked-files-in.a marked-files-in.o
