#include "main.h"

/**
 * print_char - Print character to console
 *
 * @ap : input argument
 * @str: The flags structure
 * Return: On success (1)
 */
int print_char(va_list ap, str_fmt *str)
{
	(void)str;
	return (_putChar(va_arg(ap, int)));
}

/**
 * print_percentage - Print % to console
 *
 * @ap : input argument
 * @str: The flags structure
 * Return: On success (1)
 */
int print_percentage(va_list ap, str_fmt *str)
{
	(void)ap;
	(void)str;
	return (_putChar('%'));
}

/**
 * print_string - Print string to console
 *
 * @ap : Input argument
 * @str: The flags structure
 * Return: The length of the string
 */
int print_string(va_list ap, str_fmt *str)
{
	(void)str;
	char *s = va_arg(ap, char *);

	if ((int)(!s))
	{
		return (_putString("(null)"));
	} else
		return (_putString(s));
}
/**
 * print_str_special - Print string along with non-printable as hexa to console
 *
 * @ap: Input argument
 * @str: The flags structure
 * Return: The length of the string
 */
int print_str_special(va_list ap, str_fmt *str)
{
	char *s = va_arg(ap, char *), *non_printable;
	int len = 0;
	(void)str;

	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			len += 2;
			_putChar('\\');
			_putChar('x');
			non_printable = convert_number(*s, 16, UNSIGNED);
			if (non_printable[1])
				len += _putString(non_printable);
			else
			{
				_putChar('0');
				_putChar(non_printable[0]);
				len += 2;
			}
		} else
			len += _putChar(*s);
	}
	return (len);
}
/**
 *print_address - Print address of a variable  to console
 *
 * @ap: Input argument
 * @str: The flags structure
 * Return: The length of the string
 */
int print_address(va_list ap, str_fmt *str)
{
	unsigned long int addr = va_arg(ap, unsigned long int);
	char *result;
	(void)str;

	if (addr == 0)
	{
		return (_putString("(nil)"));
	}

	result = convert_number(addr, 16, UNSIGNED | LOWERCASE);
	*--result = 'x';
	*--result = '0';
	return (_putString(result));

}

