#include "monty.h"

/**
 * exit_procedure - Execute the procedure of exit
 *
 * @exitNum: The number of exit
 * 0: No argument when the program is execute
 * 1: The file cannot be open
 * 2: Malloc failed
 * 3: Unknow instrcution
 *
 * @line_number: The line number that occur an error
 * @argv: All arguments value passes in the program
 * @opcode: The opcode that occur an error
 */
void exit_procedure(int exitNum, int line_number, char **argv, char *opcode)
{
	free_line_t();
	free(monty_data);
	switch (exitNum)
	{
	case 0:
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	case 1:
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	case 2:
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	case 3:
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	case 4:
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
