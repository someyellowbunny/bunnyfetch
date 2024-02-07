CFLAGS:=-Wall -g -O2
LDFLAGS:=-g

.PHONY: all
OBJS = osrelease.o wm.o main.o

all: wm.o osrelease.o main.o
	$(CC) $(LDFLAGS) wm.o osrelease.o main.o -o bunnyfetch

.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f bunnyfetch *.o
