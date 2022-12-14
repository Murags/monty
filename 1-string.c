#include "main.h"
/**
 * _isdigit - Checks for a digit 0 through 9
 * Return: 0 or 1
 * @c: Variable
 **/
int _isdigit(char *c)
{
	char *aux = c;

	if (c == NULL)
		return (0);
	if (*aux == '-')
		aux++;

	for (; *aux != '\0'; aux++)
	{
		if ((*aux < '0' || *aux > '9'))
		{
			return (0);
		}
	}
	return (1);
}
/**
*len - counts numer of elements in an array
*
*@c: array
*
*Return: number of elements
*/
int len(char **c)
{
	int i = 0;

	while (c[i])
	{
		i++;
	}
	return (i);
}
