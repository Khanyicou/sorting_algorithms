#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array using the counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: Void.
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i;
	int *counter = NULL, k = 0, j;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	/* Allocate memory for the counter array */
	counter = malloc(sizeof(int) * (k + 1));
	if (counter == NULL)
		return;

	/* Initialize counter array to zero */
	for (j = 0; j <= k; j++)
		counter[j] = 0;

	/* Count occurrences of each element in the array */
	for (i = 0; i < size; i++)
		counter[array[i]] += 1;

	/* Update counter array to store cumulative frequencies */
	for (j = 1; j <= k; j++)
	{
		counter[j] += counter[j - 1];
		printf("%d, ", counter[j - 1]);
	}
	printf("%d\n", counter[k]);

	/* Rearrange elements based on the counter array */
	for (i = size - 1; i > 0; i--)
	{
		j = counter[array[i]] - 1;
		if (i != (size_t)j)
		{
			k = array[i];
			array[i] = array[j];
			array[j] = k;
		}
	}

	/* Print the sorted array */
	print_array(array, size);

	/* Free allocated memory */
	free(counter);
}

