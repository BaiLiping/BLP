#include <stdint.h>
#include "tm4c123gh6pm.h"

void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R =0x0000FFFF;
  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
  NVIC_ST_CTRL_R = 0x00010005; // enable SysTick with core clock, but not interrupt

}
