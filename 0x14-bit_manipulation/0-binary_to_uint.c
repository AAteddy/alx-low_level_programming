#include "main.h"

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
	unsigned int value = 0, prod = 1;
	int len;

	if (b == '\0')
	{
		return (0);
	}
	for (len = 0; b[len];)
		len++;

	for (len -= 1; len >= 0; len--)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		value += (b[len] - '0') * prod;
		prod *= 2;
	}

	return (value);
}
