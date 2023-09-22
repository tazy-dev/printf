#include "main.h"

/**
 * print_unsigned - Print integer as unsigned to console
 *
 * @ap : Argument list
 * Return: The number of digits of the output
 */
int print_unsigned(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *result;

	result = convert_number(num, 10, UNSIGNED);
	return (_putString(result));
}
