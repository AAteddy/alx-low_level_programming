#include "main.h"

/**
  * append_text_to_file - a function that appends text at the
  *                       end of a file
  * @filename: a pointer to the name of the file
  * @text_content: is the NULL terminated string to add
  *                at the end of the file
  *
  * Return: if the file exists (on success) 1,
  *         if the file desnt exist or filename is NULL return -1
  *         if you do not have the required permissions
  *         to write the file return -1
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int opn, wrt, len = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
		{
			len++;
		}
	}
	opn = open(filename, O_WRONLY | O_APPEND);
	wrt = write(opn, text_content, len);
	if (opn == -1 || wrt == -1)
	{
		return (-1);
	}
	close(opn);
	return (1);
}
