#ifndef STUDENTMANAGER_INPUTCTL_H
#define STUDENTMANAGER_INPUTCTL_H

#include "types.h"
#include "objectctl.h"
#include <stdio.h>

int inctl_get_uname(char *uname, size_t *sysid, node_t *nod)
{
	if (nod == NULL) // don't search
		;
	else //search the list
		;
	return 0;
}

int inctl_get_passd(char *passd);

int inctl_get_fname(char *fname);

int inctl_get_lname(char *lname);

int inctl_get_gname(char *gname);

int inctl_get_date(time_t *_time);

int inctl_get_idnum(char *idnum);

int inctl_get_phone(char *phone);

int inctl_get_email(char *email);

int inctl_get_rank(unsigned int *rank);

int inctl_verify_admin_uname(void);

int inctl_verify_admin_passd(void);

int inctl_search_manager(object_t **obj, node_t *nod);

int inctl_verify_passd(const char *passd);

int inctl_get_lesson_name(char *lname);

int inctl_get_lesson_sysid(size_t *sysid, node_t *nod);

int inctl_get_lesson_unit(unsigned short *unit);

int inctl_get_lesson_type(LessonType *type);

int inctl_get_scornum_sysid(size_t *sysid, node_t *nod);

int inctl_get_scornum_idnum(char *idnumstr, unsigned long *idnumint);

int inctl_get_scornum_score(unsigned char *score);

int inctl_search_lesson_sysid(object_t **obj, node_t *nod);

int inctl_search_scornum(object_t **obj, node_t *nod);

int inctl_search_employe(object_t **obj, node_t *nod);

#endif
