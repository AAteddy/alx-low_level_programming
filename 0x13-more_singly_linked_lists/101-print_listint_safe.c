#include <stdio.h>
#include "main.h"

size_t loop_ed_listint_length(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
  * loop_ed_listint_length - counts the no. of unique nodes in a
  *                          loop_ed listint_t linked list
  * @head: a pointer points to the head of hte listint_t for a check
  *
  * Return: the no. of unique nodes in the list,
  *         otherwise if the list is not looped - 0
  */
size_t loop_ed_listint_length(const listint_t *head)
{
	const listint_t *high, *low;
	size_t node = 1;

	if ((head == NULL) || (head->next == NULL))
		return (0);

	low = head->next;
	high = (head->next)->next;

	while (high)
	{
		if (low == high)
		{
			low = head;
			while (low != high)
			{
				node++;
				low = low->next;
				high = high->next;
			}

			low = low->next;
			while (low != high)
			{
				node++;
				low = low->next;
			}

			return (node);
		}

		low = low->next;
		high = (high->next)->next;
	}

	return (0);
}

/**
  * print_listint_safe - a function that prints a listint_t linked list
  * @head: pointer points to the head of the listint_t list
  *
  * Return: the no. of nodes in the list
  */
size_t print_listint_safe(const listint_t *head)
{
	size_t node;
	size_t index = 0;

	node = loop_ed_listint_length(head);

	if (node == 0)
	{
		for (head != NULL; node++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
		for (index = 0; index < node; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

	printf("->[%p] %d\n", (void *)head, head->n);
}

return (node);
}
