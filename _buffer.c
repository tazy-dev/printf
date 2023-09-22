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
	write(1, &c, 1);
	return (1);
}
