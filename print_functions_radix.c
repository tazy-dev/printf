#include "main.h"

/**
 * print_int - Print integer to console
 *
 * @ap : input argument
 * Return: The number of digits of the output
 */
int print_int(va_list ap)
{
	int num = va_arg(ap, int);

	return (_putString(convert_number(num, 10, 0)));
}
