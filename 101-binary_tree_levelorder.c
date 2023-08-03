#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_queue - Creates an empty queue.
 *
 * Return: Pointer to the created queue, or NULL on failure.
 */
queue_t *create_queue(void)
{
	queue_t *queue;

	queue = malloc(sizeof(queue_t));
	if (queue == NULL)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

/**
 * enqueue - Add an element to the rear of the queue.
 *
 * @queue: Pointer to the queue.
 * @node: The binary tree node to enqueue.
 */
void enqueue(queue_t *queue, const binary_tree_t *node)
{
	queue_node_t *new_node;

	new_node = malloc(sizeof(queue_node_t));
	if (new_node == NULL)
		return;
	new_node->node = node;
	new_node->next = NULL;
	if (queue->rear == NULL)
	{
		queue->front = new_node;
		queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}

/**
 * dequeue - Remove an element from the front of the queue.
 *
 * @queue: Pointer to the queue.
 *
 * Return: The binary tree node dequeued, or NULL if the queue is empty.
 */
const binary_tree_t *dequeue(queue_t *queue)
{
	queue_node_t *temp;
	const binary_tree_t *node;

	if (queue == NULL || queue->front == NULL)
		return (NULL);
	node = queue->front->node;
	temp = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	free(temp);
	return (node);
}

/**
 * queue_is_empty - Check if the queue is empty.
 *
 * @queue: Pointer to the queue.
 *
 * Return: 1 if the queue is empty, 0 otherwise.
 */
int queue_is_empty(queue_t *queue)
{
	return (queue == NULL || queue->front == NULL);
}

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Description: The value in the node is passed as a parameter to the function.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	const binary_tree_t *node;

	if (tree == NULL || func == NULL)
		return;
	queue = create_queue();
	if (queue == NULL)
		return;
	enqueue(queue, tree);
	while (!queue_is_empty(queue))
	{
		node = dequeue(queue);
		func(node->n);
		if (node->left)
			enqueue(queue, node->left);
		if (node->right)
			enqueue(queue, node->right);
	}
	free(queue);
}
