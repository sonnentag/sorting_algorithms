#include "sort.h" 

/**
 * insertion_sort_list -
 *
 * Return:
 */
void insertion_sort_list(listint_t **list)
{
	int current[1];
	listint_t **position, *temp;

	position = list;
	(*position) = (*position)->next;
	
	for (; (*position)->next != NULL; *position = (*position)->next) /* while list continues */
	{
		current[0] = (*position)->n;
		temp = create_listint(current, 1);

/* decrement through unsorted list (left of position) until value is greater than position or we reach first node */
		while (((*position)->prev != NULL) && ((*position)->prev->n >= temp->n)) 
		{
			/* make new node of position attributes */
			temp->prev = (*position)->prev;
			temp->next = (*position)->next;

			/* make current node attributes of previous */
			(*position)->prev = (*position)->prev->prev; 
			(*position)->next = (*position)->prev->next; 

			/* make previous same as temp */
			(*position)->prev = temp;
			(*position)->prev->next = ->next;
		}	
/* if previous is not greater then swap this position (which is >) with temp */
		if ((*position)->prev->n < temp->n) 
		{
			(*position)->prev->next = temp;
			(*position)->next->prev = temp;
			free(temp);
		}
		print_list(*list);

	}

}
