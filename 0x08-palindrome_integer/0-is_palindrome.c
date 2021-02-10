#include "palindrome.h"


/**
 * PalindromeCheck - check if int is palidrome or not
 * @numcheck: checking if the number is pali
 * @head: begining of list
 * @backend: back of list
 * Return: 1 or 0
 */
int PalindromeCheck(unsigned long numcheck, unsigned long head, unsigned long backend)
{
	if ((numcheck / head % 10 == numcheck / backend % 10) && (head < backend))
    {
		return (PalindromeCheck(numcheck, head * 10, backend / 10));
    }
	else if (numcheck / head % 10 != numcheck / backend % 10)
    {
		return (0);
    }
	else
    {
		return (1);
    }
}

/**
 * BackendNumber - number to check if its palindrome
 * @backendNumber: number thas being checked
 * Return: number
 */
unsigned long int BackendNumber(unsigned long backendNumber)
{
	unsigned long index;

	for (index = 1; backendNumber / 10; index *= 10)
    {
		backendNumber /= 10;
    }
    return (index);
}


/**
 * is_palindrome - function that checks whether an integer is a palindrome
 * @n: is the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	return (PalindromeCheck(n, 1, BackendNumber(n)));
}
