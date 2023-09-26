#include "sort.h"

/**
 * selection_sort - implement selection sort
 * @array: array to sort
 * @size: size of int array
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, min_idx;

	if (size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;
		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
