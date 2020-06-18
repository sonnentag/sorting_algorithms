#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list using insertion method
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *pointer, *sorted, *temp;

	if ((!list) || (!(*list)->next))
		return;
	current = *list;
	temp = current;

	while (current) /* starting at head of list */
	{
		while (current->prev) /* while we are not on the last node */
		{
			pointer = current->prev; /* assign pointer to previous node */
			sorted = pointer; /* list to the left is sorted */

			if (pointer->n >= current->n) /* if pevious node's value is not less than current value */
				swap(pointer, current, list); /* swap */

			current = sorted; /* set pointer to prev */ 
		}
		current = temp->next; /* move current to next */
		temp = current; /* hold in temp for next pass */
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

	if (pointer->prev) /* if we are not on first node */
	{
		temp = pointer->prev;
		temp->next = current;
		current->prev = temp;
		pointer->prev = current;
		pointer->next = current->next;
		current->next = pointer;
	}
	else /* if we are on first node */
	{
		pointer->next = current->next;
		temp = pointer;
		temp->prev = current;
		current->prev = NULL;
		current->next = temp;
		temp = current;
		*list = temp;
	}

	if (pointer->next) /* if we are not on last node tell next node we are now it's prev */
		pointer->next->prev = pointer;

	print_list(*list);
}
