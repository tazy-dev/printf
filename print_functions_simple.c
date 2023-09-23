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
	char *result;
	char padding = ' ';
	unsigned int text_len, fill;
	unsigned long num;

	if (str->lng)
		num = (unsigned long)va_arg(ap, unsigned long);
	else if (str->sh)
		num = (unsigned short)va_arg(ap, unsigned int);
	else
		num = (unsigned int)va_arg(ap, unsigned int);
	result = convert_number(num, 10, UNSIGNED);
	text_len = _strlen(result);
	if (text_len >= str->width)
		return (_putString(result));
	fill = str->width - text_len;
	while (fill--)
		*--result = padding;
	return (_putString(result));
}

/**
 * print_expression - Prints the expression before the specifier when unknown
 *                    specifier is passed to id
 * @start: The expression start pointer
 * @end: The expression end pointer
 * @flags: The flags structure.
 *
 * Return: The length of the uknown expression
 */
int print_expression(const char *start, const char *end, str_fmt *flags)
{
	int express_len = 0;

	if (flags->plus && flags->hash)
		express_len += _putString("%#+");
	else if (!(flags->plus) && flags->hash)
	{
		if (flags->space)
			express_len += _putString("%# "); /* condition */
		else
			express_len += _putString("%#");
	}
	else if (flags->plus && !(flags->hash))
		express_len += _putString("%+");
	else if (flags->space)
		express_len += _putString("% ");
	else
		express_len += _putChar('%');
	start += express_len;
	while (start <= end)
	{
		if ((*start != 'h') && (*start != 'l'))
			express_len += _putChar(*start);
		++start;
	}

	return (express_len);
}
