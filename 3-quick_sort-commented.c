#include "sort.h"

/**
 * quick_sort - sort array using quicksort method
 * @array: provoded array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int l, r; /* left, right */

	l = 0; /* left field */

	if (size)
		r = size - 1; /* right field */
	if (array)
		qsort_recursion(array, l, r, size); /* here we go */
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

	if (l < r) /* not sure why this shouldn't be a while, but alas it works */
	{
		pivot = part(array, l, r, size); /* use lomuto method to find field to use as 'partition' */
		qsort_recursion(array, l, pivot - 1, size); /* recurse to sort left of pivot */
		qsort_recursion(array, pivot + 1, r, size); /* recurse again to sort right of pivot */
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
	int x, p, s, tmp, n;

	x = l; /* assign x as temp of left value */
	p = array[r]; /* p is value of right, to be used for comparison on last print */
	s = l - 1; /* s is 1 index less of left, should be sorted */

	while (x <= r - 1) /* while our current left index has not reached the past element before */
	{
		n = array[x]; /* value of left index in current pass used only to compare for print below */
		if (array[x] <= p) /* if left value is not greater than the right value */
		{
			s++; /* move the end of sorted */
			tmp = array[s]; /* and swap */
			array[s] = array[x];
			array[x] = tmp;
		}
		if (array[x] != n) /* if array[x] has changed from n above */
			print_array(array, size); /* print array */
		x++;
	}
	s++; /* now that we're at the end (!(x <= r - 1)) */
	/* this logic is still a little unclear for me, why do we assume these need to be swapped? */
	tmp = array[s]; /* swap rightmost sorted element with current left at end */
	array[s] = array[x];
	array[x] = tmp;
	if (p != array[r]) /* if right element has changed since we entered this function */
		print_array(array, size);

	return (s); /* this is our new sorted / pivot to use for next iteration/recursion */
}
