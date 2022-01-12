#include "monty.h"
/**
 * _push - add node at the beginnig of the stack
 * @stack: address of pointer of the element af the top of the stack
 * @line_number: number of the line in the file
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	line_t *current = monty_data->current;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit_procedure(2, line_number, NULL, NULL);
	if (strlen(current->value) == 1)
	{
		if (current->value[0] == 48)
			new->n = 0;
		else
			new->n = atoi(current->value);
	}
	new->n = atoi(current->value);
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		(*stack)->prev = new;
		new->prev = NULL;
		new->next = *stack;
		*stack = new;
	}
}
