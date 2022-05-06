#include "switches.h"
#include "draw_shapes.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "sm.h"
#include "lcddraw.h"


int state = 0;

int shape1_limit = 250;
int shape2_limit = 150;
int shape3_limit = 100;

u_int backgroundColor = COLOR_BLUE;
//Turning this into assembly
/*void update_state()
{
  switch(state){
  case 0:
    but1();
    break;
  case 1:
    but2();
    break;
  case 2:
    but3();
    break;
  case 3:
    but4();
    break;
  }
}
*/

void button1_logic()
{
  static int count = 0;
  if(shape1_limit <= 0) {
    shape1_limit = 250;
  }
  
  count++;
  if(count >= shape1_limit){
    count = 0;
    draw_moving_shapes();
  }
}

void but1()
{
  buzzer_set_period(500);
  drawChar5x7(20, screenWidth/2, '1',COLOR_BLACK, backgroundColor);
}

void button2_logic()
{
  static int count = 0;
  if(shape2_limit <= 0) {
    shape2_limit = 250;
  }
  
  count++;
  if(count >= shape2_limit){
    count = 0;
    //draw_moving_shapes();
    draw_moving_shapes2();
  }
}

void but2()
{
  //draw_moving_shapes();
  //draw_moving_shapes2();
    buzzer_set_period(1000);
    drawChar5x7(20, screenWidth/2, '2',COLOR_BLACK, backgroundColor);
}
void button3_logic()
{
  static int count = 0;
  if(shape3_limit <= 0) {
    shape3_limit = 250;
  }
  
  count++;
  if(count >= shape3_limit){
    count = 0;
    //draw_moving_shapes();
    //draw_moving_shapes2();
    draw_moving_shapes3();
  }
}

void but3()
{
  //draw_moving_shapes();
  //draw_moving_shapes2();
  //draw_moving_shapes3();
    buzzer_set_period(1500);
    drawChar5x7(20, screenWidth/2, '3',COLOR_BLACK, backgroundColor);
}

void but4()
{
  //init_shapes();
    clearScreen(COLOR_BLUE);
    buzzer_set_period(800);
}

  
    
  
