#include "monty.h"
stack_t *head = NULL;
/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL || fd == NULL)
		err(2, argv[1]);
	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = line_tok(buffer, line_number, format);
	}
	free(buffer);
	node_free();
	fclose(fd);
	return (0);
}

/**
 * line_tok - divide the lines into tokens
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format.
 * Return: Returns int
*/

int line_tok(char *buffer, int line_number, int format)
{
	char *opcode, *num;
	const char *delim = "\n\t\r ";

	if (buffer == NULL)
		err(4);
	opcode = strtok(buffer, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	num = strtok(NULL, delim);
	_findfunc(opcode, num, line_number, format);
	return (format);
}
