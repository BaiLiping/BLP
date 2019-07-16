#include "tm4c123gh6pm.h"
#include <stdint.h>




void enable_periodic_interrupt(void){
  NVIC_ST_CTRL_R |=(1u<<1);
  //*((uint32_t *)0xE000ED20)=0x6FFFFFFF;
}

void disable_periodic_interrupt(void){
  NVIC_ST_CTRL_R &=~(1u<<1);
}
