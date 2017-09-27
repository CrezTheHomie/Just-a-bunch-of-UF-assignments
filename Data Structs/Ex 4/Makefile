CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Floyd-Warshall: Floyd-Warshall.o
	$(CC) $(LFLAGS) Floyd-Warshall.o -o Floyd-Warshall

Floyd-Warshall.o: Floyd-Warshall.cpp 
	$(CC) $(CFLAGS) Floyd-Warshall.cpp

clean:
	rm -rf *o Floyd-Warshall
