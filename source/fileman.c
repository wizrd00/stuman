#include "fileman.h"

static FILE *managerfile;
static FILE *employefile;
static FILE *lessonsfile;
static FILE *scornumfile;

status_t open_member_file(const char *path, MemberType type)
{
	status_t _stat = SUCCESS;
	FILE *file = FILEWITHTYPE(type);
	file = fopen(path, "a+");
	CHECK_PTR(file, ERROPEN);
	if (fseek(file, 0, SEEK_SET) != 0) {
		fclose(file);
		_stat = ERRSEEK;
	}
	return _stat;
}

status_t fetch_member_file(MemberInfo *info, MemberType type)
{
	status_t _stat = SUCCESS;
	FILE *file = FILEWITHTYPE(type);
	MemberInfo tmpinfo;
	// TODO
	return _stat;
}

status_t sync_member_file(MemberInfoList *list, MemberType type)
{
	status_t _stat = SUCCESS;
	FILE *file = FILEWITHTYPE(type);
	// TODO
	return _stat;
}

status_t close_member_file(MemberType type)
{
	status_t _stat = SUCCESS;
	FILE *file = FILEWITHTYPE(type);
	CHECK_EQUAL(0, fclose(file), ERRCLOS);
	return _stat;
}

status_t open_lesson_file(const char *path)
{
	status_t _stat = SUCCESS;
	lessonsfile = fopen(path, "a+");
	CHECK_PTR(lessonsfile, ERROPEN);
	if (fseek(lessonsfile, 0, SEEK_SET) != 0) {
		fclose(lessonsfile);
		_stat = ERRSEEK;
	}
	return _stat;
}

status_t fetch_lesson_file(LessonInfo *info)
{
	status_t _stat = SUCCESS;
	LessonInfo tmpinfo;
	// TODO
	return _stat;
}

status_t sync_lesson_file(LessonInfoList *list)
{
	status_t _stat = SUCCESS;
	// TODO
	return _stat;
}

status_t close_lesson_file(void)
{
	status_t _stat = SUCCESS;
	CHECK_EQUAL(0, fclose(lessonsfile), ERRCLOS);
	return _stat;
}

status_t open_scornum_file(const char *path)
{
	status_t _stat = SUCCESS;
	scornumfile = fopen(path, "a+");
	CHECK_PTR(scornumfile, ERROPEN);
	if (fseek(scornumfile, 0, SEEK_SET) != 0) {
		fclose(scornumfile);
		_stat = ERRSEEK;
	}
	return _stat;
}

status_t fetch_scornum_file(ScornumInfo *info)
{
	status_t _stat = SUCCESS;
	ScornumInfo tmpinfo;
	// TODO
	return _stat;
}

status_t sync_scornum_file(ScornumInfoList *list)
{
	status_t _stat = SUCCESS;
	// TODO
	return _stat;
}

status_t close_scornum_file(void)
{
	status_t _stat = SUCCESS;
	CHECK_EQUAL(0, fclose(scornumfile), ERRCLOS);
	return _stat;
}
