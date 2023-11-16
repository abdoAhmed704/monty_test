#include "monty.h"

/**
 * node_MUL - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: Interger representing the line number of of the opcode.
 *
 * Return: nothing
 */

void node_MUL(stack_t **stack, unsigned int lines)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		iferrs2(8, lines, "mul");

	(*stack) = (*stack)->next;
	mul = (*stack)->nums * (*stack)->prev->nums;
	(*stack)->nums = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * node_MOD - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: Interger representing the line number of of the opcode.
 *
 *Return: nothing
 */

void node_MOD(stack_t **stack, unsigned int lines)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		iferrs2(8, lines, "mod");


	if ((*stack)->nums == 0)
		iferrs2(9, lines);
	(*stack) = (*stack)->next;
	mod = (*stack)->nums % (*stack)->prev->nums;
	(*stack)->nums = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
