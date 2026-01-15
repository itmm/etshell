.PHONY: all test clean sub_test sub_test_clean dist

ETSHELL_DIR ?= ..
CPPFLAGS += -I$(ETSHELL_DIR)
CXXFLAGS += -std=c++20 -O3 -Wall -pedantic -Werror

DIST_DIR ?= $(HOME)/bin

LIBS :=

LINK.o = $(CXX) $(LDFLAGS) $(TARGET_ARCH)

all: test

%.d: %.cpp
	$(CXX) -MM $(CPPFLAGS) $< -o $@

sub_test:
	$(MAKE) -C tests

sub_test_clean:
	$(MAKE) -C tests clean

dist:
	# dist

$(DIST_DIR)/%: %
	cp $< $@
