#include "monty.h"

/**
 * _get_func - Target the function by commands
 *
 * @current: The current node of a linked list line_t
 *
 * Return: The function catches, NULL otherwise
 */
void (*_get_func(line_t *current))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruc[] = {
	    {"push", _push},
	    {"pop", _pop},
	    {"pall", _pall},
	    {"swap", _swap},
	    /**{"pint", _push},*/
	    {NULL, NULL}};
	int i = 0;

	while (instruc[i].opcode != NULL)
	{
		if (strcmp(instruc[i].opcode, current->commands) == 0)
			return (instruc[i].f);

		i++;
	}
	return (NULL);
}

/**
 * execute_monty - Functions that execute all commands passes in file
 *
 */
void execute_monty(void)
{
	line_t *current;
	void (*f)(stack_t * *stack, unsigned int line_number);
	stack_t *stack = NULL;

	current = monty_data->commands;

	while (current != NULL)
	{
		f = _get_func(current);
		if (f == NULL)
			exit_procedure(3, current->line_number, NULL, current->commands);

		monty_data->current = current;
		f(&stack, current->line_number);
		current = current->next;
	}
}
