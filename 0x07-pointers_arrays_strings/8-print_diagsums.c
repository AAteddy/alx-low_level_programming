#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints diagonal summaries
 * @a: array to use
 * @size: size of diagonal
 *
 */
void print_diagsums(int *a, int size)
{
	int i;
	int diagnlO = 0;
	int diagnlT = 0;

	for (i = 0; i < size; i++)
	{
		diagnlO += a[(i * size) + i];
		diagnlT += a[(size - 1) + ((size - 1) * i)];
	}
	printf("%d, %d\n", diagnlO, diagnlT);
}
