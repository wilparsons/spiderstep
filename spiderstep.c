#include "spiderstep.h"
#include <stdio.h>

struct spiderstep_s *spiderstep_initialize(const unsigned long grid_width, const unsigned long grid_height, const unsigned long source, const unsigned long destination, struct spiderstep_s *spiderstep) {
  spiderstep->grid_width = grid_width;
  spiderstep->grid_height = grid_height;
  spiderstep->source = source;
  spiderstep->destination = destination;
  spiderstep->step = 0;
  spiderstep->has_source_coordinates = false;
  spiderstep->has_destination_coordinates = false;
  return spiderstep;
}

void spiderstep_calculate(struct spiderstep_s *spiderstep) {
  if (spiderstep->has_source_coordinates == false) {
    spiderstep->source_y = spiderstep->source / spiderstep->grid_height;
    spiderstep->source_x = spiderstep->source - (spiderstep->grid_width * spiderstep->source_y);
  }

  if (spiderstep->has_destination_coordinates == false) {
    spiderstep->destination_y = spiderstep->destination / spiderstep->grid_height;
    spiderstep->destination_x = spiderstep->destination - (spiderstep->grid_width * spiderstep->destination_y);
    spiderstep->has_destination_coordinates = true;
  }

  if (spiderstep->source_x == spiderstep->destination_x) {
    if (spiderstep->source_y < spiderstep->destination_y) {
      spiderstep->step = spiderstep->grid_width;
      spiderstep->repetitions = spiderstep->destination_y - spiderstep->source_y;
    } else {
      if (spiderstep->source_y > spiderstep->destination_y) {
        spiderstep->step = -(spiderstep->grid_width);
        spiderstep->repetitions = spiderstep->source_y - spiderstep->destination_y;
      } else {
        spiderstep->step = 0;
        spiderstep->repetitions = 0;
      }
    }
  } else {
    if (spiderstep->source_y == spiderstep->destination_y) {
      if (spiderstep->source_x < spiderstep->destination_x) {
        spiderstep->step = 1;
        spiderstep->repetitions = spiderstep->destination_x - spiderstep->source_x;
      } else {
        spiderstep->step = -1;
        spiderstep->repetitions = spiderstep->source_x - spiderstep->destination_x;
      }
    } else {
      if (spiderstep->source_x < spiderstep->destination_x) {
        spiderstep->repetitions = spiderstep->destination_x - spiderstep->source_x;

        if (spiderstep->source_y < spiderstep->destination_y) {
          spiderstep->step = spiderstep->grid_width + 1;

          if ((spiderstep->destination_y - spiderstep->source_y) < spiderstep->repetitions) {
            spiderstep->repetitions = spiderstep->destination_y - spiderstep->source_y;
          }
        } else {
          spiderstep->step = -(spiderstep->grid_width) + 1;

          if ((spiderstep->source_y - spiderstep->destination_y) < spiderstep->repetitions) {
            spiderstep->repetitions = spiderstep->source_y - spiderstep->destination_y;
          }
        }
      } else {
        spiderstep->repetitions = spiderstep->source_x - spiderstep->destination_x;

        if (spiderstep->source_y < spiderstep->destination_y) {
          spiderstep->step = spiderstep->grid_width - 1;

          if ((spiderstep->destination_y - spiderstep->source_y) < spiderstep->repetitions) {
            spiderstep->repetitions = spiderstep->destination_y - spiderstep->source_y;
          }
        } else {
          spiderstep->step = -(spiderstep->grid_width) - 1;

          if ((spiderstep->source_y - spiderstep->destination_y) < spiderstep->repetitions) {
            spiderstep->repetitions = spiderstep->source_y - spiderstep->destination_y;
          }
        }
      }
    }
  }
}
