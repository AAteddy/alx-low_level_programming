#include "lists.h"

/**
  * pop_listint - a function that deletes the head node of a listint_t
  *               linked list, and returns the head node’s data (n)
  * @head: a pointer to the address of the head in the list
  *
  * Return: if the list is empty 0
  *         otherwise returns the head node’s data (n)
  */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int nodevalue;

	if ((head == NULL) || (*head == NULL))
	{
		return (0);
	}
	nodevalue = (*head)->n;
	tmp = (*head)->next;
	free(*head);
	*head = tmp;

	return (nodevalue);
}
