#ifndef STUDENTMANAGER_SCRNCLEAR_H
#define STUDENTMANAGER_SCRNCLEAR_H

#include <stdlib.h>

#if defined(__linux__)
#define CLEARSCRN() system("clear")
#elif defined(_WIN32)
#define CLEARSCRN() system("cls")
#endif

#endif
