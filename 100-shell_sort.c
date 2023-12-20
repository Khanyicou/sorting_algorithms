#include "sort.h"

/**
 * shell_sort - Sorts an array using the shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i, j, gap;
	int aux;

	if (array == NULL || size < 2)
		return;

	/* Initialize the gap */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	/* Start sorting with decreasing gaps */
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		/* Perform insertion sort with the current gap */
		for (i = gap; i < size; i++)
		{
			aux = array[i];

			/* Shift elements to make space for insertion */
			for (j = i; j >= gap && array[j - gap] > aux; j -= gap)
			{
				if (array[j] != array[j - gap])
					array[j] = array[j - gap];
			}

			/* Insert the element in the correct position */
			if (array[j] != aux)
array[j] = aux;
}

/* Print the current state of the array */
print_array(array, size);
}
}

