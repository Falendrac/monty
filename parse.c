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
	int buffer_size = 1086, rd, i = 0, j, diff = 0;
	char buffer[1086];
	char line[256] = { '\0' };

	rd = read(monty_data->fd, buffer, buffer_size);
	buffer[rd] = '\0';

	while (i < rd)
	{
		line[i - diff] = buffer[i];
		i++;
		if (buffer[i] == '\n')
		{
			parse(line);
			for (j = 0; j < 256; j++)
				line[j] = '\0';
			i++;
			diff = i;
		}
	}
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
		comm = strtok(line, " \t");
		value = strtok(NULL, " \t");

		comm = _strdup(comm);
		value = _strdup(value);
		if (comm != NULL)
			new_line_t_end(comm, value);
	}
}
