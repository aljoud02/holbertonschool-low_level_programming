#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the main string to check
 * @accept: the string containing the allowed characters
 *
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int i;
	int match;

	count = 0;
	while (*s != '\0')
	{
		match = 0;
		i = 0;
		while (accept[i] != '\0')
		{
			if (*s == accept[i])
			{
				match = 1;
				break;
			}
			i++;
		}

		if (match == 1)
		{
			count++;
			s++;
		}
		else
		{
			break;
		}
	}

	return (count);
}

