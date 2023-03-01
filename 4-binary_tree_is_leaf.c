#include "binary_trees.h"

/**
* binary_tree_is_leaf - function to check if a node is a leaf
* @node: pointer to node no check
* Return: 1 if true or 0 if false
*/


int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && (node->left != NULL || node->right != NULL))
		return (0);
	return (1);
}
