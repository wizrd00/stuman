#include "nodectl.h"

status_t node_alloce(object_t **obj)
{
	status_t _stat = SUCCESS;
	*obj = (object_t *) malloc(sizeof (object_t));
	CHECK_PTR(*obj, ERRALOC);
	return _stat;
}

status_t node_append(node_t *nod, object_t *obj, appendpos_t pos)
{
	status_t _stat = SUCCESS;
	node_t *new_nod = (node_t *) malloc(sizeof (node_t));
	new_nod->obj = obj;
	if (pos == APPEND_BTM) {
		while (nod->next != NULL)
			nod = nod->next;
		nod->next = new_nod;
		new_nod->prev = nod;
		new_nod->next = NULL;
	} else {
		new_nod->next = nod;
		nod->prev = new_nod;
		new_nod->prev = NULL;
	}
	return _stat;
}

status_t node_remove(node_t *nod, object_t *obj)
{
	status_t _stat = SUCCESS;
	node_t *found_nod = NULL;
	while ((nod->obj != obj) && (nod->next != NULL))
		nod = nod->next;
	CHECK_EQUAL(obj, nod->obj, NOFOUND);
	nod->prev->next = nod->next;
	nod->next->prev = nod->prev;
	free((void *) nod->obj);
	free((void *) nod);
	return _stat;
}

status_t node_search(node_t *nod, node_t **fnd, object_t *obj, bool (*compare)(object_t *obj0, object_t *obj1))
{
	status_t _stat = SUCCESS;
	bool cmp = false;
	while (!(cmp = compare(obj, nod->obj)) && (nod->next != NULL))
		nod = nod->next;
	*fnd = (cmp) ? nod : (_stat = NOFOUND, NULL);
	return _stat;
}
