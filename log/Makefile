GENERATED = Makefile lib.mk log.h log.cpp

ETSHELL_DIR ?= ..
include $(ETSHELL_DIR)/with-mdp.mk
include lib.mk

test: $(LIB)
    # done

include log.d

$(LIB): $(LIB)(log.o)

clean:
	$(RM) $(LIB) log.o
