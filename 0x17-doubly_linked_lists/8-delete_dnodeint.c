#include "lists.h"

/**
 * delete_dnodeint_at_index - A function that deletes the node at index
 *                            index of a dlistint_t linked list.
 * @head: A pointer to the head of the dlistint_t.
 * @index: the index of the node to delete.
 *
 * Return: 1 - success
 *         -1 - fail
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (temp == NULL)
			return (-1);
		temp = temp->next;
	}

	if (temp == *head)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		temp->prev->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = temp->prev;
	}

	free(temp);
	return (1);
}
