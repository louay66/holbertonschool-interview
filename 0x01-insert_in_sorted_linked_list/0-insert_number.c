#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node -  inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *tmp;

	if (!(*head))
	{
		return (NULL);
	}
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	{
		return (NULL);
	}
	if (((*head)->n > number))
	{
		new_node->n = number;
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	tmp = *head;

	while (tmp && tmp->next->n < number)
	{
		tmp = tmp->next;
	}
	new_node->n = number;
	new_node->next = tmp->next;
	tmp->next = new_node;
	return (new_node);
}
