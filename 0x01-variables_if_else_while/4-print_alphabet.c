#include <stdio.h>
/**
  *main - entry point
  *Description: 'printing all lowercase alphabets except q & e'
  *Return: always 0 (success0
  */
int main(void)
{
	int n = 97;

	while (n <= 122)
	{
		if (n == 101 || n == 113)
		{
			n++;
			continue;
		}
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}
