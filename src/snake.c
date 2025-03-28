#include "snake.h"

#define MOVE_UP(ID) ((ID) - 0x10)
#define MOVE_DW(ID) ((ID) + 0x10)
#define MOVE_LT(ID) ((ID) - 0x01)
#define MOVE_RT(ID) ((ID) + 0x01)

#define POS_X(ID) ((ID>>0) & 0x0f)
#define POS_Y(ID) ((ID>>4) & 0x0f)

#define POS(X, Y) ((Y<<4) | (X))
#define TILE_DIR(TILE) (TILE & 0x3)
#define IS_HORZ(D) (D & 0x2)
#define IS_VERT(D) (!IS_HORZ(D))

#define SNAKE_NDX(ID) ((ID) & SNAKE_ID_MASK)
#define SNAKE_TAIL_NDX() SNAKE_NDX(snake_start + snake_len - 1)
#define SNAKE_POS(ID) (snake_body_pos[SNAKE_NDX(ID)])
#define SNAKE_TILE(ID) (snake_body_tile[SNAKE_NDX(ID)])
#define SNAKE_DIR() (TILE_DIR(SNAKE_TILE(snake_start))


uint8_t snake_body_pos[SNAKE_MAX_LEN];
enum tile snake_body_tile[SNAKE_MAX_LEN];
enum dir snake_dir;
uint8_t snake_start;
uint8_t snake_len;

uint8_t redraw_pos[REDRAW_MAX_LEN];
enum tile redraw_tile[REDRAW_MAX_LEN];
uint8_t redraw_len;

uint8_t apple_pos; 
enum tile apple_tile;

uint8_t apple_put_rng = 0;
uint8_t apple_put_pos[APPLE_PUT_POS_LEN] = 
{
	POS(4, 4),
	POS(7, 5),
	POS(4, 1),
	POS(6, 9)
};

int
main(void)
{
	spi_init();

	for (uint8_t i = 0; i < 120; i++)
	{
		vga_set_xy(0, i);
		vga_write(0x00);
		for (uint8_t j = 0; j < 160; j++)
			vga_write(0x00);
	}

	for (uint8_t i = 0; i < 16; i++)
	{
		for (uint8_t j = 0; j < 12; j++)
			tile_render(POS(i, j), TILE_VOID);
	}

	apple_put();
	snake_new(POS(6, 5), 4);
	redraw_empty();

	for (;;)
	{
		snake_search();
		redraw_empty();
	}
	
	return 0;
}

void 
snake_new(uint8_t start_pos, uint8_t len)
{
	snake_len = len;
	snake_start = 0;
	snake_dir = DIR_UP;
	
	uint8_t pos = start_pos;
	snake_body_pos[0] = pos;
	snake_body_tile[0] = TILE_SNAKE_SU;
	redraw_add(pos, TILE_SNAKE_SU);
	pos = MOVE_DW(pos);

	for (uint8_t i = 1; i < len - 1; i++)
	{
		snake_body_pos[i] = pos;
		snake_body_tile[i] = TILE_SNAKE_BU;
		redraw_add(pos, TILE_SNAKE_BU);
		pos = MOVE_DW(pos);
	}

	snake_body_pos[len - 1] = pos;
	snake_body_tile[len - 1] = TILE_SNAKE_TU;
	redraw_add(pos, TILE_SNAKE_TU);
}

void
snake_move(enum dir move_dir)
{
	uint8_t prev_snake_start = snake_start;
	uint8_t prev_snake_tail = SNAKE_TAIL_NDX();
	uint8_t new_snake_tail = SNAKE_NDX(prev_snake_tail - 1);
	snake_start = SNAKE_NDX(snake_start - 1);

	enum tile prev_start_tile = snake_body_tile[prev_snake_start]; 
	prev_start_tile = tile_snake_joint(move_dir, TILE_DIR(prev_start_tile));
	enum tile new_start_tile = TILE_SNAKE_SX + move_dir;

	uint8_t prev_start_pos = snake_body_pos[prev_snake_start]; 
	uint8_t new_start_pos;

	uint8_t prev_tail_pos = snake_body_pos[prev_snake_tail];
	uint8_t new_tail_pos = snake_body_pos[new_snake_tail];

	switch (move_dir) 
	{
		case DIR_UP:
			new_start_pos = MOVE_UP(prev_start_pos);
			break;
		case DIR_RT:
			new_start_pos = MOVE_RT(prev_start_pos);
			break;
		case DIR_LT:
			new_start_pos = MOVE_LT(prev_start_pos);
			break;
		case DIR_DW:
			new_start_pos = MOVE_DW(prev_start_pos);
			break;
        }

	snake_dir = move_dir;

        snake_body_pos[snake_start] = new_start_pos;
	snake_body_tile[snake_start] = new_start_tile;
	redraw_add(new_start_pos, new_start_tile);

	snake_body_tile[prev_snake_start] = prev_start_tile;
	redraw_add(prev_start_pos, prev_start_tile);

	enum tile new_tail_tile = snake_body_tile[new_snake_tail];
	new_tail_tile = TILE_SNAKE_TX + TILE_DIR(new_tail_tile);
	snake_body_tile[new_snake_tail] = new_tail_tile;
	redraw_add(new_tail_pos, new_tail_tile);

	redraw_add(prev_tail_pos, TILE_VOID);
}

void
snake_search(void)
{
	uint8_t start_pos = snake_body_pos[snake_start];
	int8_t dy = POS_Y(apple_pos) - POS_Y(start_pos);
	int8_t dx = POS_X(apple_pos) - POS_X(start_pos);
	enum dir target_dir;
	if (dy == 0) 
	{
		if (dx == 0)
		{
			// pop snake (eaten too much)
			// if (++snake_len > SNAKE_MAX_LEN) snake_len = 0;
			apple_put();
			snake_move(snake_dir);
			return;
		}
		else 
		{
			// turn into x axis
			target_dir = dx < 0 ? DIR_LT : DIR_RT;
		}
	}
	else 
	{
		// turn into y axis
		target_dir = dy < 0 ? DIR_UP : DIR_DW;
	}

	uint8_t turn_around = (snake_dir ^ target_dir) == 0x1;
	enum dir move_dir = snake_dir;

	// puts(turn_around ? "turn around" : (snake_dir == target_dir ? "straight" : "turn"));

	if (turn_around)
	{
		// turn around
		if (IS_HORZ(snake_dir))
			move_dir = dy < 0 ? DIR_UP : DIR_DW;
		else 
			move_dir = dx < 0 ? DIR_LT : DIR_RT;
	}
	else
	{
		move_dir = target_dir;
	}

	snake_move(move_dir);
}

void
apple_put(void) 
{
	apple_pos = apple_put_pos[apple_put_rng];
	apple_tile = apple_put_rng == 0 ? TILE_APPLE_R : (apple_put_rng & 3);
	redraw_add(apple_pos, apple_tile);
	apple_put_rng = apple_put_rng < (APPLE_PUT_POS_LEN - 1) ?
		apple_put_rng + 1 : 0;
}

enum tile
tile_snake_joint(enum dir dir0, enum dir dir1)
{
	if (dir0 == dir1) return TILE_SNAKE_BX + dir0;
	uint8_t sel = (dir1 & 1) << 2;
	return TILE_SNAKE_JX + (dir0 | sel);
}

void
tile_render(uint8_t pos, enum tile tile)
{
	// printf("draw %d %d = %d\n", POS_X(pos), POS_Y(pos), tile);
	
	uint8_t x = POS_X(pos) << FRAME_BITSH;
	uint8_t y = POS_Y(pos) << FRAME_BITSH;

	const uint8_t *frame = tile_map[tile];
	for (uint8_t i = 0; i < FRAME_WIDTH; i++)
	{
		vga_set_xy(x, y++);
		vga_write(prog_read(frame - (i > 0)));
		for (uint8_t j = 0; j < FRAME_WIDTH; j++)
			vga_write(prog_read(frame++));
	}
}

void
redraw_add(uint8_t pos, enum tile tile)
{
	// when same pos already added, overwrite if tile id bigger else exit
	for (uint8_t i = 0; i < redraw_len; i++)
	{
		if (redraw_pos[i] == pos)
		{
			if (redraw_tile[i] < tile)
				redraw_tile[redraw_len] = tile;
			return;
		}
	}

	if (redraw_len == REDRAW_MAX_LEN - 1)
		redraw_empty();

	// add new entry
	redraw_pos[redraw_len] = pos;
	redraw_tile[redraw_len] = tile;
	redraw_len++;
}

void
redraw_empty(void)
{
	for (uint8_t i = 0; i < redraw_len; i++)
		tile_render(redraw_pos[i], redraw_tile[i]);	
	redraw_len = 0;
}

void
spi_init(void)
{
	SPI_DDR = MOSI_PIN | SCLK_PIN | CSEL_PIN;
	SPI_PORT |= CSEL_PIN;
	// f_osc/128 - slowest possible
	SPCR = SPE | MSTR | SPR0 | SPR1;
}

void
spi_send(uint8_t byte)
{
	SPI_PORT &= ~CSEL_PIN;
	SPDR = byte;
	while (!(SPSR & SPIF));
	SPI_PORT |= CSEL_PIN;
}

void
spi_send_buf(uint8_t *buf, uint16_t len)
{
	uint8_t *buf_end = buf + len;
	uint8_t *byte;
	for (byte = buf; byte < buf_end; byte++)
		spi_send(*byte);
}

void 
vga_set_xy(uint8_t x, uint8_t y)
{
	spi_send(0x11);
	spi_send(x);
	spi_send(y);
}

void 
vga_write(uint8_t pixel)
{
	spi_send(0x20);
	spi_send(pixel);
}


