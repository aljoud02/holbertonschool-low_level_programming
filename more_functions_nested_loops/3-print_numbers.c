#include "main.h"

/**
 * print_numbers - Prints the numbers from 0 to 9
 *
 * Description: Uses a loop to print numbers from 0 to 9
 * followed by a new line.
 * Return: void
 */
void print_numbers(void)
{
	int num;

	for (num = '0'; num <= '9'; num++)
	{
		_putchar(num);
	}
	_putchar('\n');
}
