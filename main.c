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
	int fd;


	if (argc == 1 || argc > 2)
		exit_procedure(0, 0, argv, NULL);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_procedure(1, 0, argv, NULL);

	monty_data = malloc(sizeof(data));
	if (monty_data == NULL)
		exit_procedure(2, 0, argv, NULL);

	monty_data->fd = fd;
	monty_data->commands = NULL;

	take_line();
	execute_monty();

	free_line_t();
	free(monty_data);
	close(fd);

	return (0);
}
