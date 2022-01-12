#include "monty.h"
/**
 * len_of_the_stack - counts number of nodes in the stack
 * @stack: address of pointer of the element af the top of the stack
 *
 * Return: number of nodes in the stack
 */
int len_of_the_stack(stack_t **stack)
{
	stack_t *temp;
	int len = 0;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}
