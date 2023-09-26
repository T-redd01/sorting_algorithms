#include "sort.h"

void rec_quick_sort(int *arr, size_t l, size_t h, size_t size)
{
	int tmp;
	size_t i, j = l - 1;

	printf("l: %lu, h: %lu\n\n", l, h);

	if (l >= h)
		return;

	for (i = l; i < h - 1; i++)
	{
		if (arr[i] <= arr[h - 1])
		{
			j++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			/*print_array(arr, size);*/
		}
	}
	i++;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
	/*rec_quick_sort(arr, l, j - 1, size);*/
	rec_quick_sort(arr, j + 1, h, size);
}

/*
 * quick_sort - implement quick sort algo lomuto part scheme (last el is pivot)
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j = 0 - 1;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] <= array[size - 1])
		{
			j++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			/*print_array(array, size);*/
		}
	}
	j++;
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	/*print_array(array, size);*/
	/*rec_quick_sort(array, 0, j - 1, size);*/
	rec_quick_sort(array, j + 1, size, size);
}
