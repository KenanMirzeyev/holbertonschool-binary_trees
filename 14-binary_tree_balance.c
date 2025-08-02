#include <stdlib.h>
#include "binary_trees.h"
/**
 * _binary_tree_height - height
 * @tree: t
 *
 * Return: 0
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = _binary_tree_height(tree->left);
	right_h = _binary_tree_height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}
/**
 * binary_tree_balance - calc balance factor
 * @tree: the root node of tree
 *
 * Return: if tree is null, 0
 * else, balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		int hl = (int) _binary_tree_height(tree->left),
		hr = (int) _binary_tree_height(tree->right);

		return (hl - hr);
	}
	return (0);
}
