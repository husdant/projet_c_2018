#include <stdio.h>
#include <stdlib.h>
#include "filters.h"
#include <math.h>

filters_t* fuzzy_filter (pixmap_t* fuzzy, int n)
{
  fuzzy->n=n;
  fuzzy->a=n*n;
  fuzzy->b=0;
  fuzzy->tab_filters=(int32_t**)malloc(sizeof(int32_t)*fuzzy->n);
  for (unsigned  long int i = 0; i < fuzzy->n; i++)
  {
  fuzzy->tab_filters[i]=(int32_t*)malloc(sizeof(int32_t)*fuzzy->n);
  }
  for (unsigned  long int i = 0; i < fuzzy->n; i++)
  {
    for (unsigned  long int j = 0; j < fuzzy->n; j++)
    {
      fuzzy->tab[i][j]=1;
    }
  }

}
filters_t* prewitt_x_filter (pixmap_t* prewitt_x, int n)
{
  prewitt_x->n=3;
  prewitt_x->a=2*n;
  prewitt_x->b=(prewitt_x->pixel)/2;
  prewitt_x->tab_filters=(int32_t**)malloc(sizeof(int32_t)*prewitt_x->n);
  for (unsigned  long int i = 0; i < prewitt_x->n; i++)
  {
  prewitt_x->tab_filters[i]=(int32_t*)malloc(sizeof(int32_t)*prewitt_x->n);
  }
  for (unsigned  long int i = 0; i < prewitt_x->n; i++)
  {
    for (unsigned  long int j = 0; j < prewitt_x->n; j++)
    {
      if (i==1)
      {
        perwitt_x->tab[i][j]=-1;
      }
      else if (i==prewitt_x->b)
      {
        perwitt_x->tab[i][j]=1;
      }
      else
        perwitt_x->tab[i][j]=0;
    }
  }

}
filters_t* prewitt_y_filter (pixmap_t* prewitt_y, int n)
{
  prewitt_y->n=3;
  perwitt_y->a=2*n;
  prewitt_y->b=(prewitt_y->pixel)/2;
  prewitt_y->tab_filters=(int32_t**)malloc(sizeof(int32_t)*prewitt_y->n);
  for (unsigned  long int i = 0; i < prewitt_y->n; i++)
  {
  prewitt_y->tab_filters[i]=(int32_t*)malloc(sizeof(int32_t)*prewitt_y->n);
  }
  for (unsigned  long int i = 0; i < perwitt_y->n; i++)
  {
    for (unsigned  long int j = 0; j < prewitt_y->n; j++)
    {
      if (j==1)
      {
        perwitt_y->tab[i][j]=-1;
      }
      else if (j==prewitt_x->b)
      {
        perwitt_y->tab[i][j]=1;
      }
      else
        perwitt_y->tab[i][j]=0;
    }
  }
}
filters_t* sobel_x_filter (pixmap_t* sobel_x, int n)
{
  sobel_x->n=3;
  sobel_x->a=2 pow n;
  sobel_x->b=(sobel_x->pixel)/2;
  sobel_x->tab_filters=(int32_t**)malloc(sizeof(int32_t)*sobel_x->n);
  for (unsigned  long int i = 0; i < sobel_x->n; i++)
  {
  sobel_x->tab_filters[i]=(int32_t*)malloc(sizeof(int32_t)*sobel_x->n);
  }
  for (unsigned  long int i = 0; i < sobel_x->n; i++)
  {
    for (unsigned  long int j = 0; j < sobel_x->n; j++)
    {
      if (i==0)
      {
        if (j==0)
          sobel_x->tab[i][j]=-1;
        else if (j== sobel_x->n-1)
          sobel_x->tab[i][j]=1;
        else
          sobel_x->tab[i][j]=-2;
      }
      else if (i==sobel_x->n-1)
      {
        if (j==0)
          sobel_x->tab[i][j]=1;
        else if (j== sobel_x->n-1)
          solbel_x->tab[i][j]=-1;
        else
          solbel_x->tab[i][j]=2;
      }
      else
        sobel_x->tab[i][j]=0;
    }
  }
}
filters_t* prewitt_y_filter (pixmap_t* sobel_y, int n)
{
  sobel_y->n=3;
  sobel_y->a=2pow,n;
  sobel_y->b=(sobel_y->pixel)/2;
  sobel_y->tab_filters=(int32_t**)malloc(sizeof(int32_t)*sobel_y->n);
  for (unsigned  long int i = 0; i < sobel_y->n; i++)
  {
  sobel_y->tab_filters[i]=(int32_t*)malloc(sizeof(int32_t)*sobel_y->n);
  }
  for (unsigned  long int i = 0; i < sobel_y->n; i++)
  {
    for (unsigned  long int j = 0; j < sobel_y->n; j++)
    {
      if (j==1)
      {
        sobel_y->tab[i][j]=-1;
      }
      else if (j==sobel_y->b)
      {
        sobel_y->tab[i][j]=1;
      }
      else
        sobel_y->tab[i][j]=0;
    }
  }
}
