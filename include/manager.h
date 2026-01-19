#ifndef STUDENTMANAGER_MANAGER_H
#define STUDENTMANAGER_MANAGER_H

#include "types.h"
#include "fileman.h"
#include <stdlib.h>
#include <string.h>

status_t fetch_lessons(LessonInfoList *list, size_t *len);

status_t add_new_lesson(LessonInfo *info, LessonInfoList *list);

status_t remove_lesson(LessonInfo *info, LessonInfoList *list);

status_t check_lesson_sysid(LessonInfo *srcinfo, LessonInfo **dstinfo, LessonInfoList *list);

status_t sync_lessons(LessonInfoList *list);

status_t fetch_scornums(ScornumInfoList *list, size_t *len);

status_t add_new_scornum(ScornumInfo *info, ScornumInfoList *list);

status_t check_scornum_sysid(ScornumInfo *srcinfo, ScornumInfo **dstinfo, ScornumInfoList *list);

status_t sync_scornums(ScornumInfo *info, ScornumInfoList *list);

#endif
