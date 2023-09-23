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
	char *result;
	char padding = ' ';
	long num;
	unsigned int text_len, fill;

	if (str->lng)
		num = va_arg(ap, long);
	else if (str->sh)
		num = (short)va_arg(ap, int);
	else
		num = (int)va_arg(ap, int);
	result = convert_number(num, 10, 0);
	if (str->plus && !(num < 0) && !str->sign)
		*--result = '+';
	else if (str->space && !(num < 0) && !str->sign)
		*--result = ' ';
	text_len = _strlen(result);
	if (text_len >= str->width)
	{
		return (_putString(result));
	}
	else
	{
		fill = str->width - text_len;
		while (fill--)
		{
			*--result = padding;
		}
		return (_putString(result));
	}
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
	char padding = ' ';
	unsigned int text_len, fill;

	result = convert_number(num, 2, UNSIGNED);
	if (str->hash)
	{
		*--result = 'b';
		*--result = '0';
	}
	text_len = _strlen(result);
	if (text_len >= str->width)
	{
		return (_putString(result));
	}
	else
	{
		fill = str->width - text_len;
		while (fill--)
		{
			*--result = padding;
		}
		return (_putString(result));
	}
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
	char *result;
	char padding = ' ';
	unsigned int text_len, fill,  width = str->width;
	unsigned long num;

	if (str->lng)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (str->sh)
		num = (unsigned short)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);
	if (num == 0)
	{
		while (width > 1)
		{
			_putChar(' ');
			width--;
		}
		_putChar('0');
		return (str->width);
	}
	result = convert_number(num, 8, UNSIGNED);
	if (str->hash)
		*--result = '0';
	text_len = _strlen(result);
	if (text_len >= str->width)
		return (_putString(result));
	fill = str->width - text_len;
	while (fill--)
		*--result = padding;

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
	char *result;
	char padding = ' ';
	unsigned int text_len, fill, width = str->width;
	unsigned long num;

	if (str->lng)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (str->sh)
		num = (unsigned short)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);
	if (num == 0)
	{
		while (width > 1)
		{
			_putChar(' ');
			width--;
		}
		_putChar('0');
		return (str->width);
	}
	result = convert_number(num, 16, UNSIGNED | LOWERCASE);
	if (str->hash)
	{
		*--result = 'x';
		*--result = '0';
	}
	text_len = _strlen(result);
	if (text_len >= str->width)
		return (_putString(result));
	fill = str->width - text_len;
	while (fill--)
		*--result = padding;
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

	char *result;
	char padding = ' ';
	unsigned int text_len, fill, width = str->width;
	unsigned long num;

	if (str->lng)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (str->sh)
		num = (unsigned short)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);
	if (num == 0)
	{
		while (width > 1)
		{
			_putChar(' ');
			width--;
		}
		_putChar('0');
		return (str->width);
	}
	result = convert_number(num, 16, UNSIGNED);
	if (str->hash)
	{
		*--result = 'X';
		*--result = '0';
	}
	text_len = _strlen(result);
	if (text_len >= str->width)
		return (_putString(result));
	fill = str->width - text_len;
	while (fill--)
		*--result = padding;
	return (_putString(result));
}

