#include <stdio.h>

long spiderstep(const unsigned long grid_width, const unsigned long grid_height, const unsigned long source, const unsigned long destination) {
  unsigned long source_x = source / grid_width;
  const unsigned long source_y = source / grid_height;
  unsigned long destination_x = destination / grid_width;
  const unsigned long destination_y = destination / grid_height;
  long step = 0;

  source_x = source - ((source_x << 3) + (source_x << 1));
  destination_x = destination - ((destination_x << 3) + (destination_x << 1));

  if (source != destination) {
    if (source_y == destination_y) {
      if (source_x < destination_x) {
        step = -1;
      } else {
        step = 1;
      }
    } else {
      if (source_x == destination_x) {
        if (source_y < destination_y) {
          step = grid_width;
        } else {
          step = -grid_width;
        }
      } else {
        if (source_x < destination_x) {
          if (source_y < destination_y) {
            step = grid_width + 1;
          } else {
            step = -grid_width + 1;
          }
        } else {
          if (source_y < destination_y) {
            step = grid_width - 1;
          } else {
            step = -grid_width - 1;
          }
        }
      }
    }
  }

  return step;
}
