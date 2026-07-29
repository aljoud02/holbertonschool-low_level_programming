#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct token - Struct token
 * @symbol: The data type token (c, i, f, s)
 * @print: The function pointer to print the data type
 */
typedef struct token
{
	char symbol;
	void (*print)(va_list arg);
} token_t;

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */

