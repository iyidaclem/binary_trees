#include "binary_trees.h"

/**
* max - function that return maximum between two numbers
* @num1: First number
* @num2: Second number
* Return: Return the max number
*/

size_t max(size_t num1, size_t num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}


/**
* binary_tree_height - Function to calculate the height of a binary tree
* @tree: pointer to the root of tree
* Return: the height of the tree
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (max(left_height, right_height) + 1);
}
