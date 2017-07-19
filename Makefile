AM_CFLAGS := -g -Wall -O2

CC        := gcc
CFLAGS    := $(AM_CFLAGS)

LD        := gcc

APPS      := head_tail_swap main
OBJS      := $(APPS).o
SRCS      := $(APPS).c

head_tail_swap: main.o head_tail_swap.o
	$(LD) $(AM_CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(APPS) *.o *.out
