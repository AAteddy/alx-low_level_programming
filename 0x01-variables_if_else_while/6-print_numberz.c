#include <stdio.h>
/**
  *main - entry point
  *Description: 'printing single digit numbers with putchar'
  *Return: always 0 (success)
  */
int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		putchar(i + 48);
	}
	putchar('\n');
	return (0);
}
