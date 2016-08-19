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

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pst.h"

void timeAttackMenu(void)
{
	short int input, backFlag = false;
	double result;
	while (backFlag == false) {
		//input = getTimeAttackMenuInput();
		input = getAMenuInput(getTimeAttackMenu());
		while (false == isValidMenuInput(input, 0, 5)) { // orig: isValidTimeAttackMenuInput(input)
			purgeBuffer();
			printf("\nNot a menu option\n");
			//input = getTimeAttackMenuInput();
			input = getAMenuInput(getTimeAttackMenu());
		}
		switch (input) {
			case 1:
				printf("\nThis is the number of passwords: %f\n", calculateNumberOfPasswords());
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

const char * getTimeAttackMenu(void)
{
	char * menu = "";
	/*printf("\n1. Calculate Time\n2. Set Password Length (%hu)\n3. Set Amount of "
		   "Password Characters (%hu)\n4. Set Result Unit (%s)\n5. Set Password "
		   "Attack Rate (%u) per second\n0. Back\n\n", passwordLength,
		   numberOfCharacters, timeUnit, passwordAttackRate);*/
	sprintf_s(menu, "\n1. Calculate Time\n2. Set Password Length (%hu)\n3. Set Amount of "
			"Password Characters (%hu)\n4. Set Result Unit (%s)\n5. Set Password "
			"Attack Rate (%u) per second\n0. Back\n\n", passwordLength,
			numberOfCharacters, timeUnit, passwordAttackRate);
	return menu;
}

//bool isValidTimeAttackMenuInput(short int input)
//{
//	if ((input < 0) || (input > 5)) {
//		return false;
//	}
//	return true;
//}

//short int getTimeAttackMenuInput(void)
//{
//	printTimeAttackMenu();
//	short int input;
//	printf("Enter a menu option: ");
//	scanf_s("%hi", &input);
//	return input;
//}

/* Return units: seconds */
double calculatePasswordCrackTime(double numberOfPasswords)
{
	double timeInSeconds = (double) numberOfPasswords / passwordAttackRate;
	printf("\nThis is timeInSeconds: %f\n", timeInSeconds);
	if (strcmp(timeUnit, "Days") == 0) {
		return timeInSeconds / DAYS;
	} else if (strcmp(timeUnit, "Weeks") == 0) {
		return timeInSeconds / WEEKS;
	} else if (strcmp(timeUnit, "Months") == 0) {
		return timeInSeconds / MONTHS;
	}
	return timeInSeconds / YEARS;
}