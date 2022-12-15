#include "monty.h"
/**
 * get_func - checks string and executes the appropriate function
 * @command: command to execute
 * @head: pointer to stack
 * @n: line number of command
 */
void get_func(char *command, stack_t **head, unsigned int n)
{
	unsigned int i = 0;
	instruction_t commands[] = {
		{"push", push}, {"pall", pall},
		{NULL, NULL}
	};
	while (commands[i].opcode != NULL)
	{
		if (strcmp(commands[i].opcode, command) == 0)
		{
			commands[i].f(head, n);
			return;
		}
		i++;
	}
	if (commands[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", n, command);
		exit(EXIT_FAILURE);
	}
}
