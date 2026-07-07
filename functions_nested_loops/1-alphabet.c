#include "main.h"

/**
 * print_alphabet - Prints the alphabet in lowercase
 *
 * Description: Uses a loop to print all letters from a to z
 * and then prints a new line.
 * Return: void
 */
void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		_putchar(letter);
	}
	_putchar('\n');
}
