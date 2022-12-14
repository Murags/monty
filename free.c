#include "monty.h"

void _free(stack_t **stack)
{
	stack_t *tmp;

	while ((*stack))
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
}
