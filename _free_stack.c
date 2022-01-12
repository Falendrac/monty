#include "monty.h"
/**
 * free_stack - delete all nodes of the stack
 * @head: address of the pointer of the element at the top pf the stack
 */
void free_stack(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
		return;
	while (head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
