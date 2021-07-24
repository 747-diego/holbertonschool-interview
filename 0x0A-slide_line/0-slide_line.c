#include "slide_line.h"

/**
 * shiftLeft - pushes line left
 * @line: line of numbers
 * @size: how many numbers there are in total
 */
void shiftLeft(int *line, size_t size)
{
	size_t numOne = 0;
	size_t numTwo;


	for (numOne = 0; numOne < size; numOne++)
	{
		for (numTwo = numOne + 1; numTwo < size; numTwo++)
		{
			if ( line[numTwo] != 0 && line[numOne] == 0 )
			{
				line[numOne] = line[numTwo];
				line[numTwo] = 0;
				numOne -= 1;
				continue;
			}
			if ( line[numOne] != 0 && line[numOne] == line[numTwo] )
			{
				line[numOne] = line[numOne] * 2;
				line[numTwo] = 0;
				continue;
			}
			else if ( line[numOne++] == 0 && line[numTwo] != 0 )
			{
				line[numOne++] = line[numTwo];
				line[numTwo] = 0;
				continue;
			}
			/* numTwo++; */
		}
		/* numOne++;*/
	}
}

/**
 * shiftRight - pushes line left
 * @line: line of numbers
 * @size: how many numbers there are in total
 */
void shiftRight(int *line, size_t size)
{
	size_t numOne = 1;
	size_t numTwo;

	
	while ( numOne <= size)
	{
		numTwo = numOne + 1;

		while ( numTwo <= size )
		{
			if (line[size - numTwo] != 0 && line[size - numOne] == 0)
			{
				line[size - numOne] = line[size - numTwo];
				line[size - numTwo] = 0;
				numOne--;
				continue;
			}
			if (line[size - numOne] != 0 && line[size - numOne] == line[size - numTwo])
			{
				line[size - numOne] = line[size - numOne] * 2;
				line[size - numTwo] = 0;
				continue;
			}
			else if ( line[size - (numOne++)] == 0 && line[size - numTwo] != 0 )
			{
				line[size - (numOne + 1)] = line[size - numTwo];
				line[size - numTwo] = 0;
				continue;
			}
			numTwo++;
		}
		numOne++;
	}
}


/**
 * slide_line - a function that slides and merges an array of integers
 * @line: points to an array of integers
 * @size: elements, that must be slided & merged to the direction represented
 * @direction: can be either: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || !size)
	{
		return (0);
	}
	
	if (direction == 76)
	{
		shiftLeft(line, size);
	}
	
	else if (direction == 82)
	{
		shiftRight(line, size);
	}
	
	else
	{
		return (0);
	}
	return (1);
}
