#include "switches.h"
#include "sm.h"

int switches = 0;
char switch1_down;
char switch2_down;
char switch3_down;
char switch4_down;

/* Updates when the interrupt fires and returns current state of switches */
static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init(void)		/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
}

void
switch_interrupt_handler(void)
{
  char p2val = switch_update_interrupt_sense();
  switches = ~p2val & SWITCHES;
  switch1_down = (p2val & SW1) ? 0 : 1;
  switch2_down = (p2val & SW2) ? 0 : 1;
  switch3_down = (p2val & SW3) ? 0 : 1;
  switch4_down = (p2val & SW4) ? 0 : 1;
  if(switch1_down){
    state = 0;
    shape1_limit -= 10;
  }
  if(switch2_down){
    state = 1;
    shape2_limit -= 15;
  }
  if(switch3_down){
    state = 2;
    shape3_limit -= 20;
  }
  if(switch4_down){
    state = 3;
    shape1_limit = 250;
    shape2_limit = 250;
    shape3_limit = 250;


  }
  update_state();

}


