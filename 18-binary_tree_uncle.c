#include "binary_trees.h"
/**
 * binary_tree_sibling - find sibling of a node
 * @node: node to find sibling of
 *
 * Return: pointer to sibling
 * if no sibling, null
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	return (node->parent->left == node ? node->parent->right :
			node->parent->left);
}
/**
 * binary_tree_uncle - find uncle of node
 * @node: node to find uncle of
 *
 * Return: the uncle of given node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}
