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
#ifndef PST_H
#define PST_H

#include <stdbool.h>

/* Macros */
#define DAYS 86400
#define WEEKS 604800
#define MONTHS 2678400 // 31 days
#define YEARS 31536000 // 365 days

/* Globals */
unsigned int passwordAttackRate;
unsigned short int passwordLength;
unsigned short int numberOfCharacters;
char * timeUnit;

// PROTOTYPES //

/* Main Menu prototypes */
void mainMenu(void);
short int getMainMenuInput(void);

/* Time Menu prototypes */
void timeAttackMenu(void);
char *  getTimeAttackMenu(void);
double calculatePasswordCrackTime(double);

/* Length Menu prototypes */
void passwordLengthMenu(void);
char *  getPasswordLengthMenu(void);
short int getTimeInput(void);
double calculatePasswordLength(short int);

/* Support prototypes */
void purgeBuffer(void);
void setTimeUnit(void);
void setPasswordLength(void);
void setPasswordAttackRate(void);
void setNumberOfCharacters(void);
void waitFor(unsigned int);
void checkMalloc(char *);
char * getNumberOfCharactersMenu(void);
char * getTimeMenu(void);
bool isValidBounds(int, short int, int);
short int getAMenuInput(char *);
short int getPasswordLengthInput(void);
double calculateNumberOfPasswords(void);
#endif // !PST_H
