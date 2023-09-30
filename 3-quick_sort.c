#include "sort.h"

void rec_quick_sort(int *arr, size_t l, size_t h, size_t size)
{
	int tmp;
	size_t i, j;

	if (!(l < h))
		return;

	j = l - 1;
	for (i = l; i < (h - 1); i++)
	{
		if (arr[i] < arr[h - 1])
		{
			j++;
			if (i != j)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				print_array(arr, size);
			}
		}
	}
	j++;
	if (j != h - 1)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		print_array(arr, size);
	}
	rec_quick_sort(arr, l, j, size);
	rec_quick_sort(arr, j + 1, h, size);
}

/*
 * quick_sort - implement quick sort algo lomuto part scheme (last el is pivot)
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	rec_quick_sort(array, 0, size, size);
}
