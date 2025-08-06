#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *tree = binary_tree_node(NULL, 56);

    tree->left = binary_tree_node(tree, 43);
    tree->left->left = binary_tree_node(tree->left, 2);
    tree->right = binary_tree_node(tree, 98);
    tree->right->left = binary_tree_node(tree->right, 78);
    tree->right->left->left = binary_tree_node(tree->right->left, 76);
    tree->right->right = binary_tree_node(tree->right, 123);
    tree->right->right->left = binary_tree_node(tree->right->right, 110);
    tree->right->right->right = binary_tree_node(tree->right->right, 234);
    binary_tree_print(tree);
    printf("remove: %d\n", 98);
    avl_remove(tree, 98);
    printf("%d\n", bst_search(tree, 234)->parent->n);
    binary_tree_print(tree);
    printf("remove: %d\n", 110);
    avl_remove(tree, 110);
    printf("%d\n", bst_search(tree, 234)->parent->n);
    binary_tree_print(tree);
    printf("remove: %d\n", 123);
    avl_remove(tree, 123);
    printf("%d\n", bst_search(tree, 234)->parent->n);
    binary_tree_print(tree);
    binary_tree_delete(tree);
    return (0);
}
