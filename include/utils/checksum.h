#ifndef STUDENTMANAGER_CHECKSUM_H
#define STUDENTMANAGER_CHECKSUM_H

#include <stddef.h>
#include <stdint.h>

static inline uint32_t checksum(char *buf, size_t size)
{
	uint64_t chsum = 0;
	uint64_t hword = 0;
	size_t remain = size % (size_t) 4;  
	for (int i = 0, r = remain - 1; r >= 0; r--, i++)
		chsum += buf[i] << (r * 8);
	for (int i = remain; i < size; i += 4)
		chsum += (buf[i] << 24) | (buf[i] << 16) | (buf[i] << 8) | (buf[i]);
	while ((hword = chsum >> 32) != 0)
		chsum = hword + (chsum & 0xffffffff);
	return (uint32_t) chsum;
}

#endif
