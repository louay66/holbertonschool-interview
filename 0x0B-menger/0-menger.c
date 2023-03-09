#include "menger.h"
/**
 * menger - draw a 2D menger sponge squair
 *
 * @level: level of menger sponge
 *
 * Return: void
 */
void menger(int level)
{
	int i, j, k, p, q;

	if (level < 0)
	{
		return;
	}

	int size = pow(3, level);
	char sponge[size][size];

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			sponge[i][j] = '#';
		}
	}
	int center = size / 3;

	for (i = center; i < center * 2; i++)
	{
		for (j = center; j < center * 2; j++)
		{
			sponge[i][j] = ' ';
		}
	}
	for (k = 0; k < level; k++)
	{
		int step = pow(3, k);

		for (i = step; i < size; i += step * 3)
		{
			for (j = step; j < size; j += step * 3)
			{
				for (p = 0; p < step; p++)
				{
					for (q = 0; q < step; q++)
					{
						sponge[i + p][j + q] = ' ';
					}
				}
			}
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%c", sponge[i][j]);
		}
		printf("\n");
	}
}
