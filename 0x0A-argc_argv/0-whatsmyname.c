#include "main.h"
#include <stdio.h>
#define UNUSED(x) (void)(x)
/**
  *main - a program that prints its name, followed by a new line
  *@argc: number of arguments which are supplied to the program
  *@argv: an array of pointers to the program
  *
  *Return: always 0
  */
int main(int argc, char *argv[])
{
	UNUSED(argc);
	printf("%s\n", argv[0]);
}
