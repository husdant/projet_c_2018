#include <stdlib.h>

enum type_t {P1, P2, P3} ;

typedef enum type_t pixmap_type_t;// a revoir
typedef unsigned long  int pixel_t;
typedef struct pixmap_t pixmap_t;
struct pixmap_t
{
  pixmap_type_t type;
  unsigned long  int hauteur;
  unsigned long  int largeur;
  pixel_t pixel;
  pixel_t** pixel_tab;
};

int readline (FILE* fichier, char* buf);
pixmap_t* load_pixmap(char* filename);
void free_pixmap (pixmap_t* pix);
pixmap_t* copy_pixmap(pixmap_t* ancienne);
void save_pixmap(pixmap_t* pix,char* filename);
