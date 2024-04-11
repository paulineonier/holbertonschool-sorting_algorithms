#include "sort.h"
#include <stdio.h>

/**
 * print_list - Imprime une liste doublement chaînée d'entiers
 * @list: Pointeur vers le début de la liste
 */
void print_list(const listint_t *list)
{
	const listint_t *current = list;

	while (current != NULL)
	{
		printf("%d", current->n);
		if (current->next != NULL)
			printf(", ");
		current = current->next;
	}
	printf("\n");
}
