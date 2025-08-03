#include "binary_trees.h"
/**
 * binary_tree_rotate_right - right rotate
 * @tree: root node
 *
 * Return: new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree && tree->left)
	{
		binary_tree_t *left = tree->left;

		tree->left = left->right;
		if (tree->left)
			tree->left->parent = tree;
		left->right = tree;
		tree->parent = left;
		left->parent = NULL;
		return (left);
	}
	return (NULL);
}
