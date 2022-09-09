#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h> /* exit */
#include <unistd.h> /* write */
#include <string.h>


void parse_line(char *line, unsigned int line_number);
void check_file(int num, char *name, FILE **file)
{

	if (num != 2)
	{
		perror("USAGE: ./monty [file]");
		exit (EXIT_FAILURE);
	}
	else
	{
		if (!(*file = fopen(name, "r")))
		{
			write(2, name, strlen(name));
			perror(" doesn't exist");
			exit (EXIT_FAILURE);
		}
		else
		{
			printf("%s exists\n", name);
		}
	}
}
void parse_line(char *line, unsigned int line_number)
{
	char *token;
	int numtok = 0;

	token = strtok(line, " \t\n\r;:");
	while (token != NULL)
	{
		printf("On line %d, token %d is %s\n",\
				line_number, numtok + 1, token);
		numtok++;
		if (numtok == 2)
			break;
		token = strtok(NULL, " \t\n\r;:");
	}
}


void parse_file(FILE **file)
{
	char *line = NULL;
	size_t len = 0;
	int numchar;
	unsigned int line_number = 0;

	printf("\nGotten here\n");
	while ((numchar = getline(&line, &len, *file)) != -1)
	{
		line_number++;
		printf("%d\t:%s", line_number, line);
		parse_line(line, line_number);
	}
}

int main(int argc, char **argv)
{
	FILE *file;

	check_file(argc, argv[1], &file);
	parse_file(&file);
	fclose(file);
	return (0);
}
