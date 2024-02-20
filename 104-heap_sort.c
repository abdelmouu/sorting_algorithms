#include "sort.h"
#include <stdio.h>
/**
 * swap_nums - swaps numbers
 *
 * @arr: input array
 * @a: first index
 * @b: second index
 * Return: Nothing
 */
void swap_nums(int *arr, int a, int b)
{
	arr[a] = arr[a] + arr[b];
	arr[b] = arr[a] - arr[b];
	arr[a] = arr[a] - arr[b];
}

/**
 * recursion_heap - recursion that builds the max heap tree
 *
 * @arr: input array
 * @i: id
 * @size: size
 * @limit: limit
 * Return: no return
 */
void recursion_heap(int *arr, int i, size_t size, int limit)
{
	int greater;
	int j;

	j = i * 2;

	if (j + 2 < limit)
	{
		recursion_heap(arr, j + 1, size, limit);
		recursion_heap(arr, j + 2, size, limit);
	}

	if (j + 1 >= limit)
		return;

	if (j + 2 < limit)
		greater = (arr[j + 1] > arr[j + 2]) ? (j + 1) : (j + 2);
	else
		greater = j + 1;

	if (arr[i] < arr[greater])
	{
		swap_nums(arr, i, greater);
		print_array(arr, size);
		recursion_heap(arr, greater, size, limit);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending
 * order using the Heap sort algorithm
 *
 * @array: input array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t limit;

	if (!array || size == 0)
		return;

	i = 0;
	limit = size;

	while (limit > 1)
	{
		recursion_heap(array, i, size, limit);
		if (array[i] >= array[limit - 1])
		{
			swap_nums(array, i, limit - 1);
			print_array(array, size);
		}
		limit--;
	}
}
