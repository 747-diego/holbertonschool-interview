#include "sandpiles.h"


/**
 * displayGrid - shows rows and columns
 * @grid: rows and columns
 */
void displayGrid(int grid[3][3])
{
	int row = 0;
	int column = 0;

	printf("=\n");
	while (row < 3)
	{
		column = 0;
		while (column < 3)
		{
			if (column)
			{
				printf(" ");
			}
			printf("%d", grid[row][column]);
			column++;
		}
		row++;
		printf("\n");
	}
}

/**
 * sandpiles_sum - a function that computes the sum of two sandpiles
 * @grid1: both grid1 and grid2 are individually stable
 * @grid2: both grid1 and grid2 are individually stable
 * Return: nada
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row = 0, column = 0, odd = 0, left, right, up, down;

	while (row < 3)
	{
		column = 0;
		while (column < 3)
		{
			grid1[row][column] += grid2[row][column], grid2[row][column] = 0, column++;
		}
		row++;
	}
	row = 0;
	while (row < 3)
	{
		column = 0;
		while (column < 3)
		{
			if (grid1[row][column] > 3)
			{
				if (!odd)
				{
					displayGrid(grid1);
				}
				odd = 1, grid1[row][column] -=  4;
				left = column - 1, right = column + 1, up = row - 1, down = row + 1;
				if (left > -1)
					grid2[row][left] += 1;
				if (right < 3)
					grid2[row][right] += 1;
				if (up > -1)
					grid2[up][column] += 1;
				if (down < 3)
					grid2[down][column] += 1;
			}
			column++;
		}
		row++;
	}
	if (odd)
		sandpiles_sum(grid1, grid2);
}
