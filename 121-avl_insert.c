#include "binary_trees.h"
/**
 * bst_parent - find parent node where value can be inserted
 * @tree: bst
 * @value: value
 *
 * Return: pointer to parent
 */
bst_t *bst_parent(bst_t *tree, int value)
{
	while (1)
	{
		if (!tree)
			return (NULL);
		if (value > tree->n)
		{
			if (!tree->right)
				break;
			tree = tree->right;
		}
		else if (value < tree->n)
		{
			if (!tree->left)
				break;
			tree = tree->left;
		}
		else
			return (NULL);
	}
	return (tree);
}
/**
 * bst_insert - inserts a node to bst
 * @tree: double pointer to root node
 * @value: value of node
 *
 * Return: pointer to created node,
 * if failed, NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree)
	{
		binary_tree_t *node;

		if (*tree)
		{
			binary_tree_t *parent = bst_parent(*tree, value);

			if (!parent)
				return (NULL);
			node = binary_tree_node(parent, value);
			if (!node)
				return (NULL);
			if (parent->n > node->n)
				parent->left = node;
			else
				parent->right = node;
		}
		else
		{
			node = binary_tree_node(NULL, value);
			if (!node)
				return (NULL);
			*tree = node;
		}
		return (node);
	}
	return (NULL);
}
/**
 * avl_insert - insert into avl tree
 * @tree: double pointer to root node
 * @value: value to be inserted
 *
 * Return: newly created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = bst_insert(tree, value);

	while (node)
	{
		int bf = binary_tree_balance(node);

		while (bf < -1)
		{
			binary_tree_rotate_left(node);
			bf = binary_tree_balance(node);
		}
		while (bf > 1)
		{
			binary_tree_rotate_right(node);
			bf = binary_tree_balance(node);
		}
		node = node->parent;
	}
	return (node);
}
