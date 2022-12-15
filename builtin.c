#include "monty.h"

/*global_t global;*/
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

	new->n = global.element;
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
/**
*pint - prints top element on stack
*
*@stack: pointer to list
*@line_number: line no
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		_free(stack);
		fclose(global.fd);
		exit(EXIT_FAILURE);
	}
}
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (!curr)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = curr->next;
		if (*stack)
			(*stack)->prev = NULL;
	}
	free(curr);
}
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
