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
	char padding = ' ';
	unsigned int fill = 1;

	while (fill < str->width)
	{
		_putChar(padding);
		fill++;
	}
	_putChar(va_arg(ap, int));
	return (str->width);
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
	char padding = ' ';
	char *text = va_arg(ap, char *);
	unsigned int text_len = _strlen(text), fill;

	if ((int)(!text))
	{
		return (_putString("(null)"));
	}
	else if (text_len >= str->width)
		return (_putString(text));
	fill = str->width - text_len;
	while (fill--)
	{
		_putChar(padding);
	}
	_putString(text);
	return (str->width);
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
	char *text = va_arg(ap, char *);
        char *non_printable;
	int len = 0;
	(void)str;

	for (; *text; text++)
	{
		if ((*text > 0 && *text < 32) || *text >= 127)
		{
			len += 2;
			_putChar('\\');
			_putChar('x');
			non_printable = convert_number(*text, 16, UNSIGNED);
			if (non_printable[1])
				len += _putString(non_printable);
			else
			{
				_putChar('0');
				_putChar(non_printable[0]);
				len += 2;
			}
		}
		else
			len += _putChar(*text);
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
	char *ptr;
	char padding = ' ';
	unsigned int text_len, fill;
	unsigned long int addr = va_arg(ap, unsigned long int);

	if (addr == 0)
	{
		return (_putString("(nil)"));
	}

	ptr = convert_number(addr, 16, UNSIGNED | LOWERCASE);
	*--ptr = 'x';
	*--ptr = '0';
	text_len = _strlen(ptr);
	if (text_len >= str->width)
	{
		return (_putString(ptr));
	}
	else
	{
		fill = str->width - text_len;
		while (fill--)
		{
			*--ptr = padding;
		}
		return (_putString(ptr));
	}
}

