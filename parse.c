#include "monty.h"
#include "string.h"

/**
 * take_line - Read all the file and integrate the content in a buffer
 * of size 1086.
 * Parse the buffer line by line and call another function for parse with
 * strtok.
 *
 */
void take_line(void)
{
	int buffer_size = 1024;
	char buffer[1024];

	while (fgets(buffer, buffer_size, monty_data->fd) != NULL)
		parse(buffer);

}

/**
 * parse - Parse the current line with space and tab separators
 *
 * @line: Current line for parsing
 */
void parse(char *line)
{
	char *comm, *value;

	if (line != NULL)
	{
		comm = strtok(line, " \t\n");
		value = strtok(NULL, " \t\n");

		comm = _strdup(comm);
		value = _strdup(value);
		if (comm != NULL)
			new_line_t_end(comm, value);
	}
}
