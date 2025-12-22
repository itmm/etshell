include ../Makefile.base

test: csv2ttsv
	@# $(MAKE) sub_test

csv2ttsv: csv2ttsv.o log_lib csv_lib
	@echo building $@
	@$(CC) csv2ttsv.o -L../csv -lcsv -L../log -llog -o $@

csv2ttsv.o: ../csv/csv.h ../log/log.h

clean:
	@rm -f csv2ttsv csv2ttsv.o
	@# $(MAKE) sub_test_clean
