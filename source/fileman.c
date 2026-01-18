#include "fileman.h"

static FILE *managerfile;
static FILE *employefile;

status_t open_manager_file(const char *path)
{
	status_t _stat = SUCCESS;
	managerfile = fopen(path, "a+");
	CHECK_PTR(managerfile, ERROPEN);
	if (fseek(managerfile, 0, SEEK_SET) != 0) {
		fclose(managerfile);
		_stat = ERRSEEK;
	}
	return _stat;
}

status_t fetch_manager(ManagerInfo *info)
{
	status_t _stat = SUCCESS;
	ManagerInfo tmpinfo;
	// TODO
	return _stat;
}

status_t append_manager(ManagerInfo *info)
{
	status_t _stat = SUCCESS;
	CHECK_EQUAL(0, fseek(managerfile, 0, SEEK_END), ERRSEEK);
	// TODO
	CHECK_EQUAL(0, fseek(managerfile, 0, SEEK_SET), ERRSEEK);
	return _stat;
}

status_t sync_manager(ManagerInfoList *list)
{
	status_t _stat = SUCCESS;
	// TODO
	return _stat;
}

status_t close_manager_file(void)
{
	status_t _stat = SUCCESS;
	CHECK_EQUAL(0, fclose(managerfile), ERRCLOS);
	return _stat;
}

status_t open_employe_file(const char *path)
{
	status_t _stat = SUCCESS;
	employefile = fopen(path, "a+");
	CHECK_PTR(employefile, ERROPEN);
	if (fseek(employefile, 0, SEEK_SET) != 0) {
		fclose(employefile);
		_stat = ERRSEEK;
	}
	return _stat;
}

status_t fetch_employe(EmployeInfo *info)
{
	status_t _stat = SUCCESS;
	// TODO
	return _stat;
}

status_t append_employe(EmployeInfo *info)
{
	status_t _stat = SUCCESS;
	CHECK_EQUAL(0, fseek(employefile, 0, SEEK_END), ERRSEEK);
	// TODO
	CHECK_EQUAL(0, fseek(employefile, 0, SEEK_SET), ERRSEEK);
	return _stat;
}

status_t sync_employe(EmployeInfoList *list)
{
	status_t _stat = SUCCESS;
	// TODO
	return _stat;
}

status_t close_employe_file(void)
{
	status_t _stat = SUCCESS;
	CHECK_EQUAL(0, fclose(employefile), ERRCLOS);
	return _stat;
}
