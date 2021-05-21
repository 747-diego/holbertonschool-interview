#include "holberton.h"

/**
 * main - main code
 * @argc: first argument
 * @argv: second arguments
 * Return: succes
 */
int main(int argc, char *argv[])
{
	char *len, *temporary, *sideMemory, *erorr = "Error";
	int index = 0, jdx = 0;
	int keys = 0, length = 0;
	char *argmuentOne, *argumentTwo;
	int spaceTest = 0;
	char *space, *spaces;
	char zero = '0';
	char zeroTwoPointO = '\0';

	if (argc != 3 || !confirmingArgs(argv[1], argv[2]))
	{
		for (erorr = "Error"; erorr[index]; index++)
			_putchar(erorr[index]);
		_putchar('\n');
		exit(98);
	}
	argmuentOne = argv[1];
	argumentTwo = argv[2];
	while (argmuentOne[index])
	{
		index++;
	}
	while (argumentTwo[jdx])
	{
		jdx++;
	}
	length += jdx + 2;
	if (jdx > index)
	{
		temporary = argmuentOne;
		argmuentOne = argumentTwo;
		argumentTwo = temporary;
	}
	/* allocating space */
	space = malloc(length + 1);
	for (spaceTest = 0; spaceTest < length; spaceTest++)
	{
		space[spaceTest] = zero;
	}
	space[spaceTest] = zeroTwoPointO;
	len = space;
	sideMemory = len;
	len = sumUp(len, argmuentOne);
	free(sideMemory);
	/* allocating more space */
	space = malloc(length + 1);
	for (spaceTest = 0; spaceTest < length; spaceTest++)
	{
		space[spaceTest] = zero;
	}
	space[spaceTest] = zeroTwoPointO;
	spaces = space;
	sideMemory = spaces;
	spaces = sumUp(spaces, argumentTwo);
	free(sideMemory);
	temporary = testTempo(len, spaces, length);
	temporary = test(temporary);
	for (keys = 0; temporary[keys]; keys++)
	{
		_putchar(temporary[keys]);
	}
	_putchar('\n');
	free(len);free(spaces);free(temporary);
	return (0); /* succes */
}

/* ---------------------------------------------------------------------------------------------------------------------------------------- */

/**
 * doubleCheck - checks argumnets
 * @check: checking argument
 */
void doubleCheck(char *check)
{
	char zero = '0';
	int index = 0, num = 0, carry = 0;

	while (check[index])
	{
		index++;
	}
	index--;

	for (; index >= 0; index--)
	{
		num = check[index] - zero;
		;
		num += num + carry;
		if (num >= 10)
		{
			num -= 10;
			carry = 1;
		} 
		else
		{
			carry = 0;
		}
		check[index] = num + zero;

	}
}


/**
 * cases - checks num
 * @numCharacter: number into character
 * Return: succes
 */
int cases(char numCharacter)
{
	switch (numCharacter)
	{
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
			return (1);
		default:
			return (0);
	}
}

/**
 * confirmingArgs - verifys the arguments
 * @firstArgment: the first input
 * @secondArgument: the second input
 * Return: succes
 */
int confirmingArgs(char *firstArgment, char *secondArgument)
{
	char zeroSymbol = '0';
	int index = 0;

	if (checkIfNULL(firstArgment))
	{
		_putchar(zeroSymbol);
		_putchar('\n');
		exit(0);
	}

	if (checkIfNULL(secondArgument))
	{
		_putchar(zeroSymbol);
		_putchar('\n');
		exit(0);
	}
	for (; firstArgment[index]; index++)
	{
		if (!cases(firstArgment[index]))
		{
			return (0);
		}
	}
	for (index = 0; secondArgument[index]; index++)
	{
		if (!cases(secondArgument[index]))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * checkIfNULL - check if zero
 * @string: num character to check
 * Return: sucess
 */
int checkIfNULL(char *string)
{
	int index = 0;
	char zero = '0';

	for (index = 0; string[index]; index++)
		if (string[index] != zero)
		{
			return (0);
		}
	return (1);
}

/**
 * sumUp - sum of dos numeros
 * @numone: num1
 * @numtwo: num2
 * Return: the sum (in string form)
 */
char *sumUp(char *numone, char *numtwo)
{
	int index = 0, indexTwo = 0;
	int keyValue = 0, length = 0;
	int argumentOne = 0, argumentTwo = 0, swap = 0;
	char zero = '0';
	char *tempOne, *tempTwo;

	while (numone[index])
		index++;
	while (numtwo[indexTwo])
		indexTwo++;
	tempOne = malloc(index + 1 + 1);
	for (keyValue = 0; keyValue < index + 1 + 1; keyValue++)
		tempOne[keyValue] = '\0';
	tempTwo = malloc(index + 1 + 1);
	for (keyValue = 0; keyValue < index - indexTwo + 1; keyValue++)
		tempTwo[keyValue] = zero;
	for (; keyValue < index + 1 + 1; keyValue++, length++)
		tempTwo[keyValue] = numtwo[length];
	index--;
	for (; index >= 0; index--)
	{
		keyValue = index + 1;
		argumentTwo = tempTwo[keyValue] - zero;
		argumentOne = numone[index] - zero;
		if (argumentOne + argumentTwo + swap >= 10)
		{
			tempOne[keyValue] = ((argumentOne + argumentTwo + swap) - 10) + zero;
			swap = 1;
		}
		else
		{
			tempOne[keyValue] = (argumentOne + argumentTwo + swap) + zero;
			swap = 0;
		}
	}
	if (swap == 1)
	{
		tempOne[0] = '1';
	}
	else
	{
		tempOne[0] = '0';
	}
	free(tempTwo);
	return (tempOne);
}

/**
 * test - squeeze out zeros on the front
 * @test: the string to squeegee
 * Return: a string without leading zeros
 */
char *test(char *string)
{
	int index = 0, indexTwo = 0, keys = 0;
	char *new;
	char zero = '0';

	while (string[indexTwo] == zero)
	{
		indexTwo++;
	}
	index = indexTwo;
	while (string[index])
	{
		index++;
	}
	new = malloc(index - indexTwo + 1);
	for (keys = indexTwo; keys < index + 1; keys++)
		new[keys - indexTwo] = string[keys];
	free(string);
	return (new);
}

/**
 * testTempo - testing temporary holder
 * @argumentone: first argument
 * @argumentwo: second argument
 * @size: size
 * Return: succes
 */
char *testTempo(char *argumentone, char *argumentwo, int size)
{
	char *acc, *tmp, *space;
	char zero = '0';
	int argOne, num = 0, swap = 0;
	int index = 0, indexTwo = 0, check = 0;


	space = malloc(size + 1);
	for (index = 0; index < size; index++)
	{
		space[index] = zero;
	}
	space[index] = '\0';
	acc = space;
	while (!checkIfNULL(argumentwo))
	{
		while (argumentwo[check])
		{
			check++;
		}
		for (indexTwo = 0; indexTwo < check; indexTwo++)
		{
			num = (argumentwo[indexTwo] - zero) / 2;
			num += (5 * swap);
			swap = (argumentwo[indexTwo] - zero) % 2;
			argumentwo[indexTwo] = num + zero;
		}
		argOne = swap;
		if (argOne == 1)
		{
			tmp = acc;
			acc = sumUp(acc, argumentone);
			free(tmp);
		}
		doubleCheck(argumentone);
	}
	return (acc);
}
