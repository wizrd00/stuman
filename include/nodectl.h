#ifndef STUDENTMANAGER_NODECTL_H
#define STUDENTMANAGER_NODECTL_H

#include "types.h"
#include <stdlib.h>

#define ISNOT_REACHED_END(nod) ((nod)->next != NULL)
#define IS_REACHED_END(nod) ((nod)->next == NULL)
#define GET_NEXT(nod) ((nod)->next);
#define GET_PREV(nod) ((nod)->prev);
#define GET_HEAD_NODE(nod) ((nod)->prev);

typedef enum {
	APPEND_TOP,
	APPEND_BTM
} appendpos_t;

status_t node_alloce(object_t **obj);

status_t node_append(node_t *nod, object_t *obj, appendpos_t pos);

status_t node_remove(node_t *nod, object_t *obj);

status_t node_search(node_t *nod, object_t *obj, object_t **hdl, bool (*compare)(object_t *obj0, object_t *obj1));

#endif
