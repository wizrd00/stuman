#ifndef STUDENTMAN_ADMIN_H
#define STUDENTMAN_ADMIN_H

#include "types.h"
#include "fileman.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

status_t fetch_members(MemberInfoList *list, size_t *len, MemberType type);

status_t add_new_(MemberInfo *info, MemberInfoList *list, MemberType type);

status_t remove_member(MemberInfo *info, MemberInfoList *list, MemberType type);

status_t check_member_sysid(MemberInfo *srcinfo, MemberInfo **dstinfo, MemberInfoList *list, MemberType type);

status_t sync_members(MemberInfoList *list, MemberType type);

#endif
