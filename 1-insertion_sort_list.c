#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index, *key;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	index = (*list)->next;

	while (index != NULL)
	{
		key = index;

		while (key->prev != NULL && key->n < key->prev->n)
		{
			if (key->next != NULL)
				key->next->prev = key->prev;
			key->prev->next = key->next;

			key->next = key->prev;
			key->prev = key->prev->prev;

			if (key->prev != NULL)
				key->prev->next = key;
			else
				*list = key;

			if (key->next != NULL)
				key->next->prev = key;

			else if (key->prev == NULL)
			{
				index = key;
			}

			print_list(*list);
		}

		index = index->next;
	}
}
