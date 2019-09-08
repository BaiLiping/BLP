#include "TM4C123GH6PM.h"

void Init_UART1(){
UART1->CTL = UART1->CTL & (0U) ; //disable this URAT port while set things up
//UART1->CTL = UART1->CTL & (~(1U<<5));//it is zero by default disable high-speed, make every info 16bits
UART1->IBRD= 8; // integer baud rate divisor, 16,000,000/(16*115200)=8.68
UART1->FBRD= 43; // fractional baud rate divisor, 64*(8.6805-8)
UART1->LCRH = UART1->LCRH | (3U<<5); //the word lenght is 8 bits
UART1->LCRH = UART1->LCRH | (1U<<4); //enable FIFO
UART1->CTL = UART1->CTL | (1U) ; //enable this URAT port after set things up
GPIOC_AHB->AFSEL = GPIOC_AHB->AFSEL | (3U<<4); //enable alternative function for pin4 and pin5
GPIOC_AHB->DEN = GPIOC_AHB->DEN | (3U<<4);//digital enable pin4 and pin5

}