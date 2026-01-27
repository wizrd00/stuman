#include "interact.h"

const char *intro =
	"Welcome to StuMan version " VERSION "\n"
	"\t|\n"
	"\t|____Maintainer : Arash Ghaffari (homework project for IKIU)\n"
	"\t|____GitHub : https://github.com/wizrd00\n"
	"\t|____Written in : The C99 (ISO99)\n"
	"\t|____Help : in all menus `b` is for return back to previous menu and `q` is for exit the program\n";
const char *inputstr = "Enter your choice(q:exit, b:back) : ";
const char *main_options =
	"\n"
	"1.Admin login\n"
	"2.Manager login\n"
	"3.Employee login\n\n";
const char *admin_options =
	"\n"
	"1.Add new Manager\n"
	"2.Add new Employee\n"
	"3.List members\n"
	"4.Remove specific manager\n"
	"5.Remove specific employee\n"
	"6.Reports\n"
	"7.Backup database\n"
	"8.Logout\n";
const char *manager_options =
	"\n"
	"1.Add new lesson\n"
	"2.Add new Score\n"
	"3.Change specific lesson information\n"
	"4.Change specific score information\n"
	"5.Remove specific lesson\n"
	"6.Reports\n"
	"7.Account settings\n"
	"8.Logout\n";
const char *employe_options =
	"\n"
	"1.Add new student\n"
	"2.Add new Score\n"
	"3.Change specific student information\n"
	"4.Reports\n"
	"5.Account settings\n"
	"6.Logout\n";
const char *admin_report_options =
	"\n"
	"1.List all employees\n"
	"2.List all managers\n"
	"3.List all fired employees\n";
const char *change_lesson_info_options =
	"\n"
	"1.Change lesson name\n"
	"2.Change lesson unit\n"
	"3.Change lesson type\n";
const char *manager_report_options =
	"\n"
	"1.Find students by first name\n"
	"2.Find students by last name\n"
	"3.Find students by id number\n"
	"4.List all students information\n"
	"5.List all lessons information\n"
	"6.List all removed lessons\n"
	"7.List all active lessons\n"
	"8.Scores of specific student\n"
	"9.Scores of students in specific lesson\n"
	"a.Average score of specific student\n"
	"c.Average score of specific lesson\n"
	"d.List all students ordered by average score\n"
	"e.List students who passed specific lesson\n"
	"f.List students who failed specific lesson\n"
	"g.List all failed students\n";
const char *manager_account_options =
	"\n"
	"1.Change password\n"
	"2.Change phone number\n"
	"3.Change email address\n";

void inact_appinfo(void)
{
	printf(intro);
	return;
}

MainOpt inact_main(void)
{
	MainOpt _opt;
	char inopt;
	printf(main_options);
	printf(inputstr);
	CHECK_SCANF(scanf("%c", &inopt), 1, MAIN_FAILURE);
	switch (inopt) {
	case '1' : _opt = MAIN_ADMINLOGIN; break;
	case '2' : _opt = MAIN_EMPLOYELOGIN; break;
	case '3' : _opt = MAIN_EMPLOYELOGIN; break;
	case 'q' : case 'b' : _opt = MAIN_EXIT; break;
	default : _opt = MAIN_FAILURE;
	}
	return _opt;
}

AdminOpt inact_admin(void)
{
	AdminOpt _opt;
	char inopt;
	printf(admin_options);
	printf(inputstr);
	CHECK_SCANF(scanf("%c", &inopt), 1, ADMIN_FAILURE);
	switch (inopt) {
	case '1' : _opt = ADMIN_NEW_EMPLOYE; break;
	case '2' : _opt = ADMIN_NEW_EMPLOYE; break;
	case '3' : _opt = ADMIN_LIST_MEMBER; break;
	case '4' : _opt = ADMIN_REMOVE_EMPLOYE; break;
	case '5' : _opt = ADMIN_REMOVE_EMPLOYE; break;
	case '6' : _opt = ADMIN_REPORTS; break;
	case '7' : _opt = ADMIN_BACKUP_DATABASE; break;
	case '8' : _opt = ADMIN_LOGOUT; break;
	case 'b' : _opt = ADMIN_BACK; break;
	case 'q' : _opt = ADMIN_EXIT; break;
	default : _opt = ADMIN_FAILURE;
	}
	return _opt;
}

ManagerOpt inact_manager(void)
{
	ManagerOpt _opt;
	char inopt;
	printf(manager_options);
	printf(inputstr);
	CHECK_SCANF(scanf("%c", &inopt), 1, MANAGER_FAILURE);
	switch (inopt) {
	case '1' : _opt = MANAGER_NEW_LESSON; break;
	case '2' : _opt = MANAGER_NEW_SCORE; break;
	case '3' : _opt = MANAGER_CHANGE_LESSON; break;
	case '4' : _opt = MANAGER_CHANGE_SCORE; break;
	case '5' : _opt = MANAGER_REMOVE_LESSON; break;
	case '6' : _opt = MANAGER_REPORTS; break;
	case '7' : _opt = MANAGER_ACCOUNT_SETTING; break;
	case '8' : _opt = MANAGER_LOGOUT; break;
	case 'b' : _opt = MANAGER_BACK; break;
	case 'q' : _opt = MANAGER_EXIT; break;
	default : _opt = MANAGER_FAILURE;
	}
	return _opt;
}

EmployeOpt inact_employe(void)
{
	EmployeOpt _opt;
	char inopt;
	printf(employe_options);
	printf(inputstr);
	CHECK_SCANF(scanf("%c", &inopt), 1, EMPLOYE_FAILURE);
	switch (inopt) {
	case '1' : _opt = EMPLOYE_NEW_STUDENT; break;
	case '2' : _opt = EMPLOYE_NEW_SCORE; break;
	case '3' : _opt = EMPLOYE_CHANGE_STUDENT; break;
	case '4' : _opt = EMPLOYE_REPORTS; break;
	case '5' : _opt = EMPLOYE_ACCOUNT_SETTING; break;
	case '6' : _opt = EMPLOYE_LOGOUT; break;
	case 'b' : _opt = EMPLOYE_BACK; break;
	case 'q' : _opt = EMPLOYE_EXIT; break;
	default : _opt = EMPLOYE_FAILURE;
	}
	return _opt;
}

AdminReportOpt inact_admin_report(void)
{
	AdminReportOpt _opt;
	char inopt;
	printf(admin_report_options);
	printf(inputstr);
	CHECK_SCANF(scanf("%c", &inopt), 1, ADMIN_REPORT_FAILURE);
	switch (inopt) {
	case '1' : _opt = ADMIN_REPORT_EMPLOYES_LIST; break;
	case '2' : _opt = ADMIN_REPORT_MANAGERS_LIST; break;
	case '3' : _opt = ADMIN_REPORT_FIRED_EMPLOYES_LIST; break;
	case 'b' : _opt = ADMIN_REPORT_BACK; break;
	case 'q' : _opt = ADMIN_REPORT_EXIT; break;
	default : _opt = ADMIN_REPORT_FAILURE;
	}
	return _opt;
}

ChangeLessonInfoOpt inact_change_lesson_info(void)
{
	ChangeLessonInfoOpt _opt;
	char inopt;
	printf(change_lesson_info_options);
	printf(inputstr);
	CHECK_SCANF(scanf("%c", &inopt), 1, CHANGE_LESSON_INFO_FAILURE);
	switch (inopt) {
	case '1' : _opt = CHANGE_LESSON_INFO_NAME; break;
	case '2' : _opt = CHANGE_LESSON_INFO_UNIT; break;
	case '3' : _opt = CHANGE_LESSON_INFO_TYPE; break;
	case 'b' : _opt = CHANGE_LESSON_INFO_BACK; break;
	case 'q' : _opt = CHANGE_LESSON_INFO_EXIT; break;
	default : _opt = CHANGE_LESSON_INFO_FAILURE;
	}
}

ManagerReportOpt inact_manager_report(void)
{
	ManagerReportOpt _opt;
	char inopt;
	printf(manager_report_options);
	printf(inputstr);
	CHECK_SCANF(scanf("%c", &inopt), 1, MANAGER_REPORT_FAILURE);
	switch (inopt) {
	case '1' : _opt = MANAGER_REPORT_FIND_STUDENTS_INFO_BYFIRSTNAME; break;
	case '2' : _opt = MANAGER_REPORT_FIND_STUDENTS_INFO_BYLASTNAME; break;
	case '3' : _opt = MANAGER_REPORT_FIND_STUDENT_INFO_BYIDNUM; break;
	case '4' : _opt = MANAGER_REPORT_LIST_STUDENTS_INFO; break;
	case '5' : _opt = MANAGER_REPORT_LIST_LESSONS_INFO; break;
	case '6' : _opt = MANAGER_REPORT_LIST_REMOVED_LESSONS; break;
	case '7' : _opt = MANAGER_REPORT_LIST_ACTIVE_LESSONS; break;
	case '8' : _opt = MANAGER_REPORT_SPECIFIC_STUDENT_SCORES; break;
	case '9' : _opt = MANAGER_REPORT_STUDENTS_SCORES_SPECIFIC_LESSON; break;
	case 'a' : _opt = MANAGER_REPORT_SPECIFIC_STUDENT_AVERAGE; break;
	case 'c' : _opt = MANAGER_REPORT_SPECIFIC_LESSON_AVERAGE; break;
	case 'd' : _opt = MANAGER_REPORT_LIST_STUDENTS_BYAVERAGE; break;
	case 'e' : _opt = MANAGER_REPORT_SPECIFIC_LESSON_PASSED_STUDENTS; break;
	case 'f' : _opt = MANAGER_REPORT_SPECIFIC_LESSON_FAILED_STUDENTS; break;
	case 'g' : _opt = MANAGER_REPORT_LIST_FAILED_STUDENTS; break;
	case 'b' : _opt = MANAGER_REPORT_BACK; break;
	case 'q' : _opt = MANAGER_REPORT_EXIT; break;
	defautl : MANAGER_REPORT_FAILURE;
	}
	return _opt;
}

ManagerAccountOpt inact_manager_account(void)
{
	ManagerAccountOpt _opt;
	char inopt;
	printf(manager_account_options);
	printf(inputstr);
	CHECK_SCANF(scanf("%c", &inopt), 1, MANAGER_ACCOUNT_FAILURE);
	switch (inopt) {
	case '1' : _opt = MANAGER_ACCOUNT_CHANGE_PASSWORD; break;
	case '2' : _opt = MANAGER_ACCOUNT_CHANGE_PHONE; break;
	case '3' : _opt = MANAGER_ACCOUNT_CHANGE_EMAIL; break;
	case '4' : _opt = MANAGER_ACCOUNT_BACK; break;
	case '5' : _opt = MANAGER_ACCOUNT_EXIT; break;
	default : _opt = MANAGER_ACCOUNT_FAILURE;
	}
	return _opt;
}
