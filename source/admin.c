#include "admin.h"

status_t fetch_managers(ManagerInfoList *list, size_t *len)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(open_manager_file(MANAGERFILEPATH));
	while (true) {
		list->next = (ManagerInfoList *) malloc(sizeof (ManagerInfoList));
		if (list->next == NULL) {
			_stat = ERRALOC;
			break;
		}
		_stat = fetch_manager(&list->info);
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

status_t add_new_manager(ManagerInfo *info, ManagerInfoList *list)
{
	status_t _stat = SUCCESS;
	while (list->next != NULL)
		list = list->next;
	list->next = (ManagerInfoList *) malloc(sizeof (ManagerInfoList));
	if (list->next == NULL)
		return _stat = ERRALOC;
	list->next->next = NULL;
	memcpy((void *) &list->next->info, (void *) info, sizeof (ManagerInfo));
	CHECK_STAT(append_manager(&list->next->info));
	return _stat;
}

status_t remove_manager(ManagerInfo *info, ManagerInfoList *list)
{
	status_t _stat = SUCCESS;
	ManagerInfo *target;
	if (check_manager_sysid(info, &target, list) == SUCCESS) {
		target->end_time = time(NULL);
		target->status = false;
	}
	return _stat;
}

status_t check_manager_sysid(ManagerInfo *srcinfo, ManagerInfo **dstinfo, ManagerInfoList *list)
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

status_t sync_managers_file(ManagerInfoList *list)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(sync_manager(list));
	return _stat;
}

status_t fetch_employes(EmployeInfoList *list, size_t *len)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(open_employe_file(EMPLOYEFILEPATH));
	while (true) {
		list->next = (EmployeInfoList *) malloc(sizeof (EmployeInfoList));
		if (list->next == NULL) {
			_stat = ERRALOC;
			break;
		}
		_stat = fetch_employe(&list->info);
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

status_t add_new_employe(EmployeInfo *info, EmployeInfoList *list)
{
	status_t _stat = SUCCESS;
	while (list->next != NULL)
		list = list->next;
	list->next = (EmployeInfoList *) malloc(sizeof (EmployeInfoList));
	if (list->next == NULL)
		return _stat = ERRALOC;
	list->next->next = NULL;
	memcpy((void *) &list->next->info, (void *) info, sizeof (EmployeInfo));
	CHECK_STAT(append_employe(&list->next->info));
	return _stat;
}


status_t remove_employe(EmployeInfo *info, EmployeInfoList *list)
{
	status_t _stat = SUCCESS;
	EmployeInfo *target;
	if (check_employe_sysid(info, &target, list) == SUCCESS) {
		target->end_time = time(NULL);
		target->status = false;
	}
	return _stat;
}

status_t check_employe_sysid(EmployeInfo *srcinfo, EmployeInfo **dstinfo, EmployeInfoList *list)
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

status_t sync_employes_file(EmployeInfoList *list)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(sync_employe(list));
	return _stat;
}
