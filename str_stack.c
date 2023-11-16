#include "monty.h"

/**
 * charPrint - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lines: Interger representing the line number of of the opcode.
 */

void charPrint(stack_t **stack, unsigned int lines)
{
	int ASCII_int;

	if (stack == NULL || *stack == NULL)
		str_err(11, lines);

	ASCII_int = (*stack)->nums;
	if (ASCII_int < 0 || ASCII_int > 127)
		str_err(10, lines);
	printf("%c\n", ASCII_int);
}

/**
 * strPrint - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */

void strPrint(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ASCII_int;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ASCII_int = temp->nums;
		if (ASCII_int <= 0 || ASCII_int > 127)
			break;
		printf("%c", ASCII_int);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotateB - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */

void rotateB(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotateT - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */

void rotateT(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
