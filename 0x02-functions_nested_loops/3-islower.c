#include "main.h"
/**
  *_islower - checks if c is a lowercase alphabet
  *
  *@c: the character in ascii code
  *Return: always 0
  */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
