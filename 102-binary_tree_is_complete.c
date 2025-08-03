#include "binary_trees.h"
/**
 * binary_tree_is_complete - check if tree is complete
 * @tree: root node of tree
 *
 * Return: 1 if complete, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree)
	{
		int h = 1, found_null = 0;

		while (1)
		{
			int x = 0, i, j;

			for (i = 0; i < (1 << h); i++)
			{
				const binary_tree_t *node = tree;

				for (j = h - 1; j >= 0; j--)
				{
					if ((i >> j) % 2 == 0)
						node = node->left;
					else
						node = node->right;
					if (!node)
						break;
				}
				if (node)
				{
					if (found_null)
						return (0);
					x++;
				}
				else
					found_null = 1;
			}
			if (x == 0)
				break;
			h++;
		}
		return (1);
	}
	return (0);
}
