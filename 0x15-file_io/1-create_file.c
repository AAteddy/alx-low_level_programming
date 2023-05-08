#include "main.h"

/**
  * create_file - a function that creates a file
  * @filename: is the name of the file to create
  * @text_content: is a NULL terminated string to write to the file
  *
  * Return: on success returns 1, or
  *         if the fuction fails, returns -1
  */
int create_file(const char *filename, char *text_content)
{
	int opn, wrt;
	int length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length])
		{
			lenght++;
		}
	}

	opn = open(filename, O_CREATE | O_RDWR | O_TRUNC, 0600);
	wrt = write(opn, text_content, length);

	if (opn == -1 || wrt == -1)
		return (-1);

	close(opn);

	return (1);
}
