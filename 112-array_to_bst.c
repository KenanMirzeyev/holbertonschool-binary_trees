#include "binary_trees.h"
/**
 * array_to_bst - create bst from array
 * @array: an array of int
 * @size: size of array
 *
 * Return: root node or NULL if failed
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
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
		if (!bst_insert(&tree, array[i]))
			return (NULL);
	}
	return (tree);
}
