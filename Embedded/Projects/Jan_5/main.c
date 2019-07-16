#include <stdint.h>
#include "Systick.h"
#include "PLL.h"
#include "bsp.h"
#include "tm4c123gh6pm.h"
#include "Periodic_Interrupt.h"
#include "GPIO.h"
#include "PortF_Interrupt.h"

uint32_t count=0;


void main()
{
  PLL_Init(Bus4MHz);
  SysTick_Init(0x000FFFFF);
  GPIO_Port_DIGITAL_Init(1,'B');
  GPIO_Port_DIGITAL_Init(1,'F');
  GPIO_Port_DIGITAL_Init(1,'A');
  GPIO_Port_DIGITAL_Init(1,'E');

  EnableInterrupts();
  enable_portF_interrupt();
  enable_portE_interrupt();
  enable_portA_interrupt();

  while(1){
    GPIO_PORTB_AHB_DATA_BITS_R[0x07] = (GPIO_PORTE_AHB_DATA_BITS_R[0x0E]>>1);
    GPIO_PORTB_AHB_DATA_BITS_R[0xF8] = (GPIO_PORTA_AHB_DATA_BITS_R[0x7D]<<1);
  }
}

