#include "main.h"
/**
  *_abs - a function that computes
  *absolute value of an integer
  *
  *@n: input number as an integer
  *Return: always 0
  */
int _abs(int n)
{
	if (n >= 0)
	{
		return (n);
	}
	else
	{
		return (n * -1);
	}
}
