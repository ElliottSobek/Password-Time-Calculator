/*
 * Password Time Calculator
 * Copyright (C) 2016  Author: Elliott Sobek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/* Guard */
#ifndef PST_H
#define PST_H

/* Macros */
#define DAYS 86400
#define WEEKS 604800
#define MONTHS 2678400 // 31 days
#define YEARS 31536000 // 365 days

/* Globals */
char *timeUnit;
unsigned int passwordAttackRate;
unsigned short passwordLength;
unsigned short numberOfCharacters;

#endif /* End PST_H */
