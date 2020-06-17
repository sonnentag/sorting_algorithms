#include "sort.h"
/**
* heap_sort - function
* @array: array to sort
* @size: size of array to sort
*
* Description: func to sort an array using heapsort siftdown algo
* Return: Nothing
*/
void heap_sort(int *array, size_t size)
{
	unsigned int *end_ptr, temp_swap;

	/*begin_ptr = array[0];*/

	if (array == NULL || size < 2)
		return;
	for (end_ptr = array[size - 1]; end_ptr > 0; end_ptr--)
	{
		temp_swap = array[0];
		array[0] = array[end_ptr];
		array[end_ptr] = temp_swap;
	}

}
