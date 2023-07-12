#include "list.h"

/**
 * add_node_end - Add a new node at the begining
 * of a double circular linked list
 * @list: Pointer to the list to modify
 * @str: The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	return (add_node_end(list, str) ? *list = (*list)->prev : NULL);
}
/**
 * add_node_end - Add a new node at the end of a double circular linked list
 * @list: Pointer to the list to modify
 * @str: The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_end(List **list, char *str)
{
	List *end, *new;

	if (!list || !str)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	if (!(*list))
	{
		*list = new;
		new->next = new->prev = new;
	}
	else
	{
		end = (*list)->prev;

		new->prev = end;
		new->next = (*list);
		end->next = (*list)->prev = new;
	}

	return (new);
}
