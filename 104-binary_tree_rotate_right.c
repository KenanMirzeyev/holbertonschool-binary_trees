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
		tree->parent = left;
		left->right = tree;
		left->parent = NULL;
		return (left);
	}
	return (NULL);
}
