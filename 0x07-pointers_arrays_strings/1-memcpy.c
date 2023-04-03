#include "main.h"
/**
  *_memcpy -  function copies @n bytes from memory
  * area @src to memory area @dest
  *@n: The number of bytes to copy from @src
  *@src: The source buffer to copy characters from
  *@dest: A pointer to the memory area to copy @src into
  *
  *Return: A pointer to the destination buffer @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
