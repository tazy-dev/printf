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
	const char *p;
	int result_len = 0;

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
		++p;
		/*in case the given specifier is not defined*/
		if (!function_pointer(*p))
		{
			result_len += _putChar('%');
			result_len += _putChar(*p);
		} else
			result_len += sprcifier_function(*p, ap);

	}
	_putChar(BUFFER_FLUSH);
	va_end(ap);
	return (result_len);
}


