#include "monty.h"
/**
 * _add - adds the top two elements of the stack
 * @stack: address of pointer of the element af the top of the stack
 * @line_number: number of the line in the file
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1, *ptr2;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	if (len_of_the_stack(&*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr1 = *stack;
	ptr2 = (*stack)->next;
	ptr2->n += ptr1->n;
	*stack = ptr2;
	ptr2->prev = NULL;
	free(ptr1);
}
