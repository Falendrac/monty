#include "monty.h"

/**
 * new_line_t_end - Add a node at the end in line_t list
 *
 * @commands: Commands catch with getline
 * @value: Value associate with the commands
 * @line_number: The line number of the command
 *
 * Return: NULL if malloc fail, new node otherwise
 */
line_t *new_line_t_end(char *commands, char *value, int line_number)
{
	line_t *new, *current;

	new = malloc(sizeof(line_t));
	if (new == NULL)
		exit_procedure(2, 0, NULL, NULL);

	new->commands = commands;
	new->value = value;
	new->line_number = line_number;
	new->next = NULL;
	new->prev = NULL;

	if (monty_data->commands == NULL)
	{
		monty_data->commands = new;
		return (new);
	}
	else
	{
		current = monty_data->commands;

		while (current->next != NULL)
			current = current->next;

		new->prev = current;
		current->next = new;
	}

	return (new);
}

/**
 * free_line_t - Free a line_t list
 *
 */
void free_line_t(void)
{
	line_t *current;

	while (monty_data->commands != NULL)
	{
		current = monty_data->commands;
		monty_data->commands = monty_data->commands->next;
		free(current->commands);
		free(current->value);
		free(current);
	}
}

