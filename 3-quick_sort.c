#include "sort.h"
/**
 * swap - swaps 2 int values
 * @array: the intger array to sort
 * @size: the size of the array
 * @a: address of first value
 * @b: address of second values
 *
 * Return: void
*/
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}
/**
 * lomuto_partition - partition thr array
 * @array: the intger array to sort
 * @size: array size
 * @lo: the low index of the sort range
 * @hi: the high index of the sort range
 *
 * Return: size_t
*/
size_t lomuto_partition(int array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivot = arry[hi];

	for (i = j = lo; j < hi; j++)
		if (arry[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[hi]);

	return (i);
}
/**
 *
 *
 *
 *
*/
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}
/**
 *
 *
 *
 *
*/void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
