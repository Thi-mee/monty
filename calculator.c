#include "monty.h"

/**
 * add - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/
void add(stack_t **stack, unsigned int line_number)
{
	unsigned int sum;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, sum);
}

/**
 * sub - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/
void sub(stack_t **stack, unsigned int line_number)
{
	unsigned int res;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = (*stack)->next->n - (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, res);
}

/**
 * division - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/
void division(stack_t **stack, unsigned int line_number)
{
	unsigned int divide;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	divide = (*stack)->next->n / (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, divide);
}

/**
 * mul - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/
void mul(stack_t **stack, unsigned int line_number)
{
	unsigned int power;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	power = (*stack)->next->n * (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, power);
}

/**
 * mod - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/
void mod(stack_t **stack, unsigned int line_number)
{
	unsigned int module;
	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	module = (*stack)->next->n % (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, module);
}
