#include "monty.h"
/**
 * swap_nodes - Swaps the top two elements
 * @stack: Pointer to a pointer pointing to top .
 * @line_number: Interger in the line
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errtwo(8, line_number, "swap");
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
 * adds - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_ay: interger representing the line
 */
void adds(stack_t **stack, unsigned int line_ay)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errtwo(8, line_ay, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop_function - Does nothing.
 * @stack: Pointer to a pointer pointing to top
 * @line_ay: Interger representing the numb
 */
void nop_function(stack_t **stack, unsigned int line_ay)
{
	(void)stack;
	(void)line_ay;
}

/**
 * div_ay- Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_ay: Interger representing the line number of of the opcode.
 */
void div_ay(stack_t **stack, unsigned int line_ay)
{
	int q;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_ay, "div");

	if ((*stack)->n == 0)
		more_err(9, line_ay);
	(*stack) = (*stack)->next;
	q = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = q;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
