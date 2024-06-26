#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - sorts an array of integer in ascending order using Bubble sort
 * @array: Array to be sorted
 * @size: Size of array
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;
	bool swapped;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = false;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = true;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
