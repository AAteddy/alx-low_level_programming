#include "main.h"
/**
  *factorial - a function that returns the factorial of a given number
  *@n: the number to be found a factor of
  *
  *Return: returns a factor or -1
  */
int factorial(int n)
{
	int fact = n;

	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (1);
	}
	else
	{
		fact = n * factorial(n - 1);
	}
	return (fact);
}
