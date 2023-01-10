#include "sandpiles.h"

/**
 * print_grid1 - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid1(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sum_grid - add grid2 to grid1
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sum_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * is_stable - chech if there is not found number
 * greater than 3 in each cell
 * @grid1: Left 3x3 grid
 * Return: 0 if grid is stable else 1
 */
int is_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{

			if (grid1[i][j] > 3)
			{
				return (1);
			}
		}
	}
	return (0);
}
/**
 * toppling_round - toppling_round
 * @grid1: Left 3x3 grid
 */

void toppling_round(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;

				if (i - 1 >= 0)
					grid1[i - 1][j] += 1;
				if (i + 1 <= 2)
					grid1[i + 1][j] += 1;
				if (j + 1 <= 2)
					grid1[i][j + 1] += 1;
				if (j - 1 >= 0)
					grid1[i][j - 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - sandplis theory
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grid(grid1, grid2);

	while (is_stable(grid1) != 0)
	{
		printf("=\n");
		print_grid1(grid1);
		toppling_round(grid1);
	}
}
