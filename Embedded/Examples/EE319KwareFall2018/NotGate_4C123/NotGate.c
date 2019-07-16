

/*Runs on TM4C123
 Implements a NOT gate described in class
 PE1 is an output to LED, Positive logic
 PE0 is an input from switch, Positive logic
 Switch pressed causes LED to go OFF and 
 release causes LED to go ON.

*/
#include <stdint.h>

#include "tm4c123gh6pm.h"

void InitF(void){
 volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R|0x20;	// Turn clock on PortF
  delay = 100;					// Wait
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
  GPIO_PORTF_DIR_R = 0x0E;
  GPIO_PORTF_PUR_R = 0x11;
  GPIO_PORTF_DEN_R = 0x1F;
}
unsigned long In,Out;
int main(void){    volatile unsigned long delay;
  InitF();
// one time initialization goes here
  SYSCTL_RCGCGPIO_R |= 0x10;	// Turn clock on PortE
  delay = 100;					// Wait
  GPIO_PORTE_DIR_R |= 0x02; // PE1 out
  GPIO_PORTE_DIR_R &= ~(0x01); // PE0 input
  GPIO_PORTE_DEN_R |= 0x03;
	
  while(1){
// operations to be executed over and over go here
    In = GPIO_PORTE_DATA_R & 0x01;
    Out = ~In;
    Out = Out<<1;
    GPIO_PORTE_DATA_R = Out;
 //   GPIO_PORTE_DATA_R = (GPIO_PORTE_DATA_R&~0x02)|Out;
  }
}
