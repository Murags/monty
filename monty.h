#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int element;

void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int linenumber);
void swap(stack_t **stack, unsigned int linenumber);
void add(stack_t **stack, unsigned int linenumber);
void sub(stack_t **stack, unsigned int linenumber);
void _div(stack_t **stack, unsigned int linenumber);
void mul(stack_t **stack, unsigned int linenumber);

int _strcmp(char *s1, char *s2);
int len(char **c);
int _isdigit(char *c);
int check_line(char **command);
char **parser(char *buffer);
void exec_cmd(char **command, unsigned int line_number, stack_t **head);

#endif
