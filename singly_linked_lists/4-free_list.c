#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a list_t linked list.
 * @head: A pointer to the head of the list_t list to be freed.
 *
 * Description: Recursively or iteratively releases all nodes and their
 * duplicated internal string attributes from the system heap workspace.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}

