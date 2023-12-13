#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: the string that is to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_eputchar(str[y]);
		y++;
	}
}

int _eputchar(char z)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (z == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(2, buf, y);
		y = 0;
	}
	if (z != BUF_FLUSH)
		buf[y++] = z;
	return (1);
}

int _putfd(char z, int fd)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (z == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(fd, buf, y);
		y = 0;
	}
	if (z != BUF_FLUSH)
		buf[y++] = z;
	return (1);
}

int _putsfd(char *str, int fd)
{
	int y = 0;

	if (!str)
		return (0);
	while (*str)
	{
		y += _putfd(*str++, fd);
	}
	return (y);
}
