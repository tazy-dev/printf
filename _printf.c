#include "main.h"

/**
 * _printf - Custom Printf function
 *
 * @format : The input format string containing
 *           format specifiers %,
 * Return: The number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *p, *express;
	int result_len = 0;
	str_fmt flags;

	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			result_len += _putChar(*p);
			continue;
		}
		if (!*(p + 1) || (*(p + 1) == ' ' && !*(p + 2)))
		{
			result_len = -1;
			break;
		}
		express = p;
		p++;
		intialize_fmt_str(&flags);
		while (parse_flags(*p, &flags))
			++p;
		p = parse_width(p, ap, &flags);
		p = parse_modifier(p, &flags);
		if (!function_pointer(*p))
			result_len += print_expression(express, --p, &flags);
		else
			result_len += sprcifier_function(*p, ap, &flags);
	}
	_putChar(BUFFER_FLUSH);
	va_end(ap);
	return (result_len);
}
