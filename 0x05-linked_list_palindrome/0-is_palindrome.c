#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check if the list is palinrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if list is palindrom return 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast;
	int *stack, i = -1;

	slow = fast = *head;
	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);

	stack = malloc(sizeof(int) * 1024);

	while (fast && fast->next)
	{
		stack[++i] = slow->n;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast)
		slow = slow->next;

	while (slow)
	{
		if (stack[i--] != slow->n)
		{
			free(stack);
			return (0);
		}
		slow = slow->next;
	}

	free(stack);
	return (1);
}
