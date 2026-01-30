#ifndef STUDENTMANAGER_FMTCHECK_H
#define STUDENTMANAGER_FMTCHECK_H

#include <stdbool.h>

static inline bool check_username_format(const char *uname);

static inline bool check_password_format(const char *passd);

static inline bool check_alphabet_format(const char *name);

static inline bool check_datestr_format(const char *date);

#endif
