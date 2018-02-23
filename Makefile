#	MAKEFILE
CFLAGS = -g -Wall -Wshadow -o
GCC = gcc $(CFLAGS)

all:	producer consumer master

producer: 

consumer: 

master:

clean:
	rm -f *.o producer consumer master
