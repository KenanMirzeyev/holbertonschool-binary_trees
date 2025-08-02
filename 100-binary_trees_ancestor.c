#include "binary_trees.h"
/**
 * is_ancestor - check if ancestor
 * @node: a node to be checked
 * @anc: the ancestor to be checked
 *
 * Return: 1 if ancestor, 0 else
 */
int is_ancestor(const binary_tree_t *node, const binary_tree_t *anc)
{
	if (!node || !anc)
		return (0);
	do
		node = node->parent;
	while (node && node != anc);
	return (node != NULL);
}
/**
 * binary_trees_ancestor - find lowest common ancestor
 * @first: first node
 * @second: second node
 *
 * Return: lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	binary_tree_t *node;
	if (!first || !second)
		return (0);
	node = first->parent;
	while (node && !is_ancestor(second, node))
		node = node->parent;
	return (node);
}

