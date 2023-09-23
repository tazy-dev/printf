#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define LOWERCASE 1
#define UNSIGNED 2

/**
 * struct string_format - Flags amd modifiers structure
 *
 * @sign : signed(0) or unsigned(1).
 *
 * @plus : Plus flag
 * @space : Space flag
 * @hash :Hashtag flag
 * @minus : Minus flag
 * @zero : zero flag
 *
 * @width : Variable minimum width
 * @percesion : string length , number of digits, number of fractional digits
 *
 * @lng : long modifier
 * @sh : Short modifier
 *
 * Description : This structure handels the various
 *               flags , modifiers and length that preceed
 *               the specifier and affect the result
 */
typedef struct string_format
{
	unsigned int sign;
	unsigned int plus;
	unsigned int space;
	unsigned int hash;
	unsigned int minus;
	unsigned int zero;
	unsigned int width;
	unsigned int percesion;
	unsigned int lng;
	unsigned int sh;
} str_fmt;

/**
 * struct specifier - Different Printf Specifier
 *
 * @specifier : The specifier character.
 * @function : A pointer to the method printing the value acoording
 *              to the specifier and available flags
 *
 * Description : This structure handels the various
 *               specifier and mapping each to a function that match
 *               the specifier with arguments to print the result
 *
 */
typedef struct specifier
{
	char  specifier;
	int (*function)(va_list, str_fmt *);/*Pointer to the Actual function*/

} fmt_spec;

/*main Functiond*/
int _printf(const char *format, ...);

/*_buffer.c module*/
int _putString(char *);
int _putChar(char);

/*print_functions.c file*/
int print_char(va_list, str_fmt *);
int print_percentage(va_list, str_fmt *);
int print_string(va_list, str_fmt *);
int print_str_special(va_list, str_fmt *);
int print_address(va_list, str_fmt *);

/*print_functions_radix.c file*/
int print_int(va_list, str_fmt *);
int print_bin(va_list, str_fmt *);
int print_oct(va_list, str_fmt *);
int print_hex(va_list, str_fmt *);
int print_HEX(va_list, str_fmt *);

/*print_functions_simple.c file*/
int print_unsigned(va_list, str_fmt *);
int print_expression(const char *, const char *, str_fmt *);

/*utils.c file*/
char *convert_number(long int, int, int);
int (*function_pointer(char))(va_list, str_fmt *);
int sprcifier_function(char, va_list, str_fmt *);
int _isdigit(int);
int _strlen(char *);


/*format_specifiers.c*/
void intialize_fmt_str(str_fmt *);
int parse_flags(char, str_fmt *);
const char *parse_modifier(const char *, str_fmt *);
const char *parse_width(const char *, va_list, str_fmt *);
#endif
