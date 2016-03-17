#include <stdio.h>
#include "game/map.h"

Cell Map[MAP_FLOOR][MAP_HEIGHT][MAP_WIDTH] = {
  { { WALL, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, START },
    { NONE, NONE, NONE, NONE, NONE, NONE, NONE, ENEMY, NONE, NONE },
    { NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE },
    { NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE },
    { HOUSE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE, WALL },
  }
};

void show_map(Point player_p) {
  int w, h;

  for ( w = -1; w <= MAP_WIDTH; w++ ) {
    show_cell(WALL);
  }
  puts("");
  for ( h = 0; h < MAP_HEIGHT; h++ ) {
    show_cell(WALL);
    for ( w = 0; w < MAP_WIDTH; w++ ) {
      if ( player_p.height == h && player_p.width == w ) {
        printf("Ｐ");
      } else {
        show_cell(Map[player_p.floor][h][w]);
      }
    }
    show_cell(WALL);
    puts("");
  }
  for ( w = -1; w <= MAP_WIDTH; w++ ) {
    show_cell(WALL);
  }
  puts("");
}

void show_cell(Cell cell) {
  switch( cell ) {
  case NONE : printf("  "); break;
  case WALL : printf("■"); break;
  case HOUSE : printf("△"); break;
  case ENEMY : printf("※"); break;
  }
}

Point get_floor_start(int floor) {
  int h, w;
  Point p = { 0, 0, floor };

  for ( p.height = 0; p.height < MAP_HEIGHT; p.height++ ) {
    for ( p.width = 0; p.width < MAP_WIDTH; p.width++ ) {
      if ( Map[p.floor][p.height][p.width] == START ) { return p; }
    }
  }
}
