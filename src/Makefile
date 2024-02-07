CFLAGS:=-Wall -g -O2
LDFLAGS:=-g

.PHONY: all
OBJS = osrelease.o main.o

all: osrelease.o main.o
	$(CC) $(LDFLAGS) osrelease.o main.o -o bunnyfetch

# main.o: main.c
# 	$(CC) $(CFLAGS) -c main.c -o main.o

# osrelease.o: osrelease.c
# 	$(CC) $(CFLAGS) -c osrelease.c osrelease.o

.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f bunnyfetch *.o
