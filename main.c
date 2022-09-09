#include "monty.h"

/**
 * main - beginning of function
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 is success.
 */

int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	size_t bufsize;
	char *buffer = NULL;
	FILE *fp;
	stack_t *stack = NULL;

	checkAndOpenFile(argc, argv[1], &fp);
	while ((getline(&buffer, &bufsize, fp)) != -1)
	{
		line_number++;
		if (strcmp(buffer, "\n") == 0)
			continue;
		else
		{
			parseAndProcess(buffer, &stack, line_number);
		}
	}
	if (buffer == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}

	free(buffer);
	freeStack(&stack);
	fclose(fp);
	return (0);
}
