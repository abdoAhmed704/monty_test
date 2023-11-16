#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * 
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	Fileopen(argv[1]);
	nodes_free();
	return (0);
}

/**
 * node_create - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node.
 *	Otherwise NULL.
 */

stack_t *node_create(int num)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		iferrs(4);
	node->next = NULL;
	node->prev = NULL;
	node->nums = num;
	return (node);
}

/**
 * nodes_free - Free node
 */

void nodes_free(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * add_queue - Adds node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */

void add_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;
}
