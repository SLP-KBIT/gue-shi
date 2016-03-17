#ifndef __MAP_H__
#define __MAP_H__

#include "game/character.h"
#include <stdbool.h>
#define MAP_WIDTH 10
#define MAP_HEIGHT 5
#define MAP_FLOOR 1
#define MOVE_DIR_NUM 4
#define ARROW_UP 'k'
#define ARROW_DOWN 'j'
#define ARROW_LEFT 'h'
#define ARROW_RIGHT 'l'
#define GAME_EXIT 'q'

typedef enum { NO, UP, DOWN, LEFT, RIGHT } Arrow;
typedef enum { NONE, START, WALL, HOUSE, ENEMY } Cell;

extern Cell Map[MAP_FLOOR][MAP_HEIGHT][MAP_WIDTH];

void show_map(Point player_p);
void show_cell(Cell cell);
void show_prompt(void);
struct point get_floor_start(int floor);
bool player_move(Player *player);

#endif
