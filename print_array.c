#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Intiger Prints an array
 *
 * @array: To be printed array
 * @size: The size of arrayof element
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
