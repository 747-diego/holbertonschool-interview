#ifndef _MULTIPLICATION_H_
#define _MULTIPLICATION_H_

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* PROTOTYPES */
int _putchar(char c);
int _strlen(char *str);
void print_error(void);
int mul(char *firstNumber, unsigned int numOneSize, char *secondNumber,
		    unsigned int numTwoSize, unsigned int finalProduct);
int checkIfLessThan(int indexOne, char *nodeMem);

#endif
