#include "switches.h"
#include "draw_shapes.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "sm.h"
#include "lcddraw.h"


int state = 0;

u_int backgroundColor = COLOR_BLUE;

void update_state()
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
void but1()
{
   
  //draw_moving_shapes();
   buzzer_set_period(500);
   drawChar5x7(20, screenWidth/2, '1',COLOR_BLACK, backgroundColor);
}

void but2()
{
  //draw_moving_shapes();
  //draw_moving_shapes2();
    buzzer_set_period(1000);
    drawChar5x7(20, screenWidth/2, '2',COLOR_BLACK, backgroundColor);
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

  
    
  
