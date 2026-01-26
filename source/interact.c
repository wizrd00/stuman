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
