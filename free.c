#include "monty.h"
/**
*_free - frees a list
*
*@stack: pointer to list
*/
void _free(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
}
