#include "main.h"
#include <stdio.h>
/**
  *main - a program that prints its name, followed by a new line
  *@argc: number of arguments which are supplied to the program
  *@argv: an array of pointers to the program
  *
  *Return: always 0
  */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	printf("%s\n", argv[0]);

	return (0);
}
