#include "sort.h"

/**
 * create_counter - increment counter by using array element as index
 * @counter: counting array
 * @max: size of counter
 * @array: array to sort
 * @size: size of array
 */
void create_counter(int *counter, int max, int *array, size_t size)
{
	size_t i, tmp = 0;

	for (i = 0; i < (size_t)max; i++)
		counter[i] = 0;

	for (i = 0; i < size; i++)
		counter[(array[i])] += 1;

	for (i = 0; i < (size_t)max; i++)
	{
		if (counter[i])
		{
			counter[i] += tmp;
			tmp = counter[i];
		}
	}
	print_array(counter, max);
}

/**
 * counting_sort - implement counting sirt algorithm
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j, tmp = 0;
	int max, *counter;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	counter = malloc((max - 1) * sizeof(int *));
	if (!counter)
		return;

	create_counter(counter, max + 1, array, size);
	for (i = 0; i < (size_t)(max + 1); i++)
	{
		if (counter[i])
		{
			j = counter[i];
			while (counter[i] - tmp)
			{
				array[(counter[i] - 1)] = i;
				counter[i] -= 1;
			}
			tmp = j;
		}
	}
	free(counter);
}
