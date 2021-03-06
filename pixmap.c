  #include <stdio.h>
  #include <stdlib.h>
  #include "pixmap.h"


  int readline (FILE* fichier, char* buf)
  {
    do
    {
      if(fgets(buf,71,fichier) == NULL)
        return 0;
    }
    while(buf[0] == '#');
    return 1;
  }

  pixmap_t* load_pixmap(char* filename)
  {
    int erreur=1;
    FILE* pixmapFile=NULL;
    pixmapFile = fopen(filename,"r");
    pixmap_t* image=NULL;
    image=(pixmap_t*)malloc(1*sizeof(pixmap_t));
    char buf[71]={0};
    if(!readline(pixmapFile,buf))
      return NULL;
    if (buf[0] =='P')
    {
      if (buf[1]=='1')
      {
        image->type=P1;
      }
      else if(buf[1]=='2')
      {
        image->type=P2;
      }
      else if(buf[1]=='3')
      {
        image->type=P3;
      }
      else
      {
      printf("erreur de format\n");
      erreur=0;
      }
    }
    else
    {
      printf("erreur format\n");
      erreur=0;
    }
    if (erreur)
    {
      while(!readline(pixmapFile,buf))
        readline(pixmapFile,buf);
      sscanf(buf, "%lu %lu",&image->largeur,&image->hauteur);
      switch (image->type) {
        case 0:
        image->pixel_tab=(pixel_t**)malloc(image->largeur*sizeof(pixel_t));
        for (unsigned  long int i = 0; i < image->largeur; i++)
        {
        image->pixel_tab[i]=(pixel_t*)malloc(image->hauteur*sizeof(pixel_t));
        }
        for (unsigned  long int i = 0; i < image->hauteur; i++)
        {
          for (unsigned  long int j = 0; j < image->largeur; j++)
          {
             while(!readline(pixmapFile,buf))
               readline(pixmapFile,buf);
              sscanf(buf, "%lu",(long unsigned int*)&image->pixel_tab[i][j]);
          }
        }
        break;
        case 1:
        while(!readline(pixmapFile,buf))
          readline(pixmapFile,buf);
        sscanf(buf, "%lu",(long unsigned int*)&image->pixel);
        image->pixel_tab=(pixel_t**)malloc(image->largeur*sizeof(pixel_t));
        for (unsigned  long int i = 0; i < image->largeur; i++)
        {
        image->pixel_tab[i]=(pixel_t*)malloc(image->hauteur*sizeof(pixel_t));
        }
        for (unsigned  long int i = 0; i < image->hauteur; i++)
        {
          for (unsigned  long int j = 0; j < image->largeur; j++)
          {
             while(!readline(pixmapFile,buf))
               readline(pixmapFile,buf);
              sscanf(buf, "%lu",(long unsigned int*)&image->pixel_tab[i][j]);
          }
        }
        break;
        case 2:
        while(!readline(pixmapFile,buf))
          readline(pixmapFile,buf);
        sscanf(buf, "%lu",(unsigned long int*)&image->pixel);
        image->pixel_tab=(pixel_t**)malloc(image->largeur*sizeof(pixel_t));
        for (unsigned  long int i = 0; i < image->largeur; i++)
        {
        image->pixel_tab[i]=(pixel_t*)malloc(image->hauteur*sizeof(pixel_t));
        }
        for (unsigned  long int i = 0; i < image->hauteur; i++)
        {
          for (unsigned  long int j = 0; j < image->largeur; j++)
           {
            unsigned int tmp;
            pixel_t res=0;
            while(!readline(pixmapFile,buf))
              readline(pixmapFile,buf);
            sscanf(buf, "%u",&tmp);
            res=tmp;
            while(!readline(pixmapFile,buf))
              readline(pixmapFile,buf);
            sscanf(buf, "%u",&tmp);
            res=res<<16;
            res+=tmp;
            while(!readline(pixmapFile,buf))
            {
              readline(pixmapFile,buf);
            }
            sscanf(buf, "%u",&tmp);
            res=res<<16;
            res+=tmp;
            image->pixel_tab[i][j]=res;
          }
      }
        break;

      }
    }
    fclose(pixmapFile);
    return image;
  }

  void free_pixmap (pixmap_t* pix)
  {
    for (unsigned  long int i = 0; i < pix->largeur; i++) {
      free (pix->pixel_tab[i]);
    }
    free(pix->pixel_tab);
    free(pix);
  }

  pixmap_t* copy_pixmap(pixmap_t* ancienne)
  {
    pixmap_t* nouvelle=NULL;
    nouvelle=(pixmap_t*)malloc(1*sizeof(pixmap_t));
    nouvelle->type=ancienne->type;
    nouvelle->largeur=ancienne->largeur;
    nouvelle->hauteur=ancienne->hauteur;
    nouvelle->pixel=ancienne->pixel;
    nouvelle->pixel_tab=(pixel_t**)malloc(nouvelle->largeur*sizeof(pixel_t));
    for (unsigned  long int i = 0; i < nouvelle->largeur; i++) {
      nouvelle->pixel_tab[i]=(pixel_t*)malloc(nouvelle->hauteur*sizeof(pixel_t));
    }
    for (unsigned  long int i = 0; i < nouvelle->largeur; i++) {
      for (unsigned  long int j = 0; j < nouvelle->hauteur; j++) {
        nouvelle->pixel_tab[i][j]=ancienne->pixel_tab[i][j];
      }
    }
    return nouvelle;
  }
  void save_pixmap(pixmap_t* pix,char* filename)
  {
    FILE* fich=NULL;
    fich=fopen(filename,"w");
    fprintf(fich,"P%d\n",pix->type+1);
    fprintf(fich,"%lu %lu\n",pix->largeur,pix->hauteur);
    switch (pix->type) {
      case 0:
      for (unsigned  long int i = 0; i < pix->hauteur; i++)
      {
        for (unsigned  long int j = 0; j < pix->largeur; j++)
        {
          fprintf(fich, "%lu\n",pix->pixel_tab[i][j]);
        }
      }
      break;
      case 1:
      fprintf(fich,"%lu\n",pix->pixel);
      for (unsigned  long int i = 0; i < pix->hauteur; i++)
      {
        for (unsigned  long int j = 0; j < pix->largeur; j++)
        {
          fprintf(fich, "%lu\n",pix->pixel_tab[i][j]);
        }
      }
      break;
      case 2:
      fprintf(fich,"%lu\n",pix->pixel);
      for (unsigned  long int i = 0; i < pix->hauteur; i++)
      {
        for (unsigned  long int j = 0; j < pix->largeur; j++)
        {
          pixel_t tmp=0;
          tmp=(pix->pixel_tab[i][j]>>32);
          fprintf(fich, "%lu\n",tmp);
          tmp=(pix->pixel_tab[i][j]>>16)&0xFFFF;
          fprintf(fich, "%lu\n",tmp);
          tmp=pix->pixel_tab[i][j]&0xFFFF;
          fprintf(fich, "%lu\n",tmp);
        }
      }
      break;
    }
    fclose(fich);
  }
