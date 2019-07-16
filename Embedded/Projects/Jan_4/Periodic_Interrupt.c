#include "tm4c123gh6pm.h"
#include <stdint.h>




void enable_periodic_interrupt(void){
  NVIC_ST_CTRL_R |=(1u<<1);
}

void disable_periodic_interrupt(void){
  NVIC_ST_CTRL_R &=(0u<<1);
}
