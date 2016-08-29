CC = gcc

CFLAGS = -Wall -std=c11

all: pst

pst: pst.o mainMenu.o timeMenu.o lengthMenu.o shared.o
	$(CC) $(CFLAGS) pst.o mainMenu.o timeMenu.o lengthMenu.o shared.o -o PST -l m

pst.o: pst.c
	$(CC) $(CFLAGS) pst.c -c

mainMenu.o: mainMenu.c
	$(CC) $(CFLAGS) mainMenu.c -c

timeMenu.o: timeMenu.c
	$(CC) $(CFLAGS) timeMenu.c -c

lengthMenu.o: lengthMenu.c
	$(CC) $(CFLAGS) lengthMenu.c -c

shared.o: shared.c
	$(CC) $(CFLAGS) shared.c -c

.PHONY: clean
clean:
	rm *.o