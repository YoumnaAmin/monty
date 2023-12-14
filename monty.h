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
	int n;
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

typedef void (*op_func)(stack_t **, unsigned int);
int line_tok(char *buffer, int line_number, int format);
void _findfunc(char *opcode, char *value, int ln, int format);
void get_func(op_func func, char *op, char *val, int ln, int format);
stack_t *create_node(int n);
void node_free(void);
void _push(stack_t **new_node, __attribute__((unused))unsigned int ln);
void _pall(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void adds(stack_t **stack, unsigned int line_ay);
void nop_function(stack_t **stack, unsigned int line_ay);
void err(int errorstyle, ...);
void errtwo(int errorstyle, ...);
void errthree(int errorstyle, ...);
void swap_nodes(stack_t **stack, unsigned int line_number);
void free_nodes(void);
void more_err(int errorstyle, unsigned int line_number, char *instruction);
#endif
