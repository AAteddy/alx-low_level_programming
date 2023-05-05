#include "main.h"
#include <stdlib>

/**
  * binary_to_uint - a function that converts a binary
  *                  number to an unsigned int
  * @b: is a pointer pointing to a string of 0 and 1 chars
  *
  * Return: If b is NULL or contains chars not 0 or 1 - 0
  *         otherewise the converted no.
  */
unsigned int binary_to_uint(const char *b)
{
	unsigned int value = 0;
	int i;

	if (!b)
	{
		return (0);
	}
	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
		{
			return (0);
		}
		value = 2 * value + (b[i] - '0');
	}

	return (value);
}
