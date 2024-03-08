// In development.

#include <stdio.h>

int main(void) {
  // todo: optimizing without array
  unsigned int a = 0;
  unsigned long grid_height = 10;
  unsigned long grid_width = 10;
  unsigned long step[10] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
  unsigned long source = 0;
  unsigned long source_x = source - ((source / grid_width) * 10);
  unsigned long source_y = source / grid_height;
  unsigned long destination = 95;
  unsigned long destination_x = destination - ((destination / grid_width) * 10);
  unsigned long destination_y = (destination / grid_height);
  unsigned char i = source_y < destination_y;

  step[0] = grid_width + 1;
  step[1] = grid_width - 1;
  step[2] = 1;
  step[3] = 0;
  step[4] = grid_width - 1;
  step[5] = grid_width + 1;
  step[8] = grid_width;
  step[9] = grid_width;

  while (a != 10) {
    printf("%lu ", step[a]);
    a++;
  }

  printf("\n");

  if (source_y == destination_y) {
    i += 2;
  }

  if (source_x < destination_x) {
    i += 4;
  }

  if (source_x == destination_x) {
    i += 8;
  }

  // 11        9      1    0     9       11       1    0     10      10
  // 1 2 8     1 8    1    _     1 8     1 2 8    1    _     2 8     2 8

  // 1 +1
  // 8 +width-2 (8)
  // 2 +2

  // 0 5  11
  // 1 4  9
  // 2 6  1
  // 3 7  0
  // 8 9  10

  a = 0;

  while (a != 10) {
    printf("%u ", a & 8);
    a++;
  }

  printf("\n");

  if (
    (i & 1) == 0 &&
    i != 6
  ) {
    source -= step[i];
    printf("The directional step decrement value is %lu.\n", step[i]);
  } else {
    source += step[i];
    printf("The directional step increment value is %lu.\n", step[i]);
  }

  printf("The navigation position is changed to %lu.", source);
  return a;
}
