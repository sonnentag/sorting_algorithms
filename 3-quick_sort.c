#include "sort.h"

/**
 * quick_sort - sort array using quicksort method
 * @array: provoded array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int l, r; /* left, right */

	l = 0;

	if (size)
		r = size - 1;
	if (array)
		qsort_recursion(array, l, r, size);
	print_array(array, size);
}


/**
 * qsort_recursion - recursive quicksort
 * @array: provided array
 * @l: left, less than pivot
 * @r: right, greater than pivot
 * @size: size of array
 */
void qsort_recursion(int *array, int l, int r, size_t size)
{
	int pivot;

	if (l < r)
	{
		pivot = part(array, l, r, size);
		qsort_recursion(array, l, pivot - 1, size);
		qsort_recursion(array, pivot + 1, r, size);
	}
}

/**
 * part - partition unsorted array
 * @array: provided array
 * @l: left, less than pivot
 * @r: right, greater than pivot
 * @size: size of array
 * Return: index of pivot
 */
int part(int *array, int l, int r, size_t size)
{
	int x = l, p = array[r], s = l - 1, tmp;

	while (x <= r - 1)
	{
		if (array[x] <= p)
		{
			s++;
			tmp = array[s];
			array[s] = array[x];
			array[x] = tmp;
			print_array(array, size);
		}
		x++;
	}
	s++;
	tmp = array[s];
	array[s] = array[x];
	array[x] = tmp;
	print_array(array, size);

	return (s);
}
