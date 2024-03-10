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
  struct spiderstep_s _spiderstep = {
    .grid_height = 10,
    .grid_width = 10,
    .source = 0,
    .destination = 95,
    .has_source_coordinates = false,
    .has_destination_coordinates = false
  };
  struct spiderstep_s *spiderstep = &_spiderstep;
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
  unsigned char i = 0;

  grid[spiderstep->source] = 1;

  while (spiderstep->source != spiderstep->destination) {
    spiderstep_calculate(spiderstep);

    while (spiderstep->repetitions != 0) {
      spiderstep->source += spiderstep->step;
      grid[spiderstep->source] = 3;
      spiderstep->repetitions--;
    }
  }

  grid[spiderstep->destination] = 2;

  while (i != 100) {
    printf("%u", grid[i]);

    if (((i + 1) % 10) == 0) {
      printf("\n");
    } else {
      printf(" ");
    }

    i++;
  }

  return 0;
}
```

## Reference
#### `spiderstep_calculate()`
This is the step calculation function that accepts the following argument.

`spiderstep` is the pointer to the `struct` instance containing the grid navigation data.

The return value data type is `void`.
