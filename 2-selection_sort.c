#include "sort.h"
/**
* selection_sort - function
* @array: array to sort
* @size: size of array to sort
*
* Description: Function to sort using selection sort algorithm
* Return: Nothing
*/
void selection_sort(int *array, size_t size)
{
	unsigned int first_value, second_value, temp_swap, hold_value;

	if (array == NULL || size < 2)/*if array is empty or size too short too sort*/
		return;

	for (first_value = 0; first_value < size - 1; first_value++)
	{/*Iterate start thru 1st value of array*/
		hold_value = first_value;/*store first value*/
		for (second_value = first_value + 1; second_value < size; second_value++)
		{/*Iterate start thru value+1 of array*/
			if (array[hold_value] > array[second_value])/*compare first > second value*/
			{
				hold_value = second_value;/*if true, store second value instead of first*/
			}
		}
		if (hold_value != first_value)/*if second value was stored in hold_value*/
		{
			temp_swap = array[first_value];/*swap the hold value with first value*/
			array[first_value] = array[hold_value];
			array[hold_value] = temp_swap;
			print_array(array, size);
		}
	}
}
