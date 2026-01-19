#ifndef STUDENTMAN_FILEMAN_H
#define STUDENTMAN_FILEMAN_H

#include "types.h"
#include <stdio.h>

#define FILEWITHTYPE(type) ((type == MANAGER) ? managerfile : employefile)

status_t open_member_file(const char *path, MemberType type);

status_t fetch_member_file(MemberInfo *info, MemberType type);

status_t sync_member_file(MemberInfoList *list, MemberType type);

status_t close_member_file(MemberType type);

status_t open_lesson_file(const char *path);

status_t fetch_lesson_file(LessonInfo *info);

status_t sync_lesson_file(LessonInfoList *list);

status_t close_lesson_file(void);

status_t open_scornum_file(const char *path);

status_t fetch_scornum_file(ScornumInfo *info);

status_t sync_scornum_file(ScornumInfoList *list);

status_t close_scornum_file(void);

#endif
