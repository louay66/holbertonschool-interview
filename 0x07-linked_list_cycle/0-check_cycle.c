#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - check if linked list is cycle or not
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *node = list;
	int *addres[200];
	int i = -1;
	int j;
	int count = 0;

	if (list == NULL)
		return (1);

	while (node != NULL)
	{
		count++;
		addres[i++] = &node->n;
		for (j = 0; j <= count; j++)
		{
			if (addres[j] == &node->next->n)
			{
				return (1);
			}
		}
		node = node->next;
	}
	return (0);
}
