# SpiderStep
![SpiderStep Logo](https://repository-images.githubusercontent.com/759209321/b8f02ec6-709b-4e63-a526-0ed93d746d2c)

## Description
SpiderStep is a grid navigation step calculation algorithm.

Read [this article](https://medium.com/@wilparsons/spiderstep-is-an-optimized-calculation-of-8-directional-navigation-steps-in-2-dimensional-grids-42c849287574) for an in-depth explanation.

## Usage
``` c
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
```

## Reference
#### `spiderstep()`
This is the hashing function that accepts the 4 following arguments.

`grid_width` is the width of the rectangular grid.

`grid_height` is the height of the rectangular grid.

`source` is the starting position as an index in a grid array with `grid_width` * `grid_height` elements.

`destination` is the ending position as an index in a grid array with `grid_width` * `grid_height` elements.

The return value data type is `long`.

It returns the 32-bit signed integer increment step to calculate the next position of `source`.
