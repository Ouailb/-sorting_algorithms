#include "sort.h"

/**
 * Items_swap - Swaps two .
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 */
void Items_swap(int *array, size_t l, size_t r)
{
	int index;

	if (array != NULL)
	{
		index = array[l];
		array[l] = array[r];
		array[r] = index;
	}
}

/**
 * implement the Lomuto - Sorts a sub array
 * @array: The array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 */
void implement_Lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t x, i;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	x = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (x != i)
			{
				Items_swap(array, x, i);
				print_array(array, size);
			}
			x++;
		}
	}
	if (x != high)
	{
		Items_swap(array, x, high);
		print_array(array, size);
	}
	if (x - low > 1)
		implement_Lomuto(array, low, x - 1, size);
	if (high - x > 1)
		implement_Lomuto(array, x + 1, high, size);
}

/**
 * quick_sort - Sorts an array
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		implement_Lomuto(array, 0, size - 1, size);
	}
}
