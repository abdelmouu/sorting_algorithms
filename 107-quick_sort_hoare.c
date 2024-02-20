#include "sort.h"

/**
 * hoare_partition - Hoare partition scheme
 * @array: array
 * @low: lowest
 * @size: size
 * Return: new index at which to start new recursive partition
 */
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int i, j, p, x;

	p = array[high];
	i = low - 1;
	j = high + 1;
	while (true)
	{
		do {
			i++;
		} while (array[i] < p);
		do {
			j--;
		} while (array[j] > p);
		if (i == j)
			return (j - 1);
		else if (i > j)
			return (j);
		x = array[i];
		array[i] = array[j];
		array[j] = x;
		print_array(array, size);
	}
}

/**
 * hoare_quicksort - recursively sorts array of integers
 *
 * @array: array
 * @low: lowest
 * @high: highest
 * @size: size
 */
void hoare_quicksort(int *array, size_t low, size_t high, size_t size)
{
	size_t edge;

	if (low < high)
	{
		edge = hoare_partition(array, low, high, size);
		hoare_quicksort(array, low, edge, size);
		hoare_quicksort(array, edge + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array of integers in ascending order
 *
 * @array: array
 * @size: size
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quicksort(array, 0, size - 1, size);
}
