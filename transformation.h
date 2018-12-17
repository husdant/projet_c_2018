#include <stdlib.h>
#include "pixmap.h"


#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

enum{
  X_AXIS=1,
  Y_AXIS=2,
  XY_AXIS=3
};

pixmap_t* reverse_pixmap (pixmap_t* reverse , int flag);
pixmap_t* transform_to_gray_pixmap (pixmap_t* gray , float A,float B,float C);
pixmap_t* binarize_pixmap (pixmap_t* bin, float Al ,int con);
pixmap_t* luminositer (pixmap_t* lum, double Al ,char s);
pixmap_t* contrast (pixmap_t* cont, int n ,char s);

#endif
