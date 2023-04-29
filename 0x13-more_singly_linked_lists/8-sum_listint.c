#include "lists.h"

/**
  * sum_listint - a function that returns the sum of all the data
  *               (n) of a listint_t linked list
  * @head: a pointer address of the head in the list
  *
  * Return: sum of the lists, or
  *         otherwise if the list is empty, NULL
  */
int sum_listint(listint_t *head)
{
	listint_t *tmp;
	int sum = 0;

	tmp = head;
	while (tmp != NULL)
	{
		sum += tmp->n;
		tmp = tmp->next;
	}

	return (sum);
}
