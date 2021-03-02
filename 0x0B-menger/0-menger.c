#include "menger.h"

/**
 * printHASH - prints a hashtag when necessary
 * @row: current row
 * @column: curent column
 * @num: number used for looping
 * Return: hastag or space
 */
char printHASH(int row, int column, int num)
{
	if (num == 0)
	{
		return('#');
	}
	if ((row % (num * 3)) / num == 1)
	{
		if ((column % (num * 3)) / num == 1)
		{
			return(' ');
		}
	}
	return(printHASH(row, column, num / 3));
}


/**
 * menger - a function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int row = 0;
	int column = 0;
	int levelSize = pow(3, level);

	while (row < levelSize)
	{
		column = 0;
		while (column < levelSize)
		{
			putchar(printHASH(row, column, levelSize / 3));
			column++;
		}
		putchar('\n');
		row++;
	}
}
