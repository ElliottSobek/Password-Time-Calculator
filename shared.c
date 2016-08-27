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
#include <math.h>
#include <stdbool.h>
#include "pst.h"

void purgeBuffer(void) {
	fseek(stdin, 0, SEEK_END);
}

void setTimeUnit(void) {
	short int input;
	input = getAMenuInput(getTimeMenu());
	while (false == isValidBounds(input, 0, 4)) {
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

void setPasswordLength(void) {
	short int length;
	length = getPasswordLengthInput();
	while (false == isValidBounds(length, 0, 32)) {
		purgeBuffer();
		printf("\nEntered length not between 1 and 32 inclusive.\n");
		length = getPasswordLengthInput();
	}
	if (length == 0) {
		return;
	}
	passwordLength = length;
}

void setPasswordAttackRate(void) {
	long int attackRate;
	printf("\nEnter an attack rate between 1 and 1,000,000,000 inclusive (passwords/second). 0 to go back: ");
	scanf("%li", &attackRate);
	while (false == isValidBounds(attackRate, 0, 1000000000)) {
		purgeBuffer();
		printf("\nEntered attack rate not between 1 and 1,000,000,000 inclusive (passwords/second). 0 to go back: ");
		scanf("%li", &attackRate);
	}
	if (attackRate == 0) {
		return;
	}
	passwordAttackRate = attackRate;
}

void setNumberOfCharacters(void) {
	short int input;
	input = getAMenuInput(getNumberOfCharactersMenu());
	while (false == isValidBounds(input, 0, 4)) {
		purgeBuffer();
		printf("\nNot a menu option\n");
		input = getAMenuInput(getNumberOfCharactersMenu());
	}
	switch (input) {
		case 1: // See top of file for details.
			numberOfCharacters = 10; // Numeric
			break;
		case 2:
			numberOfCharacters = 52; // Lower/Upper case
			break;
		case 3:
			numberOfCharacters = 62; // Numeric + Lower/Upper case
			break;
		case 4:
			numberOfCharacters = 95; // Numeric + Lower/Upper case + Symbols
			break;
		case 0:
			break;
	}
}

bool isValidBounds(int input, short int lowerBound, unsigned int upperBound) {
	if ((input < lowerBound) || (input > upperBound)) {
		return false;
	}
	return true;
}

short int getAMenuInput(const char * message) {
	printf("%s", message);
	short int input;
	printf("Enter a menu option: ");
	scanf("%hi", &input);
	return input;
}

short int getPasswordLengthInput(void) {
	printf("\nEnter a password length between 1 to 32 inclusive. 0 to go back: ");
	short int input;
	scanf("%hi", &input);
	return input;
}

double calculateNumberOfPasswords(void) {
	return pow(numberOfCharacters, passwordLength);
}

const char * getNumberOfCharactersMenu(void) {
	const char * menu = "\n1. Numeric\n2. Lower/Upper Case\n3. Numeric + Lower/Upper Case\n"
		"4. Numeric + Lower/Upper Case + Symbols\n0. Back\n\n";
	return menu;
}

const char * getTimeMenu(void) {
	const char * menu = "\n1. Days\n2. Weeks\n3. Months\n4. Years\n0. Back\n\n";
	return menu;
}