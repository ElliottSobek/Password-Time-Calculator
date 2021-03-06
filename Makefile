# Password Time Calculator
# Copyright (C) 2016  Author: Elliott Sobek
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -O3 -std=c11 -Wno-unused-result

LDLIBS = -lm

.PHONY: all clean memCheck

all: pst

pst: pst.o mainMenu.o timeMenu.o lengthMenu.o shared.o
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o PST

pst.o: pst.c

mainMenu.o: mainMenu.c

timeMenu.o: timeMenu.c

lengthMenu.o: lengthMenu.c

shared.o: shared.c

clean:
	$(RM) *.o

memCheck:
	valgrind --leak-check=full -v ./PST
