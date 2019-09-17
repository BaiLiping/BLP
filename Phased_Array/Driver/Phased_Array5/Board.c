#include "TM4C123GH6PM.h"


void Init_Board(){

SYSCTL->RCC = (1U<<5);//enable internal clock 16MHz

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