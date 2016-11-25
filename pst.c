/*
 * Password Time Calculator
 * Copyright (C) 2016  Author: Elliott Sobek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
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

#include "pst.h"
#include "mainMenu.h"

void initialize(void) {
	passwordAttackRate = 1000000000;
	passwordLength = 8;
	numberOfCharacters = 62;
	timeUnit = "Days";
	printf("Password Time Calculator Copyright (C) 2016 Author: Elliott Sobek.\n"
		   "This program comes with ABSOLUTELY NO WARRANTY.\nThis is free "
		   "software, and you are welcome to redistribute it under certain "
		   "conditions.\n");
}

int main(void) {
    initialize();
    mainMenu();
    return 1;
}
