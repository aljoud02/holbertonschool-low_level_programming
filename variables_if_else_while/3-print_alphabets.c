#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char low;
	char up;

	low = 'a';
	while (low <= 'z')
	{
		putchar(low);
		low++;
	}

	up = 'A';
	while (up <= 'Z')
	{
		putchar(up);
		up++;
	}

	putchar('\n');

	return (0);
}
