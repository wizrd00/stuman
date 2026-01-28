#ifndef STUDENTMANAGER_HANDLE_H
#define STUDENTMANAGER_HANDLE_H

#include "types.h"
#include "interact.h"
#include "inputctl.h"
#include "outputctl.h"
#include "errorctl.h"
#include "utils/scrnclear.h"
#include <stdlib.h>

#define HANDLE(func)\
	do {hdl[func()](); CLEARSCRN();} while (0)

typedef void (*handler_t)(void);

void handle_main(void);

void handle_admin(void);

void handle_new_manager(void);

void handle_new_employe(void);

void handle_list_members(void);

void handle_remove_manager(void);

void handle_remove_employe(void);

void handle_admin_reports(void);

void handle_admin_report_employes_list(void);

void handle_admin_report_managers_list(void);

void handle_admin_report_fired_employes_list(void);

void handle_admin_report_back(void);

void handle_admin_report_exit(void);

void handle_admin_report_failure(void);

void handle_backup_database(void);

void handle_admin_back(void);

void handle_admin_exit(void);

void handle_admin_failure(void);

void handle_manager(void);

void handle_new_lesson(void);

void handle_new_scornum(void);

void handle_change_lesson(void);

void handle_change_lesson_name(void);

void handle_change_lesson_unit(void);

void handle_change_lesson_type(void);

void handle_change_lesson_back(void);

void handle_change_lesson_exit(void);

void handle_change_lesson_failure(void);

void handle_manager_reports(void);

void handle_manager_report_find_students_byfname(void);

void handle_manager_report_find_students_bylname(void);

void handle_manager_report_find_student_byidnum(void);

void handle_manager_report_list_students_info(void);

void handle_manager_report_list_lessons_info(void);

void handle_manager_report_list_removed_lessons(void);

void handle_manager_report_list_active_lessons(void);

void handle_manager_report_student_scores(void);

void handle_manager_report_student_scores_lesson(void);

void handle_manager_report_student_average(void);

void handle_manager_report_lesson_average(void);

void handle_manager_report_list_students_average(void);

void handle_manager_report_lesson_passed_students(void);

void handle_manager_report_lesson_failed_students(void);

void handle_manager_report_list_failed_students(void);

void handle_manager_report_back(void);

void handle_manager_report_exit(void);

void handle_manager_report_failure(void);

void handle_manager_account(void);

void handle_manager_account_password(void);

void handle_manager_account_phone(void);

void handle_manager_account_email(void);

void handle_manager_account_back(void);

void handle_manager_account_exit(void);

void handle_manager_account_failure(void);

void handle_change_scornum(void);

void handle_remove_lesson(void);

void handle_manager_back(void);

void handle_manager_exit(void);

void handle_manager_failure(void);

void handle_employe(void);

void handle_new_student(void);

void handle_new_scornum(void);

void handle_change_student(void);

void handle_employe_reports(void);

void handle_employe_account(void);

void handle_employe_back(void);

void handle_employe_exit(void);

void handle_employe_failure(void);

void handle_employe_change_student(void);

void handle_change_student_major(void);

void handle_change_student_phone(void);

void handle_change_student_email(void);

void handle_change_student_back(void);

void handle_change_student_exit(void);

void handle_change_student_failure(void);

void handle_employe_reports(void);

void handle_employe_report_find_students_byfname(void);

void handle_employe_report_find_students_bylname(void);

void handle_employe_report_find_student_byidnum(void);

void handle_employe_report_list_students_date_range(void);

void handle_employe_report_list_students_major(void);

void handle_employe_report_list_students_city(void);

void handle_employe_report_back(void);

void handle_employe_report_exit(void);

void handle_employe_report_failure(void);

void handle_employe_account(void);

void handle_employe_account_password(void);

void handle_employe_account_phone(void);

void handle_employe_account_email(void);

void handle_employe_account_back(void);

void handle_employe_account_exit(void);

void handle_employe_account_failure(void);

void handle_back(void);

void handle_exit(void);

void handle_failure(void);

extern node_t *manager_list;
extern node_t *employe_list;
extern node_t *student_list;
extern node_t *lessons_list;
extern node_t *scornum_lsit;

#endif
