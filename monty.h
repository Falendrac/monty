#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct command_line - All command line the program get in a monty program
 *
 * @line_number: The line number of the current node
 * @commands: The commands of the current node
 * @value: The value of the commands
 * @next: The next node of a line_t list
 * @prev: The previous node of a line_t list
 */
typedef struct command_line
{
	int line_number;
	char *commands;
	char *value;
	struct command_line *next;
	struct command_line *prev;
} line_t;

/**
 * struct data_jf - Data we need in all programm
 *
 * @fd: File descriptor we open
 * @commands: All commands we have in the file
 * @value: All value associate with commands
 */
typedef struct data_jf
{
	int fd;
	line_t *commands;
} data;

extern data *monty_data;

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strdup(char *str);

/* functions for the stack*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **head);
void free_stack(stack_t **head);

/* Functions for the main program */
void exit_procedure(int exitNum, int line_number, char **argv, char *opcode);
line_t *new_line_t_end(char *commands, char *value);
void free_line_t(void);
void take_line(void);
void parse(char *line);
void (*_get_func(line_t *current))(stack_t **stack, unsigned int line_number);
void execute_monty(void);

/*utils function*/
int len_of_the_stack(stack_t **stack);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
#endif /*__MONTY_H__*/
