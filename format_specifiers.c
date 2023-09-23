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
 * parse_modifier - Determine the length flags
 *
 * @m: modufier
 * @str: The flags stucture
 *
 * Return: Increase in address passed if modifier found
 */
const char *parse_modifier(const char *m, str_fmt *str)
{
	switch (*m)
	{
		case 'l':
			str->lng = 1;
			++m;
			break;
		case 'h':
			str->sh = 1;
			++m;
			break;
		default:
			break;
	}
	return (m);
}
/**
 * parse_width - Update witdth in flags structure
 *
 * @wid : pointer to the width value or *
 * @ap : argument list
 * @str : The flags stucture
 *
 * Return: pointer to the next flag or specifier
 */
const char *parse_width(const char *wid, va_list ap, str_fmt *str)
{
	unsigned int width;

	if (*wid == '*')
	{
		width = va_arg(ap, int);
		wid++;
	} else
	{
		while (_isdigit(*wid))
		{
			width = width * 10 + (*wid++ - '0');
		}


	}
	str->width = width;
	return (wid);
}
