#include "sort.h"

/*
 * quick_sort - implement quick sort algo lomuto part scheme (last el is pivot)
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int tmp;
	size_t i;
	ssize_t j = -1;
	for (i = 0; i < size; i++)
	{
		if (array[i] < array[size - 1])
		{
			j++;
			if (j != i)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
		if (i == size - 1)
		{
			j++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}

}
