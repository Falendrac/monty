#include "monty.h"
/**
 * _mod - computes the rest of the div of the 2nd by the top elt of the stack
 * @stack: address of pointer of the element af the top of the stack
 * @line_number: number of the line in the file
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1, *ptr2;

	if (len_of_the_stack(&*stack) < 2)
	{
		_free_stack(stack);
		free_line_t();
		fclose(monty_data->fd);
		free(monty_data);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr1 = *stack;
	ptr2 = (*stack)->next;
	if (ptr1->n == 0)
	{
		_free_stack(stack);
		free_line_t();
		fclose(monty_data->fd);
		free(monty_data);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr2->n %= ptr1->n;
	*stack = ptr2;
	ptr2->prev = NULL;
	free(ptr1);
}
