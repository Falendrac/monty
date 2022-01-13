#include "monty.h"
/**
 * _rotr - rotates the stack to the bottom.
 * @stack: address of pointer of the element af the top of the stack
 * @line_number: number of the line in the file
 */
void _rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{

	stack_t *temp1, *temp2;

	if (*stack != NULL && len_of_the_stack(&*stack) > 1)
	{
		temp1 = temp2 = *stack;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->prev->next = NULL;
		temp2->next = temp1;
		temp2->prev = NULL;
		temp1->prev = temp2;
		*stack = temp2;
	}
}
