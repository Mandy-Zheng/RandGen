ifeq ($(DEBUG),true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o random.o
	$(CC) -o program main.o random.o

main.o: main.c main.c random.h
	$(CC) -c main.c

random.o: random.c random.h
	$(CC) -c random.c random.h

run:
	./program

clean:
	rm *.o
	rm *.exe

memcheck:
	valgrind --leak-check=yes ./program
