#include "binary_trees.h"
/**
 * binary_tree_levelorder - traverse level order
 * @tree: binary tree
 * @func: function to execute
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		int h = 1;

		func(tree->n);
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
					func(node->n);
					x++;
				}
			}
			if (x == 0)
				break;
			h++;
		}
	}
}
