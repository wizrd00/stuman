#include "admin.h"

status_t fetch_members(MemberInfoList *list, size_t *len, MemberType type)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(open_member_file(MANAGERFILEPATH, type));
	while (true) {
		list->next = (MemberInfoList *) malloc(sizeof (MemberInfoList));
		if (list->next == NULL) {
			_stat = ERRALOC;
			break;
		}
		_stat = fetch_member_file(&list->info, type);
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
	return _stat;
}

status_t add_new_member(MemberInfo *info, MemberInfoList *list, MemberType type)
{
	status_t _stat = SUCCESS;
	while (list->next != NULL)
		list = list->next;
	list->next = (MemberInfoList *) malloc(sizeof (MemberInfoList));
	if (list->next == NULL)
		return _stat = ERRALOC;
	list->next->next = NULL;
	memcpy((void *) &list->next->info, (void *) info, sizeof (MemberInfo));
	return _stat;
}

status_t remove_member(MemberInfo *info, MemberInfoList *list, MemberType type)
{
	status_t _stat = SUCCESS;
	MemberInfo *target;
	if (check_member_sysid(info, &target, list, type) == SUCCESS) {
		target->end_time = time(NULL);
		target->status = false;
	} else {
		_stat = NOSYSID;
	}
	return _stat;
}

status_t check_member_sysid(MemberInfo *srcinfo, MemberInfo **dstinfo, MemberInfoList *list, MemberType type)
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

status_t sync_members(MemberInfoList *list, MemberType type)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(sync_member_file(list, type));
	return _stat;
}
