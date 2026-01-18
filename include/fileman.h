#ifndef STUDENTMAN_FILEMAN_H
#define STUDENTMAN_FILEMAN_H

#include "types.h"
#include <stdio.h>

status_t open_manager_file(const char *path);

status_t fetch_manager(ManagerInfo *info);

status_t append_manager(ManagerInfo *info);

status_t sync_manager(ManagerInfoList *list);

status_t close_manager_file(void);

status_t open_employe_file(const char *path);

status_t fetch_employe(EmployeInfo *info);

status_t append_employe(EmployeInfo *info);

status_t sync_employe(EmployeInfoList *list);

status_t close_employe_file(void);

#endif
