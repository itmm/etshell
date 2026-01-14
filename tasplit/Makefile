include ../base.mk
include ../log/lib.mk
include ../ta/lib.mk
include ../marked-files-in/lib.mk
include ../marked-files-out/lib.mk

test: tasplit
	# done

include tasplit.d

tasplit: tasplit.o $(LIBS)

clean:
	$(RM) tasplit tasplit.o .mdp_run
