#include "binary_trees.h"

/**
* binary_tree_delete - Function to delete entire binary tree
* @tree: point to the root of the binary tree
* Return: void
*/


void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (tree != NULL)
	{
		left = tree->left;
		right = tree->right;
		free(tree);
		binary_tree_delete(left);
		binary_tree_delete(right);
	}
}

