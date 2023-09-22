#include "main.h"

/**
 * _putString - Add string to the buffer
 *
 * @str : Input string
 * Return: The length of @str.
 */
int _putString(char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		_putChar(*str++);
	}
	return (len);
}
/**
 * _putChar - Add char to the buffer and print to console
 *            when the buffer is full
 *
 * @c : Input character
 * Return: The length of @c.
 */

int _putChar(char c)
{
	static int i;
	static char buffer[BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= BUFFER_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		buffer[i++] = c;
	return (1);
}
