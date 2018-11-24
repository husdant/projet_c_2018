#include <stdio.h>
#include <stdlib.h>
#include "pixmap.h"

int main(int argc, char ** argv)
{
  pixmap_t * pix = load_pixmap("lena.ppm");
  pixmap_t * copy = copy_pixmap(pix);
  save_pixmap(copy,"lena-output.ppm");
  printf("%lu %lu %lu",copy->hauteur,copy->largeur,copy->pixel);
  free_pixmap(copy);
  free_pixmap(pix);

  return 0;
}
