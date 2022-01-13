#include "monty.h"

/**
 * exit_procedure - Execute the procedure of exit
 *
 * @exitNum: The number of exit
 * 0: No argument when the program is execute
 * 1: The file cannot be open
 * 2: Malloc failed
 * 3: Unknow instrcution
 * 4: Wrong value for push
 *
 * @line_number: The line number that occur an error
 * @argv: All arguments value passes in the program
 * @opcode: The opcode that occur an error
 */
void exit_procedure(int exitNum, int line_number, char **argv, char *opcode)
{
	switch (exitNum)
	{
	case 0:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 1:
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		break;
	case 2:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 3:
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		break;
	case 4:
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		break;
	}
	if (exitNum > 2)
	{
		free_line_t();
		fclose(monty_data->fd);
		free(monty_data);
	}
	exit(EXIT_FAILURE);
}
