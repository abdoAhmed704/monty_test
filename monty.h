#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
        int nums;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int lines);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void Fileopen(char *file_name);
int parseLine(char *BUFF, int line_number, int format);
void findF(char *opcode, char *value, int ln, int format);
void file_read(FILE *filedes);

int len_chars(FILE *);

/*Stack operations*/
stack_t *node_create(int num);
void nodes_free(void);
void add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln);
void stack_print(stack_t **stack, unsigned int lines);
void add_queue(stack_t **, unsigned int);

void FUN_call(op_func func, char *op, char *val, int ln, int format);

void TOP_print(stack_t **stack, unsigned int lines);

void POPtotop(stack_t **stack, unsigned int lines);
void nothing(stack_t **stack, unsigned int lines);
void Nodes_swap(stack_t **stack, unsigned int lines);

/*Maths*/
void node_DIV(stack_t **stack, unsigned int lines);
void nodes_SUB(stack_t **stack, unsigned int lines);
void nodes_ADD(stack_t **stack, unsigned int lines);
void node_MOD(stack_t **stack, unsigned int lines);
void node_MUL(stack_t **stack, unsigned int lines);

/*Strings*/
void rotateT(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotateB(stack_t **stack, __attribute__((unused))unsigned int ln);
void strPrint(stack_t **stack, __attribute__((unused))unsigned int ln);
void charPrint(stack_t **stack, unsigned int lines);


/*Errors*/
void iferrs(int iferror, ...);
void iferrs2(int iferror, ...);
void str_err(int error_code, ...);

#endif
