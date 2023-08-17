#include "lists.h"

/**
 * insert_dnodeint_at_index - A function that inserts a new
 *                            node at a given position.
 * @h: a pointer to the head of the dlistint_t list.
 * @idx: the position to insert the new node.
 * @n: an integer for the new node to hold.
 *
 * Return: NULL - if the function fails.
 *        otherwise - the address of the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp = *h, *new;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		temp = temp->next;
		if (temp == NULL)
			return (NULL);
	}

	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = temp;
	new->next = temp->next;
	temp->next->prev = new;
	temp->next = new;

	return (new);
}
