#include "binary_trees.h"
#include <stdlib.h>
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
/**
 * min - find minimum value in tree
 * @tree: root node
 *
 * Return: minimum value pointer
 */
bst_t *min(const bst_t *tree)
{
	bst_t *m = (bst_t *) tree, *ml, *mr;

	if (tree->left)
	{
		ml = min(tree->left);
		if (ml->n < m->n)
			m = ml;
	}
	if (tree->right)
	{
		mr = min(tree->right);
		if (mr->n < m->n)
			m = mr;
	}
	return (m);
}
/**
 * remove_from_parent - removes node from parent
 * @node: node to remove from parent
 *
 * Return: 1 if removed
 * 0 else
 */
int remove_from_parent(bst_t *node)
{
	if (node->parent)
	{
		if (node == node->parent->left)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		return (1);
	}
	return (0);
}
/**
 * bst_remove - bst remove node
 * @root: root node
 * @value: value of node to be removed
 *
 * Return: new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = bst_search(root, value), *nxt;

	if (node)
	{
		if (node->left && node->right)
			nxt = min(node->right);
		else if (!(node->right || node->left))
			nxt = NULL;
		else
			nxt = node->right ? node->right : node->left;
		if (nxt)
		{
			remove_from_parent(nxt);
			if (!node->left && nxt->left)
			{
				node->left = nxt->left;
				node->left->parent = node;
			}
			if (!node->right && nxt->right)
			{
				node->right = nxt->right;
				node->right->parent = node;
			}
			node->n = nxt->n;
			free(nxt);
		}
		else
		{
			if (!remove_from_parent(node))
				root = NULL;
			free(node);
		}
	}
	return (root);
}
/**
 * avl_remove - remove a node from avl
 * @root: root node
 * @value: the value to be removed
 *
 * Return: new root node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node = bst_search(root, value), *parent;

	if (!node)
		return (root);
	parent = node->parent;
	root = bst_remove(root, value);
	if (!(node == parent->left || node == parent->right))
		node = parent;
	while (node)
	{
		avl_t *parent = node->parent;
		int bf = binary_tree_balance(node);

		if (bf < -1)
		{
			if (binary_tree_balance(node->left) <= 0)
				root = binary_tree_rotate_left(node);
			else
			{
				binary_tree_rotate_right(node->right);
				root = binary_tree_rotate_left(node);
			}
		}
		else if (bf > 1)
		{
			if (binary_tree_balance(node->left) >= 0)
				root = binary_tree_rotate_right(node);
			else
			{
				binary_tree_rotate_left(node->left);
				root = binary_tree_rotate_right(node);
			}
		}
		node = parent;
	}
	return (root);
}
