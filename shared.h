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

#ifndef SHARED_H
#define SHARED_H

#include <stdbool.h>

void purgeBuffer(void);
void setTimeUnit(void);
void setPasswordLength(void);
void setPasswordAttackRate(void);
void setNumberOfCharacters(void);
void checkMalloc(char*);
char *getNumberOfCharactersMenu(void);
char *getTimeMenu(void);
bool isValidBounds(int, short int, int);
short getAMenuInput(char*);
short getPasswordLengthInput(void);
double calculateNumberOfPasswords(void);

#endif /* End SHARED_H */
