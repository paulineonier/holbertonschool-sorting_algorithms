#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Imprime une liste doublement chaînée d'entie
 * trie ine liste doublemt chain�e d'entiers par ordre
 * croissant,en utilist l'agorithme de trie par insertion
 * @list: pointeir vers pointeur de la tete de liste
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		insertion_point = current;
		while (insertion_point->prev != NULL &&
				insertion_point->n < insertion_point->prev->n)
		{
			/* echanger les node */
			if (insertion_point->prev->prev != NULL)
				insertion_point->prev->prev->next = insertion_point;
			if (insertion_point->next != NULL)
				insertion_point->next->prev = insertion_point->prev;
			insertion_point->prev->next = insertion_point->next;
			insertion_point->next = insertion_point->prev;
			insertion_point->prev = insertion_point->next->prev;
			insertion_point->next->prev = insertion_point;
			if (insertion_point->prev == NULL)
				*list = insertion_point;
			print_list(*list);
			insertion_point = insertion_point->prev;
		}
		current = current->next;
	}
}
