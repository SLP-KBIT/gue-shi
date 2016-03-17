#include <stdio.h>
#include "game/map.h"
#include "game/character.h"

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
  case START :
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

void show_prompt(void) {
  puts("←:h  →:l  ↓:j  ↑:k  Exit:q");
}

bool player_move(Player *player) {
  char input_chars[MOVE_DIR_NUM] = { ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT };
  char input;
  Point dir = { 0, 0 };
  int f = player->pos.floor, h = player->pos.height, w = player->pos.width;

  input = get_input_key(input_chars, MOVE_DIR_NUM);

  switch ( input ) {
  case ARROW_UP: dir.height = -1; break;
  case ARROW_DOWN: dir.height = 1; break;
  case ARROW_LEFT: dir.width = -1; break;
  case ARROW_RIGHT: dir.width = 1; break;
  case GAME_EXIT: return false;
  }

  h += dir.height;
  w += dir.width;

  if ( h < 0 || h >= MAP_HEIGHT || w < 0 || w >= MAP_WIDTH || Map[f][h][w] == WALL ) { return true; }
  player->pos.height = h;
  player->pos.width = w;

  return true;
}
