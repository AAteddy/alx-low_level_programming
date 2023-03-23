#include "main.h"
/**
  *print_numbers - a function that prints from 0 to 9
  *
  */
void print_numbers(void)
{
	char n;

	for (n = '0'; n <= '9'; n++)
	{
		_putchar(n);
	}

	_putchar('\n');
}
