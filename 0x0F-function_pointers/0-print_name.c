#include "function_pointers.h"
/**
 * print_name - a function that prints the name
 * @name: name to be print
 * @f: function to use
 *
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
