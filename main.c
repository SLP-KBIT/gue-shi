#include <stdio.h>
#include "sys/input.h"
#include "game/title.h"
#include "game/map.h"

int main(void) {
  Point player_p = get_floor_start(0);

  printf("%d\n", title());
  show_map(player_p);
  return 0;
}
