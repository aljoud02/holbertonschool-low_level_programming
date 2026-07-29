#include "variadic_functions.h"

/**
 * print_all - Prints anything based on a format string.
 * @format: A list of types of arguments passed to the function.
 * @...: A variable number of arguments to be printed.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *str, *sep = "";

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		while (format[i] == 'c' || format[i] == 'i' ||
		       format[i] == 'f' || format[i] == 's')
		{
			printf("%s", sep);
			if (format[i] == 'c')
				printf("%c", va_arg(args, int));
			if (format[i] == 'i')
				printf("%d", va_arg(args, int));
			if (format[i] == 'f')
				printf("%f", va_arg(args, double));
			if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
			}
			sep = ", ";
			break;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}

