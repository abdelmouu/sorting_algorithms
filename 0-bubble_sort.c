#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending
 * order using the Bubble sort algorithm.
 * @array: a pointer to the array of integers that
 * needs to be sorted.
 * @size: the number of elements in the array.
 */

void bubble_sort(int *array, size_t size)
{

	size_t i, index, tmp = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
		for (index = 0; index < size; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
			tmp = array[index];
			array[index] = array[index + 1];
			array[index + 1] = tmp;
			print_array(array, size);
			}
		}
}
