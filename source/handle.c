#include "handle.h"

node_t *manager_list;
node_t *employe_list;
node_t *student_list;
node_t *lessons_list;
node_t *scornum_list;

object_t *registrar;
objecttype_t registrar_type;

object_t *edit_obj;

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
	char uname[MAXUNAMESIZE];
	char passd[MAXPASSDSIZE];
	for (int i = 1; i <= TRYCOUNT; i++)
		if ((inctl_get_uname(uname, "Enter Admin Username : ") == SUCCESS) && (strcmp("admin", uname) == 0))
			break;
		else if (i == TRYCOUNT)
			return;
	for (int i = 1; i <= TRYCOUNT; i++)
		if ((inctl_get_passd(passd, "Enter Admin Password : ") == SUCCESS) && (strcmp("p455w0rd", passd) == 0))
			break;
		else if (i == TRYCOUNT)
			return;
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
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_fname(obj->manager.fname) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_lname(obj->manager.lname) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_uname(obj->manager.uname) == SUCCESS) {
			obj->manager.sysid = checksum(obj->manager.uname, strnlen(obj->manager.uname, MAXUNAMESIZE));
			if (check_object_sysid(manager_list, obj, NULL, MANAGER) == NOFOUND)
				break;
			logic_error("username %s already in use, try different one", obj->manager.uname);
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_passd(obj->manager.passd) == SUCCESS) {
			break;	
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_gname(obj->manager.gname) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_date(&obj->manager.start_time) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_idnum(obj->manager.idnum) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_phone(obj->manager.phone) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_email(obj->manager.email) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
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
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_employe_fname(obj->employe.fname) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_employe_lname(obj->employe.lname) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_employe_uname(obj->employe.uname) == SUCCESS) {
			obj->employe.sysid = checksum(obj->employe.uname, strnlen(obj->employe.uname, MAXUNAMESIZE));
			if (check_object_sysid(employe_list, obj, NULL, EMPLOYE) == NOFOUND)
				break;
			logic_error("username %s already in use, try different one", obj->employe.uname);
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_employe_passd(obj->employe.passd) == SUCCESS) {
			break;	
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_employe_date(&obj->employe.start_time) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_employe_phone(obj->employe.phone) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_employe_email(obj->employe.email) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_employe_rank(&obj->employe.rank) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	obj->employe.status = true;
	if ((_stat = add_object(employe_list, obj)) != SUCCESS) {
		stat_error(_stat, "failed to add employe, try again!");
		free((void *) obj);
	}
	return;
}

void handle_list_members(void)
{
	outctl_list_member(manager_list, MANAGER);
	outctl_list_member(employe_list, EMPLOYE);
	return;
}

void handle_remove_manager(void)
{
	status_t _stat = SUCCESS;
	object_t obj;
	object_t *found_obj;
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_uname(obj.manager.uname) == SUCCESS) {
			if (check_object_sysid(manager_list, &obj, &found_obj, MANAGER) == SUCCESS) {
				if (remove_object(manager_list, found_obj) == NOFOUND)
					found_error("remove failed! this error must not happen! ABORT...");
				break;
			}
			found_error("there is no manager with username %s in database", obj.manager.uname);
		} else if (i == TRYCOUNT) {
			return;
		}
	return;	
}

void handle_remove_employe(void)
{
	status_t _stat = SUCCESS;
	object_t obj;
	object_t *found_obj;
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_employe_uname(obj.employe.uname) == SUCCESS) {
			if (check_object_sysid(employe_list, &obj, &found_obj, EMPLOYE) == NOFOUND) {
				if (remove_object(employe_list, found_obj) == NOFOUND)
					found_error("remove failed! this error must not happen! ABORT...");
				break;
			}
			found_error("there is no employee with username %s in database", obj.employe.uname);
		} else if (i == TRYCOUNT) {
			return;
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
	object_t obj;
	size_t lessons_count;
	size_t scornum_count;
	time_t access_time;
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_uname(obj.manager.uname) == SUCCESS) {
			obj.manager.sysid = checksum(obj.manager.uname, strnlen(obj.manager.uname, MAXUNAMESIZE));
			if (check_object_sysid(manager_list, &obj, &registrar, MANAGER) == SUCCESS)
				break;
			logic_error("there is no username %s in database, first you need a Manager Account", obj.manager.uname);
		} else if (i == TRYCOUNT) {
			return;
		}
	if (time(&access_time) == -1)
		fatal_error_exit("program failed to retrieve time with time() call! exiting...");
	if (access_time - registrar->manager.suspend_time < SUSPENDTIME) {
		logic_error("your account has been suspended, wait 5 minutes then login again");
		registrar = NULL;
		return;
	}
	for (int i = 1; i <= TRYCOUNT; i++)
		if ((inctl_get_manager_passd(obj.manager.passd) == SUCCESS) && (strcmp(registrar->manager.passd, obj.manager.passd) == 0)) {
			break;
		} else if (i == TRYCOUNT) {
			registrar = NULL;
			return;
		}
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
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_lesson_lname(obj->lesson.lname) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i < TRYCOUNT; i++)
		if (inctl_get_lesson_sysid(&obj->lesson.sysid) == SUCCESS) {
			if (check_object_sysid(lessons_list, obj, NULL, LESSONS) == NOFOUND)
				break;
			logic_error("sysid %zu already in use, try different one", obj->lesson.sysid);
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_lesson_unit(&obj->lesson.unit) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_lesson_type(&obj->lesson.type) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
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
	for (int i = 1; i <= TRYCOUNT; i++)
		if ((inctl_get_scornum_sysid(&obj->scornum.sysid) == SUCCESS) && (inctl_get_scornum_idnum(obj->scornum.idnumstr, &obj->scornum.idnumint) == SUCCESS)) {
			if (check_object_sysid(scornum_list, obj, NULL, SCORNUM) == NOFOUND)
				break;
			logic_error("combination of sysid %zu and idnum %s already in use, try different one", obj->scornum.sysid, obj->scornum.idnumstr);
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_scornum_score(&obj->scornum.score) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	if (time(&obj->scornum.add_time) == -1)
		fatal_error_exit("program failed to retrieve time with time() call! exiting...");
	obj->scornum.member.sysid = ((obj->scornum.member.type = registrar_type) == MANAGER) ? registrar->manager.sysid : registrar->employe.sysid;
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
	object_t obj;
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_lesson_sysid(&obj.lesson.sysid) == SUCCESS) {
			if (check_object_sysid(lessons_list, &obj, &edit_obj, LESSONS) == SUCCESS)
				break;
			logic_error("there is no lesson with sysid %zu in database", obj.lesson.sysid);
		} else if (i == TRYCOUNT) {
			return;
		}
	CLEARSCRN();
	while (true)
		HANDLE(inact_change_lesson_info);
	return;
}

void handle_change_lesson_name(void)
{
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_lesson_lname(edit_obj->lesson.lname) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	return;
}

void handle_change_lesson_unit(void)
{
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_lesson_unit(&edit_obj->lesson.unit) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	return;
}

void handle_change_lesson_type(void)
{
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_lesson_type(&edit_obj->lesson.type) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	return;
}

void handle_change_lesson_back(void)
{
	status_t _stat = SUCCESS;
	if ((_stat = upload_objects(lessons_list, LESSONS)) != SUCCESS)
		stat_error(_stat, "failed to sync lessons linked-list to database! your recent edits haven't save, do it again");
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
	object_t obj;
	for (int i = 1; i <= TRYCOUNT; i++)
		if ((inctl_get_scornum_sysid(&obj.scornum.sysid) == SUCCESS) && (inctl_get_scornum_idnum(obj.scornum.idnumstr, &obj.scornum.idnumint) == SUCCESS)) {
			if (check_object_sysid(scornum_list, &obj, &edit_obj, SCORNUM) == SUCCESS)
				break;
			logic_error("there is no score with sysid %zu and idnum %s in database", obj.scornum.sysid, obj.scornum.idnumstr);
		} else if (i == TRYCOUNT) {
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_scornum_score(&edit_obj->scornum.score) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	if ((_stat = upload_objects(scornum_list, SCORNUM)) != SUCCESS)
		stat_error(_stat, "failed to sync scores linked-list to database! your recent edits havan't save, do it again");
	return;
}

void handle_remove_lesson(void)
{
	status_t _stat = SUCCESS;
	object_t obj;
	object_t *found_obj;
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_lesson_sysid(&obj.lesson.sysid) == SUCCESS) {
			if ((_stat = check_object_sysid(lessons_list, &obj, &found_obj, LESSONS)) == NOFOUND) {
				if (remove_object(lessons_list, found_obj) == NOFOUND)
					found_error("remove failed! this error must not happen! ABORT...");
				break;
			}
			found_error("there is no lesson with sysid %zu in database", obj.lesson.sysid);
		} else if (i == TRYCOUNT) {
			return;
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

void handle_manager_account_password(void)
{
	char passd[MAXPASSDSIZE] = {0};
	for (int i = 0; i <= TRYCOUNT; i++)
		if (inctl_get_manager_passd(passd) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	strncpy(registrar->manager.passd, passd, MAXPASSDSIZE);
	return;
}

void handle_manager_account_phone(void)
{
	char phone[MAXPHONESIZE] = {0};
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_phone(phone) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	strncpy(registrar->manager.phone, phone, MAXPHONESIZE);
	return;
}

void handle_manager_account_email(void)
{
	char email[MAXEMAILSIZE] = {0};
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_manager_email(email) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	strncpy(registrar->manager.email, email, MAXEMAILSIZE);
	return;
}

void handle_manager_account_back(void)
{
	status_t _stat = SUCCESS;
	if ((_stat = upload_objects(manager_list, MANAGER)) != SUCCESS)
		stat_error(_stat, "failed to sync manager linked-list to database! your recent edits haven't save, do it again");
}

void handle_manager_account_exit(void)
{
	handle_manager_account_back();
	exit(EXIT_SUCCESS);
	return;
}

void handle_manager_account_failure(void)
{
	handle_admin_failure();
	return;
}

void handle_manager_back(void)
{
	status_t _stat = SUCCESS;
	if ((_stat = upload_objects(lessons_list, LESSONS)) != SUCCESS)
		stat_error(_stat, "failed to sync lessons linked-list to database");
	if ((_stat = upload_objects(scornum_list, SCORNUM)) != SUCCESS)
		stat_error(_stat, "failed to sync scores linked-list to database");
}

void handle_manager_exit(void)
{
	handle_manager_back();
	exit(EXIT_SUCCESS);
	return;
}

void handle_manager_failure(void)
{
	handle_admin_failure();
	return;
}

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
	object_t obj;
	size_t student_count;
	size_t scornum_count;
	time_t access_time;
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_employe_uname(obj.employe.uname) == SUCCESS) {
			obj.employe.sysid = checksum(obj.employe.uname, strnlen(obj.employe.uname, MAXUNAMESIZE));
			if (check_object_sysid(employe_list, &obj, &registrar, EMPLOYE) == SUCCESS)
				break;
			logic_error("there is no username %s in database, first you need a Employee Account", obj.employe.uname);
		} else if (i == TRYCOUNT) {
			return;
		}
	if (time(&access_time) == -1)
		fatal_error_exit("program failed to retrieve time with time() call! exiting...");
	if (access_time - registrar->employe.suspend_time < SUSPENDTIME) {
		logic_error("your account has been suspended, wait 5 minutes then login again");
		registrar = NULL;
		return;
	}
	for (int i = 1; i <= TRYCOUNT; i++)
		if ((inctl_get_employe_passd(obj.employe.passd) == SUCCESS) && (strcmp(registrar->employe.passd, obj.employe.passd) == 0)) {
			break;
		} else if (i == TRYCOUNT) {
			registrar = NULL;
			return;
		}
	registrar_type = EMPLOYE;
	outctl_log("downloading lessons data from database...");
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

void handle_new_student(void)
{
	status_t _stat = SUCCESS;
	object_t *obj = (object_t *) calloc(1, sizeof (object_t));
	if (obj == NULL)
		fatal_error_exit("memory allocation failed! exiting...");
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_fname(obj->student.fname) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_lname(obj->student.lname) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_sysid(&obj->student.sysid) == SUCCESS) {
			if (check_object_sysid(student_list, obj, NULL, STUDENT) == NOFOUND)
				break;
			logic_error("sysid %zu already in use, try different one", obj->student.sysid);
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_major(obj->student.major) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_idnum(obj->student.idnum) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_birth(obj->student.birth) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_birth_time(&obj->student.birth_time) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_phone(obj->student.phone) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_email(obj->student.email) == SUCCESS) {
			break;
		} else if (i == TRYCOUNT) {
			free((void *) obj);
			obj = NULL;
			return;
		}
	if ((_stat = add_object(scornum_list, obj)) != SUCCESS) {
		stat_error(_stat, "failed to add new score, try again");
		free((void *) obj);
	}
	return;
}

void handle_change_student(void)
{
	handler_t hdl[] = {
		handle_change_student_major,
		handle_change_student_phone,
		handle_change_student_email,
		handle_change_student_back,
		handle_change_student_exit,
		handle_change_student_failure
	};
	object_t obj;
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_sysid(&obj.student.sysid) == SUCCESS) {
			if (check_object_sysid(student_list, &obj, &edit_obj, STUDENT) == SUCCESS)
				break;
			logic_error("there is no student with sysid %zu in database", obj.student.sysid);
		} else if (i == TRYCOUNT) {
			return;
		}
	while (true)
		HANDLE(inact_change_student_info);
	return;
}

void handle_change_student_major(void)
{
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_major(edit_obj->student.major) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	return;
}

void handle_change_student_phone(void)
{
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_phone(edit_obj->student.phone) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	return;
}

void handle_change_student_email(void)
{
	for (int i = 1; i <= TRYCOUNT; i++)
		if (inctl_get_student_email(edit_obj->student.email) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	return;
}

void handle_change_student_back(void)
{
	status_t _stat = SUCCESS;
	if ((_stat = upload_objects(student_list, STUDENT)) != SUCCESS)
		stat_error(_stat, "failed to sync student linked-list to database");
	return;
}

void handle_change_student_exit(void)
{
	handle_change_student_back();
	exit(EXIT_SUCCESS);
	return;
}

void handle_change_student_failure(void)
{
	handle_admin_failure();
	return;
}

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

void handle_employe_account_password(void)
{
	char passd[MAXPASSDSIZE] = {0};
	for (int i = 0; i <= TRYCOUNT; i++)
		if (inctl_get_employe_passd(passd) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	strncpy(registrar->employe.passd, passd, MAXPASSDSIZE);
	return;
}

void handle_employe_account_phone(void)
{
	char phone[MAXPHONESIZE] = {0};
	for (int i = 0; i <= TRYCOUNT; i++)
		if (inctl_get_employe_phone(phone) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	strncpy(registrar->employe.phone, phone, MAXPHONESIZE);
	return;
}

void handle_employe_account_email(void)
{
	char email[MAXEMAILSIZE] = {0};
	for (int i = 0; i <= TRYCOUNT; i++)
		if (inctl_get_employe_email(email) == SUCCESS)
			break;
		else if (i == TRYCOUNT)
			return;
	strncpy(registrar->employe.email, email, MAXEMAILSIZE);
	return;
}

void handle_employe_account_back(void)
{
	status_t _stat = SUCCESS;
	if ((_stat = upload_objects(employe_list, EMPLOYE)) != SUCCESS)
		stat_error(_stat, "failed to sync employe linked-list to database");
	return;
}

void handle_employe_account_exit(void)
{
	handle_employe_account_back();
	exit(EXIT_SUCCESS);
	return;
}

void handle_employe_account_failure(void)
{
	handle_admin_failure();
	return;
}

void handle_employe_back(void)
{
	status_t _stat = SUCCESS;
	if ((_stat = upload_objects(student_list, STUDENT)) != SUCCESS)
		stat_error(_stat, "failed to sync student linked-list to database");
	if ((_stat = upload_objects(scornum_list, SCORNUM)) != SUCCESS)
		stat_error(_stat, "failed to sync scores linked-list to database");
	return;
}

void handle_employe_exit(void)
{
	handle_employe_back();
	exit(EXIT_SUCCESS);
	return;
}

void handle_employe_failure(void)
{
	handle_admin_failure();
	return;
}

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
