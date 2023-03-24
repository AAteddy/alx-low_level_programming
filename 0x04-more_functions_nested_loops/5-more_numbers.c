#include "main.h"

/**
  *more_numbers - a function that prints numbers
  *from 0 to 14 ten times
  *
  */
void more_numbers(void)
{
	int n, count;

	for (count = 0; count <= 9; count++)
	{
		for (n = 0; n <= 14; n++)
		{
			if (n > 9)
			{
				_putchar((n / 10) + '0');
			}
			else
			{
				_putchar((n % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
