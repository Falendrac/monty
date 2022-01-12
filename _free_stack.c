#include "monty.h"
/**
 * free_stack - delete all nodes of the stack
 * @stack: address of the pointer of the element at the top pf the stack
 */
void _free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
