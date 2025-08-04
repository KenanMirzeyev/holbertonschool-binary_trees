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
 * next - find node that will replace when a node is deleted
 * @node: the node that will be deleted
 *
 * Return: pointer to next node
 */
bst_t *next(bst_t *node)
{
	if (node)
	{
		int children = (node->left != NULL) + (node->right != NULL);

		switch (children)
		{
			case 0:
				return (NULL);
			case 1:
				return (node->left ? node->left : node->right);
			case 2:
				return (min(node->right));
		}
	}
	return (NULL);
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
	bst_t *node = bst_search(root, value);

	if (node)
	{
		bst_t *nxt = next(node);

		if (nxt)
		{
			if (!node->left && nxt->left)
			{
				node->left = nxt->left;
				node->left->parent = node;
			}
			if (!node->right && nxt->right)
			{
				node->right = nxt->right;
				node->right->parent = node->right;
			}
			node->n = nxt->n;
			remove_from_parent(nxt);
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
