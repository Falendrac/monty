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

	if (current->value == NULL || _is_number() == 0)
	{
		_free_stack(stack);
		exit_procedure(4, line_number, NULL, NULL);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		_free_stack(stack);
		exit_procedure(2, line_number, NULL, NULL);
	}
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

/**
 * _is_number - Search if the string value is a number
 *
 * Return: 0 if is not a number, 1 if is a number
 */
int _is_number(void)
{
	char *value = monty_data->current->value;
	int i = 0, boolean = 1;

	while (value[i] != '\0')
	{
		if (value[i] < '0' || value[i] > '9')
		{
			boolean = 0;
			break;
		}
		i++;
	}

	if (i == 0)
		boolean = 0;

	return (boolean);
}
