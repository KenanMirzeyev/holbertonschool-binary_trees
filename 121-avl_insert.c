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
 * do_rotate - do necessary rotation on node to balance
 * @node: newly inserted node
 *
 * Return: new root node
 * NULL if not changed
 */
avl_t *do_rotate(avl_t *node)
{
	avl_t *root = NULL;

	while (node && node->parent)
	{
		avl_t *rot = node->parent->parent, *new_root = NULL;
		int bf = binary_tree_balance(rot);

		if (bf * bf > 1)
		{
			if (rot->left && rot->left->left == node)
				new_root = binary_tree_rotate_right(rot);
			if (rot->right && rot->right->right == node)
				new_root = binary_tree_rotate_left(rot);
			if (rot->left && rot->left->right == node)
			{
				binary_tree_rotate_left(rot->left);
				new_root = binary_tree_rotate_right(rot);
			}
			if (rot->right && rot->right->left == node)
			{
				binary_tree_rotate_right(rot->right);
				new_root = binary_tree_rotate_left(rot);
			}
			if (!new_root->parent)
				root = new_root;
		}
		node = node->parent;
	}
	return (root);
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
	avl_t *new_root = do_rotate(node);

	if (new_root)
		*tree = new_root;
	return (node);
}
