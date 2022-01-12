#include "monty.h"

/**
 * _strdup - Allocated a newly space in memory and copy a
 * string given as a parameter
 *
 * @str: The string we copy
 *
 * Return: new_str
 */
char *_strdup(char *str)
{
	char *new_str;
	int strLength, loop;

	if (str == NULL)
		return (NULL);

	strLength = strlen(str) + 1;
	new_str = malloc(sizeof(char) * strLength);

	if (new_str == NULL)
		return (NULL);

	for (loop = 0 ; loop < strLength; loop++)
		*(new_str + loop) = *(str + loop);

	return (new_str);
}
