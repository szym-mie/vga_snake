#ifndef _PROGMEM_H_
#define _PROGMEM_H_

#include <stdint.h>

#define PROGMEM __attribute__((__progmem__))

uint8_t prog_read(const uint8_t *addr);

#endif//_PROGMEM_H_

