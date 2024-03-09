#include "spiderstep.h"

long spiderstep(const unsigned long grid_width, const unsigned long grid_height, const unsigned long source, const unsigned long destination) {
  const unsigned long source_x = source % grid_width;
  const unsigned long source_y = source / grid_height;
  const unsigned long destination_x = destination % grid_width;
  const unsigned long destination_y = destination / grid_height;
  long step = 0;

  if (source != destination) {
    if (source_x == destination_x) {
      if (source_y < destination_y) {
        step = grid_width;
      } else {
        step = -grid_width;
      }
    } else {
      if (source_y == destination_y) {
        if (source_x < destination_x) {
          step = 1;
        } else {
          step = -1;
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
