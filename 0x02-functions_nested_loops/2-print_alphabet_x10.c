#include "main.h"
/**
  *print_alphabet_x10 - prints the alphabets 10 times
  *
  *Return: always 0
  */
void print_alphabet_x10(void)
{
	int n;
	int m;

	for (n = 1; n <= 10; n++)
	{
		for (m = 97; m <= 122; m++)
		{
			_putchar(m);
		}
		_putchar('\n');
	}
}
