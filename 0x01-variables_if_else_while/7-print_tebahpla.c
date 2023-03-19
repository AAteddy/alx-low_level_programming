#include <stdio.h>
/**
  *main - entry point
  *Description: 'printing lowercase alphabets in reverse order'
  *Return: always 0 (success)
  */
int main(void)
{
	int n = 122;

	while (n >= 97)
	{
		putchar(n);
		n--;
	}
	putchar('\n');
	return (0);
}
