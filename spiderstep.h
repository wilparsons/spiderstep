#ifndef SPIDERSTEP_H
#define SPIDERSTEP_H

#include <stdbool.h>

struct spiderstep_s {
  unsigned long grid_height;
  unsigned long grid_width;
  unsigned long source;
  unsigned long destination;
  long step;
  unsigned long repetitions;
  unsigned long source_x;
  unsigned long source_y;
  unsigned long destination_x;
  unsigned long destination_y;
  bool has_source_coordinates;
  bool has_destination_coordinates;
};

struct spiderstep_s *spiderstep_initialize(const unsigned long grid_width, const unsigned long grid_height, const unsigned long source, const unsigned long destination, struct spiderstep_s *spiderstep);
void spiderstep_calculate(struct spiderstep_s *spiderstep);
#endif
