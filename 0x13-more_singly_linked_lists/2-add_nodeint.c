#include "lists.h"
/**
  * add_nodeint - a function that adds a new node at the
  *               beginning of a listint_t list
  * @head: a pointer to the address of the first node (head) in the list
  * @n: integer value to be inserted in that new node
  *
  * Return: address to the new node, or NULL if it fails
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	else
	{
		new->n = n;
		new->next = *head;
		*head = new;
	}
	return (new);
}
