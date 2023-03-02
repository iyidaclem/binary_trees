#include "binary_trees.h"

/**
* binary_tree_postorder - A function that goes through a
* binary tree using post-order traversal
* @tree: A pointer to the root of the binary tree
* @func: A pointer to the function to call for every node
* Return: void
*/


void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}

