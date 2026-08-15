#include <stdlib.h>
#include <string.h>
#include "store.h"

/**
 * store_init - Safely initializes the store linked list head
 * @st: Pointer to store structure
 */
void store_init(store_t *st)
{
	if (st)
		st->head = NULL;
}

/**
 * node_create - Helper logic to instantiate an internal list node safely
 * @s: Pointer to session object to bind
 *
 * Return: Pointer to node_t node, or NULL if heap exhaustion occurs
 */
static node_t *node_create(session_t *s)
{
	node_t *n = (node_t *)malloc(sizeof(*n));

	if (!n)
		return (NULL);
	n->sess = s;
	n->next = NULL;
	return (n);
}

/**
 * store_add - Hardens store insertion by guaranteeing failure memory cleanups
 * @st: Pointer to central store structure
 * @s: Pointer to allocated session object
 *
 * Return: 1 if added, 0 on failure (ensures session is fully freed)
 */
int store_add(store_t *st, session_t *s)
{
	node_t *n, *cur;

	if (!st || !s || !s->id)
	{
		if (s)
			session_destroy(s);
		return (0);
	}

	cur = st->head;
	while (cur)
	{
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, s->id) == 0)
		{
			session_destroy(s);
			return (0);
		}
		cur = cur->next;
	}

	n = node_create(s);
	if (!n)
	{
		session_destroy(s);
		return (0);
	}

	n->next = st->head;
	st->head = n;
	return (1);
}

/**
 * store_get - Retrieves a session by its string key identifier
 * @st: Pointer to store
 * @id: Target session ID string lookup
 *
 * Return: Pointer to bounded session_t, or NULL if not found
 */
session_t *store_get(store_t *st, const char *id)
{
	node_t *cur;

	if (!st || !id)
		return (NULL);

	cur = st->head;
	while (cur)
	{
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, id) == 0)
			return (cur->sess);
		cur = cur->next;
	}
	return (NULL);
}

/**
 * store_delete - Contextual deletion separating destroy from ownership handoff
 * @st: Pointer to store
 * @id: Target session ID string
 * @out: Optional external double pointer to intercept session lifecycle
 *
 * Return: 1 if successfully isolated, 0 if target ID lookup misses
 */
int store_delete(store_t *st, const char *id, session_t **out)
{
	node_t *cur, *prev;

	if (!st || !id)
		return (0);

	prev = NULL;
	cur = st->head;

	while (cur)
	{
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, id) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				st->head = cur->next;

			if (out)
				*out = cur->sess;
			else
				session_destroy(cur->sess);

			free(cur);
			return (1);
		}
		prev = cur;
		cur = cur->next;
	}

	return (0);
}

/**
 * store_destroy - Full repeatable lifecycle teardown resetting invariants
 * @st: Pointer to store to dismantle
 */
void store_destroy(store_t *st)
{
	node_t *cur, *next;

	if (!st)
		return;

	cur = st->head;
	while (cur)
	{
		next = cur->next;
		if (cur->sess)
			session_destroy(cur->sess);
		free(cur);
		cur = next;
	}
	st->head = NULL;
}

