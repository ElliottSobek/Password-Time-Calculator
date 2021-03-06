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

#if _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pst.h"
#include "shared.h"

#define LEN_MENU_LEN 170

static char *getPasswordLengthMenu(void) {
	char *const menu = (char*) malloc(LEN_MENU_LEN * sizeof(char));

	checkMalloc(menu);
	snprintf(menu, LEN_MENU_LEN, "\n1. Calculate Password Length\n"
			"2. Set Amount of Password Characters (%hu)\n"
			"3. Set Time Unit (%s)\n4. Set Password Attack Rate (%u/s)\n"
			"0. Back\n\n", numberOfCharacters, timeUnit, passwordAttackRate);
	return menu;
}

static short getTimeInput(void) {
	short input;
	printf("\nEnter an amount of time in %s: ", timeUnit);
	scanf("%hi", &input);
	return input;
}

static double calculatePasswordLength(const short time) {
	unsigned short timeInSeconds;
	if (strncmp(timeUnit, "Days", 5) == 0)
		timeInSeconds = time * DAYS;
	else if (strncmp(timeUnit, "Weeks", 6) == 0)
		timeInSeconds = time * WEEKS;
	else if (strncmp(timeUnit, "Months", 7) == 0)
		timeInSeconds = time * MONTHS;
	else
		timeInSeconds = time * YEARS;
	const double numberOfPasswords = timeInSeconds * passwordAttackRate;

	return (double) (log(numberOfPasswords) / log(numberOfCharacters));
}

void passwordLengthMenu(void) {
	short input, timeInput;
	double result;
	bool backFlag = false;

	while (!backFlag) {
		input = getAMenuInput(getPasswordLengthMenu());

		while (!isValidBounds(input, 0, 4)) {
			purgeBuffer();
			printf("\nNot a menu option\n");
			input = getAMenuInput(getPasswordLengthMenu());
		}
		switch (input) {
		case 1:
			timeInput = getTimeInput();
			while (0 > timeInput) {
				purgeBuffer();
				printf("\nTime must be positive.\n");
				timeInput = getTimeInput();
			}
			result = calculatePasswordLength(timeInput);
			printf("\nThis is the minimum password length for the time and "
				"attack rate given: %.1f (Rounded up)\n", ceil(result));
			break;
		case 2:
			setNumberOfCharacters();
			break;
		case 3:
			setTimeUnit();
			break;
		case 4:
			setPasswordAttackRate();
			break;
		case 0:
			backFlag = true;
			break;
		}
	}
}
