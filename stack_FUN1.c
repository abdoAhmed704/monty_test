#include "monty.h"

/**
 * add_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 *
 * Return: nothing
 */

void add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * stack_print - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: line number of  the opcode.
 *
 * Return: nothing
 */

void stack_print(stack_t **stack, unsigned int lines)
{
	stack_t *temp;

	(void) lines;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->nums);
		temp = temp->next;
	}
}

/**
 * POPtotop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: Interger representing the line number of of the opcode.
 *
 * Return: nothing
 */

void POPtotop(stack_t **stack, unsigned int lines)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		iferrs2(7, lines);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * TOP_print - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: Interger representing the line number of of the opcode.
 *
 * Return: nothing
 */

void TOP_print(stack_t **stack, unsigned int lines)
{
	if (stack == NULL || *stack == NULL)
		iferrs2(6, lines);
	printf("%d\n", (*stack)->nums);
}

