#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees memory allocated for a dog_t struct
 * @d: Pointer to the dog_t struct to free
 *
 * Description: This function frees the name, owner, and the dog struct itself.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}

