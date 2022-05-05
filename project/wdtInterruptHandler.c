#include <msp430.h>
#include "libTimer.h"
#include "draw_shapes.h"
#include "sm.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  int second_limit = 250;
  static int second_count = 0;

  second_count++;
  button1_logic();
  button2_logic();
  button3_logic();
  if (second_count >= second_limit) {
    //draw_moving_shapes();
    //draw_moving_shapes2();
    //draw_moving_shapes3(); 
    redraw_Screen = 1;
    second_count = 0;
  }
} 

