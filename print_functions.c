#include "main.h"

/**
 * print_char - Print character to console
 *
 * @ap : input argument
 * Return: On success (1)
 */
int print_char(va_list ap)
{
	return (_putChar(va_arg(ap, int)));
}

/**
 * print_percentage - Print % to console
 *
 * @ap : input argument
 * Return: On success (1)
 */
int print_percentage(va_list ap)
{
	(void)ap;
	return (_putChar('%'));
}

/**
 * print_string - Print string to console
 *
 * @ap : Input argument
 * Return: The length of the string
 */
int print_string(va_list ap)
{
	char *str = va_arg(ap, char *);

	if ((int)(!str))
	{
		return (_putString("(null)"));
	} else
		return (_putString(str));
}
