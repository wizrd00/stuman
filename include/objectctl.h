#ifndef STUDENTMAN_OBJECTCTL_H
#define STUDENTMAN_OBJECTCTL_H

#include "types.h"
#include "nodectl.h"
#include "fileman.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

status_t download_objects(node_t **nod, size_t *len, objecttype_t typ);

status_t add_object(node_t *nod, object_t *obj);

status_t remove_object(node_t *nod, object_t *obj);

status_t check_object_sysid(node_t *nod, object_t *obj, object_t **hdl, objecttype_t typ);

status_t upload_objects(node_t *nod, objecttype_t typ);

#endif
