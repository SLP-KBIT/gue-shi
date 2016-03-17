#include <stdio.h>
#include "sys/input.h"

char get_input_key(char arr[], int len) {
  char c = ' ';
  int i;

  system("stty -icanon -echo");
  while ( 1 ){
    c = getchar();
    if ( c != ' ' ) { break; }
  }

  for ( i = 0; i < len; i++ ) {
    if ( c == arr[i] ) { return c; }
  }

  return INPUT_ERR;
}
