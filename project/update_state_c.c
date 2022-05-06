#include "switches.h"
#include "draw_shapes.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "sm.h"
#include "lcddraw.h"

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

