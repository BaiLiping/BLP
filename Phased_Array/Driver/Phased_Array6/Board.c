#include "TM4C123GH6PM.h"
#define XTAL_16MHZ   0x00000540  // 16 MHz Crystal

void Init_Board(){

//SYSCTL->RCC = (1U<<5);//enable internal clock 16MHz
SYSCTL->RCC= SYSCTL->RCC & (~(3U<<4));//use the main oscillator
SYSCTL->RCC= SYSCTL->RCC |  (15U<<6); //set the xtal value to be 16M



/*portB related initialization*/
SYSCTL->RCGCGPIO  = SYSCTL->RCGCGPIO | (1U<<1); //enable GPIO Port B
SYSCTL->GPIOHBCTL = SYSCTL->GPIOHBCTL |(1U<<1); //enable HBC bus for Port B
GPIOB_AHB->DIR = 0xFF; //set direction as output for all pins
GPIOB_AHB->DEN = 0xFF; //enable all pins

/*UART related Initialization*/

SYSCTL->RCGCUART = SYSCTL->RCGCUART | (1U<<1); //enable U1, U0 is troublesome
SYSCTL->RCGCGPIO = SYSCTL->RCGCGPIO | (1U<<2);//enable GPIO Port C
SYSCTL->GPIOHBCTL = SYSCTL->GPIOHBCTL |(1U<<2); //enable HBC bus for Port C



}

void UART4_IRQHandler(){

}

void assert_failed (char const * file, int line) {
  while (1){};
}