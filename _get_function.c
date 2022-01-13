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
	    {"pint", _pint},
	    {"swap", _swap},
	    {"add", _add},
	    {"nop", _nop},
	    {"sub", _sub},
	    {"div", _div},
	    {"mul", _mul},
	    {"mod", _mod},
	    {"pchar", _pchar},
	    {"pstr", _pstr},
	    {"rotl", _rotl},
	    {"rotr", _rotr},
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
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;

	current = monty_data->commands;

	while (current != NULL)
	{
		if (current->commands[0] != '#')
		{
			f = _get_func(current);
			if (f == NULL)
			{
				_free_stack(&stack);
				exit_procedure(3, current->line_number, NULL, current->commands);
			}
			monty_data->current = current;
			f(&stack, current->line_number);
		}
		current = current->next;
	}
	_free_stack(&stack);
}
