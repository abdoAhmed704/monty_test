#include "monty.h"

/**
 * Fileopen - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void Fileopen(char *file_name)
{
	FILE *filedes = fopen(file_name, "r");

	if (file_name == NULL || filedes == NULL)
		iferrs(2, file_name);

	file_read(filedes);
	fclose(filedes);
}


/**
 * file_read - reads a file
 * @filedes: pointer to file descriptor
 * Return: void
 */

void file_read(FILE *filedes)
{
	int lines, format = 0;
	char *BUFF = NULL;
	size_t len = 0;

	for (lines = 1; getline(&BUFF, &len, filedes) != -1; lines++)
	{
		format = parseLine(BUFF, lines, format);
	}
	free(BUFF);
}


/**
 * parseLine - Separates each line into tokens to determine
 * which function to call
 * @BUFF: line from the file
 * @lines: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseLine(char *BUFF, int line_number, int format)
{
	char *opcode, *value;
	const char *del = "\n ";

	if (BUFF == NULL)
		iferrs(4);

	opcode = strtok(BUFF, del);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, del);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	findF(opcode, value, line_number, format);
	return (format);
}

/**
 * findF - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */

void findF(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_stack},
		{"pall", stack_print},
		{"pint", TOP_print},
		{"pop", POPtotop},
		{"nop", nothing},
		{"swap", Nodes_swap},
		{"add", nodes_ADD},
		{"sub", nodes_SUB},
		{"div", node_DIV},
		{"mul", node_MUL},
		{"mod", node_MOD},
		{"pchar", charPrint},
		{"pstr", strPrint},
		{"rotl", rotateB},
		{"rotr", rotateT},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			FUN_call(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		iferrs(3, ln, opcode);
}


/**
 * FUN_call - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */

void FUN_call(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			iferrs(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				iferrs(5, ln);
		}
		node = node_create(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_queue(&node, ln);
	}
	else
		func(&head, ln);
}
