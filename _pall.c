#include "monty.h"

/**
 * _pall - Prints all the values on the stack, from the top of the stack
 *
 * @stack: The stack with all values
 * @line_number: Unused argument
 */
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (stack != NULL && *stack != NULL)
	{
		while (*stack != NULL)
		{
			printf("%d\n", (*stack)->n);
			*stack = (*stack)->next;
		}
	}
}
