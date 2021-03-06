#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* provided.c */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* others provided */
listint_t *create_listint(const int *array, size_t size);

/* 0 */
void bubble_sort(int *array, size_t size);

/* 1 */
void insertion_sort_list(listint_t **list);
void swap(listint_t *pointer, listint_t *current, listint_t **list);

/* 2 */
void selection_sort(int *array, size_t size);

/* 3 */
void quick_sort(int *array, size_t size);
void qsort_recursion(int *array, int l, int r, size_t size);
int part(int *array, int l, int r, size_t size);

/* advanced */
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
#endif
