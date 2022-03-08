# Makefile

all: examheap

examheap: examheap.o heap.o
	g++ --std=c++11 -Wall -g -o examheap examheap.cpp heap.o

examheap.o: examheap.cpp
	g++ -c -g --std=c++11 -Wall examheap.cpp

heap.o: heap.cpp
	g++ -c -g --std=c++11 -Wall heap.cpp

clean:
	rm -f examheap *.o
