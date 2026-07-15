#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to be modified
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	int i;
	int j;
	char separators[] = " \t\n,;.!?\"(){}";

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}

		j = 0;
		while (separators[j] != '\0')
		{
			if (str[i - 1] == separators[j] && (str[i] >= 'a' && str[i] <= 'z'))
			{
				str[i] = str[i] - 32;
				break;
			}
			j++;
		}
		i++;
	}

	return (str);
}

