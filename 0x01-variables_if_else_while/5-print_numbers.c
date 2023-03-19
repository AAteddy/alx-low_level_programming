#include <stdio.h>
/**
  *main - entry point
  *Description: 'printing all single digit numbers'
  *Return: always 0 (success)
  */
int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		printf("%d", i);
	}
	printf("\n");
	return (0);
}
