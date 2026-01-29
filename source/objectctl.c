#include "objectctl.h"

static status_t init_first_node(node_t *nod)
{
	status_t _stat = SUCCESS;
	nod = (node_t *) malloc(sizeof (node_t));
	CHECK_PTR(nod, ERRALOC);
	nod->obj = (object_t *) malloc(sizeof (object_t));
	CHECK_PTR(nod->obj, ERRALOC);
	return _stat;
}

static bool compare_manager(object_t *obj0, object_t *obj1)
{
	return (obj0->manager.sysid == obj1->manager.sysid) ? true : false;
}

static bool compare_employe(object_t *obj0, object_t *obj1)
{
	return (obj0->employe.sysid == obj1->employe.sysid) ? true : false;
}

static bool compare_student(object_t *obj0, object_t *obj1)
{
}

static bool compare_lessons(object_t *obj0, object_t *obj1)
{
	return (obj0->lesson.sysid == obj1->lesson.sysid) ? true : false;
}

static bool compare_scornum(object_t *obj0, object_t *obj1)
{
	return ((obj0->scornum.sysid == obj1->scornum.sysid) && (obj0->scornum.idnumint == obj1->scornum.idnumint)) ? true : false;
}

status_t download_objects(node_t **nod, size_t *len, objecttype_t typ)
{
	status_t _stat = SUCCESS;
	object_t *obj;
	CHECK_STAT(init_first_node(*nod));
	CHECK_EQUAL(DNFETCH, fetch_object_file((*nod)->obj, typ), DNFETCH);
	while (true) {
		CHECK_STAT(node_alloce(&obj));
		if ((_stat = fetch_object_file(obj, typ)) == DNFETCH)
			break;
		CHECK_STAT(node_append(*nod, obj, APPEND_TOP));
		GET_HEAD_NODE(*nod);
		(*len)++;
	}
	return _stat;
}

status_t add_object(node_t *nod, object_t *obj)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(node_append(nod, obj, APPEND_BTM));
	return _stat;
}

status_t remove_object(node_t *nod, object_t *obj)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(node_remove(nod, obj));
	return _stat;
}

status_t check_object_sysid(node_t *nod, object_t *obj, object_t **hdl, objecttype_t typ)
{
	status_t _stat = SUCCESS;
	bool (*cmp)(object_t *obj0, object_t *obj1);
	node_t *found_node;
	switch (typ) {
	case MANAGER : cmp = compare_manager; break;
	case EMPLOYE : cmp = compare_employe; break;
	case STUDENT : cmp = compare_student; break;
	case LESSONS : cmp = compare_lessons; break;
	case SCORNUM : cmp = compare_scornum; break;
	}
	CHECK_STAT(node_search(nod, &found_node, obj, cmp));
	if (*hdl != NULL)
		*hdl = found_node->obj;
	return _stat;
}

status_t upload_members(node_t *nod, objecttype_t typ)
{
	status_t _stat = SUCCESS;
	CHECK_STAT(sync_object_file(nod, typ));
	return _stat;
}
