#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
  *main - a program that adds positive numbers
  *@argc: The number of arguments supplied to the program
  *@argv: An array of pointers to the arguments
  *
  *Return: If the program receives two arguments - 0
  *        If the program does not receive two arguments - 1
  */
int main(int argc, char *argv[])
{
	int sum = 0;
	int i, digit;

	for (i = 1; i < argc; i++)
	{
		for (digit = 0; argv[i][digit]; digit++)
		{
			if (argv[i][digit] < '0' || argv[i][digit] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}

