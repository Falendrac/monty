#include "monty.h"
/**
 * _push - add node at the beginnig of the stack
 * @stack: address of pointer of the element af the top of the stack
 * @line_number: number of the line in the file
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int value;
	line_t *current = monty_data->commands;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit_procedure(2, 0, NULL, NULL);
	if (len(monty_data->value[line_number]) == 1)
	{
		if (monty_data->value[line_number][0] == 48)
			new->n = 0;
		else
			new->n = atoi(monty_data->value[line_number]);
	}
	new->n = atoi(monty_data->value[line_number]);
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
