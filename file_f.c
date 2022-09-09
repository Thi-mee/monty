#include "monty.h"

/**
 * checkAndOpenFile - checks if file exists and opens it
 *
 * @argc: number of program arguments
 * @name: name of file
 * @file: file
 *
 * Return: void
 */
void checkAndOpenFile(int argc, char *name, FILE **file)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		*file = fopen(name, "r");
		if (!(*file))
		{
			fprintf(stderr, "Error: Can't open file %s\n", name);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * parseLine - Parses a line into commands
 *
 * @line: line to be parsed
 *
 * Return: array of command
 */
char **parseLine(char *line)
{
	char **cmds, *token, *delims;
	int i = 0;

	delims = "\t \n";
	cmds = malloc(sizeof(char *) * 3);
	if (cmds == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delims);
	while (token != NULL && i < 2)
	{
		cmds[i] = token;
		token = strtok(NULL, delims);
		i++;
	}
	return (cmds);
}

/**
 * parseAndProcess - processes the line in file
 *
 * @buff: line from the file
 * @stack: top of stack
 * @line_no: Line number
 *
 * Return: void
 */
void parseAndProcess(char *buff, stack_t **stack, unsigned int line_no)
{
	char **command;
	void (*f)(stack_t**, unsigned int);
	int i = 0;

	command = parseLine(buff);
	if ((strncmp(command[0], "push", 4)) == 0)
	{
		if (command[1] == NULL || check_for_digit(command[1]) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			free(command), freeStack(stack);
			exit(EXIT_FAILURE);
		}
		else
			push(stack, atoi(command[1]));
	}
	else
	{
		while (command[i] != NULL)
		{
			f = handle_opcodes(command[0]);
			if (f == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_no, command[i]);
				free(command), freeStack(stack);
				exit(EXIT_FAILURE);
			}
			else
				f(stack, line_no);
			i++;
		}
	}
	free(command);
}
