#include "main.h"

/**
 * print_unsigned - Print integer as unsigned to console
 *
 * @ap : Argument list
 * @str: The flags structure
 * Return: The number of digits of the output
 */
int print_unsigned(va_list ap, str_fmt *str)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *result;
	(void)str;

	result = convert_number(num, 10, UNSIGNED);
	return (_putString(result));
}

