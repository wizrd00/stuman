#include "handle.h"

node_t *manager_list;
node_t *employe_list;
node_t *student_list;
node_t *lessons_list;
node_t *scornum_list;

object_t *registrar;
objecttype_t registrar_type;

object_t *editable_obj;

void handle_main(void)
{
	status_t _stat = SUCCESS;
	handler_t hdl[] = {
		handle_admin,
		handle_manager,
		handle_employe,
		handle_back,
		handle_exit,
		handle_failure
	};
	size_t manager_count;
	size_t employe_count;
	outctl_log("downloading managers data from database...");
	if ((_stat = download_objects(&manager_list, &manager_count, MANAGER)) == SUCCESS)
		outctl_log("%zu managers found and downloaded", manager_count);
	else
		stat_error_exit(_stat, "downloading managers data failed, exiting...");
	outctl_log("downloading employees data from database...");
	if ((_stat = download_objects(&employe_list, &employe_count, EMPLOYE)) == SUCCESS)
		outctl_log("%zu employees found and downloaded", employe_count);
	else
		stat_error_exit(_stat, "downloading employees data failed, exiting...");
	CLEARSCRN();
	while (true)
		HANDLE(inact_main);
	return;
}

void handle_admin(void)
{
	status_t _stat = SUCCESS;
	handler_t hdl[] = {
		handle_new_manager,
		handle_new_employe,
		handle_list_members,
		handle_remove_manager,
		handle_remove_employe,
		handle_admin_reports,
		handle_backup_database,
		handle_admin_back,
		handle_admin_back,
		handle_admin_exit,
		handle_admin_failure
	};
	CHECK_INCTL(inctl_verify_admin_uname());
	CHECK_INCTL(inctl_verify_admin_passd());
	while (true)
		HANDLE(inact_admin);
	return;
}

void handle_new_manager(void)
{
	status_t _stat = SUCCESS;
	object_t *obj = (object_t *) calloc(1, sizeof (object_t));
	if (obj == NULL)
		fatal_error_exit("memory allocation failed! exiting...");
	CHECK_INCTL_FREE(inctl_get_fname(obj->manager.fname), obj);
	CHECK_INCTL_FREE(inctl_get_lname(obj->manager.lname), obj);
	CHECK_INCTL_FREE(inctl_get_uname(obj->manager.uname, &obj->manager.sysid, manager_list), obj);
	CHECK_INCTL_FREE(inctl_get_passd(obj->manager.passd), obj);
	CHECK_INCTL_FREE(inctl_get_gname(obj->manager.gname), obj);
	CHECK_INCTL_FREE(inctl_get_date(&obj->manager.start_time), obj);
	CHECK_INCTL_FREE(inctl_get_idnum(obj->manager.idnum), obj);
	CHECK_INCTL_FREE(inctl_get_phone(obj->manager.phone), obj);
	CHECK_INCTL_FREE(inctl_get_email(obj->manager.email), obj);
	obj->manager.status = true;
	if ((_stat = add_object(manager_list, obj)) != SUCCESS) {
		stat_error(_stat, "failed to add manager, try again!");
		free((void *) obj);
	}
	return;
}

void handle_new_employe(void)
{
	status_t _stat = SUCCESS;
	object_t *obj = (object_t *) calloc(1, sizeof (object_t));
	if (obj == NULL)
		fatal_error_exit("memory allocation failed! exiting...");
	CHECK_INCTL_FREE(inctl_get_fname(obj->employe.fname), obj);
	CHECK_INCTL_FREE(inctl_get_lname(obj->employe.lname), obj);
	CHECK_INCTL_FREE(inctl_get_uname(obj->employe.uname, &obj->employe.sysid, employe_list), obj);
	CHECK_INCTL_FREE(inctl_get_passd(obj->employe.passd), obj);
	CHECK_INCTL_FREE(inctl_get_date(&obj->employe.start_time), obj);
	CHECK_INCTL_FREE(inctl_get_phone(obj->employe.phone), obj);
	CHECK_INCTL_FREE(inctl_get_email(obj->employe.email), obj);
	CHECK_INCTL_FREE(inctl_get_rank(&obj->employe.rank), obj);
	obj->employe.status = true;
	if ((_stat = add_object(employe_list, obj)) != SUCCESS) {
		stat_error(_stat, "failed to add employe, try again!");
		free((void *) obj);
	}
	return;
}

void handle_list_members(void)
{
	CHECK_OUTCTL(outctl_list_member(manager_list));
	CHECK_OUTCTL(outctl_list_member(employe_list));
	return;
}

void handle_remove_manager(void)
{
	status_t _stat = SUCCESS;
	object_t obj;
	object_t *found_obj;
	CHECK_INCTL(inctl_get_uname(obj.manager.uname, &obj.manager.sysid, NULL));
	if ((_stat = check_object_sysid(manager_list, &obj, &found_obj, MANAGER)) == NOFOUND) {
		found_error("there is no manager with username %s in database", obj.manager.uname);
	} else {
		if (remove_object(manager_list, found_obj) == NOFOUND)
			found_error("remove failed! this error must not happen! ABORT...");
	}
	return;	
}

void handle_remove_employe(void)
{
	status_t _stat = SUCCESS;
	object_t obj;
	object_t *found_obj;
	CHECK_INCTL(inctl_get_uname(obj.employe.uname, &obj.employe.sysid, NULL));
	if ((_stat = check_object_sysid(employe_list, &obj, &found_obj, EMPLOYE)) == NOFOUND) {
		found_error("there is no employee with username %s in database", obj.employe.uname);
	} else {
		if (remove_object(employe_list, found_obj) == NOFOUND)
			found_error("remove failed! this error must not happen! ABORT...");
	}
	return;
}

void handle_admin_reports(void)
{
	handler_t hdl[] = {
		handle_admin_report_employes_list,
		handle_admin_report_managers_list,
		handle_admin_report_fired_employes_list,
		handle_admin_report_back,
		handle_admin_report_exit,
		handle_admin_report_failure
	};
	while (true)
		HANDLE(inact_admin_report);
	return;
}

void handle_admin_report_employes_list(void);

void handle_admin_report_managers_list(void);

void handle_admin_report_fired_employes_list(void);

void handle_admin_report_back(void);

void handle_admin_report_exit(void);

void handle_admin_report_failure(void);

void handle_backup_database(void)
{
	// will implement at the end
}

void handle_admin_back(void)
{
	status_t _stat = SUCCESS;
	outctl_log("\nsync to database...\n");
	if ((_stat = upload_objects(manager_list, MANAGER)) != SUCCESS)
		stat_error_exit(_stat, "failed to sync manager linked-list to database");
	if ((_stat = upload_objects(employe_list, EMPLOYE)) != SUCCESS)
		stat_error_exit(_stat, "failed to sync employe linked-list to database");
	return;
}

void handle_admin_exit(void)
{
	handle_admin_back();
	exit(EXIT_SUCCESS);
	return;
}

void handle_admin_failure(void)
{
	logic_error("you have entered wrong option, try over");
	return;
}

void handle_manager(void)
{
	status_t _stat = SUCCESS;
	handler_t hdl[] = {
		handle_new_lesson,
		handle_new_scornum,
		handle_change_lesson,
		handle_change_scornum,
		handle_remove_lesson,
		handle_manager_reports,
		handle_manager_account,
		handle_manager_back,
		handle_manager_back,
		handle_manager_exit,
		handle_manager_failure
	};
	size_t lessons_count;
	size_t scornum_count;
	time_t access_time;
	CHECK_INCTL(inctl_search_manager(&registrar, manager_list));
	if (time(&access_time) == -1)
		fatal_error_exit("program failed to retrieve time with time() call! exiting...");
	if (access_time - registrar->manager.suspend_time < SUSPENDTIME) {
		logic_error("your account has been suspended, wait 5 minutes");
		registrar = NULL;
		return;
	}
	CHECK_INCTL(inctl_verify_passd(registrar->manager.passd));
	registrar_type = MANAGER;
	outctl_log("downloading lessons data from database...");
	if ((_stat = download_objects(&lessons_list, &lessons_count, LESSONS)) == SUCCESS)
		outctl_log("%zu lessons found and downloaded", lessons_count);
	else
		stat_error_exit(_stat, "downloading lessons data failed, exiting...");
	outctl_log("downloading scores data from database...");
	if ((_stat = download_objects(&scornum_list, &scornum_count, SCORNUM)) == SUCCESS)
		outctl_log("%zu scores found and downloaded", scornum_count);
	else
		stat_error_exit(_stat, "downloading scores data failed, exiting...");
	CLEARSCRN();
	while (true)
		HANDLE(inact_manager);
	return;
}

void handle_new_lesson(void)
{
	status_t _stat = SUCCESS;
	object_t *obj = (object_t *) calloc(1, sizeof (object_t));
	if (obj == NULL)
		fatal_error_exit("memory allocation failed! exiting...");
	CHECK_INCTL_FREE(inctl_get_lesson_name(obj->lesson.lname), obj);
	CHECK_INCTL_FREE(inctl_get_lesson_sysid(&obj->lesson.sysid, lessons_list), obj);
	CHECK_INCTL_FREE(inctl_get_lesson_unit(&obj->lesson.unit), obj);
	CHECK_INCTL_FREE(inctl_get_lesson_type(&obj->lesson.type), obj);
	if ((_stat = add_object(lessons_list, obj)) != SUCCESS) {
		stat_error(_stat, "failed to add new lesson, try again");
		free((void *) obj);
	}
	return;
}

void handle_new_scornum(void)
{
	status_t _stat = SUCCESS;
	object_t *obj = (object_t *) calloc(1, sizeof (object_t));
	if (obj == NULL)
		fatal_error_exit("memory allocation failed! exiting...");
	CHECK_INCTL_FREE(inctl_get_scornum_sysid(&obj->scornum.sysid, scornum_list), obj);
	CHECK_INCTL_FREE(inctl_get_scornum_idnum(obj->scornum.idnumstr, &obj->scornum.idnumint), obj);
	CHECK_INCTL_FREE(inctl_get_scornum_score(&obj->scornum.score), obj);
	if (time(&obj->scornum.add_time) == -1)
		fatal_error_exit("program failed to retrieve time with time() call! exiting...");
	obj->scornum.member.sysid = registrar->scornum.sysid;
	obj->scornum.member.type = registrar_type;
	if ((_stat = add_object(scornum_list, obj)) != SUCCESS) {
		stat_error(_stat, "failed to add new score, try again");
		free((void *) obj);
	}
	return;
}

void handle_change_lesson(void)
{
	status_t _stat = SUCCESS;
	handler_t hdl[] = {
		handle_change_lesson_name,
		handle_change_lesson_unit,
		handle_change_lesson_type,
		handle_change_lesson_back,
		handle_change_lesson_exit,
		handle_change_lesson_failure
	};
	CHECK_INCTL(inctl_search_lesson_sysid(&editable_obj, lessons_list));
	while (true)
		HANDLE(inact_change_lesson_info);
	return;
}

void handle_change_lesson_name(void)
{
	CHECK_INCTL(inctl_get_lesson_name(editable_obj->lesson.lname));
	return;
}

void handle_change_lesson_unit(void)
{
	CHECK_INCTL(inctl_get_lesson_unit(&editable_obj->lesson.unit));
	return;
}

void handle_change_lesson_type(void)
{
	CHECK_INCTL(inctl_get_lesson_type(&editable_obj->lesson.type));
	return;
}

void handle_change_lesson_back(void)
{
	status_t _stat = SUCCESS;
	if ((_stat = upload_objects(lessons_list, LESSONS)) != SUCCESS)
		stat_error(_stat, "failed to sync lessons linked-list to database");
	return;
}

void handle_change_lesson_exit(void)
{
	handle_change_lesson_back();
	exit(EXIT_SUCCESS);
	return;
}

void handle_change_lesson_failure(void)
{
	handle_admin_failure();
	return;
}

void handle_change_scornum(void)
{
	status_t _stat = SUCCESS;
	CHECK_INCTL(inctl_search_scornum(&editable_obj, scornum_list));
	CHECK_INCTL(inctl_get_scornum_score(&editable_obj->scornum.score));
	if ((_stat = upload_objects(scornum_list, SCORNUM)) != SUCCESS)
		stat_error(_stat, "failed to sync scores linked-list to database");
	return;
}

void handle_remove_lesson(void)
{
	status_t _stat = SUCCESS;
	object_t obj;
	object_t *found_obj;
	CHECK_INCTL(inctl_get_lesson_sysid(&obj.lesson.sysid, NULL));
	if ((_stat = check_object_sysid(lessons_list, &obj, &found_obj, LESSONS)) == NOFOUND) {
		found_error("there is no lesson with sysid %zu in database", obj.lesson.sysid);
	} else {
		if (remove_object(lessons_list, found_obj) == NOFOUND)
			found_error("remove failed! this error must not happen! ABORT...");
	}
	return;
}

void handle_manager_reports(void)
{
	handler_t hdl[] = {
		handle_manager_report_find_students_byfname,
		handle_manager_report_find_students_bylname,
		handle_manager_report_find_student_byidnum,
		handle_manager_report_list_students_info,
		handle_manager_report_list_lessons_info,
		handle_manager_report_list_removed_lessons,
		handle_manager_report_list_active_lessons,
		handle_manager_report_student_scores,
		handle_manager_report_student_scores_lesson,
		handle_manager_report_student_average,
		handle_manager_report_lesson_average,
		handle_manager_report_list_students_average,
		handle_manager_report_lesson_passed_students,
		handle_manager_report_lesson_failed_students,
		handle_manager_report_list_failed_students,
		handle_manager_report_back,
		handle_manager_report_exit,
		handle_manager_report_failure
	};
	while (true)
		HANDLE(inact_manager_report);
	return;
}

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

void handle_manager_account(void)
{
	handler_t hdl[] = {
		handle_manager_account_password,
		handle_manager_account_phone,
		handle_manager_account_email,
		handle_manager_account_back,
		handle_manager_account_exit,
		handle_manager_account_failure
	};
	while (true)
		HANDLE(inact_manager_account);
	return;
}

void handle_manager_account_password(void);

void handle_manager_account_phone(void);

void handle_manager_account_email(void);

void handle_manager_account_back(void);

void handle_manager_account_exit(void);

void handle_manager_account_failure(void);

void handle_manager_back(void);

void handle_manager_exit(void);

void handle_manager_failure(void);

void handle_employe(void)
{
	status_t _stat = SUCCESS;
	handler_t hdl[] = {
		handle_new_student,
		handle_new_scornum,
		handle_change_student,
		handle_employe_reports,
		handle_employe_account,
		handle_employe_back,
		handle_employe_back,
		handle_employe_exit,
		handle_employe_failure
	};
	size_t student_count;
	size_t scornum_count;
	time_t access_time;
	CHECK_INCTL(inctl_search_employe(&registrar, employe_list));
	if (time(&access_time) == -1)
		fatal_error_exit("program failed to retrieve time with time() call! exiting...");
	if (access_time - registrar->employe.suspend_time < SUSPENDTIME) {
		logic_error("your account has been suspended, wait 5 minutes");
		registrar = NULL;
		return;
	}
	CHECK_INCTL(inctl_verify_passd(registrar->employe.passd));
	registrar_type = EMPLOYE;
	outctl_log("downloading students data from database...");
	if ((_stat = download_objects(&student_list, &student_count, STUDENT)) == SUCCESS)
		outctl_log("%zu students found and downloaded", student_count);
	else
		stat_error_exit(_stat, "downloading students data failed, exiting...");
	outctl_log("downloading scores data from database...");
	if ((_stat = download_objects(&scornum_list, &scornum_count, SCORNUM)) == SUCCESS)
		outctl_log("%zu scores found and downloaded", scornum_count);
	else
		stat_error_exit(_stat, "downloading scores data failed, exiting...");
	CLEARSCRN();
	while (true)
		HANDLE(inact_employe);
	return;
}

void handle_new_student(void);

void handle_new_scornum(void);

void handle_change_student(void);

void handle_employe_reports(void);

void handle_employe_account(void);

void handle_employe_back(void);

void handle_employe_back(void);

void handle_employe_exit(void);

void handle_employe_failure(void);

void handle_employe_change_student(void)
{
	handler_t hdl[] = {
		handle_change_student_major,
		handle_change_student_phone,
		handle_change_student_email,
		handle_change_student_back,
		handle_change_student_exit,
		handle_change_student_failure
	};
	while (true)
		HANDLE(inact_change_student_info);
	return;
}

void handle_change_student_major(void);

void handle_change_student_phone(void);

void handle_change_student_email(void);

void handle_change_student_back(void);

void handle_change_student_exit(void);

void handle_change_student_failure(void);

void handle_employe_reports(void)
{
	handler_t hdl[] = {
		handle_employe_report_find_students_byfname,
		handle_employe_report_find_students_bylname,
		handle_employe_report_find_student_byidnum,
		handle_employe_report_list_students_date_range,
		handle_employe_report_list_students_major,
		handle_employe_report_list_students_city,
		handle_employe_report_back,
		handle_employe_report_exit,
		handle_employe_report_failure
	};
	while (true)
		HANDLE(inact_employe_report);
	return;
}

void handle_employe_report_find_students_byfname(void);

void handle_employe_report_find_students_bylname(void);

void handle_employe_report_find_student_byidnum(void);

void handle_employe_report_list_students_date_range(void);

void handle_employe_report_list_students_major(void);

void handle_employe_report_list_students_city(void);

void handle_employe_report_back(void);

void handle_employe_report_exit(void);

void handle_employe_report_failure(void);

void handle_employe_account(void)
{
	handler_t hdl[] = {
		handle_employe_account_password,
		handle_employe_account_phone,
		handle_employe_account_email,
		handle_employe_account_back,
		handle_employe_account_exit,
		handle_employe_account_failure
	};
	while (true)
		HANDLE(inact_employe_account);
	return;
}

void handle_employe_account_password(void);

void handle_employe_account_phone(void);

void handle_employe_account_email(void);

void handle_employe_account_back(void);

void handle_employe_account_exit(void);

void handle_employe_account_failure(void);

void handle_back(void)
{
	logic_error("You are in Main menu, so you can't go back any further");
	return;
}

void handle_exit(void)
{
	status_t _stat = SUCCESS;
	outctl_log("\nsync to database...\n");
	if ((_stat = upload_objects(manager_list, MANAGER)) != SUCCESS)
		stat_error(_stat, "failed to sync manager linked-list to database");
	if ((_stat = upload_objects(employe_list, EMPLOYE)) != SUCCESS)
		stat_error(_stat, "failed to sync employe linked-list to database");
	if ((_stat = upload_objects(student_list, STUDENT)) != SUCCESS)
		stat_error(_stat, "failed to sync student linked-list to database");
	if ((_stat = upload_objects(lessons_list, LESSONS)) != SUCCESS)
		stat_error(_stat, "failed to sync lessons linked-list to database");
	if ((_stat = upload_objects(scornum_list, SCORNUM)) != SUCCESS)
		stat_error(_stat, "failed to sync scores linked-list to database");
	return;
}
