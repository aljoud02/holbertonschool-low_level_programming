#include "main.h"

/**
 * print_most_numbers - Prints numbers from 0 to 9 except 2 and 4
 *
 * Description: Loops through characters '0' to '9' and prints them
 * only if they are not equal to '2' or '4', followed by a new line.
 * Return: void
 */
void print_most_numbers(void)
{
	int num;

	for (num = '0'; num <= '9'; num++)
	{
		if (num != '2' && num != '4')
		{
			_putchar(num);
		}
	}
	_putchar('\n');
}
