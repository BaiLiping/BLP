/* Board Support Package */
#include "tm4C123gh6pm.h"
#include <stdint.h>
#include "bsp.h"
#include "Periodic_Interrupt.h"
#include "GPIO.h"
uint32_t count = 0;

__stackless void assert_failed (char const *file, int line) {
    /* TBD: damage control */
     GPIO_PORTF_AHB_DATA_BITS_R[4] ^= 0xFF;; /* reset the system */
}

void SysTick_Handler(void) {
  GPIO_PORTF_AHB_DATA_BITS_R[2]^=0xFF;
  GPIO_PORTB_AHB_DATA_BITS_R[255]=0xFF;
  count++;
  GPIO_PORTB_AHB_DATA_BITS_R[count%256]^=0xFF;

}

void GPIOPortF_IRQHandler(){
//NVIC_ST_CTRL_R |=(1u<<1);
  GPIO_PORTF_AHB_ICR_R = 0x1F;

  enable_periodic_interrupt();
}

void GPIOPortE_IRQHandler(){
  //NVIC_ST_CTRL_R &=(0u<<1);
  GPIO_PORTE_AHB_ICR_R = 0x30;

  disable_periodic_interrupt();
  count++;
  GPIO_PORTF_AHB_DATA_BITS_R[8]^=0xFF;
  GPIO_PORTB_AHB_DATA_BITS_R[255]=~count;
  GPIO_PORTF_AHB_ICR_R = 0x1F;
}

void GPIOPortA_IRQHandler(){
  //NVIC_ST_CTRL_R &=(0u<<1);
  GPIO_PORTA_AHB_ICR_R = 0x80;

  disable_periodic_interrupt();
  count++;
  GPIO_PORTF_AHB_DATA_BITS_R[4]^=0xFF;
  GPIO_PORTB_AHB_DATA_BITS_R[255]=0xFF;
  GPIO_PORTB_AHB_DATA_BITS_R[count%256]^=0xFF;
}


void DisableInterrupts(void){
	__asm ("    CPSID  I\n");
}

void EnableInterrupts(void){
	__asm  ("    CPSIE  I\n");
}
