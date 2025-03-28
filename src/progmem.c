#include "progmem.h"

uint8_t 
prog_read(const uint8_t *addr)
{
	uint8_t val;
	asm volatile("lpm %0, Z" : "=r"(val) : "z"(addr));
	return val;
}
