#ifndef STUDENTMANAGER_ERRORCTL_H
#define STUDENTMANAGER_ERRORCTL_H

#include "types.h"
#include <stdarg.h>
#include <stdio.h>

static inline void fatal_error_exit(const char *msg, ...);

static inline void stat_error(status_t _stat, const char *msg, ...);

static inline void stat_error_exit(status_t _stat, const char *msg, ...);

static inline void logic_error(const char *msg, ...);

static inline void found_error(const char *msg, ...);

#endif
