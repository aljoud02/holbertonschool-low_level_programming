#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array using a comparison function.
 * @array: The array to search through.
 * @size: The number of elements in the array.
 * @cmp: A pointer to the function used to compare values.
 *
 * Return: The index of the first matching element,
 *         -1 if no element matches, size <= 0, or if pointers are NULL.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}

