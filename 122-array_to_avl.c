#include "binary_trees.h"
/**
 * array_to_avl - convert array to avl tree
 * @array: pointer to first element
 * @size: number of elements
 *
 * Return: root node
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[i] == array[j])
				break;
		}
		if (j < i)
			continue;
		if (!avl_insert(&tree, array[i]))
			return (NULL);
	}
	return (tree);
}
