#include "monty.h"

/**
 * nothing - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: Interger representing the line number of of the opcode.
 */

void nothing(stack_t **stack, unsigned int lines)
{
	(void)stack;
	(void)lines;
}


/**
 * Nodes_swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: Interger representing the line number of of the opcode.
 *
 * Return: nothing
 */

void Nodes_swap(stack_t **stack, unsigned int lines)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		iferrs2(8, lines, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * nodes_ADD - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: Interger representing the line number of of the opcode.
 *
 * Return: nothing 
 */

void nodes_ADD(stack_t **stack, unsigned int lines)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		iferrs2(8, lines, "add");

	(*stack) = (*stack)->next;
	add = (*stack)->nums + (*stack)->prev->nums;
	(*stack)->nums = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_SUB - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: Interger representing the line number of of the opcode.
 */

void nodes_SUB(stack_t **stack, unsigned int lines)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		iferrs2(8, lines, "sub");


	(*stack) = (*stack)->next;
	sub = (*stack)->nums - (*stack)->prev->nums;
	(*stack)->nums = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * node_DIV - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: Interger representing the line number of of the opcode.
 * 
 * Return: nothing
 */

void node_DIV(stack_t **stack, unsigned int lines)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		iferrs2(8, lines, "div");

	if ((*stack)->nums == 0)
		iferrs2(9, lines);
	(*stack) = (*stack)->next;
	div = (*stack)->nums / (*stack)->prev->nums;
	(*stack)->nums = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
