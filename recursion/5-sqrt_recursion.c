#include "main.h"

int find_sqrt(int n, int i);

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The natural square root, or -1 if it does not exist.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (find_sqrt(n, 1));
}

/**
 * find_sqrt - Helper function to find the square root through recursion.
 * @n: The original number.
 * @i: The current number to test as a root.
 *
 * Return: The natural square root, or -1 if it does not exist.
 */
int find_sqrt(int n, int i)
{
	if (i * i > n)
	{
		return (-1);
	}
	if (i * i == n)
	{
		return (i);
	}
	return (find_sqrt(n, i + 1));
}

