#include "main.h"

/**
 * print_char - Print character to console
 *
 * @ap : input argument
 * Return: On success (1)
 */
int print_char(va_list ap)
{
	return (_putChar(va_arg(ap, int)));
}

/**
 * print_percentage - Print % to console
 *
 * @ap : input argument
 * Return: On success (1)
 */
int print_percentage(va_list ap)
{
	(void)ap;
	return (_putChar('%'));
}

/**
 * print_string - Print string to console
 *
 * @ap : Input argument
 * Return: The length of the string
 */
int print_string(va_list ap)
{
	char *str = va_arg(ap, char *);

	if ((int)(!str))
	{
		return (_putString("(null)"));
	} else
		return (_putString(str));
}

/**
 * print_str_special - Print string along with non-printable as hexa to console
 *
 * @ap: Input argument
 * Return: The length of the string
 */
int print_str_special(va_list ap)
{
	char *str = va_arg(ap, char *), *non_printable;
	int len = 0;


	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			len += 2;
			_putChar('\\');
			_putChar('x');
			non_printable = convert_number(*str, 16, UNSIGNED);
			if (non_printable[1])
				len += _putString(non_printable);
			else
			{
				_putChar('0');
				_putChar(non_printable[0]);
				len += 2;
			}
		} else
			len += _putChar(*str);
	}
	return (len);
}

/**
 * print_address - Print address of a variable  to console
 *
 * @ap: Input argument
 * Return: The length of the string
 */
int print_address(va_list ap)
{
	unsigned long int addr = (unsigned long int) va_arg(ap, void *);
	char *result;

	if (addr == 0)
	{
		return (_putString("(nil)"));
	}

	result = convert_number(addr, 16, UNSIGNED | LOWERCASE);
	*--result = 'x';
	*--result = '0';
	return (_putString(result));

}

