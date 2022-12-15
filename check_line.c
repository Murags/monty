#include "monty.h"
/**
*check_line - checks if command exist
*
*@command: array of commands
*
*Return: 0 if true else -1
*/
int check_line(char **command)
{
	int i = 0;
	char *array[] = {"push", "pall", "pint", "pop", "nop", "swap", "add", "sub", "div", "mul", "mod", "pchar", "pstr", "rotl", NULL};

	while (array[i])
	{
		if (_strcmp(array[i], command[0]) == 0)
			return (0);
		i++;
	}
	return (-1);
}
