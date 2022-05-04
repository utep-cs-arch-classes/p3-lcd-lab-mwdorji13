#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

shape rect1;
shape rect2;
shape rect3;

u_int background_color = COLOR_BLUE;

void
shape1(int x, int y, int color){
  fillRectangle((x-10),(y), 10, 30, color);
  fillRectangle((x-20),(y-15), 10, 30, color);
}

void
shape2(int x, int y, int color){
  fillRectangle((x-10),(y), 40, 10, color);
  fillRectangle((x+20),(y-10), 10, 15, color);
}
void
shape3(int x, int y, int color){
  fillRectangle((x-10),(y), 40, 10, color);
  fillRectangle((x+5),(y-15), 10, 20, color);
}
void

init_shapes(void)
{
  // vars for the rectangle
  rect1.rect_row = 40;
  rect1.rect_col = screenWidth / 2;
  rect1.old_rect_row = 40;
  rect1.old_rect_col = screenWidth / 2;

  rect2.rect_row = 10;
  rect2.rect_col = screenWidth / 2;
  rect2.old_rect_row = 20;
  rect2.old_rect_col = screenWidth / 2;

  rect3.rect_row = 80;
  rect3.rect_col = screenWidth / 2;
  rect3.old_rect_row = 120;
  rect3.old_rect_col = screenWidth / 2;

}



void
draw_moving_shapes(void)
{
  int left_col = rect1.old_rect_col;
  int top_row  = rect1.old_rect_row;

  // blank out the old rectangle
  shape3(left_col, top_row, background_color);
  movingshape(&rect1);
  
}
void
draw_moving_shapes2(void)
{
  int left_col = rect2.old_rect_col;
  int top_row  = rect2.old_rect_row;

  // blank out the old rectangle
  shape2(left_col, top_row, background_color);
  movingshape2(&rect2);
}


void
draw_moving_shapes3(void)
{
  int left_col = rect3.old_rect_col;
  int top_row  = rect3.old_rect_row;

  // blank out the old rectangle
  shape1(left_col, top_row, background_color);
  movingshape1(&rect3);
}


void
movingshape(shape *to_draw)
{
  int shape1_x = 10;
  int shape1_y = 5;

  int left_col = to_draw->rect_col;
  int top_row  = to_draw->rect_row;

  unsigned int blue = 16, green = 0, red = 31;

  unsigned int color = (blue << 11) | (green << 5) | red;
  // draw rectangle at current position
  shape3(left_col, top_row, color);
  
  // save current position
  to_draw->old_rect_row = to_draw->rect_row;
  to_draw->old_rect_col = to_draw->rect_col;

  // update position
  to_draw->rect_row += shape1_y;
  to_draw->rect_col += shape1_x;

  // check boundaries, see if rectangle has hit the edges
  if ( ( to_draw->rect_col - 40 ) <= 0 ||            // left boundary
       ( to_draw->rect_col + 40 ) >= screenWidth ) { // right boundary

    // right or left hit, reverse x velocity
    shape1_x = shape1_x * -1;

  }

  if ( (to_draw->rect_row + 40 ) >= screenHeight ||   // bottom
       (to_draw->rect_row - 40 ) <= 0) {              // top

    // top or bottom hit, reverse y velocity
    shape1_y = shape1_y * -1;

  }
}
void
movingshape2(shape *to_draw)
{
  int shape2_x = 10;
  int shape2_y = 5;

  int left_col = to_draw->rect_col;
  int top_row  = to_draw->rect_row;

  unsigned int blue = 16, green = 0, red = 31;

  unsigned int color = (blue << 30) | (green << 5) | red;
  // draw rectangle at current position
  shape2(left_col, top_row, color);
  
  // save current position
  to_draw->old_rect_row = to_draw->rect_row;
  to_draw->old_rect_col = to_draw->rect_col;

  // update position
  to_draw->rect_row += shape2_y;
  to_draw->rect_col += shape2_x;

  // check boundaries, see if rectangle has hit the edges
  if ( ( to_draw->rect_col - 40 ) <= 0 ||            // left boundary
       ( to_draw->rect_col + 40 ) >= screenWidth ) { // right boundary

    // right or left hit, reverse x velocity
    shape2_x = shape2_x * -1;

  }

  if ( (to_draw->rect_row + 40 ) >= screenHeight ||   // bottom
       (to_draw->rect_row - 40 ) <= 0) {              // top

    // top or bottom hit, reverse y velocity
    shape2_y = shape2_y * -1;

  }
}

void
movingshape1(shape *to_draw)
{
  int shape3_x = 10;
  int shape3_y = 5;

  int left_col = to_draw->rect_col;
  int top_row  = to_draw->rect_row;

  unsigned int blue = 16, green = 0, red = 31;

  unsigned int color = (blue << 11) | (green << 5) | red;
  // draw rectangle at current position
  shape1(left_col, top_row, color);
  
  // save current position
  to_draw->old_rect_row = to_draw->rect_row;
  to_draw->old_rect_col = to_draw->rect_col;

  // update position
  to_draw->rect_row += shape3_y;
  to_draw->rect_col += shape3_x;

  // check boundaries, see if rectangle has hit the edges
  if ( ( to_draw->rect_col - 40 ) <= 0 ||            // left boundary
       ( to_draw->rect_col + 40 ) >= screenWidth ) { // right boundary

    // right or left hit, reverse x velocity
    shape3_x = shape3_x * -1;

  }

  if ( (to_draw->rect_row + 40 ) >= screenHeight ||   // bottom
       (to_draw->rect_row - 40 ) <= 0) {              // top

    // top or bottom hit, reverse y velocity
    shape3_y = shape3_y * -1;

  }
}
  
void
draw_rectangle(void)
{
  int height = 10;
  int width  = 60;
  int row = 20, col = screenWidth / 2;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int blue = 16, green = 0, red = 31;
  u_int color = (blue << 11) | (green << 5) | red;

  fillRectangle(left_col, row, width, height, color);
}

void
drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR)
{
  u_int length = x_end - x_start;
  // set the draw area from the start of the line to the end
  // height is 1 since its a line
  lcd_setArea(x_start, y, x_end, y);
  for (u_int i = 0; i < length; i++) {
    lcd_writeColor(colorBGR);
  }
  
}

void
drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color)
{
  // bottom
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord + y_point, color);
  // top
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord - y_point, color);
  // and the middle two
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord + x_point, color);
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord - x_point, color);
					  
}

