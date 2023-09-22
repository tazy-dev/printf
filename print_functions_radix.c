#include "main.h"

/**
 * print_int - Print integer to console
 *
 * @ap : input argument
 * @str: The flags structure
 * Return: The number of digits of the output
 */
int print_int(va_list ap, str_fmt *str)
{
	int num = va_arg(ap, int);
	char *result;

	result = convert_number(num, 10, 0);
	if (str->plus && !(num < 0) && !str->sign)
		*--result = '+';
	else if (str->space && !(num < 0) && !str->sign)
		*--result = ' ';
	return (_putString(result));
}

/**
 * print_bin - Print integer as Binary to console
 *
 * @ap : input argument
 * @str: The flags structure
 * Return: The number of digits of the output
 */
int print_bin(va_list ap, str_fmt *str)
{
	unsigned int num = va_arg(ap, unsigned int);
	char *result;

	result = convert_number(num, 2, UNSIGNED);
	if (str->hash)
	{
		*--result = 'b';
		*--result = '0';
	}
	return (_putString(result));
}

/**
 * print_oct - Print integer as octal to console
 *
 * @ap : argument list
 * @str: The flags structure
 *
 * Return: The number of digits of the output
 */
int print_oct(va_list ap, str_fmt *str)
{
	unsigned long num = va_arg(ap, unsigned long);
	char *result;

	result = convert_number(num, 8, UNSIGNED);
	if (str->hash)
	{
		*--result = '0';
	}
	return (_putString(result));
}

/**
 * print_hex - Print integer as hexa lowe to console
 *
 * @ap : argument list
 * @str: The flags structure
 *
 * Return: The number of digits of the output
 */
int print_hex(va_list ap, str_fmt *str)
{
	unsigned long num = va_arg(ap, unsigned long);
	char *result;

	result = convert_number(num, 16, UNSIGNED | LOWERCASE);
	if (str->hash)
	{
		*--result = 'x';
		*--result = '0';
	}
	return (_putString(result));
}

/**
 * print_HEX - Print integer as hex upper to console
 *
 * @ap : argument list
 * @str: The flags structure
 *
 * Return: The number of digits of the output
 */
int print_HEX(va_list ap, str_fmt *str)
{

	unsigned long num = va_arg(ap, unsigned long);
	char *result;

	result = convert_number(num, 16, UNSIGNED | !LOWERCASE);
	if (str->hash)
	{
		*--result = 'X';
		*--result = '0';
	}
	return (_putString(result));
}

