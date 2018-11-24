#include <stdio.h>
#include <stdlib.h>
#include "pixmap.h"


int readline (FILE* fichier, char* buf)
{
  do
  {
    if(fgets(buf,71,fichier) == NULL)
      return 0;
  } while(buf[0] == '#');
  return 1;
}

pixmap_t* load_pixmap(char* filename)
{
  FILE* pixmapFile;
  pixmap_t* pixel;
  pixmapFile = fopen(filename,"r");
  char buf[71]={0};
  if(!readline(pixmapFile,buf))
    return NULL;
  if (buf[1]=='1')
  {
    sscanf(buf, "%d",&pixel->hauteur);
    sscanf(buf, "%d",&pixel->largeur);// TODO : erreur stock p1
  }
  elseif(buf[1]=='2')
  {

  }
  elseif(buf[1]=='3')
  {

  }
  else
  {
    printf("erreur de format\n");
  }
}
