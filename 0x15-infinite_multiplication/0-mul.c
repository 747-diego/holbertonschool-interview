#include "holberton.h"

/**
 * main - main function to multiply 2 positive numbers
 * @argc: number of arguments passed in
 * @argv: argument value
 * Return: 0 or exit on error
 */
int main(int argc, char *argv[])
{
	unsigned int len1, len2, len3;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		exit(98);
	}

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	len3 = len1 + len2;
	mul(argv[1], len1, argv[2], len2, len3);
	return (0);
}

/**
 * _strlen - returns length of string
 * checks if striong only contains numbers
 * @str: passed in string
 * Return: length of string
 */
int _strlen(char *str)
{
	int i;

	for (i = 0 ; str[i] != '\0' ; ++i)
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "Error\n", 6);
			exit(98);
		}
	return (i);
}

/**
 * checkIfLessThan - checks if idx i < 0
 * @indexOne: idx
 * @nodeMem: allocated memory
 * Return: success
 */
int checkIfLessThan(int indexOne, char *nodeMem)
{
	while (indexOne >= 0 && nodeMem[indexOne] == 0)
		indexOne--;
	if (indexOne < 0)
	{
		write(1, "0\n", 2);
		free(nodeMem);
		return (0);
	}

	for (; indexOne >= 0; indexOne--)
		_putchar(nodeMem[indexOne] + '0');
	_putchar('\n');
	free(nodeMem);
	return (0);
}


/**
 * string_multiply - multiplies 2 strings
 * @str1: First string
 * @len1: Length of first string
 * @str2: Second string
 * @len2: Length of second string
 * @len3: Length to store result string
 * Return: 0 or exit with error
 */

int mul(char *str1, unsigned int len1, char *str2,
		    unsigned int len2, unsigned int len3)
{
	char *nodeMem = malloc(len3 * sizeof(char));
	int product = 0, numOne = 0, numTwo = 0, ParameterOne, ParameterTwo;
	int indexOne = len1 - 1, indexTwo = 0, node = 0;
	int test;

	if (!nodeMem)
	{
		free(nodeMem);
		write(1, "Error\n", 6);
		exit(98);
	}
	while (indexOne >= 0)
	{
		node = 0;
		ParameterOne = str1[indexOne] - '0';
		numOne = 0;
		indexTwo = len2 - 1;
		while (indexTwo >= 0)
		{
			ParameterTwo = str2[indexTwo] - '0';
			product = ParameterOne * ParameterTwo + nodeMem[numOne + numTwo] + node;
			node = product / 10;
			nodeMem[numOne + numTwo] = product % 10;
			numOne++;
			indexTwo--;
		}
		if (node > 0)
			nodeMem[numOne + numTwo] += node;
		numTwo++;
		indexOne--;
	}

	indexOne = len3;
	test = checkIfLessThan(indexOne, nodeMem);
	return (test);
}
