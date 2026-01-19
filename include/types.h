#ifndef STUDENTMAN_TYPES_H
#define STUDENTMAN_TYPES_H

#include <stddef.h>
#include <stdbool.h>
#include <time.h>

#define MAXUNAMESIZE 32
#define MAXPASSDSIZE 32
#define MAXLNAMESIZE 2 * MAXUNAMESIZE
#define MAXGNAMESIZE 2 * MAXUNAMESIZE
#define MAXIDNUMSIZE 11
#define MAXPHONESIZE 12
#define MANAGERFILEPATH "./manager.info"
#define EMPLOYEFILEPATH "./employe.info"
#define LESSONSFILEPATH "./lessons.info"
#define SCORNUMFILEPATH "./scornum.info"
#define STUDENTFILEPATH "./student.info"

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

typedef enum {
	MANAGER,
	EMPLOYE
} MemberType;

typedef enum {
	THEORY,
	PRACTICAL,
	LABORATORY,
	WORKSHOP
} LessonType;

typedef struct {
	size_t sysid; //checksum of uname
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
	unsigned int rank;
	MemberType type;
} MemberInfo;

typedef struct memberlist {
	MemberInfo info;
	struct memberlist *next;
} MemberInfoList;

typedef struct {
	size_t sysid; //code dars
	char lname[MAXLNAMESIZE];
	unsigned short unit;
	bool status;
	LessonType type;
} LessonInfo;

typedef struct lessonlist {
	LessonInfo info;
	struct lessonlist *next;
} LessonInfoList;

typedef struct {
	size_t sysid; //code dars
	unsigned long idnum;
	unsigned char score;
	time_t add_time;
	struct member {
		MemberType type;
		size_t sysid; //checksum of member uname
	};
} ScornumInfo;

typedef struct scornumlist {
	ScornumInfo info;
	struct scornumlist *next;
} ScornumInfoList;

#endif
