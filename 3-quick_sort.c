#include "sort.h"
#include <stdio.h>

void _quick_sort(int *array, int low, int high, size_t size);
int _partition(int *array, int low, int high, size_t size);

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
 * _quick_sort - Fonction récursive pour trier un tableau par quick sort
 * @array: Le tableau d'entiers à trier
 * @low: Index du premier élément
 * @high: Index du dernier élément
 * @size: Taille du tableau
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
	(void)array;
	(void)low;
	(void)high;
	(void)size;

	if (low < high)
	{
		int pi = _partition(array, low, high, size);

		_quick_sort(array, low, pi - 1, size);
		_quick_sort(array, pi + 1, high, size);
	}
}

/**
 * partition - Partitionne un tableau en fonction du pivot
 * Utilise le schéma de partition Lomut
 * @array: Tableau à partitionner
 * @low: Index du premier élément de laartition
 * @high: Index du dernier élément de la partitn
 * @size: Taille du tableau
 * Return: L'index du pivot après partitionnement
 */
int _partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;
	int temp = array[i];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];

		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
