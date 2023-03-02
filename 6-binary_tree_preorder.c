#include "binary_trees.h"

/**
* binary_tree_preorder - A function that goes through a
* binary tree using pre-order traversal
* @tree: A pointer to the root of the binary tree
* @func: A pointer to the function to call for every node
* Return: void
*/


void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}

