#include "binary_trees.h"

/**
* binary_tree_depth - Function to return the depth of a node
* @tree: pointer to the node
* Return: depth of the node
*/


size_t binary_tree_depth(const binary_tree_t *tree)
{

	if (tree == NULL || tree->parent == NULL)
		return (0);
	return	(binary_tree_depth(tree->parent) + 1);
}

