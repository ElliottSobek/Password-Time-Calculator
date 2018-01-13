/*
 * Password Time Calculator
 * Copyright (C) 2016  Author: Elliott Sobek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/* Numeric: 0123456789
 * Lower case: abcdefghijklmnopqrstuvwxyz
 * Upper case: ABCDEFGHIJKLMNOPQRSTUVWXYZ
 * Symbols: `~!@#$%^&*()-_=+[]\{}|;':",./<>?
 * 'Space' is the 33rd character after the ?
 */

#include <stdio.h>
#include <stdlib.h>

#include "pst.h"
#include "mainMenu.h"

#define DEFAULT_PASS_LEN 8
#define DEFAULT_CHARS_NUM 62
#define DEFAULT_PASS_ATK_RATE 1000000000

#define DEFAULT_TIME_UNIT "Days"

void initialize(void) {
	passwordAttackRate = DEFAULT_PASS_ATK_RATE;
	passwordLength = DEFAULT_PASS_LEN;
	numberOfCharacters = DEFAULT_CHARS_NUM;
	timeUnit = DEFAULT_TIME_UNIT;

	printf("Password Time Calculator Copyright (C) 2016 Author: Elliott Sobek.\n"
		   "This program comes with ABSOLUTELY NO WARRANTY.\n"
		   "This is free software, and you are welcome to redistribute it under"
		   " certain conditions.\n");
}

int main(void) {
    initialize();
    mainMenu();
    return EXIT_SUCCESS;
}
