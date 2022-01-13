#include "monty.h"
/**
 * _rotl - rotates the stack to the top.
 * @stack: address of pointer of the element af the top of the stack
 * @line_number: number of the line in the file
 */
void _rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{

	stack_t *temp1, *temp2;

		if (*stack != NULL && len_of_the_stack(&*stack) > 1)
	{
		temp1 = temp2 = *stack;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		temp2->next = temp1;
		temp1->prev = temp2;
		temp1->next = NULL;
	}
}
