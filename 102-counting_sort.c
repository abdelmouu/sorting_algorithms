#include "sort.h"
/**
 * counting_sort -Sorts an arrayof integers asc
 * Counting sort algorithm
 * @array: array
 * @size: size
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int n, i;
	int *bufz, *a;

	if (size < 2)
		return;

	for (n = i = 0; i < (int)size; i++)
		if (array[i] > n)
			n = array[i];

	bufz = malloc(sizeof(int) * (n + 1));
	if (!bufz)
		return;

	for (i = 0; i <= n; i++)
		bufz[i] = 0;
	for (i = 0; i < (int)size; i++)
		bufz[array[i]] += 1;
	for (i = 1; i <= n; i++)
		bufz[i] += bufz[i - 1];

	print_array(bufz, (n + 1));
	a = malloc(sizeof(int) * (size + 1));

	if (!a)
	{
		free(bufz);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		a[bufz[array[i]] - 1] = array[i];
		bufz[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = a[i];

	free(bufz);
	free(a);
}
