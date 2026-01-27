#include "fileman.h"

static FILE *managerfile;
static FILE *employefile;
static FILE *studentfile;
static FILE *lessonsfile;
static FILE *scornumfile;

status_t open_object_file(const char *path, objecttype_t type)
{
	status_t _stat = SUCCESS;
	FILE *file;
	SET_FILE_WITH_TYPE(file, type);
	file = fopen(path, "a+");
	CHECK_PTR(file, ERROPEN);
	if (fseek(file, 0, SEEK_SET) != 0) {
		fclose(file);
		_stat = ERRSEEK;
	}
	return _stat;
}

status_t fetch_object_file(object_t *obj, objecttype_t type)
{
	status_t _stat = SUCCESS;
	FILE *file;
	SET_FILE_WITH_TYPE(file, type);
	CHECK_PTR(file, ERROPEN);
	CHECK_EQUAL(0, feof(file), DNFETCH);
	fread((void *) obj, sizeof (object_t), 1, file);
	return _stat;
}

status_t sync_object_file(node_t *nod, objecttype_t type)
{
	status_t _stat = SUCCESS;
	FILE *file;
	SET_FILE_WITH_TYPE(file, type);
	CHECK_PTR(file, ERROPEN);
	CHECK_EQUAL(0, fseek(file, 0, SEEK_SET), ERRSEEK);
	while (true) {
		fwrite((void *) nod->obj, sizeof (object_t), 1, file);
		if (IS_REACHED_END(nod))
			break;
		nod = GET_NEXT(nod);
	}
	return _stat;
}

status_t close_object_file(objecttype_t type)
{
	status_t _stat = SUCCESS;
	FILE *file;
	SET_FILE_WITH_TYPE(file, type);
	CHECK_PTR(file, ERROPEN);
	CHECK_EQUAL(0, fclose(file), ERRCLOS);
	return _stat;
}
