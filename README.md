# SpiderStep
![SpiderStep Logo](https://repository-images.githubusercontent.com/759209321/6a57874b-9382-4c79-bcf1-1e0f1a265a4c)

## Description
SpiderStep is a grid navigation step calculation algorithm.

Read [this article](https://medium.com/@williamstaffordparsons/spiderstep-is-a-new-optimized-calculation-of-8-directional-navigation-steps-in-2-dimensional-grids-d90cf44d5b5c) for an in-depth explanation.

## License
SpiderStep is subject to the software licensing terms from the [LICENSE file](https://github.com/williamstaffordparsons/spiderstep/blob/master/LICENSE).

## Reference
#### `spiderstep_initialize()`
This is the initialization function that accepts the 5 following arguments.

`grid_width` is the width of the rectangular grid.

`grid_height` is the height of the rectangular grid.

`source` is the starting position as an index in a grid array with `grid_width` * `grid_height` elements.

`destination` is the ending position as an index in a grid array with `grid_width` * `grid_height` elements.

`spiderstep` is the pointer to the uninitialized `struct` instance.

The return value data type is `struct spiderstep_s *`.

It returns a pointer to a `struct` instance initialized with the parameter values.

#### `spiderstep_navigate()`
This is the step navigation function that accepts the following argument.

`spiderstep` is the pointer to the `struct` instance containing the grid navigation data.

The return value data type is `void`.

## Usage
``` c
#include "spiderstep.h"

int main(void) {
  struct spiderstep_s _spiderstep;
  struct spiderstep_s *spiderstep = spiderstep_initialize(10, 10, 0, 95, &_spiderstep);
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

  grid[spiderstep->source] = 1;

  while (spiderstep->source != spiderstep->destination) {
    spiderstep_navigate(spiderstep);
    grid[spiderstep->source] = 3;
  }

  grid[spiderstep->destination] = 2;
  return 0;
}
```
