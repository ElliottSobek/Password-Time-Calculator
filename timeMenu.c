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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pst.h"
#include "shared.h"

#define TIME_ATK_MENU_LEN 190

static char *getTimeAttackMenu(void) {
	char *const menu = (char*) malloc(TIME_ATK_MENU_LEN * sizeof(char));

	checkMalloc(menu);
	snprintf(menu, TIME_ATK_MENU_LEN, "\n1. Calculate Time\n"
			 "2. Set Password Length (%hu)\n"
			 "3. Set Amount of Password Characters (%hu)\n"
			 "4. Set Result Unit (%s)\n"
			 "5. Set Password Attack Rate (%u/s)\n"
			 "0. Back\n\n", passwordLength, numberOfCharacters, timeUnit,
			 				passwordAttackRate);
	return menu;
}

/* Return units: seconds */
static double calculatePasswordCrackTime(const double numberOfPasswords) {
	const double timeInSeconds = (double) (numberOfPasswords / passwordAttackRate);

	if (strncmp(timeUnit, "Days", 4) == 0)
		return timeInSeconds / DAYS;
	else if (strncmp(timeUnit, "Weeks", 5) == 0)
		return timeInSeconds / WEEKS;
	else if (strncmp(timeUnit, "Months", 6) == 0)
		return timeInSeconds / MONTHS;
	return timeInSeconds / YEARS;
}

void timeAttackMenu(void) {
	short input;
	double result;
	bool backFlag = false;

	while (!backFlag) {
		input = getAMenuInput(getTimeAttackMenu());
		while (!isValidBounds(input, 0, 5)) {
			purgeBuffer();
			printf("\nNot a menu option\n");
			input = getAMenuInput(getTimeAttackMenu());
		}
		switch (input) {
		case 1:
			result = calculatePasswordCrackTime(calculateNumberOfPasswords());
			printf("\nThis is the password crack time: %.1f %s\n", result, timeUnit);
			break;
		case 2:
			setPasswordLength();
			break;
		case 3:
			setNumberOfCharacters();
			break;
		case 4:
			setTimeUnit();
			break;
		case 5:
			setPasswordAttackRate();
			break;
		case 0:
			backFlag = true;
			break;
		}
	}
}
