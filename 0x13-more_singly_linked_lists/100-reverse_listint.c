#include "lists.h"

/**
  * reverse_listint - a function that reverses a listint_t linked list
  * @head: a pointer to the address of the head in the list
  *
  * Return: a pointer to the first node of the reversed list
  */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prevs = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prevs;
		prevs = *head;
		*head = next;
	}

	*head = prevs;

	return (*head);
}
