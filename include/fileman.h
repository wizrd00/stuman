#ifndef STUDENTMAN_FILEMAN_H
#define STUDENTMAN_FILEMAN_H

#include "types.h"
#include "nodectl.h"
#include <stdio.h>

#define SET_FILE_WITH_TYPE(file, type)\
	do {\
		switch (type) {\
		case MANAGER : file = managerfile; break;\
		case EMPLOYE : file = employefile; break;\
		case STUDENT : file = studentfile; break;\
		case LESSONS : file = lessonsfile; break;\
		case SCORNUM : file = scornumfile; break;\
		}\
	} while (0)

status_t open_object_file(const char *path, objecttype_t type);

status_t fetch_object_file(object_t *obj, objecttype_t type);

status_t sync_object_file(node_t *nod, objecttype_t type);

status_t close_object_file(objecttype_t type);

#endif
