#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked list in ascending
 * @list: Pointer to the doubly linked list to be sorted.
 *
 * Return: This function does not return a value.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	for (current = (*list)->next; current; current = temp)
	{
		temp = current->next;

		while (current->prev && current->prev->n > current->n)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;

			if (!current->prev)
				*list = current;
			else
				current->prev->next = current;

			print_list(*list);
		}

	}

}
