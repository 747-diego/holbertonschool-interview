#include "holberton.h"


/**
 * wildcmp - wild compare
 * @s1: string
 * @s2: special character
 * Return: identical string
 */
int wildcmp(char *s1, char *s2)
{
	char *stringOne = s1;
	char *stringTwo = s2;
	char specialCharacter = '*';
	int compare;


	if (*stringOne == '\0' && *stringTwo == '\0')
		return (1);
	if (*stringOne == *stringTwo)
	{
		compare = wildcmp(stringOne + 1, stringTwo + 1);
		return (compare);
	}
	if (*stringTwo == specialCharacter)
	{
		if (*stringOne != '\0')
		{
			compare = wildcmp(stringOne + 1, stringTwo);
		}
		return (wildcmp(stringOne, stringTwo + 1) || compare);
	}
	return (0);
}
