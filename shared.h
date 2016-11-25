#ifndef SHARED_H
#define SHARED_H

#include <stdbool.h>

void purgeBuffer(void);
void setTimeUnit(void);
void setPasswordLength(void);
void setPasswordAttackRate(void);
void setNumberOfCharacters(void);
void checkMalloc(char *);
char *getNumberOfCharactersMenu(void);
char *getTimeMenu(void);
bool isValidBounds(int, short int, int);
short getAMenuInput(char *);
short getPasswordLengthInput(void);
double calculateNumberOfPasswords(void);

#endif
