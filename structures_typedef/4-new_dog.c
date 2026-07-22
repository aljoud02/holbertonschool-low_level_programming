#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - Creates a new dog and stores copies of its details
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the new dog struct, or NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int i, len_n = 0, len_o = 0;

	if (name == NULL || owner == NULL)
		return (NULL);
	while (name[len_n])
		len_n++;
	while (owner[len_o])
		len_o++;
	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	d->name = malloc(sizeof(char) * (len_n + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	for (i = 0; i <= len_n; i++)
		d->name[i] = name[i];
	d->age = age;
	d->owner = malloc(sizeof(char) * (len_o + 1));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	for (i = 0; i <= len_o; i++)
		d->owner[i] = owner[i];
	return (d);
}

