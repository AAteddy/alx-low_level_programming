#include "lists.h"

/**
  * free_listint - a function that frees a listint_t list
  * @head: a pointer to the head of the list to be freed
  */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != Null)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
