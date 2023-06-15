#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - find a loop into linkedlists
 *@head: linkedlist root
 * Return: Always 0
 */
listint_t *find_listint_loop(listint_t *head)
{
	while (head != NULL)
	{
		if (head->next == NULL)
			return (NULL);
		if ((void *)head->next > (void *)head)
			return (head->next);
		head = head->next;
	}
	return (NULL);
}
