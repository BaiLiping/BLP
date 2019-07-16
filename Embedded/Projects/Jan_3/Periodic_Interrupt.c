#include "bsp.h"
#include "tm4c123gh6pm.h"
#include "Systick.h"
#include <stdint.h>
#include "GPIO.h"
#include "Periodic_Interrupt.h"


void periodic_interrupt_init(void){
  SysTick_Init();
  GPIO_Port_DIGITAL_Init(1,'F');
  GPIO_Port_DIGITAL_Init(1,'B');
  SYSCTL_RCGCGPIO_R = 0x22U;
  SYSCTL_GPIOHBCTL_R = 0x22U;
  GPIO_PORTF_AHB_DIR_R = 0x0EU;
  GPIO_PORTF_AHB_DEN_R = 0x0EU;
  GPIO_PORTB_AHB_DEN_R = 0xFF;
  GPIO_PORTB_AHB_DIR_R = 0xFF;
}

void enable_periodic_interrupt(void){
  NVIC_ST_CTRL_R |=0x02;
}