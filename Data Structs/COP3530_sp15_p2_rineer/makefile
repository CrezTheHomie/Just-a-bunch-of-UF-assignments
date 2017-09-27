CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

bTree: bTree.o
	$(CC) $(LFLAGS) bTree_main.o bTree.o -o bTree

bTree.o: bTree.h
	$(CC) $(CFLAGS) bTree.h

bTree_main.o: bTree_main.cpp
	$(CC) $(CFLAGS) bTree_main.cpp

clean:
	rm -rf *o  hash-table
