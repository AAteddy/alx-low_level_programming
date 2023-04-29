#include "lists.h"

/**
  * get_nodeint_at_index - a function that returns the nth node of
  *                        a listint_t linked list
  * @head: a pointer to the head of the list
  * @index: is the index of the node, starting at 0
  *
  * Return: the located node or
  *         otherwise if the node does not exist, NULL
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
	}

	return (head);
}
