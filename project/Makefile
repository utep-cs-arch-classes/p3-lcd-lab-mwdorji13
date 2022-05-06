# makfile configuration
COMMON_OBJECTS		= draw_shapes.o wdtInterruptHandler.o sm.o switches.o buzzer.o p2_interrupt_handler.o update_state_c.o moving_demo.o
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: modular_c.elf modular_s.elf

#additional rules for files
modular_c.elf: ${COMMON_OBJECTS} update_state_c.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

modular_s.elf: ${COMMON_OBJECTS} update_state_s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load_c: modular_c.elf
	msp430loader.sh $^

load_s: modular_s.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

main.o: moving_demo.h

switches.o: switches.h

sm.o: sm.h

wdtInterruptHandler.o:  wdtInterruptHandler.c draw_shapes.h sm.h 

buzzer.o: buzzer.c buzzer.h

draw_shapes.o: draw_shapes.c draw_shapes.h

update_state_c.o: update_state_c.c sm.h

update_state_s.o: update_state_s.s sm.h 
