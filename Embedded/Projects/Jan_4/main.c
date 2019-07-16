#include <stdint.h>
#include "Systick.h"
#include "PLL.h"
#include "bsp.h"
#include "tm4c123gh6pm.h"
#include "Periodic_Interrupt.h"
#include "GPIO.h"
#include "PortF_Interrupt.h"



void main()
{
  PLL_Init(Bus4MHz);
  SysTick_Init(0x000FFFFF);
  experiment_port_init();
  EnableInterrupts();
  enable_periodic_interrupt();
  //enable_portF_interrupt();

  while(1){
  }
}

