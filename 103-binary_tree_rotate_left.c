#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left rotates a tree
 * @tree: root node
 *
 * Return: new root node of tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right = tree->right;

	tree->right = right->left;
	right->left = tree;
	right->parent = NULL;
	return (right);
}
