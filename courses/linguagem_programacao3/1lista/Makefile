CC = gcc

CFLAGS = -Wall -O2

all: .exe

data.o: data.h data.c
	$(CC) -c $(CFLAGS) data.c

.exe: data.o main.c
	$(CC) -c $(CFLAGS) main.c
	$(CC) -o .exe data.o main.o

clean: 
	rm *.o 
	rm .exe
	