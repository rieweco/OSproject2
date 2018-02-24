#	MAKEFILE
CFLAGS = -g -Wall -Wshadow -o
GCC = gcc $(CFLAGS)

all:	producer consumer master

producer: producer.c timeFormat.c
	$(CC) $(CFLAGS) producer producer.c timeFormat.c	

consumer: consumer.c timeFormat.c
	$(CC) $(CFLAGS) consumer consumer.c timeFormat.c

master: main.c master.c makeargv.c
	$(CC) $(CFLAGS) master main.c master.c makeargv.c 
	

clean:
	rm -f *.o producer consumer master
