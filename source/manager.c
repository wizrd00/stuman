#include "manager.h"

status_t fetch_lessons(LessonInfoList *list, size_t *len)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(open_lesson_file(LESSONSFILEPATH));
	while (true) {
		list->next = (LessonInfoList *) malloc(sizeof (LessonInfoList));
		if (list->next == NULL) {
			_stat = ERRALOC;
			break;
		}
		_stat = fetch_lesson_file(&list->info);
		if (_stat == SUCCESS) {
			list = list->next;
			(*len)++;
		} else if (_stat = DNFETCH) {
			free((void *) list->next);
			list->next = NULL;
			_stat = SUCCESS;
			break;
		} else {
			free((void *) list->next);
			list->next = NULL;
			break;
		}
	}
}

status_t add_new_lesson(LessonInfo *info, LessonInfoList *list)
{
	status_t _stat = SUCCESS;
	while (list->next != NULL)
		list = list->next;
	list->next = (LessonInfoList *) malloc(sizeof (LessonInfoList));
	if (list->next == NULL)
		return _stat = ERRALOC;
	list->next->next = NULL;
	memcpy((void *) &list->next->info, (void *) info, sizeof (LessonInfo));
	return _stat;
}

status_t remove_lesson(LessonInfo *info, LessonInfoList *list)
{
	status_t _stat = SUCCESS;
	LessonInfo *target;
	if (check_lesson_sysid(info, &target, list) == SUCCESS)
		target->status = false;
	else
		_stat = NOSYSID;
	return _stat;
}

status_t check_lesson_sysid(LessonInfo *srcinfo, LessonInfo **dstinfo, LessonInfoList *list)
{
	status_t _stat = SUCCESS;
	while (list->info.sysid != srcinfo->sysid)
		if (list->next == NULL)
			return _stat = NOSYSID;
		else
			list = list->next;
	*dstinfo = &list->info;
	return _stat;
}

status_t sync_lessons(LessonInfoList *list)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(sync_lesson_file(list));
	return _stat;
}

status_t fetch_scornums(ScornumInfoList *list, size_t *len)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(open_scornum_file(SCORNUMFILEPATH));
	while (true) {
		list->next = (ScornumInfoList *) malloc(sizeof (ScornumInfoList));
		if (list->next == NULL) {
			_stat = ERRALOC;
			break;
		}
		_stat = fetch_scornum_file(&list->info);
		if (_stat == SUCCESS) {
			list = list->next;
			(*len)++;
		} else if (_stat = DNFETCH) {
			free((void *) list->next);
			list->next = NULL;
			_stat = SUCCESS;
			break;
		} else {
			free((void *) list->next);
			list->next = NULL;
			break;
		}
	}
}

status_t add_new_scornum(ScornumInfo *info, ScornumInfoList *list)
{
	status_t _stat = SUCCESS;
	while (list->next != NULL)
		list = list->next;
	list->next = (ScornumInfoList *) malloc(sizeof (ScornumInfoList));
	if (list->next == NULL)
		return _stat = ERRALOC;
	list->next->next = NULL;
	memcpy((void *) &list->next->info, (void *) info, sizeof (ScornumInfo));
	return _stat;
}

status_t check_scornum_sysid(ScornumInfo *srcinfo, ScornumInfo **dstinfo, ScornumInfoList *list)
{
	status_t _stat = SUCCESS;
	while ((list->info.sysid != srcinfo->sysid) || (list->info.idnum != srcinfo->idnum))
		if (list->next == NULL)
			return _stat = NOSYSID;
		else
			list = list->next;
	*dstinfo = &list->info;
	return _stat;
}

status_t sync_scornums(ScornumInfo *info, ScornumInfoList *list)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(sync_scornum_file(list));
	return _stat;
}
