#include "monty.h"

void mod(stack_t **stack, unsigned int line_number)
{
	int count = 0, temp;
	stack_t *curr = *stack;

	if (*stack)
	{
		while (curr)
		{
			curr = curr->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
			_free(stack);
			exit(EXIT_FAILURE);
		}
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			_free(stack);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = (*stack)->n % temp;
        }
        else
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		_free(stack);
                exit(EXIT_FAILURE);
        }
}
