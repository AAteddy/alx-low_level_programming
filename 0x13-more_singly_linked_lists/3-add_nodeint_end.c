#include "lists.h"
/**
  * add_nodeint_end - a function that adds a new node at the
  *                   end of a listint_t list
  * @head: a pointer to the address of the head in the list
  * @n: integer value to be inserted as a new node
  *
  * Return: address to the new node, or if it fails NULL
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *last;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	else
	{
		new->n = n;
		new->next = NULL;
	}
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	else
	{
		last = *head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;

		return (new);
	}
}
