#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 * @stack: address of the pointer on the element at the top of the stack
 * @line_number: number of the line in the file
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		_free_stack(stack);
		free_line_t();
		fclose(monty_data->fd);
		free(monty_data);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if (current->n < 32 || current->n > 126)
	{
		_free_stack(stack);
		free_line_t();
		fclose(monty_data->fd);
		free(monty_data);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}
