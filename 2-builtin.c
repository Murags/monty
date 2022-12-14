#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	int count = 0, temp;
	stack_t *curr = *stack;

	if (curr)
	{
		while (curr)
		{
			curr = curr->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
void add(stack_t **stack, unsigned int line_number)
{
	int count = 0, temp;
	stack_t *curr = *stack;

	if (curr)
	{
		while (curr)
		{
			curr = curr->next;
			count++;
		}
		if (count < 2)
		{
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n = temp + (*stack)->n;
        }
        else
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

}
