#include "binary_trees.h"
/**
 * sorted_array_to_avl - creates avl tree from sorted array
 * @array: pointer to first element
 * @size: number of elements
 *
 * Return: root node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (!array || size == 0)
		return (NULL);
	tree = binary_tree_node(NULL, array[size / 2]);
	if (!tree)
		return (NULL);
	tree->left = sorted_array_to_avl(array, size / 2);
	if (tree->left)
		tree->left->parent = tree;
	tree->right = sorted_array_to_avl(array + size / 2 + 1,
			size / 2 - !(size % 2));
	if (tree->right)
		tree->right->parent = tree;
	return (tree);
}
