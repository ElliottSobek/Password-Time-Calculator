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
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "pst.h"

#define SECOND 1

#define NUMERIC         10
#define LOWER_UPPER     52
#define NUM_LOW_UPR     62
#define NUM_LOW_UPR_SYM 95

#define TIME_MENU_LEN      48
#define NUM_CHAR_MENU_LEN 133

void purgeBuffer(void) {
	fseek(stdin, 0, SEEK_END);
}

void checkMalloc(char *charPointer) {
	if (!charPointer) {
		printf("\nError allocating memory.\n");
		sleep(4 * SECOND);
		exit(EXIT_FAILURE);
	}
}

char *getNumberOfCharactersMenu(void) {
	char *menu = malloc(NUM_CHAR_MENU_LEN * sizeof(char));

	checkMalloc(menu);
	strncpy(menu, "\n1. Numeric\n2. Lower/Upper Case"
		"\n3. Numeric + Lower/Upper Case"
		"\n4. Numeric + Lower/Upper Case + Symbols\n0. Back"
		"\n\n", NUM_CHAR_MENU_LEN);
	return menu;
}

short getPasswordLengthInput(void) {
	printf("\nEnter a password length between 1 to 32 inclusive. 0 to go back: ");
	short input;
	scanf("%hi", &input);
	return input;
}

bool isValidBounds(int input, short lowerBound, int upperBound) {
	if ((input < lowerBound) || (input > upperBound))
		return false;
	return true;
}

void setPasswordLength(void) {
	short length = getPasswordLengthInput();

	while (!isValidBounds(length, 0, 32)) {
		purgeBuffer();
		printf("\nEntered length not between 1 and 32 inclusive.\n");
		length = getPasswordLengthInput();
	}
	if (0 == length)
		return;
	passwordLength = length;
}

short getAMenuInput(char *message) {
	printf("%s", message);
	free(message);
	short input;
	printf("Enter a menu option: ");
	scanf("%hi", &input);
	return input;
}

char *getTimeMenu(void) {
	char *menu = malloc(TIME_MENU_LEN * sizeof(char));

	checkMalloc(menu);
	strncpy(menu, "\n1. Days\n2. Weeks\n3. Months\n4. Years\n0. Back\n\n"
		, TIME_MENU_LEN);
	return menu;
}

void setTimeUnit(void) {
	short input = getAMenuInput(getTimeMenu());

	while (!isValidBounds(input, 0, 4)) {
		purgeBuffer();
		printf("\nNot a menu option\n");
		input = getAMenuInput(getTimeMenu());
	}
	switch (input) {
	case 1:
		timeUnit = "Days";
		break;
	case 2:
		timeUnit = "Weeks";
		break;
	case 3:
		timeUnit = "Months";
		break;
	case 4:
		timeUnit = "Years";
		break;
	case 0:
		break;
	}
}

void setPasswordAttackRate(void) {
	long attackRate;
	printf("\nEnter an attack rate between 1 and 1,000,000,000 inclusive "
		"(passwords/second). 0 to go back: ");
	scanf("%li", &attackRate);
	while (!isValidBounds(attackRate, 0, 1000000000)) {
		purgeBuffer();
		printf("\nEntered attack rate not between 1 and 1,000,000,000 "
			"inclusive (passwords/second). 0 to go back: ");
		scanf("%li", &attackRate);
	}
	if (0 == attackRate)
		return;
	passwordAttackRate = attackRate;
}

void setNumberOfCharacters(void) {
	short input = getAMenuInput(getNumberOfCharactersMenu());

	while (!isValidBounds(input, 0, 4)) {
		purgeBuffer();
		printf("\nNot a menu option\n");
		input = getAMenuInput(getNumberOfCharactersMenu());
	}
	switch (input) {
	case 1:
		numberOfCharacters = NUMERIC;
		break;
	case 2:
		numberOfCharacters = LOWER_UPPER;
		break;
	case 3:
		numberOfCharacters = NUM_LOW_UPR;
		break;
	case 4:
		numberOfCharacters = NUM_LOW_UPR_SYM;
		break;
	case 0:
		break;
	}
}

double calculateNumberOfPasswords(void) {
	return pow(numberOfCharacters, passwordLength);
}
