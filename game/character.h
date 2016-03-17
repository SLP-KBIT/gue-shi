#ifndef __CHARACTER_H__
#define __CHARACTER_H__

typedef struct point {
  int width;
  int height;
  int floor;
} Point;

struct status {
  char name[255];
  int hp;
  int mp;
  int money;
};

typedef struct player {
  struct status status;
  struct point pos;
} Player;

typedef struct enemy {
  struct status status;
} Enemy;

#endif
