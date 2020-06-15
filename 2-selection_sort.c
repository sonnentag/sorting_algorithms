#include "sort.h"
/**
* selection_sort - function
* @array: array to sort
* @size: size of array to sort
*
* Description: Function to sort using selection sort algorithm
* Return: 0, Nothing
*/
void selection_sort(int *array, size_t size)
{
	unsigned int first_value, second_value, temp_swap, hold_value;

	for (first_value = 0; first_value < size - 1; first_value++)
	{
		hold_value = first_value;
		for (second_value = first_value + 1; second_value < size; second_value++)
		{
			if (array[hold_value] > array[second_value])
			{
				hold_value = second_value;
				/*print_array(array, size);*/
			}
		}
		if (hold_value != first_value)
		{
			temp_swap = array[first_value];
			array[first_value] = array[hold_value];
			array[hold_value] = temp_swap;
			print_array(array, size);
		}
	}
}
