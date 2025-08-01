#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - size
 * @tree:t
 *
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);
	if (tree != NULL)
	{
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
		size += 1;
	}
	return (size);
}
