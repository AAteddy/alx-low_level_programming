#include "lists.h"

/**
 * print_dlistint - A function that prints all the elements
 *                  of a dlistint_t list.
 * @h: the head of the dlistint_t list.
 *
 * Return: the number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t node = 0;

	while (h)
	{
		node++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (node);
}
