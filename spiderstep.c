#include "spiderstep.h"

struct spiderstep_s *spiderstep_initialize(const unsigned long grid_width, const unsigned long grid_height, const unsigned long source, const unsigned long destination, struct spiderstep_s *spiderstep) {
  spiderstep->grid_width = grid_width;
  spiderstep->grid_height = grid_height;
  spiderstep->source = source;
  spiderstep->destination = destination;
  spiderstep->source_step = 0;
  spiderstep->repetition_count = 0;
  spiderstep->has_source_coordinates = false;
  spiderstep->has_destination_coordinates = false;
  return spiderstep;
}

void spiderstep_navigate(struct spiderstep_s *spiderstep) {
  if (spiderstep->repetition_count == 0) {
    if (spiderstep->has_source_coordinates == false) {
      spiderstep->source_y = spiderstep->source / spiderstep->grid_width;
      spiderstep->source_x = spiderstep->source - (spiderstep->grid_width * spiderstep->source_y);
      spiderstep->has_source_coordinates = true;
    }

    if (spiderstep->has_destination_coordinates == false) {
      spiderstep->destination_y = spiderstep->destination / spiderstep->grid_width;
      spiderstep->destination_x = spiderstep->destination - (spiderstep->grid_width * spiderstep->destination_y);
      spiderstep->has_destination_coordinates = true;
    }

    if (spiderstep->source_x == spiderstep->destination_x) {
      spiderstep->source_x_step = 0;

      if (spiderstep->source_y < spiderstep->destination_y) {
        spiderstep->source_step = spiderstep->grid_width;
        spiderstep->source_y_step = 1;
        spiderstep->repetition_count = spiderstep->destination_y - spiderstep->source_y;
      } else {
        if (spiderstep->source_y > spiderstep->destination_y) {
          spiderstep->source_step = -spiderstep->grid_width;
          spiderstep->source_y_step = -1;
          spiderstep->repetition_count = spiderstep->source_y - spiderstep->destination_y;
        } else {
          spiderstep->source_step = 0;
          spiderstep->source_y_step = 0;
          spiderstep->repetition_count = 0;
        }
      }
    } else {
      if (spiderstep->source_y == spiderstep->destination_y) {
        spiderstep->source_y_step = 0;

        if (spiderstep->source_x < spiderstep->destination_x) {
          spiderstep->source_step = 1;
          spiderstep->source_x_step = 1;
          spiderstep->repetition_count = spiderstep->destination_x - spiderstep->source_x;
        } else {
          spiderstep->source_step = -1;
          spiderstep->source_x_step = -1;
          spiderstep->repetition_count = spiderstep->source_x - spiderstep->destination_x;
        }
      } else {
        if (spiderstep->source_x < spiderstep->destination_x) {
          spiderstep->repetition_count = spiderstep->destination_x - spiderstep->source_x;
          spiderstep->source_x_step = 1;

          if (spiderstep->source_y < spiderstep->destination_y) {
            spiderstep->source_step = spiderstep->grid_width + 1;
            spiderstep->source_y_step = 1;

            if ((spiderstep->destination_y - spiderstep->source_y) < spiderstep->repetition_count) {
              spiderstep->repetition_count = spiderstep->destination_y - spiderstep->source_y;
            }
          } else {
            spiderstep->source_step = -spiderstep->grid_width + 1;
            spiderstep->source_y_step = -1;

            if ((spiderstep->source_y - spiderstep->destination_y) < spiderstep->repetition_count) {
              spiderstep->repetition_count = spiderstep->source_y - spiderstep->destination_y;
            }
          }
        } else {
          spiderstep->repetition_count = spiderstep->source_x - spiderstep->destination_x;
          spiderstep->source_x_step = -1;

          if (spiderstep->source_y < spiderstep->destination_y) {
            spiderstep->source_step = spiderstep->grid_width - 1;
            spiderstep->source_y_step = 1;

            if ((spiderstep->destination_y - spiderstep->source_y) < spiderstep->repetition_count) {
              spiderstep->repetition_count = spiderstep->destination_y - spiderstep->source_y;
            }
          } else {
            spiderstep->source_step = -spiderstep->grid_width - 1;
            spiderstep->source_y_step = -1;

            if ((spiderstep->source_y - spiderstep->destination_y) < spiderstep->repetition_count) {
              spiderstep->repetition_count = spiderstep->source_y - spiderstep->destination_y;
            }
          }
        }
      }
    }
  }

  if (spiderstep->repetition_count != 0) {
    spiderstep->source += spiderstep->source_step;
    spiderstep->source_x += spiderstep->source_x_step;
    spiderstep->source_y += spiderstep->source_y_step;
    spiderstep->repetition_count--;
  }
}
