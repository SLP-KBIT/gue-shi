#include <stdio.h>
#include "input.h"

int main(void) {
  char arr[2] = {'a', 'b'};

  printf("%c\n", get_input_key(arr, 2));

  return 0;
}
