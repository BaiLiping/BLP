#include "tm4c123gh6pm.h"


void enable_portF_interrupt(void){

GPIO_PORTF_IS_R=0x11;  /*set switch to be edge sensative*/
GPIO_PORTF_IBE_R=0x00;  /*not both edge sensative*/
GPIO_PORTF_IEV_R=0x11;  /*rising edge sensative*/
GPIO_PORTF_ICR_R = 0x11; /*clear any flag*/
GPIO_PORTF_IM_R=0x11;/*arm portF*/

NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000;
NVIC_EN0_R = 0x40000000;

}