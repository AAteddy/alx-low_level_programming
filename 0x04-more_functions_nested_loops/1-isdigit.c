#include "main.h"
/**
  *_isdigit - a function that checks if a
  *character is a digit (0 - 9)
  *@c: the character to be checked
  *Return: 1 if it is a digit, otherwise 0
  */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
