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

 /* Guard */
#pragma once

#include <stdbool.h>

/* Macros */
#define DAYS 86400
#define WEEKS 604800
#define MONTHS 2678400 // 31 days
#define YEARS 31536000 // 365 days

/* Globals */
__declspec(selectany) unsigned int passwordAttackRate = 1000000000; // Per second
__declspec(selectany) unsigned short int passwordLength = 8;
__declspec(selectany) unsigned short int numberOfCharacters = 62; // Digits + Upper & Lower case
__declspec(selectany) char * timeUnit = "Days";

// PROTOTYPES //

/* PST prototypes */
int main(void);
void initialize(void);

/* Main Menu prototypes */
void mainMenu(void);
bool isValidMainMenuInput(short int);
short int getMainMenuInput(void);

/* Time Menu prototypes */
void timeAttackMenu(void);
//void printTimeAttackMenu(void);
char * getTimeAttackMenu(void);
//bool isValidTimeAttackMenuInput(short int);
//short int getTimeAttackMenuInput(void);
double calculatePasswordCrackTime(double);

/* Length Menu prototypes */
void passwordLengthMenu(void);
//void printPasswordLengthMenu(void);
char * getPasswordLengthMenu(void);
//bool isValidPasswordLengthMenuInput(short int);
short int getTimeInput(void);
//short int getPasswordLengthMenuInput(void);
double calculatePasswordLength(short int);

/* Support prototypes */
void purgeBuffer(void);
void setTimeUnit(void);
void setPasswordLength(void);
void setPasswordAttackRate(void);
void setNumberOfCharacters(void);
char * getNumberOfCharactersMenu(void);
char * getTimeMenu(void);
bool isValidMenuInput(short int, short int, short int);
//bool isValidTimeUnitInput(short int);
bool isValidPasswordLength(short int);
//bool isValidNumberOfCharactersInput(short int);
bool isValidPasswordAttackRate(int);
short int getAMenuInput(char *);
//short int getTimeUnitInput(void);
short int getPasswordLengthInput(void);
//short int getNumberOfCharactersInput(void);
double calculateNumberOfPasswords(void);