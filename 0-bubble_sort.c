#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in
 * ascending order using Bubble Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int x;
	int swp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swp = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
				swp = 1;

				print_array(array, size);
			}
		}
		if (swp == 0)
			break;
	}
}
