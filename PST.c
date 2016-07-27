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

/* Numeric: 0123456789
 * Lower case: abcdefghijklmnopqrstuvwxyz
 * Upper case: ABCDEFGHIJKLMNOPQRSTUVWXYZ
 * Symbols: `~!@#$%^&*()-_=+[]\{}|;':",./<>? 
 * 'Space' is the 33rd character after the ?
 */

/* Headers */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
// # include "mainMenu.h"
// # include "timeAttackMenu.h"
// # include "LengthMenu.h"

/* Macros */
#define DAYS 86400
#define WEEKS 604800
#define MONTHS 2678400 // 31 days
#define YEARS 31536000 // 365 days

/* Prototypes */
void mainMenu(void);
void initialize(void);
void printTimeAttackMenu(void);
void printPasswordLengthMenu(void);
void timeAttackMenu(void);
void passwordLengthMenu(void);
void setPasswordAttackRate(void);
void setPasswordLength(void);
void setNumberOfCharacters(void);
void setTimeUnit(void);
void printNumberOfCharactersOptions(void);
short int getNumberOfCharactersInput(void);
short int getTimeInput(void);
short int getPasswordLengthInput(void);
bool isValidNumberOfCharactersInput(short int);
bool isValidMainMenuInput(short int);
bool isValidTimeMenuInput(short int);
bool isValidTimeUnitInput(short int);
bool isValidPasswordLengthMenuInput(short int);
bool isValidPasswordLength(short int);
bool isValidPasswordAttackRate(int);
short int getTimeAttackMenuInput(void);
short int getPasswordLengthMenuInput(void);
short int getTimeUnitInput(void);
unsigned short int claculatePasswordLength(unsigned short int);
unsigned long long int calculateNumberOfPasswords(void);
float calculatePasswordLength(unsigned char);
float calculatePasswordCrackTime(unsigned long long int);


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
    return 1;
}

void printTimeAttackMenu(void)
{
    printf("\n1. Calculate Time\n2. Set Password Length (%hu)\n3. Set Amount of "
            "Password Characters (%hu)\n4. Set Result Unit (%s)\n5. Set Password "
            "Attack Rate (%u) per second\n0. Back\n\n", passwordLength, 
            numberOfCharacters, timeUnit, passwordAttackRate);
}

void printPasswordLengthMenu(void)
{
    printf("\n1. Calculate Password Length\n2. Set Amount of Password Characters"
            " (%hu)\n3. Set Time Unit (%s)\n4. Set Password Attack Rate (%u) per"
            " second\n0. Back\n\n", passwordLength, timeUnit, passwordAttackRate);
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
    printf("\n1. Calculate Time Until Successful brute force attack\n2. "
            "Calculate Password Length\n0. Quit\n\n");
    short int input;
    printf("Enter a menu option: ");
    scanf("%hi", &input);
    return input;
}

bool isValidMainMenuInput(short int input)
{
    if ((input < 0) || (input > 2)) {
        return false;
    }
    return true;
}

bool isValidTimeAttackMenuInput(short int input)
{
    if ((input < 0) || (input > 5)) {
        return false;
    }
    return true;
}

bool isValidPasswordLengthMenuInput(short int input)
{
    if ((input < 0) || (input > 4)) {
        return false;
    }
    return true;
}

unsigned long long int calculateNumberOfPasswords(void)
{
    return pow(numberOfCharacters, passwordLength);
}

/* Return units: seconds */
float calculatePasswordCrackTime(unsigned long long int numberOfPasswords)
{
    float timeInSeconds = (float) numberOfPasswords / passwordAttackRate;
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

float calculatePasswordLength(unsigned char time)
{
    unsigned short int timeInSeconds;
    if (strcmp(timeUnit, "Days") == 0) {
        timeInSeconds = time * DAYS;
    } else if (strcmp(timeUnit, "Weeks") == 0) {
        timeInSeconds = time * WEEKS;
    } else if (strcmp(timeUnit, "Months") == 0) {
        timeInSeconds = time * MONTHS;
    } else {
        timeInSeconds = time * YEARS;
    }
    unsigned long long int numberOfPasswords;
    numberOfPasswords = timeInSeconds * passwordAttackRate;
    return (float) log(numberOfPasswords) / log(numberOfCharacters);
}

void setPasswordAttackRate(void)
{
    int attackRate;
    printf("\nEnter an attack rate (passwords/second): ");
    scanf("%d", &attackRate);
    while (false == isValidPasswordAttackRate(attackRate)) {
        fflush(stdin);
        printf("\nAttack rate must be positive integer.\n\nEnter an attack rate "
                "(passwords/second): ");
        scanf("%d", &attackRate);
    }
    passwordAttackRate = attackRate;
}

bool isValidPasswordAttackRate(int rate)
{
    if (rate < 1) {
        return false;
    }
    return true;
}

void setPasswordLength(void)
{
    short int length;
    length = getPasswordLengthInput();
    while (false == isValidPasswordLength(length)) {
        fflush(stdin);
        printf("\nEntered length not between 1 and 10 inclusive\n");
        length = getPasswordLengthInput();
    }
    passwordLength = length;
}

short int getPasswordLengthInput(void)
{
    printf("\nEnter a password length between 1 to 10 inclusive: ");
    short int input;
    scanf("%hi", &input);
    printf("\nInput in get password: %hi\n", input);
    return input;
}

bool isValidPasswordLength(short int input)
{
    if ((input < 1) || (input > 10)) {
        return false;
    }
    return true;
}

void setNumberOfCharacters(void)
{
    short int input;
    input = getNumberOfCharactersInput();
    while (false == isValidNumberOfCharactersInput(input)) {
        fflush(stdin);
        printf("\nNot a menu option\n");
        input = getNumberOfCharactersInput();
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

short int getNumberOfCharactersInput(void)
{
    printf("\n1. Numeric\n2. Lower/Upper Case\n3. Numeric + Lower/Upper Case\n"
            "4. Numeric + Lower/Upper Case + Symbols\n0. Back\n\n");
    short int input;
    printf("Enter a menu option: ");
    scanf("%hi", &input);
    return input;
}

bool isValidNumberOfCharactersInput(short int input)
{
    if ((input < 0) || (input > 4)) {
        return false;
    }
    return true;
}

void setTimeUnit(void)
{
    short int input;
    input = getTimeUnitInput();
    while (false == isValidTimeUnitInput(input)) {
        fflush(stdin);
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

short int getTimeUnitInput(void)
{
    printf("\n1. Days\n2. Weeks\n3. Months\n4. Years\n0. Back\n\n");
    short int input;
    printf("Enter a menu option: ");
    scanf("%hi", &input);
    return input;
}

bool isValidTimeUnitInput(short int input)
{
    if ((input < 0) || (input > 4)) {
        return false;
    }
    return true;
}

void mainMenu(void)
{
    short int input;
    input = getMainMenuInput();
    while (1) {
        while (false == isValidMainMenuInput(input)) {
            fflush(stdin);
            printf("\nNot a menu option\n");
            printf("\nInput in main menu: %hi\n", input);
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

void timeAttackMenu(void)
{
    short int input, backFlag = false;
    float result;
    while (backFlag == false) {
        input = getTimeAttackMenuInput();
        while (false == isValidTimeAttackMenuInput(input)) {
            fflush(stdin);
            printf("\nNot a menu option\n");
            input = getTimeAttackMenuInput();
        }
        switch (input) {
        case 1:
            printf("\nThis is the number of passwords: %llu\n", calculateNumberOfPasswords()); // <-- Tmp
            result = calculatePasswordCrackTime(calculateNumberOfPasswords()); // result working?
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

void passwordLengthMenu(void)
{
    short int input, timeInput, backFlag = false;
    float result;
    while (backFlag == false) {
        input = getPasswordLengthMenuInput();
        while (false == isValidPasswordLengthMenuInput(input)) {
            fflush(stdin);
            printf("\nNot a menu option\n");
            input = getPasswordLengthMenuInput();
        }
        switch (input) {
        case 1: // WIP, While loop maybe give back option and error check
            timeInput = getTimeInput();
            while (timeInput < 0) {
                fflush(stdin);
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

short int getTimeInput(void)
{
    short int input;
    printf("\nEnter an amount of time in %s: ", timeUnit);
    scanf("%hi", &input);
    return input;
}

short int getTimeAttackMenuInput(void)
{
    printTimeAttackMenu();
    short int input;
    printf("Enter a menu option: ");
    scanf("%hi", &input);
    return input;
}

short int getPasswordLengthMenuInput(void)
{
    printPasswordLengthMenu();
    short int input;
    printf("Enter a menu option: ");
    scanf("%hi", &input);
    return input;
}