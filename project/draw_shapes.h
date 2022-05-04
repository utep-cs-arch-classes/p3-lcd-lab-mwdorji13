#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_
#include <lcdutils.h>

extern int shape1_x;
extern int shape2_x;
extern int shape3_x;
extern int shape1_y;
extern int shape2_y;
extern int shape3_y;
extern char redraw_Screen;
extern u_int background_color;

typedef struct shape_st {
  int rect_row;
  int rect_col;
  int old_rect_row;
  int old_rect_col;
}shape;

void init_shapes(void);
/* draws a rectangle */
void draw_rectangle(void);
/* draws an equaleral triangle by starting at the top with a 
   width of 1 and increasing the width by 1
   for every row */
void draw_triangle(void);
/* draws a circle using bresenham's algorithm */
void draw_circle(void);

void shape1(int x,int y, int color);

void shape2(int x,int y, int color);

void shape3(int x,int y, int color);

void movingshape(shape *to_draw);
void movingshape1(shape *to_draw);
void movingshape2(shape *to_draw);

void draw_moving_shapes(void);
void draw_moving_shapes2(void);
void draw_moving_shapes3(void);

#endif // _DRAW_SHAPES_H_
