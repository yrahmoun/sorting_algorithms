#include "sort.h"

/**
 * partition - partition an array into two segments
 * @array: array to sort
 * @start: index of the start of the partition
 * @end: index of the end of the partition
 * @size: size of the array
 * Return: index of the pivot
 */

int partition(int *array, int start, int end, size_t size)
{
	int pivot;
	int i;
	int j = start;
	int tmp;

	pivot = array[end];
	i = start - 1;
	while (j <= end - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i < j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
		j++;
	}
	i++;
	if (array[i] > array[end])
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * sorting - applies the quicksort algorithm
 * @array: array to sort
 * @start: index of the start of the partition
 * @end: index of the end of the partition
 * @size: size of the array
 */

void sorting(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		sorting(array, start, pivot - 1, size);
		sorting(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sorting(array, 0, size - 1, size);
}
