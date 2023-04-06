#include <stdio.h>
#include <stdlib.h>
#include "search.h"
/**
 * one_by_one - check next by next
 * @head: express line node
 * @value: value to compare
 *
 * Return: node founded
 */
skiplist_t *one_by_one(skiplist_t *head, int value)
{
	skiplist_t *current = head;

	if (!head)
		printf("n head nullll");
	while (current)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}

	return (NULL);
}

/**
 * linear_skip - found a value in skip list
 * @head: express line node
 * @value: value to compare
 *
 * Return: node founded
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *last, *skip;

	if (!head || !value)
		return (NULL);
	skip = head;
	while (skip)
	{
		if (skip->express)
		{
			printf("Value checked at index [%lu] = [%d]\n",
					 skip->express->index, skip->express->n);
			if (skip->express->n >= value)
			{
				printf("Value found between indexes[%lu] and [%lu]\n",
						 skip->index, skip->express->index);
				return (one_by_one(skip, value));
			}
			if (!skip->express->express)
			{
				last = skip->express;
				while (last->next != NULL)
					last = last->next;
				printf("Value found between indexes[%lu] and [%lu]\n",
						 skip->express->index, last->index);
				return (one_by_one(skip->express, value));
			}
		}
		skip = skip->express;
	}
	return (NULL);
}
