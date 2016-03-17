#include <stdio.h>
#include <stdbool.h>
#include "sys/input.h"
#include "game/title.h"
#include "game/map.h"
#include "game/character.h"

void play_game(Player player);

int main(void) {
  Player player;
  int input;

  player.status.hp = 10;
  player.status.mp = 10;
  player.status.money = 1000;
  player.pos = get_floor_start(0);

  input = title();

  if ( input != TITLE_EXIT ) {
    puts("");
    play_game(player);
  }

  puts("See You Again!\n");

  return 0;
}

void play_game(Player player) {
  Arrow dir;

  while ( 1 ) {
    show_map(player.pos);
    show_prompt();
    if ( player_move(&player) == false ) { break; };
  }
}
