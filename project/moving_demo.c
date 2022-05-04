#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "switches.h"
#include "sm.h"
// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

char redraw_Screen = 1;
void main()
{
  configureClocks();
  lcd_init();
  clearScreen(background_color);

  init_shapes();

  switch_init();

  enableWDTInterrupts();

  buzzer_init();

  or_sr(0x18);

  /**< CPU off , GIE on*/
  while(1){
    if (redraw_Screen){
      redraw_Screen = 0;
      //clearScreen(COLOR_BLUE);
      // switch_interrupt_handler();
    }
  }
}
