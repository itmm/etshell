.PHONY: all test clean

CFLAGS += -Wall -pedantic -Werror

all: test

test: tals
	@#$(MAKE) --directory=tests test

clean:
	@rm -f tac
	@#$(MAKE) --directory=tests clean
