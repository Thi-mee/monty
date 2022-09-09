#include "monty.h"

/**
 * handle_opcodes - function that finds functions for\
 * respective opcodes
 *
 * @func: first bytecode input
 *
 * Return: NULL of function associated
 */
void (*handle_opcodes(char *func))(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	instruction_t op_fs[] = {
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", division},
		{"mod", mod},
		{"nop", nop},
		{NULL, NULL}
	};
	while (op_fs[i].opcode != NULL)
	{
		if (strcmp(op_fs[i].opcode, func) == 0)
			return (op_fs[i].f);
		i++;
	}
	return (NULL);
}
