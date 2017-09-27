CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

hash-table: hashtable.o
	$(CC) $(LFLAGS) hashtable.o -o hash-table

hashtable.o: hashtable.cpp
	$(CC) $(CFLAGS) hashtable.cpp

clean:
	rm -rf *o  hash-table
