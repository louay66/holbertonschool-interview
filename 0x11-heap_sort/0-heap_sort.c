#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap - swap tow int var.
 * @a: first int.
 * @b: secend int
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * heapify - Implementation heapify algo.
 * @arr: ponter to a given array.
 * @N: element of an array.
 * @i: index.
 * @S: unedited size of original array.
 */
void heapify(int *arr, size_t N, int i, size_t S)
{

	int largest, left, right, size;

	size = N;
	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < size && arr[left] > arr[largest])

		largest = left;
	if (right < size && arr[right] > arr[largest])

		largest = right;
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, S);
		heapify(arr, size, largest, S);
	}
}

/**
 * heap_sort - Implementation heap_sort algo.
 * @array: ponter to a given array.
 * @size: number element of an array.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (size == 0 || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
