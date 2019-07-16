#include <stdint.h>
#include "Systick.h"
#include "PLL.h"
#include "bsp.h"
#include "tm4c123gh6pm.h"
#include "Periodic_Interrupt.h"



void main()
{
  //int j=0;
  /*PLL_Init(Bus4MHz); //initialte clock
  GPIO_Port_DIGITAL_Init(1,'F');
  GPIO_Port_DIGITAL_Init(1,'B');
  SYSCTL_RCGCGPIO_R = 0x22U;
  SYSCTL_GPIOHBCTL_R = 0x22U;
  GPIO_PORTF_AHB_DIR_R = 0x0EU;
  GPIO_PORTF_AHB_DEN_R = 0x0EU;
  GPIO_PORTB_AHB_DEN_R = 0xFF;
  GPIO_PORTB_AHB_DIR_R = 0xFF;

   all of the above would go into enable_periodic_interrupt_init();
  */

  PLL_Init(Bus8MHz);
  periodic_interrupt_init();

  EnableInterrupts();
  enable_periodic_interrupt();

  while(1){
  }





  /*while (1) {
      SysTick_Init();
      //WaitForInterrupt();
      GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN]=0xFF;
      j++;
      if(j<255)
      GPIO_PORTB_AHB_DATA_BITS_R[j]=0x00;
      else
        j=j-255;
        GPIO_PORTB_AHB_DATA_BITS_R[j]=0x00;
      SysTick_Wait10ms(10);

      GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN]=0x00;
      SysTick_Wait10ms(10);
      GPIO_PORTB_AHB_DATA_BITS_R[j]=0xFF;
      GPIO_PORTB_AHB_DATA_BITS_R[255]=0xFF;
    }//the polling method for toggling the LED*/

}
