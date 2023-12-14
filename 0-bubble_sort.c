#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * @array: array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j;
	int tmp;

	if (!array)
		return;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
