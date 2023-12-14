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
		more_err(8, line_number, "swap");
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
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_ay: interger representing the line
 */
void adds(stack_t **stack, unsigned int line_ay)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_ay, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top 
 * @line_number: Interger representing the numb
 */
void nop_function(stack_t **stack, unsigned int line_ay)
{
	(void)stack;
	(void)line_ay;
}
