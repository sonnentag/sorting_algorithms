#include "sort.h"
/**
* counting_sort - function
* @array: array to sort
* @size: size of array tosort
*
* Description: function to sort array using counting sort algo
* Retrun: Nothing
*/
void counting_sort(int *array, size_t size)
{
	size_t k;
	int *count_array;

	if (array == NULL || size < 2)
		return;
	for (k = 0; k < size; k++)
	{
		if (array[0] < array[k])
			array[0] = array[k];
	}
	count_array = malloc(sizeof(k + 1));
	if (count_array == NULL)
		return;
}
