#include "monty.h"

/**
 * err - Prints appropiate error messages determined by their error code.
 * @errorstyle: error cases in the follwing
 */
void err(int errorstyle, ...)
{
	int ly_num;
	va_list ag;
	char *ay;

	va_start(ag, errorstyle);
	switch (errorstyle)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			ly_num = va_arg(ag, int);
			ay = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ly_num, ay);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
			case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}
/**
 * errtwo - Prints appropiate error messages determined by their error code.
 * @errorstyle: error cases in the follwing
 */
void errtwo(int errorstyle, ...)
{
	va_list ag;
	char *ay;
	int ly_num;

	va_start(ag, errorstyle);
	switch (errorstyle)
	{
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			ly_num = va_arg(ag, unsigned int);
			ay = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", ly_num, ay);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}

/**
 * errthree - handles errors.
 * @errorstyle: The error codes are the following:
 */
void errthree(int errorstyle, ...)
{
	va_list ag;
	int ly_num;

	va_start(ag, errorstyle);
	ly_num = va_arg(ag, int);
	switch (errorstyle)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ly_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ly_num);
			break;
		default:
			break;
	}
	node_free();
	exit(EXIT_FAILURE);
}
