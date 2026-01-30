#include "inputctl.h"

static status_t inctl_get_string(char *string, size_t size)
{
	status_t _stat = SUCCESS;
	char *linefeed;
	if (fgets(string, size, stdin) == NULL)
		return _stat = ERRREAD;
	if ((linefeed = strchr(string, '\n')) != NULL)
		*linefeed = '\0';
	return _stat;
}

static status_t inctl_get_hidden_string(char *string, size_t size)
{
	status_t _stat = SUCCESS;
	char key;
	#if defined(__linux__)
	struct termios default_setting;
	struct termios changed_setting;
	tcgetattr(fileno(stdin), &default_setting);
	tcgetattr(fileno(stdin), &changed_setting);
	changed_setting.c_lflag &= ~ICANON;
	changed_setting.c_cflag &= ~ECHO;
	if (tcsetattr(fileno(stdin), TCSANOW, &changed_setting) == -1)
		return _stat = FAILURE;
	for (int i = 0; i < size - 1; i++) {
		key = (char) getchar();
		if (key == '\n')
			break;
		if (key == EOF)
			return _stat = ERRREAD;
		string[i] = key;
		putchar('*');
	}
	if (tcsetattr(fileno(stdin), TCSANOW, &default_setting) == -1)
		return _stat = FAILURE;
	#elif defined(_WIN32)
	for (int i = 0; i < size - 1; i++) {
		if ((key = getch()) == '\n')
			break;
		string[i] = key;
		putchar('*');
	}
	#endif
	string[size - 1] = '\0';
	return _stat;
}

status_t inctl_get_uname(char *uname, const char *msg)
{
	char tmp_uname[MAXUNAMESIZE] = {0};
	status_t _stat = SUCCESS;
	if (fputs(msg, stdout) == EOF)
		return _stat = ERRWRIT;
	CHECK_STAT(inctl_get_string(tmp_uname, MAXUNAMESIZE));
	if (!check_username_format(tmp_uname))
		return _stat = FAILFMT;
	strncpy(uname, tmp_uname, MAXUNAMESIZE);
	return _stat;
}

status_t inctl_get_passd(char *passd, const char *msg)
{
	status_t _stat = SUCCESS;
	char tmp_passd[MAXPASSDSIZE] = {0};
	if (fputs(msg, stdout) == EOF)
		return _stat = ERRWRIT;
	CHECK_STAT(inctl_get_hidden_string(tmp_passd, MAXPASSDSIZE));
	if (!check_username_format(tmp_passd))
		return _stat = FAILFMT;
	strncpy(passd, tmp_passd, MAXPASSDSIZE);
	return _stat;
}

status_t inctl_get_manager_fname(char *fname)
{
	status_t _stat = SUCCESS;
	char tmp_fname[MAXUNAMESIZE] = {0};
	if (fputs(INCTL_FNAMEMSG, stdout) == EOF)
		return _stat = ERRWRIT;
	CHECK_STAT(inctl_get_string(tmp_fname, MAXUNAMESIZE));
	if (!check_alphabet_format(tmp_fname))
		return _stat = FAILFMT;
	strncpy(fname, tmp_fname, MAXUNAMESIZE);
	return _stat;
}

status_t inctl_get_manager_lname(char *lname)
{
	status_t _stat = SUCCESS;
	char tmp_lname[MAXLNAMESIZE] = {0};
	if (fputs(INCTL_LNAMEMSG, stdout) == EOF)
		return _stat = ERRWRIT;
	CHECK_STAT(inctl_get_string(tmp_lname, MAXLNAMESIZE));
	if (!check_alphabet_format(tmp_lname))
		return _stat = FAILFMT;
	strncpy(lname, tmp_lname, MAXLNAMESIZE);
	return _stat;
}

status_t inctl_get_manager_uname(char *uname)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(inctl_get_uname(uname, INCTL_UNAMEMSG));
	return _stat;
}

status_t inctl_get_manager_passd(char *passd)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(inctl_get_passd(passd, INCTL_PASSDMSG));
	return _stat;
}

status_t inctl_get_manager_gname(char *gname)
{
	status_t _stat = SUCCESS;
	if (fputs(INCTL_GNAMEMSG, stdout) == EOF)
		return _stat = ERRWRIT;
	CHECK_STAT(inctl_get_string(gname, MAXGNAMESIZE));
	return _stat;
}

status_t inctl_get_manager_date(time_t *dst)
{
	status_t _stat = SUCCESS;
	char datestr[INCTL_DATESIZE] = {0};
	time_t tmp_time;
	struct tm date;
	memset((void *) &date, 0, sizeof (struct tm));
	if (fputs(INCTL_DATEMSG, stdout) == EOF)
		return _stat = ERRWRIT;
	CHECK_STAT(inctl_get_string(datestr, INCTL_DATESIZE));
	sscanf(datestr, "%d/%d/%d", &date.tm_year, &date.tm_mon, &date.tm_mday);
	if ((tmp_time = mktime(&date)) == -1)
		return _stat = ERRTIME;
	*dst = tmp_time;
	return _stat;
}

status_t inctl_get_manager_idnum(char *idnum);

status_t inctl_get_manager_phone(char *phone);

status_t inctl_get_manager_email(char *email);

status_t inctl_get_employe_fname(char *fname);

status_t inctl_get_employe_lname(char *lname);

status_t inctl_get_employe_uname(char *uname);

status_t inctl_get_employe_passd(char *passd);

status_t inctl_get_employe_date(time_t *dst);

status_t inctl_get_employe_phone(char *phone);

status_t inctl_get_employe_email(char *email);

status_t inctl_get_employe_rank(unsigned int *rank);

status_t inctl_get_lesson_lname(char *lname);

status_t inctl_get_lesson_sysid(size_t *sysid);

status_t inctl_get_lesson_unit(unsigned short *unit);

status_t inctl_get_lesson_type(LessonType *type);

status_t inctl_get_scornum_sysid(size_t *sysid);

status_t inctl_get_scornum_idnum(char *idnumstr, unsigned long *idnumint);

status_t inctl_get_scornum_score(unsigned char *score);

status_t inctl_get_student_fname(char *fname);

status_t inctl_get_student_lname(char *lname);

status_t inctl_get_student_sysid(size_t *sysid);

status_t inctl_get_student_major(char *major);

status_t inctl_get_student_idnum(char *idnum);

status_t inctl_get_student_birth(char *birth);

status_t inctl_get_student_birth_time(time_t *dst);

status_t inctl_get_student_phone(char *phone);

status_t inctl_get_student_email(char *email);
