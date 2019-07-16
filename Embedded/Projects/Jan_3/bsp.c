/* Board Support Package */
#include "tm4C123gh6pm.h"
//#include "tm4c_cmsis.h"
#include "bsp.h"
#include "GPIO.h"


__stackless void assert_failed (char const *file, int line) {
    /* TBD: damage control */
     GPIO_PORTF_AHB_DATA_BITS_R[4] ^= 0xFF;; /* reset the system */
}

void SysTick_Handler(void) {
    GPIO_PORTB_AHB_DATA_BITS_R[1]^=0xFF;
}

//*********** DisableInterrupts ***************
// disable interrupts
// inputs:  none
// outputs: none
void DisableInterrupts(void){
	__asm ("    CPSID  I\n");/*this is set using assembly lanugage
                                  CPSID I stand for  Change Processor State/Disable Interrupt*/
}

//*********** EnableInterrupts ***************
// emable interrupts
// inputs:  none
// outputs: none
void EnableInterrupts(void){
	__asm  ("    CPSIE  I\n"); /*assembly language
 CPSIT I stand for Change Processor State/Enable Interrupt*/
}
