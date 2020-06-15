#include "sort.h"
/**
* bubble_sort - function
* @array : array to sort
* @size: size of array
*
* Description: function to sort an array using bubble sort method
* Return: Nothing
*/
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t index, start;

	if (array == NULL || size < 2)/*if array is empty or size too short to sort*/
		return;

	for (start = 0; start < size - 1; start++) /*shortening list as we swap*/
	{
		for (index = 0; index < size - start - 1; index++) /*move through array*/
		{
			if (array[index] > array[index + 1]) /*if current place is > next place*/
			{/*swap*/
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
