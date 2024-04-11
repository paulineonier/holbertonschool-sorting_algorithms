#include "sort.h"
#include <stdio.h>

void _quick_sort(int *array, int low, int high, size_t size);
int _partition(int *array, int low, int high, size_t size);
void _swap(int *a, int *b);

/**
 * quick_sort - Trie un tableau d'entiers par tri rapide (Quick sort)
 * @array: Le tableau d'entiers atrier
 * @size: Taille du tableau
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - Fonction récursive pour trier un sous-tablea
 * @array: Le tableau d'entiers trier
 * @low: L'indice de début du sous-tablea
 * @high: L'indice de fin du sous-tableau
 * @size: Taille du tableau
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = _partition(array, low, high, size);

		_quick_sort(array, low, pivot_index - 1, size);
		_quick_sort(array, pivot_index + 1, high, size);
	}
}

/**
 * _partition - Réalise une partition en utilisant le schéma de Lomut
 * @array: Le tableau d'entiers trier
 * @low: L'indice de début du sous-tablea
 * @high: L'indice de fin du sous-tableau
 * @size: Taille du tableau
 *
 * Return: L'indice du pivot
 */
int _partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			_swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	_swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * _swap - change les valeurs de deux entiers
 * @a: Pointeur vers le premier entier
 * @b: Pointeur vers le deuxième entie
 */
void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
