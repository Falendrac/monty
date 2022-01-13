#include "monty.h"
/**
 * _sub - subtracts the top element from the second top element of the stack
 * @stack: address of pointer of the element af the top of the stack
 * @line_number: number of the line in the file
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1, *ptr2;

	if (len_of_the_stack(&*stack) < 2)
	{
		_free_stack(stack);
		free_line_t();
		fclose(monty_data->fd);
		free(monty_data);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr1 = *stack;
	ptr2 = (*stack)->next;
	ptr2->n -= ptr1->n;
	*stack = ptr2;
	ptr2->prev = NULL;
	free(ptr1);
}
