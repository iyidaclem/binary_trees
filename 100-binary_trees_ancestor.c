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
	return (binary_tree_depth(tree->parent) + 1);
}


/**
* binary_trees_ancestor - lowest common ancestor of two nodes
* @first: The first node
* @second: The second node
* Return: Pointer to the ancestor or NULL if not exists
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t fDepth = 0, sDepth =  0, diff =  0;

	if (first && second)
	{
		fDepth = binary_tree_depth(first);
		sDepth = binary_tree_depth(second);
		if (fDepth == sDepth)
		{
			if (first->parent == second->parent)
				return (first->parent);
			return (binary_trees_ancestor(first->parent, second->parent));
		}
		else if (fDepth > sDepth)
		{
			diff = fDepth - sDepth;
			for (; diff > 0; diff--)
			{
				if (first->parent == second)
					return (first->parent);
				first = first->parent;
			}
			return (binary_trees_ancestor(first, second));
		}
		else
		{
			diff = sDepth - fDepth;
			for (; diff > 0; diff--)
			{
				if (second->parent == first)
					return (second->parent);
				second = second->parent;
			}
			return (binary_trees_ancestor(first, second));
		}
	}

	return (NULL);
}

