#include "lists.h"

/**
  * free_listint_safe - a function that frees a listint_t list
  * @h: a pointer to the first node in the list
  *
  * Return: the size of the list that was free’d
  */
size_t free_listint_safe(listint_t **h)
{
	size_t length = 0;
	int diff;
	listint_t *tmp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			length++;
		}
		else
		{
			free(*h);
			*h = NULL;
			length++;
			break;
		}
	}

	*h = NULL;

	return (length);
}
