#include "tm4c123gh6pm.h"


void enable_portF_interrupt(void){

  GPIO_PORTF_AHB_PUR_R = 0x11;     //     enable weak pull-up on PF4
  GPIO_PORTF_AHB_IS_R = 0x0;     // (d) PF4 is edge-sensitive
  GPIO_PORTF_AHB_IBE_R = 0;    //     PF4 is not both edges
  GPIO_PORTF_AHB_IEV_R |= ~0x11;    //     PF4 falling edge event
  GPIO_PORTF_AHB_ICR_R = 0x11;      // (e) clear flag4
  GPIO_PORTF_AHB_IM_R = 0x11;      // (f) arm interrupt on PF4 *** No IME bit as mentioned in Book ***

  //NVIC_PRI7_R = ; // (g) priority 5
  NVIC_EN0_R |= 0x40000000;      // (h) enable interrupt 30 in NVIC

}

void enable_portE_interrupt(void){

  GPIO_PORTE_AHB_PUR_R = 0x30; //pullup
  GPIO_PORTE_AHB_PDR_R = 0x0E;
  GPIO_PORTE_AHB_IS_R = 0x00;
  GPIO_PORTE_AHB_IBE_R = 0;
  GPIO_PORTE_AHB_IEV_R = ~0x30;    // pullup, using falling edge
  GPIO_PORTE_AHB_ICR_R = 0x30;
  GPIO_PORTE_AHB_IM_R = 0x30;

  //NVIC_PRI1_R |= 0x80; // (g) priority 5
  NVIC_EN0_R |= 0x00000010;      // (h) enable interrupt 30 in NVIC

}

void enable_portA_interrupt(void){

  GPIO_PORTA_AHB_PUR_R = 0x80;
  GPIO_PORTA_AHB_PDR_R = 0x7C;
  GPIO_PORTA_AHB_IS_R = 0;
  GPIO_PORTA_AHB_IBE_R = 0;
  GPIO_PORTA_AHB_IEV_R = ~0x80;
  GPIO_PORTA_AHB_ICR_R = 0x80;
  GPIO_PORTA_AHB_IM_R = 0x80;

  //NVIC_PRI0_R |= 0x04; // (g) priority 5
  NVIC_EN0_R |= 0x00000001;      // (h) enable interrupt 30 in NVIC

}