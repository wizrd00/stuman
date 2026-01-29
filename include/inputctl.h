#ifndef STUDENTMANAGER_INPUTCTL_H
#define STUDENTMANAGER_INPUTCTL_H

#include "types.h"
#include "utils/unamecheck.h"
#include "utils/passdcheck.h"
#include <stdio.h>

status_t inctl_get_uname(char *uname, const char *msg);

status_t inctl_get_passd(char *passd, const char *msg);

status_t inctl_get_manager_fname(char *fname);

status_t inctl_get_manager_lname(char *lname);

status_t inctl_get_manager_uname(char *uname);

status_t inctl_get_manager_passd(char *passd);

status_t inctl_get_manager_gname(char *gname);

status_t inctl_get_manager_date(time_t *dst);

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

#endif
