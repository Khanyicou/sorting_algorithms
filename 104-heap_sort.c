#include "sort.h"

/**
 * swap_root - Swaps the root nodes of a heap.
 * @array: The heap to be sorted.
 * @root: The root index of the heap.
 * @hi: The higher index.
 * @size: The size of the array.
 *
 */
void swap_root(int *array, size_t root, size_t hi, size_t size)
{
	size_t lo, mi, tmp;
	int aux;

	while ((lo = (2 * root + 1)) <= hi)
	{
		tmp = root;
		mi = lo + 1;
		if (array[tmp] < array[lo])
			tmp = lo;
		if (mi <= hi && array[tmp] < array[mi])
			tmp = mi;
		if (tmp == root)
			return;
		aux = array[root];
		array[root] = array[tmp];
		array[tmp] = aux;
		print_array(array, size);
		root = tmp;
	}
}

/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t hi, gap;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/* Build a max heap */
	for (gap = (size - 2) / 2; gap != (size_t)-1; gap--)
		swap_root(array, gap, size - 1, size);

	hi = size - 1;
	/* Extract elements from the heap */
	while (hi > 0)
	{
		tmp = array[hi];
		array[hi] = array[0];
		array[0] = tmp;
		print_array(array, size);
		hi--;
		swap_root(array, 0, hi, size);
	}
}

