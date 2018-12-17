#include <stdlib.h>
#include "pixmap.h"
#include "transformation.h"

#ifndef FILTERS_H
#define FILTERS_H

typedef struct filters_t filters_t;
struct filters_t
{
  int n;
  int32_t** tab_filters;
  uint32_t b;
  uint32_t a;
};

pixmap_t* fuzzy_filter (pixmap_t* fuzzy, int n);
filters_t* prewitt_x_filter (pixmap_t* prewitt_x, int n);
filters_t* prewitt_y_filter (pixmap_t* prewitt_y, int n);

#endif
