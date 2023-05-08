#include <stdlib.h>
#include <stdio.h>
#include "main.h"

char *create_buff(char *filename);
void close_file(int fd);

/**
  * create_buff - a function that allocates 1024 bytes for a buffer
  * @filename: name of the file buffer used in storing chars
  *
  * Return: a pointer to the newly allocated buffer
  */
char *create_buff(char *filename)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buffer);
}

/**
  * close_file - closes the file discriptor
  * @fd: the file descriptor to be closed
  */
void close_file(int fd)
{
	int cls;

	cls = close(fd);

	if (cls == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
			exit(100);
	}
}

/**
  * main - a function that Copies the contents of a file to another file
  * @argc: The number of arguments supplied to the program
  * @argv: An array of pointers to the arguments
  *
  * Return: on success returns 0, but
  *         If the argument count is incorrect - exit code 97
  *         If file_from does not exist or cannot be read - exit code 98
  *         If file_to cannot be created or written to - exit code 99
  *         If file_to or file_from cannot be closed - exit code 100
  */
int main(int argc, char *argv[])
{
	int src, dest, rd, wrt;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buff(argv[2]);
	src = open(argv[1], O_RDONLY);
	rd = read(src, buffer, 1024);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (src == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wrt = write(dest, buffer, rd);
		if (dest == -1 || wrt == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		rd = read(src, buffer, 1024);
		dest = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(buffer);
	close_file(src);
	close_file(dest);

	return (0);
}
