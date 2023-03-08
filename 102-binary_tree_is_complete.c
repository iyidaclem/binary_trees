#include "binary_trees.h"


/**
* enqueue - Function to add element to a queue
* @last: Pointer to the last item  of the queue
* @head: Pointer to the head of the queue
* @node: value of the new item
* Return: pointer to the new item or NULL
*/

void enqueue(queue_t **last, queue_t **head,  binary_tree_t *node)
{
	queue_t *new_item;

	if (node)
	{
		new_item = malloc(sizeof(queue_t));
			if (new_item == NULL)
				return;
		new_item->node = node;
		if ((*head) == NULL)
		{
			(*head) = new_item;
			(*last) = new_item;
		}
		else
		{
			(*last)->next = new_item;
			(*last) = (*last)->next;
		}
	}
}

/**
* dequeue - removes first item;
* @head: pointer to the head of the queue
* Return: void
*/

void dequeue(queue_t **head)
{
	queue_t *temp;

	if (head)
	{
		temp = (*head);
		(*head) = (*head)->next;
		free(temp);
	}
}

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


/**
* binary_tree_is_complete - function that checks if a
* binary tree is complete
* @tree: pointer to the tree
* Return: 1 if true or 0 if false
*/


int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *head = NULL;
	queue_t *last = NULL;
	size_t height;
	int factor = 1;
	int main_factor = -1;
	int is_complete = 1;

	if (tree)
	{
		enqueue(&last, &head, (binary_tree_t *)tree);
		while (head != NULL)
		{
			height = binary_tree_height(head->node);
			if (height ==  1)
			{
				main_factor += factor;
				factor = 0;
				if (main_factor != 0 && (main_factor % 2) != 0)
					is_complete = 0;
				if (head->node->left != NULL)
					main_factor += 1;
				if (head->node->right != NULL)
					main_factor += 1;
				if (head->node->right && !head->node->left)
					is_complete = 0;
			}
			else if (height > 1)
			{
				if (head->node->left == NULL || head->node->right == NULL)
					is_complete = 0;
			}

			enqueue(&last, &head, head->node->left);
			enqueue(&last, &head, head->node->right);
			dequeue(&head);
		}
	}
	return (is_complete);
}

