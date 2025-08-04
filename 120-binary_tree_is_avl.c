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
		ml = max(tree->left);
		if (ml > m)
			m = ml;
	}
	if (tree->right)
	{
		mr = max(tree->right);
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
 * binary_tree_is_avl - check if tree is avl
 * @tree: root node of tree
 *
 * Return: 1 if avl else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree)
	{
		int lh = (int) _binary_tree_height(tree->left);
		int rh = (int) _binary_tree_height(tree->right);
		int bf = lh - rh;
		int is_bst = binary_tree_is_bst(tree);

		if (is_bst && (bf * bf <= 1))
		{
			int avl_l = binary_tree_is_avl(tree->left);
			int avl_r = binary_tree_is_avl(tree->right);

			return ((!tree->left || avl_l) &&
				(!tree->right || avl_r));
		}
	}
	return (0);
}
