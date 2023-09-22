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

/**
 * print_bin - Print integer as Binary to console
 *
 * @ap : input argument
 * Return: The number of digits of the output
 */
int print_bin(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);

	return (_putString(convert_number(num, 2, UNSIGNED)));
}

/**
 * print_oct - Print integer as octal to console
 *
 * @ap : argument list
 *
 * Return: The number of digits of the output
 */
int print_oct(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *result;

	result = convert_number(num, 8, UNSIGNED);
	return (_putString(result));
}

/**
 * print_hex - Print integer as hexa lowe to console
 *
 * @ap : argument list
 *
 * Return: The number of digits of the output
 */
int print_hex(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *result;

	result = convert_number(num, 16, UNSIGNED | LOWERCASE);
	return (_putString(result));
}

/**
 * print_HEX - Print integer as hex upper to console
 *
 * @ap : argument list
 *
 * Return: The number of digits of the output
 */
int print_HEX(va_list ap)
{

	unsigned int num = va_arg(ap, unsigned int);
	char *result;

	result = convert_number(num, 16, UNSIGNED | !LOWERCASE);
	return (_putString(result));
}
