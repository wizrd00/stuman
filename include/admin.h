#ifndef STUDENTMAN_ADMIN_H
#define STUDENTMAN_ADMIN_H

#include "types.h"
#include "fileman.h"
#include <stdlib.h>
#include <time.h>

status_t fetch_managers(ManagerInfoList *list, size_t *len);

status_t add_new_manager(ManagerInfo *info, ManagerInfoList *list);

status_t remove_manager(ManagerInfo *info, ManagerInfoList *list);

status_t check_manager_sysid(ManagerInfo *srcinfo, ManagerInfo **dstinfo, ManagerInfoList *list);

status_t sync_managers_file(ManagerInfoList *list);

status_t fetch_employes(ManagerInfoList *list, size_t *len);

status_t add_new_employe(EmployeInfo *info, EmployeInfoList *list);

status_t remove_employe(EmployeInfo *info, EmployeInfoList *list);

status_t check_empolye_sysid(ManagerInfo *srcinfo, EmployeInfo **dstinfo,  EmployeInfoList *list);

status_t sync_employes_file(EmployeInfoList *list);

#endif
