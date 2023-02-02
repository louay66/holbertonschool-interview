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

	while (node && node->next)
	{
		list = list->next;
		node = node->next->next;
		if (node == list)
			return (1);
	}
	return (0);
}
