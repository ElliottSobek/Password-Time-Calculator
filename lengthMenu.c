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

#if _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "pst.h"
#include "shared.h"

char *getPasswordLengthMenu(void) {
	char *menu = malloc(170 * sizeof(char));
	checkMalloc(menu);
	snprintf(menu, 170, "\n1. Calculate Password Length\n2. Set Amount of Password Characters"
		" (%hu)\n3. Set Time Unit (%s)\n4. Set Password Attack Rate (%u) per"
		" second\n0. Back\n\n", numberOfCharacters, timeUnit, passwordAttackRate);
	return menu;
}

short getTimeInput(void) {
	short input;
	printf("\nEnter an amount of time in %s: ", timeUnit);
	scanf("%hi", &input);
	return input;
}

double calculatePasswordLength(short time) {
	unsigned short timeInSeconds;
	if (strncmp(timeUnit, "Days", 5) == 0)
		timeInSeconds = time * DAYS;
	else if (strncmp(timeUnit, "Weeks", 6) == 0)
		timeInSeconds = time * WEEKS;
	else if (strncmp(timeUnit, "Months", 7) == 0)
		timeInSeconds = time * MONTHS;
	else
		timeInSeconds = time * YEARS;
	double numberOfPasswords;
	numberOfPasswords = timeInSeconds * passwordAttackRate;
	return (double) (log(numberOfPasswords) / log(numberOfCharacters));
}

void passwordLengthMenu(void) {
	short input, timeInput;
	bool backFlag = false;
	double result;
	while (backFlag == false) {
		input = getAMenuInput(getPasswordLengthMenu());
		while (false == isValidBounds(input, 0, 4)) {
			purgeBuffer();
			printf("\nNot a menu option\n");
			input = getAMenuInput(getPasswordLengthMenu());
		}
		switch (input) {
		case 1:
			timeInput = getTimeInput();
			while (timeInput < 0) {
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
