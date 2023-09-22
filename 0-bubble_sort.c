#include "sort.h"

/**
 * bubble_sort - implement bubble sort algorithm
 * @array: array holding ints
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j;

	if (size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (j == size - 1)
				break;
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array((const int *)array, size);
			}
		}
	}
}
