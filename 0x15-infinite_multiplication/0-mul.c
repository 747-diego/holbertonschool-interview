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
 * mul - big numbers being MULTIPLIED
 * @firstNumber: big num one
 * @numOneSize: big num one size
 * @secondNumber: big num two
 * @numTwoSize: big num two size
 * @finalProduct: big big num from two nums
 * Return: succes
 */

int mul(char *firstNumber, unsigned int numOneSize, char *secondNumber,
		    unsigned int numTwoSize, unsigned int finalProduct)
{
	char *nodeMem = malloc(finalProduct * sizeof(char));
	int product = 0, numOne = 0, numTwo = 0, ParameterOne, ParameterTwo;
	int indexOne = numOneSize - 1, indexTwo = 0, node = 0;
	int success;

	if (!nodeMem)
	{
		free(nodeMem);
		write(1, "Error\n", 6);
		exit(98);
	}
	while (indexOne >= 0)
	{
		node = 0;
		ParameterOne = firstNumber[indexOne] - '0';
		numOne = 0;
		indexTwo = numTwoSize - 1;
		while (indexTwo >= 0)
		{
			ParameterTwo = secondNumber[indexTwo] - '0';
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

	indexOne = finalProduct;
	success = checkIfLessThan(indexOne, nodeMem);
	return (success);
}
