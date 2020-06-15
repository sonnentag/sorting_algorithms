#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list using insertion method
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *pointer, *sorted;
	int x;

	if (current->next)
	{
		current = current->next;
		while (current)
		{
			pointer = current;
			sorted = current->prev;
			current = current->next;
			x = 0;
			for ( ; ((sorted) && sorted->n > pointer->n) ; sorted = sorted->prev)
				x++;
			if (x)
			{
				pointer->prev->next = pointer->next;
				if (pointer->next)
					pointer->next->prev = pointer->prev;
				if (!sorted)
				{
					sorted = *list;
					pointer->prev = NULL;
					pointer->next = sorted;
					pointer->next->prev = pointer;
					*list = pointer;
				}
				else
				{
					sorted = sorted->next;
					sorted->prev->next = pointer;
					pointer->prev = sorted->prev;
					sorted->prev = pointer;
					pointer->next = sorted;
				}
			}
			print_list(*list);
		}
	}
}
