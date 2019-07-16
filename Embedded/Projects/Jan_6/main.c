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
  GPIO_Port_DIGITAL_Init(1,'B');
  //GPIO_Port_DIGITAL_Init(1,'F');
  //GPIO_Port_DIGITAL_Init(1,'A');
  //GPIO_Port_DIGITAL_Init(1,'E');

  //EnableInterrupts();
  //enable_portF_interrupt();
  //enable_portE_interrupt();
  //enable_portA_interrupt();

  while(1){
    /*bitband addressing to the data register, one step*/
    //GPIO_PORTB_AHB_DATA_BITS_R[0x07] = (GPIO_PORTE_AHB_DATA_BITS_R[0x0E]>>1);
    //GPIO_PORTB_AHB_DATA_BITS_R[0xF8] = (GPIO_PORTA_AHB_DATA_BITS_R[0x7D]<<1);
    /*traditional way of accessing data, read-change-write, three steps
       also for situations like this, complier would complain that you
        did not specify the order for him to access a volitile data*/
    //GPIO_PORTB_AHB_DATA_R = (GPIO_PORTA_AHB_DATA_R&0x0000007C)<<1;
    //GPIO_PORTB_AHB_DATA_R |= ((GPIO_PORTE_AHB_DATA_R&0x0000'000E)>>1);
    //for(int i=0;i<1000;++i) {GPIO_PORTB_AHB_DATA_BITS_R[255] = 255;}
    //for(int i=0;i<1000;++i) {GPIO_PORTB_AHB_DATA_BITS_R[255] = 0;}
    GPIO_PORTB_AHB_DATA_BITS_R[255] = 255>>1;
    GPIO_PORTB_AHB_DATA_BITS_R[255] = 0;

    //for(int i=0;i<10000;++i){GPIO_PORTB_AHB_DATA_BITS_R[0x04]=0x11111;}
    //for(int i=0;i<10000;++i){GPIO_PORTB_AHB_DATA_BITS_R[0x04]=0;}
  }
}

