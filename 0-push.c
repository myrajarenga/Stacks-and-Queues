#include "monty.h"
/**
 * push - pushes an element to stack
 * @head: address of pointer
 * @n: line number
 * Return: void
 */
void push(stack_t **head, unsigned int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	char *s = strtok(NULL, " \t\n");
	int i;
	int retval;

	for (i = 0; s[i]; i++)
	{
		if (i == 0 && s[i] == '-')
			continue;
		if (isdigit(s[i]) == 0)
			retval = 1;
		else
		{
			retval = 0;
		}
	}
	if (s == NULL || retval == 1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!head)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(s);
	new_node->prev = NULL;
	new_node->next = *head;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * pall - prints all elements
 * @head: pointer to stack
 * @n: linenum of operation
 * Return: void
 */
void pall(stack_t **head, unsigned int n)
{
	stack_t *temp;
	(void) n;

	if (head == NULL || (*head) == NULL)
		return;
	for (temp = *head; temp != NULL; temp = temp->next)
		printf("%d\n", temp->n);
}


