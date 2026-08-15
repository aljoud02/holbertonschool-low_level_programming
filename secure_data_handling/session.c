#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - Creates a new session securely with self-contained ownership
 * @id: Pointer to caller-provided ID string
 * @uid: User identifier
 * @data: Pointer to caller-provided data byte array
 * @data_len: Length of the data buffer
 *
 * Return: Pointer to allocated session_t, or NULL if any allocation fails
 */
session_t *session_create(const char *id, unsigned int uid,
			  const unsigned char *data, size_t data_len)
{
	session_t *s;

	if (!id)
		return (NULL);

	s = (session_t *)malloc(sizeof(*s));
	if (!s)
		return (NULL);

	s->id = strdup(id);
	if (!s->id)
	{
		free(s);
		return (NULL);
	}

	s->uid = uid;

	if (data_len > 0 && data != NULL)
	{
		s->data = (unsigned char *)malloc(data_len);
		if (!s->data)
		{
			free(s->id);
			free(s);
			return (NULL);
		}
		memcpy(s->data, data, data_len);
		s->data_len = data_len;
	}
	else
	{
		s->data = NULL;
		s->data_len = 0;
	}

	return (s);
}

/**
 * session_set_data - Updates a session's data buffer safely without leaks
 * @s: Pointer to target session_t structure
 * @data: Pointer to the new data bytes
 * @data_len: New data buffer length
 *
 * Return: 1 if successful, 0 if allocation fails (leaves original data intact)
 */
int session_set_data(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *tmp;

	if (!s)
		return (0);

	if (data_len == 0 || data == NULL)
	{
		free(s->data);
		s->data = NULL;
		s->data_len = 0;
		return (1);
	}

	tmp = (unsigned char *)realloc(s->data, data_len);
	if (!tmp)
		return (0);

	s->data = tmp;
	memcpy(s->data, data, data_len);
	s->data_len = data_len;
	return (1);
}

/**
 * session_destroy - Safely dismantles a self-contained session object
 * @s: Pointer to session_t to release
 */
void session_destroy(session_t *s)
{
	if (!s)
		return;

	free(s->id);
	free(s->data);
	free(s);
}

