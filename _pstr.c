#include "monty.h"
/**
 * _pstr - prints the string starting at the top of the stack +  a new line
 * @stack: address of the pointer on the element at the top of the stack
 * @line_number: number of the line in the file
 */

void _pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		(printf("\n"));
		return;
	}
	current = *stack;
	while (current)
	{
		if ((current)->n == 0)
		{
			printf("\n");
			break;
		}
		if ((current)->n >= 0 && (current)->n <= 127)
			printf("%c", (current)->n);
		current = (current)->next;
	}
}
