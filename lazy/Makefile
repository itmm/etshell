.PHONY: all test clean

CFLAGS += -Wall -pedantic -Werror

all: test

test: lazy $(TESTS)
	@$(MAKE) --directory=tests test

clean:
	@rm -f lazy
	@$(MAKE) --directory=tests clean
