#include "binary_trees.h"
/**
 * binary_tree_is_full - check if tree is full
 * @tree: root node of th tree
 *
 * Return: 1 if full 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		int count = (tree->left != NULL) + (tree->right != NULL);

		if (count == 0)
			return (1);
		if (count == 1)
			return (0);
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
	}
	return (0);
}
