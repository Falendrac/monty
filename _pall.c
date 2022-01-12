#include "monty.h"

/**
 * _pall - Prints all the values on the stack, from the top of the stack
 *
 * @stack: The stack with all values
 * @line_number: Unused argument
 */
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	if (stack != NULL && *stack != NULL)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", (current->n));
			current = current->next;
		}
	}
}
