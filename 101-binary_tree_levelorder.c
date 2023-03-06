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
* binary_tree_levelorder - function that goes through a binary
* tree using level-order traversal
* @tree: pointer to the root of the tree
* @func: pointer to the function to execute for each node
* Return: Void
*/


void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *head = NULL;
	queue_t *last = NULL;

	if (tree && func)
	{
		enqueue(&last, &head, (binary_tree_t *)tree);
		while (head)
		{
			func(head->node->n);
			enqueue(&last, &head, head->node->left);
			enqueue(&last, &head, head->node->right);
			dequeue(&head);
		}
	}
}
