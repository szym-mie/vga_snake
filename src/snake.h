#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdint.h>

#include "m88.h"
#include "tile.h"

#define SNAKE_MAX_LEN 8
#define SNAKE_ID_MASK 0x7

#define REDRAW_MAX_LEN 8

#define APPLE_PUT_POS_LEN 4

enum dir
{
	DIR_UP = 0x0,
	DIR_DW = 0x1,
	DIR_LT = 0x2,
	DIR_RT = 0x3
};

enum tile
{
	TILE_VOID     = 0x00, // void
	TILE_APPLE_G  = 0x01, // apple - green
	TILE_APPLE_R  = 0x02, // apple - red
	TILE_APPLE_Y  = 0x03, // apple - yellow

	TILE_SNAKE_BU = 0x04, // body - up
	TILE_SNAKE_BD = 0x05, // body - down
	TILE_SNAKE_BL = 0x06, // body - left
	TILE_SNAKE_BR = 0x07, // body - right

	TILE_SNAKE_SU = 0x08, // start - up
	TILE_SNAKE_SD = 0x09, // start - down
	TILE_SNAKE_SL = 0x0a, // start - left
	TILE_SNAKE_SR = 0x0b, // start - right
	
	TILE_SNAKE_TU = 0x0c, // tail - up
	TILE_SNAKE_TD = 0x0d, // tail - down
	TILE_SNAKE_TL = 0x0e, // tail - left
	TILE_SNAKE_TR = 0x0f, // tail - right

	TILE_SNAKE_LU = 0x10, // left -> up
	TILE_SNAKE_LD = 0x11, // left -> down
	TILE_SNAKE_UL = 0x12, // up -> left
	TILE_SNAKE_UR = 0x13, // up -> right
	
	TILE_SNAKE_RU = 0x14, // right -> up
	TILE_SNAKE_RD = 0x15, // right -> down
	TILE_SNAKE_DL = 0x16, // down -> left
	TILE_SNAKE_DR = 0x17  // down -> right
};

#define TILE_SNAKE_BX TILE_SNAKE_BU
#define TILE_SNAKE_SX TILE_SNAKE_SU
#define TILE_SNAKE_TX TILE_SNAKE_TU
#define TILE_SNAKE_JX TILE_SNAKE_LU

void snake_new(uint8_t start_pos, uint8_t len);
void snake_move(enum dir move_dir);
void snake_search(void);
void apple_put(void); 
enum tile tile_snake_joint(enum dir dir0, enum dir dir1);
void tile_render(uint8_t pos, enum tile tile);
void redraw_add(uint8_t pos, enum tile tile);
void redraw_empty(void);

#define SPI_DDR DDRB
#define SPI_PORT PORTB
#define SCLK_PIN PINB5
#define MOSI_PIN PINB3
#define CSEL_PIN PINB2

void spi_init(void);
void spi_send(uint8_t byte);
void spi_send_buf(uint8_t *buf, uint16_t len);

void vga_set_xy(uint8_t x, uint8_t y);
void vga_write(uint8_t pixel);

#endif//_SNAKE_H_
