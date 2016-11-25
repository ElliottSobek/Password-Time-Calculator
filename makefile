# Password Time Calculator
# Copyright (C) 2016  Author: Elliott Sobek
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -O3 -std=c11

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
