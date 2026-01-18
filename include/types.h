#ifndef STUDENTMAN_TYPES_H
#define STUDENTMAN_TYPES_H

#include <stddef.h>

#define MAXUNAMESIZE 32
#define MAXPASSDSIZE 32
#define MAXNAMESIZE 32
#define MAXIDNUMSIZE 10
#define MAXPHONESIZE 11
#define MANAGERFILEPATH "./manager.info"
#define EMPLOYEFILEPATH "./employe.info"

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
	NOSYSID,
	DNFETCH,
	INVPASS,
	ERRALOC,
	ERROPEN,
	ERRSEEK,
	ERRCLOS
} status_t;

typedef struct {
	size_t sysid;
	char uname[MAXUNAMESIZE];
	char passd[MAXPASSDSIZE];
	char fname[MAXNAMESIZE];
	char lname[2 * MAXNAMESIZE];
	char gname[2 * MAXNAMESIZE];
	char idnum[MAXIDNUMSIZE];
	char phone[MAXPHONESIZE];
	char *email;
	bool status;
	time_t start_time;
	time_t end_time;
	time_t suspend_time;
} ManagerInfo;

typedef struct managerlist {
	ManagerInfo info;
	struct managerlist *next;
} ManagerInfoList;

typedef struct {
	size_t sysid;
	char uname[MAXUNAMESIZE];
	char passd[MAXPASSDSIZE];
	char fname[MAXNAMESIZE];
	char lname[2 * MAXNAMESIZE];
	char phone[MAXPHONESIZE];
	char *email;
	bool status;
	time_t start_time;
	time_t end_time;
	time_t suspend_time;
	unsigned int rank;
} EmployeInfo;

typedef struct employelist {
	EmployeInfo info;
	struct employelist *next;
} EmployeInfoList;

#endif
