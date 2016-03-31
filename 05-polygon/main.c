#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main( int argc, char** argv ) {

  screen s;
  color c;
  clear_screen(s);
  
  c.red = 255;
  c.blue = 0;
  c.green = 0;

  struct matrix *edges;
  struct matrix *transform;
  struct matrix *polygons;
  
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  polygons = new_matrix(4,4);
  
  add_polygon(polygons,100,100,100,200,200,200,300,300,300);
  draw_polygons(polygons,s,c);
  display(s);
  clear_screen(s);
  transform = make_rotX(45);
  matrix_mult(transform,polygons);
  draw_polygons(polygons,s,c);
  display(s);
					       
  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );

  free_matrix( transform );
  free_matrix( edges );
}  