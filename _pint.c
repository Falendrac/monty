#include "monty.h"
/**
 * _pint - prints the value at the top of the stack
 * @stack: address of the pointer on the element at the top of the stack
 * @line_number: number of the line in the file
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		free_line_t();
		free(monty_data);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
