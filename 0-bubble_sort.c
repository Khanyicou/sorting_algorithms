#include "sort.h"

/**
 * bubble_sort - sort list with bubble
 * @array: To be printed array
 * @size: size of elemen
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, t = size;
	int holder;

	if (array == NULL)
		return;
	for (t = size; t > 0; t--)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				holder = array[i];
				array[i] = array[i + 1];
				array[i + 1] = holder;
				print_array(array, size);
			}
		}
	}
}
