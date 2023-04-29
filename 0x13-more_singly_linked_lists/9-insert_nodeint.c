#include "lists.h"

/**
  * insert_nodeint_at_index - a function that inserts a new
  *                           node at a given position
  * @head: a pointer to the address of the head in the list
  * @idx: is the index of the list where the new node
  *       should be added. Index starts at 0
  * @n: integer value of the new node to be inserted
  *
  * Return: address of the new node, or
  *         if the function fails NULL
  */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *copy = *head;
	unsigned int node;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = copy;
		*head = new;
		return (new);
	}

	for (node = 0; node < (idx - 1); node++)
	{
		if (copy == NULL || copy->next == NULL)
			return (NULL);

		copy = copy->next;
	}

	new->next = copy->next;
	copy->next = new;

	return (new);
}

