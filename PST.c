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

/* Headers */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// # include <stdio_ext.h> Don't work?
// # include "PST.h"

/* Macros */
#define TRUE 0
#define FALSE 1
#define DAYS 86400
#define WEEKS 4492800 // Fix <--
#define MONTHS 2678400
#define YEARS 31536000

/* Prototypes */
void mainMenu(void);
void initialize(void);
void printTimeAttackMenu(void);
void printPasswordLengthMenu(void);
void timeAttackMenu(void);
void passwordLengthMenu(void);
void printTimeUnitOptions(void);
void setPasswordAttackRate(void);
void setPasswordLength(unsigned short int);
void setNumberOfCharacters(unsigned short int);
void setTimeUnit(void);
char isValidMainMenuInput(unsigned short int);
char isValidTimeMenuInput(unsigned short int);
char isValidTimeUnitInput(unsigned short int);
char isValidPasswordAttackRate(unsigned int);
char isValidPasswordLengthMenuInput(unsigned short int);
float calculatePasswordCrackTime(unsigned long long int);
unsigned short int getMenuInput(void);
unsigned short int getTimeAttackMenuInput(void);
unsigned short int getPasswordLengthMenuInput(void);
unsigned short int getTimeUnitInput(void);
unsigned short int roundUp(float);
unsigned short int secondsToDays(unsigned int);
unsigned short int secondsToWeeks(unsigned int);
unsigned short int secondsToMonths(unsigned int);
unsigned short int secondsToYears(unsigned int);
unsigned short int claculatePasswordLength(unsigned short int);
unsigned long long int calculateNumberOfPasswords(void);


/* Globals */
unsigned int passwordAttackRate = 1000000000; // Per second
unsigned short int passwordLength = 8;
unsigned short int numberOfCharacters = 62; // Digits + Upper & Lower case
char * timeUnit = "Days";

/* Functions */
int main(void)
{
    initialize();
    mainMenu();
    return 0;
}

void printMainMenu(void)
{
    printf("\n1. Calculate Time Until Successful brute force attack\n2. "
            "Calculate Password Length\n0. Quit\n\n");
}

void printTimeAttackMenu(void)
{
    printf("\n1. Calculate Time\n2. Set Password Length (%d)\n3. Set Amount of "
            "Password Characters (%d)\n4. Set Result Unit (%s)\n5. Set Password "
            "Attack Rate (%d)\n0. Back\n\n", passwordLength, numberOfCharacters,
            timeUnit, passwordAttackRate);
}

void printPasswordLengthMenu(void)
{
    printf("\n1. Calculate Password Length\n2. Set Amount of Password Characters"
            " (%d)\n3. Set Time Unit (%s)\n4. Set Password Attack Rate (%d)\n0. "
            "Back\n\n", passwordLength, timeUnit, passwordAttackRate);
}

void initialize(void)
{
    printf("Password Time Calculator Copyright (C) 2016 Author: Elliott Sobek.\n"
            "This program comes with ABSOLUTELY NO WARRANTY.\nThis is free "
            "software, and you are welcome to redistribute it under certain "
            "conditions.\n");
}

unsigned short int getMainMenuInput(void)
{
    printMainMenu();
    int input;
    printf("Enter a menu option: ");
    scanf("%d", &input);
    return input;
}

char isValidMainMenuInput(unsigned short int input)
{
    if ((input < 0) || (input > 2)) {
        return FALSE;
    } else {
        return TRUE;
    }
}

char isValidTimeAttackMenuInput(unsigned short int input)
{
    if ((input < 0) || (input > 5)) {
        return FALSE;
    } else {
        return TRUE;
    }
}

char isValidPasswordLengthMenuInput(unsigned short int input)
{
    if ((input < 0) || (input > 4)) {
        return FALSE;
    } else {
        return TRUE;
    }
}

unsigned long long int calculateNumberOfPasswords(void)
{
    return pow(numberOfCharacters, passwordLength);
}

/* Return units: seconds */
float calculatePasswordCrackTime(unsigned long long int numberOfPasswords)
{
    float timeInSeconds = (float) numberOfPasswords / passwordAttackRate;
    if (strcmp(timeUnit, "Days") == 0) {
        return timeInSeconds / DAYS;
    } else if (strcmp(timeUnit, "Weeks") == 0) {
        return timeInSeconds / WEEKS;
    } else if (strcmp(timeUnit, "Months") == 0) {
        return timeInSeconds / MONTHS;
    }
    return timeInSeconds / YEARS;
}

unsigned short int calculatePasswordLength(unsigned long long int numberOfPasswords)
{
    return log(numberOfPasswords) / log(numberOfCharacters);
}

unsigned short int roundUp(float num)
{
    int roundNum = 100 * num;
    double decimal = (100 * num) - roundNum;
    if (decimal > 0) {
        roundNum = (num + 0.01) * 100;
    } else {
        roundNum = num * 100;
    }
    return roundNum;
}

unsigned short int secondsToDays(unsigned int time)
{
    return time / DAYS;
}

unsigned short int secondsToWeeks(unsigned int time)
{
    return time / WEEKS;
}

unsigned short int secondsToMonths(unsigned int time)
{
    return time / MONTHS;
}

unsigned short int secondsToYears(unsigned int time)
{
    return time / YEARS;
}

void setPasswordAttackRate(void)
{
    int attackRate;
    printf("Enter an attack rate (passwords/second): ");
    scanf("%d", &attackRate);
    while (FALSE == isValidPasswordAttackRate(attackRate)) {
        printf("Attack rate must be positive.\n\nEnter an attack rate "
                "(passwords/second): ");
        scanf("%d", &attackRate);
    }
    passwordAttackRate = attackRate;
}

char isValidPasswordAttackRate(unsigned int rate)
{
    if (rate > 0) {
        return TRUE;
    }
    return FALSE;
}

void setPasswordLength(unsigned short int length)
{
    passwordLength = length;
}

void setNumberOfCharacters(unsigned short int num)
{
    numberOfCharacters = num;
}

void setTimeUnit(void)
{
    unsigned short int input;
    input = getTimeUnitInput();
    while (FALSE == isValidTimeUnitInput(input)) {
        printf("\nNot a menu option\n");
        input = getTimeUnitInput();
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

unsigned short int getTimeUnitInput(void)
{
    printTimeUnitOptions();
    int input;
    printf("Enter a menu option: ");
    scanf("%d", &input);
    return input;
}

void printTimeUnitOptions(void)
{
    printf("\n1. Days\n2. Weeks\n3. Months\n4. Years\n0. Back\n\n");
}

char isValidTimeUnitInput(unsigned short int input)
{
    if ((input < 0) || (input > 4)) {
        return FALSE;
    } else {
        return TRUE;
    }
}

void mainMenu(void)
{
    unsigned short int input;
    input = getMainMenuInput();
    while (1) {
        while (FALSE == isValidMainMenuInput(input)) {
            printf("\nNot a menu option\n");
            input = getMainMenuInput();
        }
        switch (input) {
        case 1:
            timeAttackMenu();
            break;
        case 2:
            passwordLengthMenu();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        }
    }
}

void timeAttackMenu(void)
{
    unsigned short int input;
    float result;
    input = getTimeAttackMenuInput();
    while (FALSE == isValidTimeAttackMenuInput(input)) {
        printf("\nNot a menu option\n");
        input = getTimeAttackMenuInput();
    }
    switch (input) {
    case 1:
        result = calculatePasswordCrackTime(calculateNumberOfPasswords());
        printf("This is result: %d %s", roundUp(result), timeUnit);
        break;
    case 2:
        // setPasswordLength
        break;
    case 3:
        // setNumberOfCharacters
        break;
    case 4:
        setTimeUnit();
        break;
    case 5:
        setPasswordAttackRate();
        break;
    case 0:
        break;
    }
}

void passwordLengthMenu(void)
{
    unsigned short int menuOption;
    menuOption = getPasswordLengthMenuInput();
    while (1) {
        switch (menuOption) {
        case 1:
            // Calculate
            break;
        case 2:
            // setNumberOfCharacters
            break;
        case 3:
            setTimeUnit();
            break;
        case 4:
            setPasswordAttackRate();
            break;
        case 0:
            mainMenu();
            break;
        default:
            printf("\nNot a menu option\n");
            menuOption = getPasswordLengthMenuInput();
            break;
        }
    }
}

unsigned short int getTimeAttackMenuInput(void)
{
    printTimeAttackMenu();
    int input;
    printf("Enter a menu option: ");
    scanf("%d", &input);
    return input;
}

unsigned short int getPasswordLengthMenuInput(void)
{
    printPasswordLengthMenu();
    int input;
    printf("Enter a menu option: ");
    scanf("%d", &input);
    return input;
}