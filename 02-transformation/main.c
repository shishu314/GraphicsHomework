#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;

  c.red = 255;
  c.blue = 0;
  c.green = 0;
  clear_screen(s);
  
  struct matrix *edges;
  struct matrix *transform;
  struct matrix *rot;
  
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  
  /* Temporary stuff
  struct matrix* rotx = new_matrix(4,4);
  struct matrix* roty = new_matrix(4,4);
  struct matrix* rotz = new_matrix(4,4);
  */
  
  /* Testing Code
  print_matrix(edges);
  ident(edges);
  printf("Edges - Lastcol = %d\n",edges->lastcol);
  print_matrix(edges);
  scalar_mult(0.5,edges);
  print_matrix(edges);
  edges = make_translate(0.5,0.5,0.5);
  print_matrix(edges);
  printf("Transform:\n");
  copy_matrix(edges,transform);
  print_matrix(transform);
  printf("Transform - Lastcol = %d\n",transform->lastcol);
  grow_matrix(transform,8);
  print_matrix(transform);
  printf("%g\n",transform->m[0][transform->lastcol]);
  printf("\n");
  //ident(edges);
  ident(transform);
  matrix_mult(transform,edges);
  print_matrix(edges);
  add_point(edges,1,1,1);
  add_point(edges,1,1,1);
  add_point(edges,1,1,1);
  add_point(edges,1,1,1);
  add_point(edges,1,1,1);
  int lastcol = edges->lastcol;
  //printf("%d\n",!(edges->m[lastcol][0]));
  print_matrix(edges);
  printf("%s\n","RotX:");
  rotx = make_rotX(90.0);
  print_matrix(rotx);
  printf("%s\n","RotY:");
  roty = make_rotY(90.0);
  print_matrix(roty);
  printf("%s\n","RotZ:");
  rotz = make_rotZ(90.0);
  print_matrix(rotz);
  */
  
  add_edge(edges,200,250,0,400,250,0);
  add_edge(edges,400,250,0,300,300,0);
  add_edge(edges,300,300,0,200,250,0);
  print_matrix(edges);
  draw_lines(edges,s,c);
  transform = make_translate(-100,0,0);
  matrix_mult(transform,edges);
  print_matrix(edges);
  draw_lines(edges,s,c);
  transform = make_scale(2.0,2.0,0);
  matrix_mult(transform,edges);
  print_matrix(edges);
  draw_lines(edges,s,c);
  
  /*
  rot = make_rotZ(10);
  int count = 0;
  while(count < 8){
    draw_lines(edges,s,c);
    matrix_mult(rot,edges);
    print_matrix(edges);
    count ++;
  }
  */
  free_matrix( transform );
  free_matrix( edges );
  //display(s);
   
  
  save_extension(s, "matrix.png");
}  
