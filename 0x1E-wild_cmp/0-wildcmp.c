#include "holberton.h"


/**
 * wildcmp - wild compare
 * @s1: string
 * @s2: special character
 * Return: identical string
 */
int wildcmp(char *s1, char *s2)
{
	char specialCharacter = '*';
	char null = '\0';
	char *stringOne = s1;
	char *stringTwo = s2;
	int compare = 0;

	if (*stringOne == null && *stringTwo == null)
		return (1);
	if (*stringOne == *stringTwo)
	{
		compare = wildcmp(stringOne + 1, stringTwo + 1);
		return (compare);
	}
	if (*stringTwo == specialCharacter)
	{
		if (*stringOne != null)
		{
			compare = wildcmp(stringOne + 1, stringTwo);
		}
		return (wildcmp(stringOne, stringTwo + 1) || compare);
	}
	return (0);
}
