#include "binary_trees.h"
/**
 * min - find minimum value in tree
 * @tree: root node
 *
 * Return: minimum value
 */
int min(const binary_tree_t *tree)
{
	int m = tree->n, ml, mr;

	if (tree->left)
	{
		ml = min(tree->left);
		if (ml < m)
			m = ml;
	}
	if (tree->right)
	{
		mr = min(tree->right);
		if (mr < m)
			m = mr;
	}
	return (m);
}
/**
 * max - find maximum value in tree
 * @tree: root node
 *
 * Return: maximum value
 */
int max(const binary_tree_t *tree)
{
	int m = tree->n, ml, mr;

	if (tree->left)
	{
		ml = min(tree->left);
		if (ml > m)
			m = ml;
	}
	if (tree->right)
	{
		mr = min(tree->right);
		if (mr > m)
			m = mr;
	}
	return (m);
}

/**
 * binary_tree_is_bst - check if tree is bst
 * @tree: root node
 *
 * Return: 1 if bst, 0 else
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!(tree &&
		(tree->left ? max(tree->left) < tree->n : 1) &&
		(tree->right ? min(tree->right) > tree->n : 1) &&
		(tree->left ? binary_tree_is_bst(tree->left) : 1) &&
		(tree->right ? binary_tree_is_bst(tree->right) : 1)))
		return (0);
	return (1);
}
