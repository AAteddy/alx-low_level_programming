#include "main.h"
/**
  *_isalpha - checks if the character is a lowercase or uppercase alphabet
  *
  *@c: the character in the ASCII code
  *Return: always 0
  */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
