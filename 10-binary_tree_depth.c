#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - depth
 * @tree: t
 *
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t left_d, right_d;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_d = binary_tree_depth(tree->left);
	right_d = binary_tree_depth(tree->right);

	return ((left_d > right_d ? left_d : right_d) + 1);
}

