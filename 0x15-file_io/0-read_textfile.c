#include "main.h"
#include <stdlib.h>

/**
  * read_textfile - a function that reads a text file and prints it
  *                 to the POSIX standard output
  * @filename: a pointer to the name of the text file to be read
  * @letters: the number of letters the function should read & print
  *
  * Return: the actual number of letters it could read and print, or
  *         0 - if the function fails or filename is NULL
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t op, rd, wt;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	op = open(filename, O_RDONLY);
	rd = read(op, buffer, letters);
	wt = write(STDOUT_FILENO, buffer, rd);

	if (op == -1 || rd == -1 || wt == -1 || rd != wt)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(op);

	return (wt);
}



