#include "monty.h"

/**
 * nop - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/
void nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * pchar - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int letter;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	letter = (*stack)->n;

	if (letter >= 0 && letter <= 255)
	{
		putchar(letter);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range,\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	int string;
	stack_t *tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	while (tmp)
	{
		string = tmp->n;
		if (string > 0 && string <= 127)
			putchar(string);
		else
			break;
		tmp = tmp->next;
	}
	putchar('\n');
}
