#include "main.h"

/**
  * get_bit - a function that returns the value of a bit at a given index
  * @index: is the index, starting from 0 of the bit you want to get
  * @n: the no. to be serached
  *
  * Return: the value of the bit at index index
  *         otherwise -1 if an error occured
  */
int get_bit(unsigned long int n, unsigned int index)
{
	int value;

	if (index > 32)
		return (-1);

	value = (n >> index & 1);

	return (value);
}
