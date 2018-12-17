#include <stdio.h>
#include <stdlib.h>
#include "pixmap.h"
#include "transformation.h"
#include "filters.h"
#include <string.h>

int main(int ac, char ** av)
{
  char* input = NULL;
  char* output = NULL;
  for (int i=1 ;i<ac ; i++)
  {
    if (strcmp("-i",av[i]) == 0 || strcmp("--input",av[i]) == 0)
    {
      i++;
      input = av[i];
    }
    else if (strcmp ("-o",av[i])==0 || strcmp("--output", av[i]) == 0)
    {
      i++;
      output = av[i];
    }
    else
      return (0);
  }

  pixmap_t * pix;
  if (input == NULL)
    pix = load_pixmap("lena_p3.ppm");
  else
    pix = load_pixmap(input);
  pixmap_t * copy = copy_pixmap(pix);
  //reverse_pixmap(copy,X_AXIS);
  //transform_to_gray_pixmap (copy, 0.299,0.587,0.114);
  //binarize_pixmap (copy,0.5,26);
   luminositer(copy,1.5,'g');
  //contrast (copy, 25 ,'a');
  if (output == NULL)
    save_pixmap(copy,"lena-output.ppm");
  else
    save_pixmap(copy,output);
  printf("%lu %lu %lu",copy->hauteur,copy->largeur,copy->pixel);
  free_pixmap(copy);
  free_pixmap(pix);
  return 0;
}
