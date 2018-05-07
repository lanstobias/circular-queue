CC := gcc
FLAGS := -g -std=c99 -Wall -Werror
CCFLAGS := $(CC) $(FLAGS)

all: executable tests


executable: main.o Queue.o Queue.h
	$(CC) main.o Queue.o -o queue

tests: TestQueue.o Queue.h
	$(CC) Queue.o TestQueue.o -o tests


main.o: main.c Queue.h
	$(CCFLAGS) -c main.c

Queue.o: Queue.c Queue.h
	$(CCFLAGS) -c Queue.c

TestQueue.o: TestQueue.c Queue.c Queue.h
	$(CCFLAGS) -c TestQueue.c Queue.c


clean:
	rm *.o queue tests