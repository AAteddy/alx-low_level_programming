#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
  *main - a program that multiplies two numbers
  *@argc: The number of arguments supplied to the program
  *@argv: An array of pointers to the arguments
  *
  *Return: always 0 (success)
  */
int main(int argc, char *argv[])
{
	int product, num1, num2;

	if (argc <= 2)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		num1 = argv[1];
		num2 = argv[2];
		product = num1 * num2;
		printf("%d\n", product);
	}
	return (0);
}
