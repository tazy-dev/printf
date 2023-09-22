#include "main.h"

/**
 * function_pointer - get the function corresponfing to the
 *                    specifier
 *
 * @s : specifier
 * Return: A pointer to the coresponding function
 */
int (*function_pointer(char s))(va_list)
{
	int index = 0;
	fmt_spec specifier_list[] = {
		{'c', print_char},
		{'%', print_percentage},
		{'s', print_string},
		{' ', NULL}};

	while (specifier_list[index].specifier != ' ')
	{
		if (s == specifier_list[index].specifier)
		{
			return (specifier_list[index].function);
		}
		index++;
	}
	return (NULL);
}
/**
 * sprcifier_function - the function corresponfing to the
 *                    specifier
 *
 * @s : specifier
 * @ap : input argument
 * Return: The length of the printed result
 */
int sprcifier_function(char s, va_list ap)
{
	int (*func)(va_list) = function_pointer(s);

	if (func)
		return (func(ap));
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
