#ifndef _TILE_H_
#define _TILE_H_

#include "progmem.h"

#define FRAME_WIDTH 8
#define FRAME_BITSH 3
#define FRAME_SIZE (FRAME_WIDTH * FRAME_WIDTH)

const uint8_t PROGMEM tile_map[24][FRAME_SIZE] =
{
	{ // VOID
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d,
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e,
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d,
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // APPLE_G
		0x2e, 0x2e, 0x2e, 0x02, 0x24, 0x24, 0x2e, 0x2e,
		0x2e, 0x2e, 0x2e, 0x02, 0x2e, 0x24, 0x24, 0x2e,
		0x2e, 0x2e, 0x2c, 0x2e, 0x2c, 0x2c, 0x2e, 0x2e,
		0x2e, 0x2c, 0x2c, 0x2c, 0x2e, 0x2d, 0x2c, 0x2e,
		0x2e, 0x24, 0x2c, 0x2c, 0x2c, 0x2d, 0x2c, 0x2e,
		0x2e, 0x24, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2e,
		0x2e, 0x2e, 0x24, 0x24, 0x24, 0x2c, 0x2e, 0x2e,
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e
	},
	{ // APPLE_R
		0x2e, 0x2e, 0x2e, 0x02, 0x24, 0x24, 0x2e, 0x2e,
		0x2e, 0x2e, 0x2e, 0x02, 0x2e, 0x24, 0x24, 0x2e,
		0x2e, 0x2e, 0x23, 0x23, 0x23, 0x23, 0x2e, 0x2e,
		0x2e, 0x23, 0x23, 0x23, 0x23, 0x2b, 0x23, 0x2e,
		0x2e, 0x21, 0x23, 0x23, 0x23, 0x2b, 0x23, 0x2e,
		0x2e, 0x21, 0x23, 0x23, 0x23, 0x23, 0x23, 0x2e,
		0x2e, 0x2e, 0x21, 0x21, 0x21, 0x23, 0x2e, 0x2e,
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e
	},
	{ // APPLE_Y
		0x2e, 0x2e, 0x2e, 0x02, 0x24, 0x24, 0x2e, 0x2e,
		0x2e, 0x2e, 0x2e, 0x02, 0x2e, 0x24, 0x24, 0x2e,
		0x2e, 0x2e, 0x2f, 0x25, 0x2f, 0x2f, 0x2e, 0x2e,
		0x2e, 0x2f, 0x2f, 0x2f, 0x2f, 0x1f, 0x2f, 0x2e,
		0x2e, 0x25, 0x2f, 0x2f, 0x2f, 0x1f, 0x2f, 0x2e,
		0x2e, 0x25, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2e,
		0x2e, 0x2e, 0x25, 0x25, 0x25, 0x2f, 0x2e, 0x2e,
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e
	},
	{ // SNAKE_BU
		0x2e, 0x27, 0x27, 0x24, 0x27, 0x27, 0x24, 0x2e,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x2d,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x2d, 0x24, 0x27, 0x27, 0x24, 0x27, 0x27, 0x2e,
		0x2e, 0x27, 0x27, 0x24, 0x27, 0x27, 0x24, 0x2e,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x2d,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x2d, 0x24, 0x27, 0x27, 0x24, 0x27, 0x27, 0x2e
	},
	{ // SNAKE_BD
		0x2e, 0x27, 0x27, 0x24, 0x27, 0x27, 0x24, 0x2e,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x2d,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x2d, 0x24, 0x27, 0x27, 0x24, 0x27, 0x27, 0x2e,
		0x2e, 0x27, 0x27, 0x24, 0x27, 0x27, 0x24, 0x2e,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x2d,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x2d, 0x24, 0x27, 0x27, 0x24, 0x27, 0x27, 0x2e
	},
	{ // SNAKE_BL
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x24, 0x27, 0x24, 0x27, 0x24, 0x27, 0x24, 0x27, 
		0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 
		0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 
		0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 0x27, 
		0x27, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 
		0x27, 0x24, 0x27, 0x24, 0x27, 0x24, 0x27, 0x24, 
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_BR
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x24, 0x27, 0x24, 0x27, 0x24, 0x27, 0x24, 0x27, 
		0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 
		0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 
		0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 0x27, 
		0x27, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 
		0x27, 0x24, 0x27, 0x24, 0x27, 0x24, 0x27, 0x24, 
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_SU
		0x2e, 0x2e, 0x2e, 0x2b, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2e, 0x2d, 0x2b, 0x27, 0x24, 0x2d, 0x2e, 0x2d,
		0x2e, 0x2e, 0x27, 0x27, 0x27, 0x24, 0x2e, 0x2e,
		0x2d, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x2e,
		0x2e, 0x27, 0x02, 0x27, 0x27, 0x02, 0x27, 0x2e,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2d,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x2e,
		0x2d, 0x24, 0x27, 0x27, 0x27, 0x27, 0x27, 0x2e
	},
	{ // SNAKE_SD
		0x2e, 0x27, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x2d,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x2d, 0x27, 0x02, 0x27, 0x27, 0x02, 0x27, 0x2e,
		0x2e, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x2e,
		0x2e, 0x2d, 0x24, 0x27, 0x27, 0x27, 0x2e, 0x2d,
		0x2e, 0x2e, 0x2e, 0x27, 0x27, 0x2b, 0x2e, 0x2e,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2b, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_SL
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2e, 0x2d, 0x2e, 0x27, 0x27, 0x24, 0x27, 0x24,
		0x2e, 0x2e, 0x24, 0x27, 0x02, 0x27, 0x24, 0x27,
		0x2d, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 
		0x2b, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 
		0x2e, 0x2b, 0x27, 0x27, 0x02, 0x27, 0x24, 0x27,
		0x2e, 0x2e, 0x2e, 0x27, 0x27, 0x24, 0x27, 0x24,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_SR
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x24, 0x27, 0x24, 0x27, 0x27, 0x2d, 0x2e, 0x2d,
		0x27, 0x24, 0x27, 0x02, 0x27, 0x27, 0x2b, 0x2e,
		0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x2b, 
		0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x2e,
		0x27, 0x24, 0x27, 0x02, 0x27, 0x24, 0x2e, 0x2d,
		0x27, 0x27, 0x24, 0x27, 0x27, 0x2e, 0x2e, 0x2e,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_TU
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x27, 0x27, 0x2e,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x2d,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x2d, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x2e,
		0x2e, 0x27, 0x27, 0x24, 0x27, 0x27, 0x27, 0x2e,
		0x2e, 0x2d, 0x27, 0x27, 0x27, 0x24, 0x2e, 0x2d,
		0x2e, 0x2e, 0x2e, 0x27, 0x24, 0x2e, 0x2e, 0x2e,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_TD
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2e, 0x2d, 0x2e, 0x24, 0x27, 0x2d, 0x2e, 0x2d,
		0x2e, 0x2e, 0x24, 0x27, 0x27, 0x27, 0x2e, 0x2e,
		0x2d, 0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 0x2e,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x2e,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2d,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x2e,
		0x2d, 0x27, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e
	},
	{ // SNAKE_TL
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x27, 0x27, 0x24, 0x27, 0x27, 0x2d, 0x2e, 0x2d,
		0x27, 0x24, 0x27, 0x24, 0x27, 0x24, 0x2e, 0x2e,
		0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x27, 0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 0x2e,
		0x27, 0x24, 0x27, 0x24, 0x27, 0x27, 0x2e, 0x2d,
		0x24, 0x27, 0x24, 0x27, 0x27, 0x2e, 0x2e, 0x2e,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_TR
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2e, 0x2d, 0x2e, 0x27, 0x27, 0x24, 0x27, 0x24,
		0x2e, 0x2e, 0x27, 0x27, 0x24, 0x27, 0x24, 0x27,
		0x2d, 0x27, 0x27, 0x24, 0x27, 0x27, 0x27, 0x27, 
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27,
		0x2e, 0x2d, 0x24, 0x27, 0x24, 0x27, 0x24, 0x27,
		0x2e, 0x2e, 0x2e, 0x27, 0x27, 0x24, 0x27, 0x27,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_LU
		0x2e, 0x27, 0x27, 0x24, 0x27, 0x27, 0x24, 0x2e,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x24,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27,
		0x2d, 0x2e, 0x24, 0x27, 0x24, 0x27, 0x27, 0x27,
		0x2e, 0x2e, 0x27, 0x27, 0x24, 0x27, 0x27, 0x27,
		0x2e, 0x2d, 0x2e, 0x27, 0x27, 0x27, 0x24, 0x27,
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x24, 0x27, 0x24,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_LD
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x27, 0x24, 0x27,
		0x2e, 0x2e, 0x2e, 0x27, 0x24, 0x24, 0x27, 0x27,
		0x2d, 0x2e, 0x27, 0x27, 0x27, 0x27, 0x27, 0x24,
		0x2e, 0x2e, 0x27, 0x24, 0x24, 0x27, 0x27, 0x27,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x27,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x24,
		0x2d, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e
	},
	{ // SNAKE_UL
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x24, 0x27, 0x24, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d,
		0x27, 0x24, 0x27, 0x27, 0x27, 0x2e, 0x2e, 0x2e,
		0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 0x2d, 0x2e,
		0x27, 0x27, 0x27, 0x24, 0x27, 0x24, 0x2e, 0x2e,
		0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x2d,
		0x24, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x2d, 0x24, 0x27, 0x27, 0x24, 0x27, 0x27, 0x2e
	},
	{ // SNAKE_UR
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x27, 0x24, 0x27,
		0x2e, 0x2e, 0x2e, 0x27, 0x24, 0x24, 0x27, 0x27,
		0x2d, 0x2e, 0x27, 0x27, 0x27, 0x27, 0x27, 0x24,
		0x2e, 0x2e, 0x27, 0x24, 0x24, 0x27, 0x27, 0x27,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x27,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x24,
		0x2d, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e
	},
	{ // SNAKE_RU
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x24, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x2d,
		0x27, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x27, 0x27, 0x27, 0x24, 0x24, 0x27, 0x2d, 0x2e,
		0x24, 0x27, 0x27, 0x27, 0x27, 0x27, 0x2e, 0x2e,
		0x27, 0x27, 0x24, 0x24, 0x27, 0x2d, 0x2e, 0x2d,
		0x27, 0x24, 0x27, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_RD
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x24, 0x27, 0x24, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d,
		0x27, 0x24, 0x27, 0x27, 0x27, 0x2e, 0x2e, 0x2e,
		0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 0x2d, 0x2e,
		0x27, 0x27, 0x27, 0x24, 0x27, 0x24, 0x2e, 0x2e,
		0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x2d,
		0x24, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x2d, 0x24, 0x27, 0x27, 0x24, 0x27, 0x27, 0x2e
	},
	{ // SNAKE_DL
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x24, 0x27, 0x24, 0x27, 0x27, 0x24, 0x27, 0x2d,
		0x27, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x2e,
		0x27, 0x27, 0x27, 0x24, 0x24, 0x27, 0x2d, 0x2e,
		0x24, 0x27, 0x27, 0x27, 0x27, 0x27, 0x2e, 0x2e,
		0x27, 0x27, 0x24, 0x24, 0x27, 0x2d, 0x2e, 0x2d,
		0x27, 0x24, 0x27, 0x2e, 0x2e, 0x2e, 0x2e, 0x2e,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
	{ // SNAKE_DR
		0x2e, 0x27, 0x27, 0x24, 0x27, 0x27, 0x24, 0x2e,
		0x2e, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x24,
		0x2e, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27,
		0x2d, 0x2e, 0x24, 0x27, 0x24, 0x27, 0x27, 0x27,
		0x2e, 0x2e, 0x27, 0x27, 0x24, 0x27, 0x27, 0x27,
		0x2e, 0x2d, 0x2e, 0x27, 0x27, 0x27, 0x24, 0x27,
		0x2e, 0x2e, 0x2e, 0x2e, 0x2e, 0x24, 0x27, 0x24,
		0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e, 0x2d, 0x2e
	},
};

#endif//_TILE_H_

