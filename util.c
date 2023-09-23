#include "main.h"

/**
 * function_pointer - get the function corresponfing to the
 *                    specifier
 *
 * @s : specifier
 * Return: A pointer to the coresponding function
 */
int (*function_pointer(char s))(va_list, str_fmt *)
{
	int index = 0;
	fmt_spec specifier_list[] = {
		{'c', print_char},
		{'%', print_percentage},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_bin},
		{'o', print_oct},
		{'x', print_hex},
		{'X', print_HEX},
		{'u', print_unsigned},
		{'S', print_str_special},
		{'p', print_address},
		{' ', NULL}};

	while (specifier_list[index].specifier != ' ')
	{
		if (s == specifier_list[index].specifier)
			return (specifier_list[index].function);
		index++;
	}
	return (NULL);
}
/**
 * sprcifier_function - the function corresponfing to the
 *                    specifier
 * @s : specifier
 * @str : specifier structure
 * @ap : input argument
 * Return: The length of the printed result
 */
int sprcifier_function(char s, va_list ap, str_fmt *str)
{
	int (*func)(va_list, str_fmt *) = function_pointer(s);

	if (func)
		return (func(ap, str));
	return (0);
}
/**
 * convert_number - Convert a number to a string
 *
 * @num : Number to be converted
 * @base : Decimal,octal,hexa or binary
 * @check : Check if number un/signed or lowercase
 *		or uppercase (hexa)
 * Return: pointer to the resulting string
 *
 */
char *convert_number(long int num, int base, int check)
{
	static char *conv_table;
	static char res_buf[64];
	unsigned long int n = num;
	char sign = 0;
	char *ptr;

	if (!(check & UNSIGNED) && (num < 0))
	{
		n = -num;
		sign = '-';
	}
	conv_table = (check & LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &res_buf[63];
	*ptr = '\0';
	do {
		*--ptr = conv_table[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}
/**
 * _isdigit - checks if it is an integer
 *
 * @num : Number to be checked
 * Return: 1 if digit , 0 other
 */
int _isdigit(int num)
{
	return (num >= '0' && num <= '9');
}

/**
 * _strlen - Calc the length of a string
 *
 * @str: Input String
 * Return: the length of a string
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str++)
	{
		len++;
	}

	return (len);
}
