#include <stdio.h>
/**
  *main - entry point
  *Description: 'prints lowercase & uppercase alphabets'
  *Return: always 0 (success)
  */
int main(void)
{
	int lc = 97;
	int uc = 65;

	while (lc <= 122)
	{
		putchar(lc);
		lc++;
	}
	while (uc <= 90)
	{
		putchar(uc);
		uc++;
	}
	putchar('\n');
	return (0);
}

