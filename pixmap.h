enum type_t {P1, P2, P3} ;

typedef enum type_t pixmap_type_t;
typedef unsigned long long pixel_t;
typedef struct pixmap_t pixmap_t;
struct pixmap_t
{
  pixmap_type_t type;
  unsigned long long hauteur;
  unsigned long long largeur;
  pixel_t pixel;
  pixel_t** pixel_tab;
};

pixmap_t* load_pixmap(char* filename)
