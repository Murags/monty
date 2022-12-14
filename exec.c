#include "monty.h"
/**
*exec_cmd - calls the correct function to execute
*
*@command: array containing the command
*@line_number: line no being excecuted
*@head: pointer to list
*/
void exec_cmd(char **command, unsigned int line_number, stack_t **head)
{
	int i = 0;
	instruction_t selector[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"nop", nop},
			{"swap", swap},
			{"add", add},
			{"sub", sub},
			{"div", _div},
			{"mul", mul},
			{"mod", mod},
			{"pchar", pchar},
			{NULL, NULL}
		};
	if (_strcmp(command[0], "push") == 0)
	{
		if (len(command) == 2)
		{
			if (_isdigit(command[1]) == 1)
				element = atoi(command[1]);
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	while ((selector + i)->opcode)
	{
		if (_strcmp((selector + i)->opcode, command[0]) == 0)
		{
			(selector + i)->f(head, line_number);
			return;
		}
		i++;
	}
}
