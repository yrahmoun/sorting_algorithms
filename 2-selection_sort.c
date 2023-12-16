#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t min;
	size_t i = 0;
	size_t j;

	if (!array || size < 2)
		return;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		if (i != min)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
