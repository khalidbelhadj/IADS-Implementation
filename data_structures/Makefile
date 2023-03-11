CFLAGS=-Wall -Wextra -std=c11 -pedantic

output: main.o
	g++ ${CFLAGS} main.o -o main

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o main
