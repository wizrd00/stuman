#ifndef STUDENTMANAGER_INTERACT_H
#define STUDENTMANAGER_INTERACT_H

#include "types.h"
#include "objectctl.h"
#include <stdio.h>

#define CHECK_SCANF(val0, val1, err)\
	do {if (val0 != val1) {return _opt = MAIN_FAILURE;}} while (0)

void inact_appinfo(void);

MainOpt inact_main(void);

AdminOpt inact_admin(void);

ManagerOpt inact_manager(void);

EmployeOpt inact_employe(void);

AdminReportOpt inact_admin_report(void);

ChangeLessonInfoOpt inact_change_lesson_info(void);

ManagerReportOpt inact_manager_report(void);

ManagerAccountOpt inact_manager_account(void);

ChangeStudentInfoOpt inact_change_student_info(void);

EmployeReportOpt inact_employe_report(void);

EmployeAccountOpt inact_employe_account(void);

extern const char *intro;
extern const char *main_options;
extern const char *admin_options;
extern const char *manager_options;
extern const char *employe_options;
extern const char *admin_report_options;
extern const char *change_lesson_info_options;
extern const char *manager_report_options;
extern const char *manager_account_options;
extern const char *change_student_info_options;
extern const char *employe_report_options;
extern const char *employe_account_options;

#endif
