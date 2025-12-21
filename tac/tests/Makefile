TESTS := test_simple test_escaping test_cascading

.PHONY: all test $(TESTS) clean

all: test

test_simple:
	@echo "abc" > a
	@echo "def" > b
	@../tac a b > t
	@echo "%file a\nabc\n%file b\ndef" > e
	@diff t e
	@rm a b t e

test_escaping:
	@echo "%ab%c" > a
	@../tac a > t
	@echo "%file a\n%%ab%c" > e
	@diff t e
	@rm a t e

test_cascading:
	@echo "abc" > a
	@../tac a > tt
	@../tac tt > t
	@echo "%file tt\n%%file a\nabc" > e
	@diff t e
	@rm a t tt e

test: $(TESTS)

clean:
	@rm -f t e
