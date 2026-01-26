#ifndef STUDENTMAN_TYPES_H
#define STUDENTMAN_TYPES_H

#include <stddef.h>
#include <stdbool.h>
#include <time.h>

#define VERSION "0.1.0"
#define MAXUNAMESIZE 32
#define MAXPASSDSIZE 32
#define MAXLNAMESIZE 64
#define MAXGNAMESIZE 64
#define MAXIDNUMSIZE 11
#define MAXPHONESIZE 12
#define MANAGERFILEPATH "./manager.info"
#define EMPLOYEFILEPATH "./employe.info"
#define STUDENTFILEPATH "./student.info"
#define LESSONSFILEPATH "./lessons.info"
#define SCORNUMFILEPATH "./scornum.info"

#define CHECK_STAT(val)\
	do {if (val != SUCCESS) {return _stat = val;}} while (0)

#define CHECK_EQUAL(val0, val1, err)\
	do {if (val0 != val1) {return _stat = err;}} while (0)

#define CHECK_NOTEQUAL(val0, val1, err)\
	do {if (val0 == val1) {return _stat = err;}} while (0)

#define CHECK_PTR(val, err)\
	do {if (val == NULL) {return _stat = err;}} while (0)

typedef enum {
	SUCCESS,
	FAILURE,
	NOFOUND,
	NOSYSID,
	DNFETCH,
	INVPASS,
	ERRALOC,
	ERROPEN,
	ERRSEEK,
	ERRCLOS
} status_t;

typedef enum {
	MANAGER,
	EMPLOYE,
	STUDENT,
	LESSONS,
	SCORNUM
} objecttype_t;

typedef enum {
	THEORY,
	PRACTICAL,
	LABORATORY,
	WORKSHOP
} LessonType;

typedef enum {
	MAIN_ADMINLOGIN,
	MAIN_MANAGERLOGIN,
	MAIN_EMPLOYELOGIN,
	MAIN_EXIT,
	MAIN_FAILURE
} MainOpt;

typedef enum {
	ADMIN_NEW_MANAGER,
	ADMIN_NEW_EMPLOYE,
	ADMIN_LIST_MEMBER,
	ADMIN_REMOVE_MANAGER,
	ADMIN_REMOVE_EMPLOYE,
	ADMIN_REPORTS,
	ADMIN_BACKUP_DATABASE,
	ADMIN_LOGOUT,
	ADMIN_BACK,
	ADMIN_EXIT,
	ADMIN_FAILURE
} AdminOpt;

typedef enum {
	MANAGER_NEW_LESSON,
	MANAGER_NEW_SCORE,
	MANAGER_CHANGE_LESSON,
	MANAGER_CHANGE_SCORE,
	MANAGER_REMOVE_LESSON,
	MANAGER_REPORTS,
	MANAGER_ACCOUNT_SETTING,
	MANAGER_LOGOUT,
	MANAGER_BACK,
	MANAGER_EXIT,
	MANAGER_FAILURE
} ManagerOpt;

typedef enum {
	EMPLOYE_NEW_STUDENT,
	EMPLOYE_NEW_SCORE,
	EMPLOYE_CHANGE_STUDENT,
	EMPLOYE_REPORTS,
	EMPLOYE_ACCOUNT_SETTING,
	EMPLOYE_LOGOUT,
	EMPLOYE_BACK,
	EMPLOYE_EXIT,
	EMPLOYE_FAILURE
} EmployeOpt;

typedef union {
	struct ManagerInfo {
		size_t sysid;
		char uname[MAXUNAMESIZE];
		char passd[MAXPASSDSIZE];
		char fname[MAXUNAMESIZE];
		char lname[MAXLNAMESIZE];
		char gname[MAXGNAMESIZE];
		char idnum[MAXIDNUMSIZE];
		char phone[MAXPHONESIZE];
		char *email;
		bool status;
		time_t start_time;
		time_t end_time;
		time_t suspend_time;
	} manager;
	struct EmployeInfo {
		size_t sysid;
		char uname[MAXUNAMESIZE];
		char passd[MAXPASSDSIZE];
		char fname[MAXUNAMESIZE];
		char lname[MAXLNAMESIZE];
		char phone[MAXPHONESIZE];
		char *email;
		bool status;
		time_t start_time;
		time_t end_time;
		time_t suspend_time;
		unsigned int rank;
	} employe;
	struct StudnetInfo {
		size_t sysid;
		char fname[MAXUNAMESIZE];
		char lname[MAXLNAMESIZE];
		char idnum[MAXIDNUMSIZE];
		char birth[MAXLNAMESIZE];
		char major[MAXLNAMESIZE];
		char phone[MAXPHONESIZE];
		time_t birth_time;
		char *email;
	} student;
	struct LessonInfo {
		size_t sysid;
		char lname[MAXLNAMESIZE];
		unsigned short unit;
		bool status;
		LessonType type;
	} lesson;
	struct ScornumInfo {
		size_t sysid;
		char idnumstr[MAXIDNUMSIZE];
		unsigned long idnumint;
		unsigned char score;
		time_t add_time;
		struct Registrar {
			objecttype_t type;
			size_t sysid;
		} member;
	} scornum;
} object_t;

typedef struct node {
	object_t *obj;
	struct node *next;
	struct node *prev;
} node_t;

#endif
