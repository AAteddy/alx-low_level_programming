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
	listint_t *new,
	listint_t *tmp = *head;
	unsigned int i;

	new = malloc(sizeof(listint_t));
	if ((new == NULL) || (head == NULL))
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; tmp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new->next = tmp->next;
			tmp->next = new;
			return (new);
		}
		else
			tmp = tmp->next;
	}

	return (NULL);

}
