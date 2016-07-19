/* Headers */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// # include <stdio_ext.h>
// # include "PST.h"

/* Macros */
#define TRUE 0
#define FALSE 1
#define DAYS 86400
#define WEEKS 4492800
#define MONTHS 2678400
#define YEARS 31536000

/* Prototypes */
void mainMenu(void);
void initialize(void);
void printTimeAttackMenu(void);
void printPasswordLengthMenu(void);
void setPasswordAttackRate(unsigned int);
void setPasswordLength(unsigned short int);
void setNumberOfCharacters(unsigned short int);
void setTimeUnit(char *);
char isValidMainMenuInput(unsigned short int);
char isValidTimeMenuInput(unsigned short int);
char isValidPasswordLengthMenuInput(unsigned short int);
float calculatePasswordCrackTime(unsigned long long int);
unsigned short int getMenuInput(void);
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
    unsigned short int menuOption;
    menuOption = getMenuInput();
    while (menuOption != 999) {
        switch (menuOption) {
        case 1:
            printTimeAttackMenu();
            menuOption = getMenuInput();
            break;
        case 2:
            printPasswordLengthMenu();
            menuOption = getMenuInput();
            break;
        case 0:
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("\nNot a menu option\n");
            menuOption = getMenuInput();
            break;
        }
    }
    return 0;
}

void printMainMenu(void)
{
    printf("\n1. Calculate Time Until Successful brute force attack\n2. "
            "Calculate Password Length\n0. Quit\n\n");
}

void printTimeAttackMenu(void)
{
    printf("\n1. Calculate Time\n2. Set Password Length\n3. Set Amount of "
            "Password Characters\n4. Set Result Unit\n5. Set Password Attack "
            "Rate\n0. Back\n\n");
}

void printPasswordLengthMenu(void)
{
    printf("\n1. Calculate Password Length\n2. Set Amount of Password Characters"
            "\n3. Set Time Unit\n4. Set Password Attack Rate\n0. Back\n\n");
}

void initialize(void)
{
    printf("VERSION[]\nLICENSE\nABSOLUTELY NO WARRANTY\nAUTHOR PERSONAL USE\n");
}

unsigned short int getMenuInput(void)
{
    printMainMenu();
    int index;
    printf("Enter a menu option: ");
    scanf("%d", &index);
    return index;
}

char isValidMainMenuInput(unsigned short int input)
{
    if ((input < 0) || (input > 2)) {
        return FALSE;
    } else {
        return TRUE;
    }
}

char isValidTimeMenuInput(unsigned short int input)
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
    return (float) numberOfPasswords / passwordAttackRate;
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

void setPasswordAttackRate(unsigned int attackRate)
{
    passwordAttackRate = attackRate;
}

void setPasswordLength(unsigned short int length)
{
    passwordLength = length;
}

void setNumberOfCharacters(unsigned short int num)
{
    numberOfCharacters = num;
}

void setTimeUnit(char * unit)
{
    timeUnit = unit;
}