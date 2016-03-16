#include <stdio.h>
#include <string.h>
#include "input.h"
#include "title.h"

int title(void) {
  char input_chars[TITLE_SELECTION_NUM] = {'0' + TITLE_NEW_GAME, '0' + TITLE_CONTINUE, '0' + TITLE_EXIT};
  char input = INPUT_ERR;

  printf("hoge\n\n");
  printf("1. New Game\n");
  printf("2. Continue\n\n");
  printf("9. Exit\n\n");
  printf("> ");

  input = get_input_key(input_chars, TITLE_SELECTION_NUM);
  while ( input == INPUT_ERR ) {
    printf("Please Input 1, 2 or 9\n");
    printf("> ");
    input = get_input_key(input_chars, 2);
  }

  return input - '0';
}
