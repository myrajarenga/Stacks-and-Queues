#include "monty.h"
/**
 * main - entry point of the program
 * @argv:pointer to arguments
 * @argc: number of arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE  *fp = NULL;
	char *buff = NULL;
	char *s;
	stack_t *head = NULL;
	unsigned int n = 1;
	size_t len = 1;

	if  (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Cant open file %s\n", argv[1]);
		exit(EXIT_FAILURE);	
	}
	while (getline(&buff, &len, fp) != -1)
	{
		s = strtok(buff, " \t\n");
		if (s != NULL)
			get_func(s, &head, n);
		n++;
	}
	free(buff);
	free(fp);
	free(head);
	return (0);
}
