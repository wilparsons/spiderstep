#include <stdio.h>
#include "spiderstep.h"

int main(void) {
  unsigned char grid[100] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  };
  unsigned long grid_height = 10;
  unsigned long grid_width = 10;
  unsigned long source = 0;
  unsigned long destination = 95;
  long step;
  unsigned char i = 0;

  grid[source] = 1;

  while (source != destination) {
    source += spiderstep(grid_width, grid_height, source, destination);
    grid[source] = 3;
  }

  grid[destination] = 2;

  while (i != 100) {
    printf("%u ", grid[i]);

    if (((i + 1) % 10) == 0) {
      printf("\n");
    }

    i++;
  }

  return 0;
}
