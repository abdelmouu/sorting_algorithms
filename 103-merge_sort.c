#include "sort.h"
#include <stdio.h>
/**
 * print_data - print data
 * @msg: message
 * @a: array
 * @from: start
 * @to: end
 * Return:nothing
 */
void print_data(char *msg, int *a, int from, int to)
{
	char *brid;
	int i;

	printf("[%s]: ", msg);
	brid = "";

	for (i = from; i <= to; i++)
	{
		printf("%s%d", brid, a[i]);
		brid = ", ";
	}
	printf("\n");
}

/**
 * merge - Auxiliar function to merge sort algorithm
 * @a: array
 * @low: low
 * @middle: mid
 * @high: high
 * @buff: buffer
 * Return: nothing
 */
void merge(int *a, int low, int middle, int high, int *buff)
{
	int lo, lm, i;

	lo = i = low;
	lm = middle + 1;

	printf("Merging...\n");
	print_data("left", a, low, middle);
	print_data("right", a, middle + 1, high);

	while (lo <= middle && lm <= high)
	{
		if (a[lo] < a[lm])
			buff[i++] = a[lo++];
		else
			buff[i++] = a[lm++];
	}

	while (lo <= middle)
		buff[i++] = a[lo++];

	while (lm <= high)
		buff[i++] = a[lm++];

	for (i = low; i <= high; i++)
		a[i] = buff[i];

	print_data("Done", a, low, high);
}
/**
 * msort -Auxiliar function for merge sort algorithm
 * @array: array
 * @low: low
 * @high: high
 * @buffer: buffer
 * Return: nothing
 */
void msort(int *array, int low, int high, int *buffer)
{
	int mid;

	if (low < high)
	{
		mid = (low + high - 1) / 2;
		msort(array, low, mid, buffer);
		msort(array, mid + 1, high, buffer);
		merge(array, low, mid, high, buffer);
	}
}
/**
 * merge_sort -Sorts an arrayof integers
 * in ascending order using the
 * Merge sort algorithm
 * @array: array
 * @size: size
 * Return: no return
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	msort(array, 0, size - 1, buffer);
	free(buffer);
}
