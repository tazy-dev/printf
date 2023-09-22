#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

#define LOWERCASE 1
#define UNSIGNED 2

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
	int (*function)(va_list);/*Pointer to the Actual function*/

} fmt_spec;

/*main Functiond*/
int _printf(const char *format, ...);

/*_buffer.c module*/
int _putString(char *);
int _putChar(char);

/*print_functions.c file*/
int print_char(va_list);
int print_percentage(va_list);
int print_string(va_list);

/*print_functions_radix.c file*/
int print_int(va_list);
int print_bin(va_list);
int print_oct(va_list);
int print_hex(va_list);
int print_HEX(va_list);

/*print_functions_simple.c file*/
int print_unsigned(va_list);

/*utils.c file*/

char *convert_number(int, int, int);
int (*function_pointer(char))(va_list);
int sprcifier_function(char, va_list);

#endif
