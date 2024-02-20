#include "sort.h"
#include <stdio.h>
/**
 * print_bitonic - prints the array modified by bitonic algorithm
 *
 * @arr: input array
 * @i: first index
 * @limit: last index
 * Return: nothing
 */
void print_bitonic(int *arr, int i, int limit)
{
	char *sep;

	for (sep = ""; i < limit; i++)
	{
		printf("%s%d", sep, arr[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * sort_up - sorts the array in ascd
 *
 * @arr: input array
 * @low: first index
 * @high: last index
 * Return: nothing
 */
void sort_up(int *arr, int low, int high)
{
	int i, j, x;

	for (i = low; i < high; i++)
	{
		x = i;

		for (j = i + 1; j < high; j++)
		{
			if (arr[x] > arr[j])
				x = j;
		}

		if (x != i)
		{
			arr[i] = arr[i] + arr[x];
			arr[x] = arr[i] - arr[x];
			arr[i] = arr[i] - arr[x];
		}
	}
}

/**
 * sort_down - sorts the array in desc
 *
 * @arr: input array
 * @low: first index
 * @high: last index
 * Return: nothing
 */
void sort_down(int *arr, int low, int high)
{
	int i, j, x;

	for (i = low; i < high; i++)
	{
		x = i;

		for (j = i + 1; j < high; j++)
		{
			if (arr[x] < arr[j])
				x = j;
		}

		if (x != i)
		{
			arr[i] = arr[i] + arr[x];
			arr[x] = arr[i] - arr[x];
			arr[i] = arr[i] - arr[x];
		}
	}
}

/**
 * recursion - recursive function that executes the bitonic sort
 *
 * @arr: input array
 * @low: first index
 * @high: last index
 * @bool: UP or DOWN
 * @size: size
 * Return: nothing
 */
void recursion(int *arr, int low, int high, int bool, size_t size)
{
	char *optl;

	if (high - low < 2)
		return;

	optl = (bool == 0) ? "UP" : "DOWN";
	printf("Merging [%d/%ld] (%s):\n", high - low, size, optl);
	print_bitonic(arr, low, high);

	if (high - low == 2)
		return;

	recursion(arr, low, (high + low) / 2, 0, size);
	sort_up(arr, low, (high + low) / 2);
	printf("Result [%d/%ld] (%s):\n", ((high + low) / 2) - low, size, "UP");
	print_bitonic(arr, low, (high + low) / 2);

	recursion(arr, (high + low) / 2, high, 1, size);
	sort_down(arr, (high + low) / 2, high);
	printf("Result [%d/%ld] (%s):\n", high - ((high + low) / 2), size, "DOWN");
	print_bitonic(arr, (high + low) / 2, high);
}

/**
 * bitonic_sort - first function that executes the bitonic_sort
 * @array: input array
 * @size: size of the array
 * Return: no return
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recursion(array, 0, size, 0, size);
	sort_up(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	print_bitonic(array, 0, size);
}
