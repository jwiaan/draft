.PHONY: all clean
all = server client
src = $(wildcard *.c)
all: $(all)
$(all): common.o
$(src:.c=.o): common.h
clean:
	rm -f *.o $(all)
