#include "monty.h"
/**
*main - entry of the program
*
*@argc: number of arguments
*@argv: argument vectors
*
*Return: 0
*/
int main(int argc, char **argv)
{
	FILE *f;
	char line[1024];
	char **command;
	unsigned int line_number = 1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fgetc(f) == EOF)
	{
		fprintf(stderr, "Error: %s file empty\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, 1024, f) != NULL)
	{
		command = parser(line);
		if (check_line(command) == -1)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, command[0]);
			exit(EXIT_FAILURE);
		}
		exec_cmd(command, line_number, &head);
		line_number++;
	}
	fclose(f);
	return (0);
}
/**
*parser- parses the commmand input
*
*@buffer: string containing command
*
*Return: Parsed command
*/
char **parser(char *buffer)
{
	char **cmd, *token;
	int i;

	if (buffer == NULL)
		return (NULL);

	token = strtok(buffer, " \t\n");
	if (token == NULL)
		return (NULL);

	cmd = malloc(sizeof(char *) * 1024);

	i = 0;
	while (token)
	{
		cmd[i++] = token;
		token = strtok(NULL, " \n");
	}
	cmd[i] = NULL;
	return (cmd);
}
