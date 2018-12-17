    #include <stdio.h>
    #include <stdlib.h>
    #include "transformation.h"



    pixmap_t* reverse_pixmap (pixmap_t* reverse , int flag)
    {
      pixel_t tmp;
      printf("avant case\n");
      switch (flag) {
        case 1 :
          for(unsigned long int i=0 ; i<(reverse->largeur)/2  ;i++ )
          {
            for(unsigned long int j=0 ; j<(reverse->hauteur)-1 ; j++)
            {
              tmp = reverse->pixel_tab[i][j];
              reverse->pixel_tab[i][j]=reverse->pixel_tab[(reverse->largeur)-1-i][j];
              reverse->pixel_tab[(reverse->largeur)-1-i][j]=tmp;
            }
          }
            break;
        case 2 :
            for(unsigned long int i=0 ; i<(reverse->largeur)-1  ;i++ )
            {
              for(unsigned long int j=0 ; j<(reverse->hauteur)/2 ; j++)
              {
                printf("%lu\n",j );
                tmp = reverse->pixel_tab[i][j];
                reverse->pixel_tab[i][j]=reverse->pixel_tab[i][(reverse ->hauteur-1)-j];
                reverse->pixel_tab[i][(reverse->hauteur-1)-j]=tmp;
              }
            }
          break;
        case 3:
            for(unsigned long int i=0 ; i<(reverse->largeur)/2  ;i++ )
            {
              for(unsigned long int j=0 ; j<(reverse->hauteur)-1 ; j++)
              {
                tmp = reverse->pixel_tab[i][j];
                reverse->pixel_tab[i][j]=reverse->pixel_tab[(reverse->largeur)-1-i][(reverse ->hauteur-1)-j];
                reverse->pixel_tab[(reverse->largeur)-1-i][(reverse ->hauteur-1)-j]=tmp;
              }
            }
           break;
      default :
        printf("erreur\n");
      }
    return reverse;
    }

    pixmap_t* transform_to_gray_pixmap (pixmap_t* gray, float A ,float B ,float C)
      {
        pixel_t g=0;
        pixel_t r=0;
        pixel_t bl=0;
        gray->type=P2;
        for (unsigned  long int i = 0; i < gray->hauteur; i++) {
          for (unsigned  long int j = 0; j < gray->largeur; j++) {
            r=(gray->pixel_tab[i][j]>>32);
            g=(gray->pixel_tab[i][j]>>16)&0xFFFF;
            bl=gray->pixel_tab[i][j]&0xFFFF;
            gray->pixel_tab[i][j]=A*r+B*g+C*bl;
          }
        }
        return gray;
      }

      pixmap_t* binarize_pixmap (pixmap_t* bin, float Al ,int con)
        {
          double tmp;
        //  float lim = Al * (long unsigned int)bin->pixel;
        //  printf("%f\n",lim);
          pixel_t g=0;
          pixel_t r=0;
          pixel_t bl=0;
          printf("avant\n");
          if(bin->type==1)
          {
            printf("la\n");
            bin->type=P1;
            for (unsigned  long int i = 0; i < bin->hauteur; i++)
            {
              for (unsigned  long int j = 0; j < bin->largeur; j++)
              {
                tmp = (float)(long unsigned int)bin->pixel_tab [i][j]/(long unsigned int)bin->pixel;
                //printf("%lf,%lf,%lu\n",tmp,(double)bin->pixel_tab [i][j],(long unsigned int)bin->pixel );
                if (tmp>Al)
                   bin->pixel_tab [i][j]=0;
                else
                  bin->pixel_tab [i][j]=1;

          /*        if (bin->pixel_tab [i][j]< lim)
                     bin->pixel_tab [i][j]=0;
                  else
                    bin->pixel_tab [i][j]=1;
            */  }
            }
          }
          else if ( bin->type==2)
          {
            bin->type=P1;
            for (unsigned  long int i = 0; i < bin->hauteur; i++)
            {
              for (unsigned  long int j = 0; j < bin->largeur; j++)
              {
                r=(float)(long unsigned int)(bin->pixel_tab[i][j]>>32);
                g=(float)(long unsigned int)((bin->pixel_tab[i][j]>>16)&0xFFFF);
                bl=(float)(long unsigned int)(bin->pixel_tab[i][j]&0xFFFF);
                tmp=(r*g*bl)/(float)(long unsigned int)((bin->pixel)*(bin->pixel)*(bin->pixel));
                //printf("%llu %llu %llu %llu %f \n",r,g,bl,bin->pixel,tmp);
                if (tmp>Al)
                  bin->pixel_tab[i][j]=0;
                else
                  bin->pixel_tab[i][j]=1;
              }
            }
          }
          else
            printf("bleu\n");
          printf("apres\n");
          return bin;
        }

        pixmap_t* luminositer (pixmap_t* lum, double Al ,char s)
          {
            pixel_t g=0;
            pixel_t r=0;
            pixel_t bl=0;
            pixel_t res=0;
            double tmp;
            if(lum->type==1)
            {
              for (unsigned  long int i = 0; i < lum->hauteur; i++)
              {
                for (unsigned  long int j = 0; j < lum->largeur; j++)
                {
                  tmp= (lum->pixel_tab[i][j])*Al;
                  if(tmp>lum->pixel)
                    lum->pixel_tab[i][j]=lum->pixel;
                  else if (tmp<0)
                    lum->pixel_tab[i][j]=0;
                  else
                    lum->pixel_tab[i][j]=tmp;

                }
              }
            }
            else if ( lum->type==2)
            {
              if (s == 'a') {
                for (unsigned  long int i = 0; i < lum->hauteur; i++)
                {
                  for (unsigned  long int j = 0; j < lum->largeur; j++)
                  {
                    r=(lum->pixel_tab[i][j]>>32);
                    g=((lum->pixel_tab[i][j]>>16)&0xFFFF);
                    bl=(lum->pixel_tab[i][j]&0xFFFF);
                    r=(r*Al);
                    g=(g*Al);
                    bl=(bl*Al);
                    if(r>lum->pixel-1)
                      r=lum->pixel-1;
                    else if (r<0)
                      r=0;
                    if(g>lum->pixel-1)
                      g=lum->pixel-1;
                    else if (g<0)
                      g=0;
                    if(bl>lum->pixel-1)
                      bl=lum->pixel-1;
                    else if (bl<0)
                      bl=0;
                    res=r;
                    res=res<<16;
                    res+=g;
                    res=res<<16;
                    res+=bl;
                    lum->pixel_tab[i][j]=res;
                  }
                }
              }
            else if (s == 'r')
            {
              for (unsigned  long int i = 0; i < lum->hauteur; i++)
              {
                for (unsigned  long int j = 0; j < lum->largeur; j++)
                {
                  r=(lum->pixel_tab[i][j]>>32);
                  g=((lum->pixel_tab[i][j]>>16)&0xFFFF);
                  bl=(lum->pixel_tab[i][j]&0xFFFF);
                  r=(r*Al);
                  if(r>lum->pixel)
                    r=lum->pixel;
                  else if (r<0)
                    r=0;
                  res=r;
                  res=res<<16;
                  res+=g;
                  res=res<<16;
                  res+=bl;
                  lum->pixel_tab[i][j]=res;
                }
              }
            }
            else if (s == 'g')
            {
              for (unsigned  long int i = 0; i < lum->hauteur; i++)
              {
                for (unsigned  long int j = 0; j < lum->largeur; j++)
                {
                  r=(lum->pixel_tab[i][j]>>32);
                  g=((lum->pixel_tab[i][j]>>16)&0xFFFF);
                  bl=(lum->pixel_tab[i][j]&0xFFFF);
                  g=(g*Al);
                  if(g>lum->pixel)
                    g=lum->pixel;
                  else if (g<0)
                    g=0;
                  res=r;
                  res=res<<16;
                  res+=g;
                  res=res<<16;
                  res+=bl;
                  lum->pixel_tab[i][j]=res;
                }
              }
            }
            else if (s == 'b')
            {
              for (unsigned  long int i = 0; i < lum->hauteur; i++)
              {
                for (unsigned  long int j = 0; j < lum->largeur; j++)
                {
                  r=(lum->pixel_tab[i][j]>>32);
                  g=((lum->pixel_tab[i][j]>>16)&0xFFFF);
                  bl=(lum->pixel_tab[i][j]&0xFFFF);
                  bl=(bl*Al);
                  if(bl>lum->pixel)
                    bl=lum->pixel;
                  else if (bl<0)
                    bl=0;
                  res=r;
                  res=res<<16;
                  res+=g;
                  res=res<<16;
                  res+=bl;
                  lum->pixel_tab[i][j]=res;
                }
              }
            }
          }
            else
              printf("bleu\n");
            printf("apres\n");
            return lum;
          }
          pixmap_t* contrast (pixmap_t* cont, int n ,char s)
          {
            int g=0;
            pixel_t r=0;
            int bl=0;
            pixel_t res=0;
            if(cont->type==1)
            {
              for (unsigned  long int i = 0; i < cont->hauteur; i++)
              {
                for (unsigned  long int j = 0; j < cont->largeur; j++)
                {
                  cont->pixel_tab [i][j] = ((float)(long unsigned int)cont->pixel_tab [i][j]+n);
                  if(cont->pixel_tab[i][j]>cont->pixel)
                    cont->pixel_tab[i][j]=cont->pixel;
                  else if (cont->pixel_tab[i][j]<0)
                    cont->pixel_tab[i][j]=0;
                }
              }
            }
            else if ( cont->type==2)
            {
              if (s == 'a') {
                for (unsigned  long int i = 0; i < cont->hauteur; i++)
                {
                  for (unsigned  long int j = 0; j < cont->largeur; j++)
                  {
                    r=(cont->pixel_tab[i][j]>>32)&0xFFFF;
                    g=((cont->pixel_tab[i][j]>>16)&0xFFFF);
                    bl=(cont->pixel_tab[i][j]&0xFFFF);
                    r=(r+n > cont->pixel) ? cont->pixel: r+n;
                    g=(g+n > cont->pixel) ? cont->pixel: g+n;
                    bl=(bl+n > cont->pixel) ? cont->pixel: bl+n;
                    //printf("%d, %d, %d\n",r,g,bl);
              /*      if(r>cont->pixel)
                      r=cont->pixel;
                    else if (r<0)
                      r=0;
                    if(g>cont->pixel)
                      g=cont->pixel;
                    else if (g<0)
                      g=0;
                    if(bl>cont->pixel)
                      bl=cont->pixel;
                    else if (bl<0)
                      bl=0;*/
                    res=r;
                    res=res<<16;
                    res+=g;
                    res=res<<16;
                    res+=bl;
                    cont->pixel_tab[i][j]=res;
                  }
                }
              }
            else if (s == 'r')
            {
              for (unsigned  long int i = 0; i < cont->hauteur; i++)
              {
                for (unsigned  long int j = 0; j < cont->largeur; j++)
                {
                  r=(cont->pixel_tab[i][j]>>32);
                  g=((cont->pixel_tab[i][j]>>16)&0xFFFF);
                  bl=(cont->pixel_tab[i][j]&0xFFFF);
                  r=(r+n);
                  if(r>cont->pixel)
                    r=cont->pixel;
                  else if (r<0)
                    r=0;
                  res=r;
                  res=res<<16;
                  res+=g;
                  res=res<<16;
                  res+=bl;
                  cont->pixel_tab[i][j]=res;
                }
              }
            }
            else if (s == 'g')
            {
              for (unsigned  long int i = 0; i < cont->hauteur; i++)
              {
                for (unsigned  long int j = 0; j < cont->largeur; j++)
                {
                  r=(cont->pixel_tab[i][j]>>32);
                  g=((cont->pixel_tab[i][j]>>16)&0xFFFF);
                  bl=(cont->pixel_tab[i][j]&0xFFFF);
                  g=(g+n);
                  if(g>cont->pixel)
                    g=cont->pixel;
                  else if (g<0)
                    g=0;
                  res=r;
                  res=res<<16;
                  res+=g;
                  res=res<<16;
                  res+=bl;
                  cont->pixel_tab[i][j]=res;
                }
              }
            }
            else if (s == 'b')
            {
              for (unsigned  long int i = 0; i < cont->hauteur; i++)
              {
                for (unsigned  long int j = 0; j < cont->largeur; j++)
                {
                  r=(cont->pixel_tab[i][j]>>32);
                  g=((cont->pixel_tab[i][j]>>16)&0xFFFF);
                  bl=(cont->pixel_tab[i][j]&0xFFFF);
                  bl=(bl+n);
                  if(bl>cont->pixel)
                    bl=cont->pixel;
                  else if (bl<0)
                    bl=0;
                  res=r;
                  res=res<<16;
                  res+=g;
                  res=res<<16;
                  res+=bl;
                  cont->pixel_tab[i][j]=res;
                }
              }
            }
          }
            else
              printf("bleu\n");
            printf("apres\n");
            return cont;
          }
