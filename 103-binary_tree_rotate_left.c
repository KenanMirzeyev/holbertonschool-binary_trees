#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left rotates a tree
 * @tree: root node
 *
 * Return: new root node of tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree && tree->right)
	{
		binary_tree_t *right = tree->right, *p = tree->parent;

		tree->right = right->left;
		if (tree->right)
			tree->right->parent = tree;
		tree->parent = right;
		right->left = tree;
		right->parent = p;
		if (p)
		{
			if (p->left == tree)
				p->left = right;
			else
				p->right = right;
		}
		return (right);
	}
	return (NULL);
}
