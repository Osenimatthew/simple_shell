#include "shell.h"
/**
 * _Strncpy - Copies a string
 * @dest: The destination string to be copied to
 * @src: The source string
 * @n: The number of characters to be copied
 *
 * Return: The concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int p, q;
	char *s = dest;

	p = 0;
	while (src[p] != '\0' && p < n - 1)
	{
		dest[p] = src[p];
		p++;
	}
	if (p < n)
	{
		q = p;
		while (q < n)
		{
			dest[q] = '\0';
			q++;
		}
	}
	return (s);
}

char *_strncat(char *dest, char *src, int n)
{
	int p, q;
	char *s = dest;

	p = 0;
	q = 0;
	while (dest[p] != '\0')
		p++;
	while (src[q] != '\0' && q < n)
	{
		dest[p] = src[q];
		p++;
		q++;
	}
	if (q < n)
		dest[p] = '\0';
	return (s);
}

/**
 * _Strchr - Locates a character in a string
 * @s: The string to be parsed
 * @c: The character to look for
 *
 * Return: (s) A pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
