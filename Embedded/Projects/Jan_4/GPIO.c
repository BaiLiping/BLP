#include<stdint.h>
#include "GPIO.h"
#include "tm4c123gh6pm.h"

void GPIO_Port_DIGITAL_Init(uint32_t Bus_Number, char Port){

  if (Port=='A')
  {   SYSCTL_RCGCGPIO_R |= PortA_Enable;
      if (Bus_Number==1)
      {SYSCTL_GPIOHBCTL_R |= PortA_Enable;
       GPIO_PORTA_AHB_DIR_R |= 0XFF;
       GPIO_PORTA_AHB_DEN_R |= 0XFF;
      }
      else
      {SYSCTL_GPIOHBCTL_R &= ~PortA_Enable;
        GPIO_PORTA_DIR_R |= 0xFF;
        GPIO_PORTA_DEN_R |= 0xFF;
      }
  }
if(Port=='B')
{SYSCTL_RCGCGPIO_R |= PortB_Enable;
      if (Bus_Number==1)
      {SYSCTL_GPIOHBCTL_R |= PortB_Enable;
       GPIO_PORTB_AHB_DIR_R |= 0XFF;
       GPIO_PORTB_AHB_DEN_R |= 0XFF;}
      else
      {SYSCTL_GPIOHBCTL_R &= ~PortB_Enable;
        GPIO_PORTB_DIR_R |= 0xFF;
        GPIO_PORTB_DEN_R |= 0xFF; }
}
  if(Port=='C')
  { SYSCTL_RCGCGPIO_R |= PortC_Enable;
      if (Bus_Number==1)
      {SYSCTL_GPIOHBCTL_R |= PortC_Enable;
       GPIO_PORTC_AHB_DIR_R |= 0XFF;
       GPIO_PORTC_AHB_DEN_R |= 0XFF; }
      else
      {SYSCTL_GPIOHBCTL_R &= ~PortC_Enable;
        GPIO_PORTC_DIR_R |= 0xFF;
        GPIO_PORTC_DEN_R |= 0xFF;}
  }
if(Port=='D')
{SYSCTL_RCGCGPIO_R |= PortD_Enable;
      if (Bus_Number==1)
      {SYSCTL_GPIOHBCTL_R |= PortD_Enable;
       GPIO_PORTD_AHB_DIR_R |= 0XFF;
       GPIO_PORTD_AHB_DEN_R |= 0XFF; }
      else
      {SYSCTL_GPIOHBCTL_R &= ~PortD_Enable;
        GPIO_PORTD_DIR_R |= 0xFF;
        GPIO_PORTD_DEN_R |= 0xFF; }
}
if(Port=='E')
{    SYSCTL_RCGCGPIO_R |= PortE_Enable;
      if (Bus_Number==1)
      {SYSCTL_GPIOHBCTL_R |= PortE_Enable;
       GPIO_PORTE_AHB_DIR_R |= 0XFF;
       GPIO_PORTE_AHB_DEN_R |= 0XFF;}
      else
      {SYSCTL_GPIOHBCTL_R &= ~PortE_Enable;
        GPIO_PORTE_DIR_R |= 0xFF;
        GPIO_PORTE_DEN_R |= 0xFF; }
}
if(Port=='F')
{    SYSCTL_RCGCGPIO_R |= PortF_Enable;
      if (Bus_Number==1)
      {SYSCTL_GPIOHBCTL_R |= PortF_Enable;
       GPIO_PORTF_AHB_DIR_R |= 0X0E;
       GPIO_PORTF_AHB_DEN_R |= 0X0E;}
      else
      {SYSCTL_GPIOHBCTL_R &= ~PortB_Enable;
        GPIO_PORTF_DIR_R |= 0x0E;
        GPIO_PORTF_DEN_R |= 0x0E;}
}
}

void experiment_port_init(void){
  GPIO_Port_DIGITAL_Init(1,'F');
  GPIO_Port_DIGITAL_Init(1,'B');
  SYSCTL_RCGCGPIO_R = 0x22U;
  SYSCTL_GPIOHBCTL_R = 0x22U;
  GPIO_PORTF_AHB_DIR_R = 0x0EU;
  GPIO_PORTF_AHB_DEN_R = 0x1FU;
  //GPIO_PORTF_PUR_R = 0x11;
  GPIO_PORTB_AHB_DEN_R = 0xFF;
  GPIO_PORTB_AHB_DIR_R = 0xFF;
}