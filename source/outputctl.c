#include "outputctl.h"

int outctl_log(char *msg, ...)
{
	va_list ap;
	va_start(ap, msg);
	fputs("[LOG] ", stdout);
	vprintf(msg, ap);
	putchar('\n');
	va_end(ap);
	return 0;
}


int outctl_list_member(node_t *nod, objecttype_t typ)
{
	object_t *obj;
	char date[21];
	struct tm *lctime;
	if (nod == NULL)
		return 0;
	switch (typ) {
	case MANAGER :
		fputs("Managers\n", stdout);
		fputs("    |\n    |", stdout);
		while (true) {
			obj = nod->obj;
			lctime = localtime(&obj->manager.start_time);
			if (lctime == NULL)
				return -1;
			strftime(date, sizeof (date), "%F  %T", lctime);
			fputs("-> ", stdout);
			printf("Manager %s %s with username '%s' in group %s start at %s\n    |", obj->manager.fname, obj->manager.lname, obj->manager.uname, obj->manager.gname, date);
			if (!ISNOT_REACHED_END(nod))
				break;
			nod = GET_NEXT(nod);
		}
		break;
	case EMPLOYE :
		fputs("Employees\n", stdout);
		fputs("    |\n    |", stdout);
		while (true) {
			obj = nod->obj;
			lctime = localtime(obj->employe.start_time);
			if (lctime == NULL)
				return -1;
			strftime(date, sizeof (date), "%F  %T", lctime);
			fputs("-> ", stdout);
			printf("Employee %s %s with username '%s' start at %s\n    |", obj->employe.fname, obj->employe.lname, obj->employe.uname, date);
			if (!ISNOT_REACHED_END(nod))
				break;
			nod = GET_NEXT(nod);
		}
		break;
	default :
		return -1;
	}
	return 0;
}
