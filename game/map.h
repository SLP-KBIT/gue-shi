#ifndef __MAP_H__
#define __MAP_H__
#define MAP_WIDTH 10
#define MAP_HEIGHT 5
#define MAP_FLOOR 1

typedef enum { UP, DOWN, LEFT, RIGHT } Arrow;
typedef enum { NONE, START, WALL, HOUSE, ENEMY } Cell;
typedef struct {
  int width;
  int height;
  int floor;
} Point;

extern Cell Map[MAP_FLOOR][MAP_HEIGHT][MAP_WIDTH];

void show_map(Point player_p);
void show_cell(Cell cell);
Point get_floor_start(int floor);

#endif
