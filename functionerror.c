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
	switch (error_code)
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
	free_nodes();
	exit(EXIT_FAILURE);
}

void errtwo(int errorstyle, ...)
{
	va_list ag;
	char *ay;
	int ly_num;

	va_start(ag, error_code);
	switch (error_code)
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
	free_nodes();
	exit(EXIT_FAILURE);
}
