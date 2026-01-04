include ../Makefile.base
include ../log/Makefile.lib
include Makefile.lib

t_csv: ../csv/libcsv.a ../log/liblog.a

test: t_csv
	@echo "testing csv ... \c";
	@./t_csv
	@echo "ok"

clean:
	@rm -f libcsv.a csv.o
