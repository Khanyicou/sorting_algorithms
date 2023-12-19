#include "sort.h"

/**
 * quick_sort - function that sort an array of integers
 * in ascending order using quick sort algorithm
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
qs(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @first: 1st position
 * @last: last position
 * @size: array size
 * Return: int
 */
int partition(int *array, int first, int last, size_t size)
{
	int i = first - 1, aux, j;

	for (j = first; j <= last - 1; j++)
	{
		if (array[j] < array[last])
		{
			i++;
			if (i < j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[last])
	{
		aux = array[i + 1];
		array[i + 1] = array[last];
		array[last] = aux;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs - sorts an array of integers recursively
 * @array: array
 * @first: first position
 * @last: last position
 * @size: size of array
 */
void qs(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		qs(array, first, pivot - 1, size);
		qs(array, pivot + 1, last, size);
	}
}
