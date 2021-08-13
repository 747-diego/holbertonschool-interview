#include "regex.h"

/**
 * regex_match - checks for matches and patterns in strings
 * @str: string to scan
 * @pattern: expression
 * Return: 1 || 0
 */
int regex_match(char const *str, char const *pattern)
{
	char zeroChar = '\0';
	int indexMatch = 0;
	char period = '.';

	if (*str == zeroChar && *pattern == zeroChar)
	{
		return (1);
	}

	if ((*pattern == period || *str == *pattern) && *(pattern + 1) != '*')
	{
		return (regex_match(str += 1, pattern += 1));
	}

	if (*(pattern + 1) == '*')
	{
		if (*str != zeroChar && (*pattern == period || *str == *pattern))
		{
			indexMatch = regex_match(str += 1, pattern);
		}
		return (regex_match(str, pattern + 2) || indexMatch);
	}

	return (0);
}
