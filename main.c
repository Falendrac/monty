#include "monty.h"
data *monty_data;

/**
 * main - The main function for monty project
 *
 * @argc: Argument count
 * @argv: All arguments values
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fd;

	if (argc == 1 || argc > 2)
		exit_procedure(0, 0, argv, NULL);

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		exit_procedure(1, 0, argv, NULL);

	monty_data = malloc(sizeof(data));
	if (monty_data == NULL)
		exit_procedure(2, 0, argv, NULL);

	monty_data->fd = fd;
	monty_data->commands = NULL;
	monty_data->current = NULL;

	take_line();
	execute_monty();

	free_line_t();
	free(monty_data);
	fclose(fd);

	return (EXIT_SUCCESS);
}
