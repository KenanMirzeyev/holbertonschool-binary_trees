#include "binary_trees.h"
/**
 * bst_search - searches a value in binary tree
 * @tree: pointer to root node of tree
 * @value: value to be searched
 *
 * Return: pointer to node
 * if not found, NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		if (tree->n == value)
			return ((bst_t *) tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
