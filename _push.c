#include "monty.h"

/**
 * _is_number - Search if the string value is a number
 *
 * Return: 0 if is not a number, 1 if is a number
 */
int _is_number(void)
{
	char *value = monty_data->current->value;
	int i = 0, boolean = 1;

	if (value[i] == '-' || value[i] == '+')
		i++;
	while (value[i] != '\0')
	{
		if (value[i] < '0' || value[i] > '9')
		{
			boolean = 0;
			break;
		}
		i++;
	}
	if (i == 0 || (i == 1 && value[i - 1] <= '-'))
		boolean = 0;

	return (boolean);
}

/**
 * _add_to_stack_t - Add an element in the stack or in the queue
 * check the data monty_data
 *
 * @stack: address of pointer of the element af the top of the stack
 * @new: The new element adding in the stack/queue
 */
void _add_to_stack_t(stack_t **stack, stack_t *new)
{
	stack_t *current;

	if (monty_data->order == STACK)
	{
		(*stack)->prev = new;
		new->prev = NULL;
		new->next = *stack;
		*stack = new;
	}
	else if (monty_data->order == QUEUE)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;

		current->next = new;
		new->prev = current;
		new->next = NULL;
	}
}

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
		_add_to_stack_t(stack, new);
}

