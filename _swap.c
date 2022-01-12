#include "monty.h"
/**
 * _swap - swaps the top two elements of the stack
 * @stack: address of pointer of the element af the top of the stack
 * @line_number: number of the line in the file
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr1, *ptr2;

	if (len_of_the_stack(stack) < 2)
	{
		_free_stack(stack);
		free_line_t();
		free(monty_data);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr1 = *stack;
	ptr2 = (*stack)->next;
	ptr1->next = ptr2->next;
	if (len_of_the_stack(stack) > 2)
		ptr2->next->prev = ptr1;
	ptr1->prev = ptr2;
	ptr2->next = ptr1;
	ptr2->prev = NULL;
	*stack = ptr2;
}
