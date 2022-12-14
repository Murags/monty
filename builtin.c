#include "monty.h"

int element;
/**
*push - adds element to the stack
*
*@stack: pointer to list
*@line_number: line no being executed
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return;

	new->n = element;
	new->prev = NULL;
	new->next = *stack;
	*stack = new;

	if (new->next != NULL)
		new->next->prev = new;
}
/**
*pall - prints all elements in the list
*
*@line_number: line number being executed
*@stack: pointer to list
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (*stack == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
