#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list using insertion method
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *pointer, *sorted, *temp;

	if (!list)
		return;
	current = *list;
	temp = current;

	while (current)
	{
		while (current->prev)
		{
			pointer = current->prev;
			sorted = pointer;

			if (pointer->n >= current->n)
				swap(pointer, current, list);

			current = sorted;
		}
		current = temp->next;
		temp = current;
	}
}

/**
 * swap - swap nodes in doubly linked list
 * @pointer: node to swap with current
 * @current: node to swap with pointer
 * @list: list to relink if first element & we'll print from here as well.
 */
void swap(listint_t *pointer, listint_t *current, listint_t **list)
{
	listint_t *temp;

	if (pointer->prev)
	{
		temp = pointer->prev;
		temp->next = current;
		current->prev = temp;
		pointer->prev = current;
		pointer->next = current->next;
		current->next = pointer;
	}
	else
	{
		pointer->next = current->next;
		temp = pointer;
		temp->prev = current;
		current->prev = NULL;
		current->next = temp;
		temp = current;
		*list = temp;
	}

	if (pointer->next)
		pointer->next->prev = pointer;

	print_list(*list);
}
