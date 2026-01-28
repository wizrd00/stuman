#ifndef STUDENTMANAGER_OUTPUTCTL_H
#define STUDENTMANAGER_OUTPUTCTL_H

#include "types.h"
#include <stdarg.h>
#include <stdio.h>

int outctl_log(char *msg, ...);

int outctl_list_member(node_t *nod);

#endif
