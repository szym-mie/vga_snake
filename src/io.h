#ifndef _IO_H_
#define _IO_H_

#include <stdint.h>

#define IO_REG(IO_ADDR) *((volatile uint8_t *) IO_ADDR) 

// unsafe
#define INT_VECT(VECT) \
void VECT(void) __attribute__((__signal__, __used__, __externally_visible__)); \
void VECT(void)

#define INT_RET volatile asm("reti" ::: "memory");

#endif//_IO_H_
