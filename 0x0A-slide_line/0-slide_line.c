#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"
/**
 * push_zero_left - moves all intger to the left
 * @line: array of int
 * @size: number of items in the array
 */

void push_zero_left(int *line, int size)
{
	{
		int i, tmp;

		for (i = 1; i < size; i++)
		{
			if (line[i] != 0)
			{
				tmp = i;
				while (line[i - 1] == 0 && i > 0)
				{
					line[i - 1] = line[i];
					line[i] = 0;
					--i;
				}
				i = tmp;
			}
		}
	}
}
/**
 * push_zero_right - moves all intger to the right
 * @line: array of int
 * @size: number of items in the array
 */
void push_zero_right(int *line, int size)
{
	int i, tmp;

	for (i = size - 2; i + 1 > 0; i--)
	{
		if (line[i] != 0)
		{
			tmp = i;
			while (line[i + 1] == 0 && i < size - 1)
			{
				line[i + 1] = line[i];
				line[i] = 0;
				++i;
			}
			i = tmp;
		}
	}
}
/**
 * merge_left - merge two same int
 * @array: a pointer to an integer array
 * @size: number of items in the array
 */
void merge_left(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] == array[i + 1])
		{
			array[i + 1] *= 2;
			array[i] = 0;
			++i;
		}
	}
}
/**
 * merge_right - merge two same int
 * @array: a pointer to an integer array
 * @size: number of items in the array
 */
void merge_right(int *array, size_t size)
{
	size_t i;

	for (i = size - 1; i + 1 > 1; i--)
	{
		if (array[i] == array[i - 1])
		{
			array[i - 1] *= 2;
			array[i] = 0;
			--i;
		}
	}
}
/**
 * slide_line - slides and merges an array of int
 * @line: points to an array
 * @size: number of elements in the array.
 * @direction: left or right
 * Return: 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || size < 1)
		return (0);
	switch (direction)
	{
		case SLIDE_LEFT:
			push_zero_left(line, size);
			merge_left(line, size);
			push_zero_left(line, size);
			break;
		case SLIDE_RIGHT:
			push_zero_right(line, size);
			merge_right(line, size);
			push_zero_right(line, size);
	}

	return (1);
}
