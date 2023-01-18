#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_node(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * is_palindrome - check if the list is palinrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if list is palindrom return 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	listint_t *count, *cur;

	count = *head;
	cur = *head;
	listint_t *part1 = NULL;
	listint_t *part2 = NULL;
	int i = 0;
	int j = 0;

	while (count)
	{
		i++;
		count = count->next;
	}

	if (i % 2 != 0)
		return (0);

	while (cur)
	{
		if (j < (i / 2))
		{
			add_nodeint_end(&part1, cur->n);
			j++;
		}
		else
		{
			add_node(&part2, cur->n);
		}
		cur = cur->next;
	}
	while (part1 || part2)
	{
		if (part1->n != part2->n)
		{
			free_listint(part1);
			free_listint(part2);
			return (0);
		}
		part1 = part1->next;
		part2 = part2->next;
	}

	return (1);
}
