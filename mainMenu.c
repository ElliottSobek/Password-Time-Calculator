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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pst.h"

void mainMenu(void) {
	short input;
	input = getMainMenuInput();
	while (1) {
		while (false == isValidBounds(input, 0, 2)) {
			purgeBuffer();
			printf("\nNot a menu option\n");
			input = getMainMenuInput();
		}
		switch (input) {
			case 1:
				timeAttackMenu();
				input = getMainMenuInput();
				break;
			case 2:
				passwordLengthMenu();
				input = getMainMenuInput();
				break;
			case 0:
				exit(EXIT_SUCCESS);
		}
	}
}

short getMainMenuInput(void) {
	printf("\n1. Calculate Time Until Successful brute force attack\n2. "
		   "Calculate Password Length\n0. Quit\n\n");
	short input;
	printf("Enter a menu option: ");
	scanf("%hi", &input);
	return input;
}
