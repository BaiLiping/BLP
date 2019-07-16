/* Board Support Package */
#include "tm4C123gh6pm.h"
#include <stdint.h>
#include "bsp.h"
#include "Periodic_Interrupt.h"
#include "GPIO.h"
uint32_t count = 0;
uint32_t n = 0;
__stackless void assert_failed (char const *file, int line) {
    /* TBD: damage control */
     GPIO_PORTF_AHB_DATA_BITS_R[4] ^= 0xFF;; /* reset the system */
}

void SysTick_Handler(void) {
  GPIO_PORTF_AHB_DATA_BITS_R[4]^=0xFF;
  GPIO_PORTB_AHB_DATA_BITS_R[255]=0xFF;
  count++;
  GPIO_PORTB_AHB_DATA_BITS_R[count%256]^=0xFF;
  }

void GPIOPortF_IRQHandler(){
GPIO_PORTF_ICR_R=0x11;
n++;
if (n==5)
disable_periodic_interrupt();
/*if (GPIO_PORTF_DATA_R==0x10)
enable_periodic_interrupt();
if (GPIO_PORTF_DATA_R==0x01)
{disable_periodic_interrupt();
GPIO_PORTF_AHB_DATA_BITS_R[4]^=0xFF;
count++;
GPIO_PORTB_AHB_DATA_BITS_R[count%256]^=0xFF;
} */

}
void DisableInterrupts(void){
	__asm ("    CPSID  I\n");/*this is set using assembly lanugage
                                  CPSID I stand for  Change Processor State/Disable Interrupt*/
}

void EnableInterrupts(void){
	__asm  ("    CPSIE  I\n"); /*assembly language
 CPSIT I stand for Change Processor State/Enable Interrupt*/
}
