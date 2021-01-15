#include "sandpiles.h"

/**
 * printGrid - displays two sandpiles
 * @grid: individual stable grid 
 */
void printGrid(int grid[3][3])
{
	int i = 0;
    int j = 0;

	printf("=\n");

	while (i < 3)
	{
		while (j < 3)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
            j++;
		}
		printf("\n");
        i++;
	}
}

/**
 * sandpiles_sum - a function that computes the sum of two sandpiles
 * @grid1: indvidual stable grids
 * @grid2: indvidual stable grids
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
    int j = 0; 
    int left, right, up, down, uneven = 0;

	for (i = 0; i < 3; i++)
		while (j < 3)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
            j++;
		}

    i = 0;
    j = 0;

	for (i = 0; i < 3; i++)
	{
        while (j < 3)
        {
			if (grid1[i][j] > 3)
			{
				if (!uneven)
					printGrid(grid1);
				uneven = 1;
				grid1[i][j] -=  4;
				left = j - 1;
				right = j + 1;
				up = i - 1;
				down = i + 1;
				if (left > -1)
					grid2[i][left] += 1;
				if (right < 3)
					grid2[i][right] += 1;
				if (up > -1)
					grid2[up][j] += 1;
				if (down < 3)
					grid2[down][j] += 1;
			}
            j++;
        }
    }        
	if (uneven)
		sandpiles_sum(grid1, grid2);
}
