#include"main.h"

/**
 * intialize_fmt_str - Initialize the flags structure
 *
 * @s: The flags structure
 */
void intialize_fmt_str(str_fmt *s)
{
	s->sign = 0;
	s->plus = 0;
	s->space = 0;
	s->hash = 0;
	s->zero = 0;
	s->minus = 0;
	s->width = 0;
	s->percesion = UINT_MAX;
	s->lng = 0;
	s->sh = 0;
}
/**
 * parse_flags - assign valuse to the flags structure based on the passed flag
 *
 * @f: The flag found in the format string
 * @str: The flags structure
 * Return: If a flag us found (1), otherwise (0)
 */
int parse_flags(char f, str_fmt *str)
{
	int found;

	switch (f)
	{
		case '+':
			str->plus = 1;
			found = 1;
			break;
		case ' ':
			str->space = 1;
			found = 1;
			break;
		case '#':
			str->hash = 1;
			found = 1;
			break;
		default:
			found = 0;
			break;
	}
	return (found);
}

/**
 * print_expression - Prints the expression before the specifier when unknown
 *                    specifier is passed to id
 * @flags: The flags structure.
 *
 * Return: The length of the uknown expression
 */
int print_expression(str_fmt *flags)
{
	int express_len = 0;

	if (flags->plus && flags->hash)
		express_len += _putString("%#+");
	else if (!(flags->plus) && flags->hash)
	{
		if (flags->space)
			express_len += _putString("%# ");
		else
			express_len += _putString("%#");
	}
	else if (flags->plus && !(flags->hash))
	{
		express_len += _putString("%+");
	} else if (flags->space)
	{
		express_len += _putString("% ");
	} else
	{
		express_len += _putChar('%');
	}
	return (express_len);
}

