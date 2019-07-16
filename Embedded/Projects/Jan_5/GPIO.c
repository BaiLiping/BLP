#include<stdint.h>
#include "GPIO.h"
#include "tm4c123gh6pm.h"

void GPIO_Port_DIGITAL_Init(uint32_t Bus_Number, char Port){

if (Port=='A')
{
      SYSCTL_RCGCGPIO_R |= PortA_Enable;
      if (Bus_Number==1)
      {
        SYSCTL_GPIOHBCTL_R |= PortA_Enable;
        GPIO_PORTA_AHB_DIR_R = 0x00;
        //GPIO_PORTA_AHB_PDR_R = 0xFC;
        GPIO_PORTA_AHB_DEN_R |= 0xFC;
        //GPIO_PORTA_AHB_AFSEL_R = 0;
        //GPIO_PORTA_AHB_PCTL_R = 0;
        //GPIO_PORTA_AHB_AMSEL_R = 0;
      }
      else
      {
        SYSCTL_GPIOHBCTL_R = PortA_Enable;
        GPIO_PORTA_DIR_R |= 0x00;
        GPIO_PORTA_DEN_R |= 0xFF;
        //GPIO_PORTF_PUR_R |= 0xFF;
        GPIO_PORTA_AFSEL_R = 0;
        GPIO_PORTA_PCTL_R = 0;
        GPIO_PORTA_AMSEL_R = 0;
      }
}

if (Port=='B')
{
      SYSCTL_RCGCGPIO_R |= PortB_Enable;
      if (Bus_Number==1)
      {
        SYSCTL_GPIOHBCTL_R |= PortB_Enable;
        GPIO_PORTB_AHB_DIR_R |= 0xFF;
        GPIO_PORTB_AHB_DEN_R |= 0xFF;
        GPIO_PORTB_AHB_AFSEL_R = 0;
        GPIO_PORTB_AHB_PCTL_R = 0;
        GPIO_PORTB_AHB_AMSEL_R = 0;
      }
      else
      {
        SYSCTL_GPIOHBCTL_R = PortB_Enable;
        GPIO_PORTB_DIR_R |= 0xFF;
        GPIO_PORTB_DEN_R |= 0xFF;
        GPIO_PORTB_AFSEL_R = 0;
        GPIO_PORTB_PCTL_R = 0;
        GPIO_PORTB_AMSEL_R = 0;
      }
}


if (Port=='D')
{
      SYSCTL_RCGCGPIO_R |= PortD_Enable;
      if (Bus_Number==1)
      {
        SYSCTL_GPIOHBCTL_R |= PortD_Enable;
        GPIO_PORTD_AHB_DIR_R |= 0xFF;
        GPIO_PORTD_AHB_DEN_R |= 0xFF;
        GPIO_PORTD_AHB_AFSEL_R = 0;
        GPIO_PORTD_AHB_PCTL_R = 0;
        GPIO_PORTD_AHB_AMSEL_R = 0;
      }
      else
      {
        SYSCTL_GPIOHBCTL_R &= ~PortD_Enable;
        GPIO_PORTD_DIR_R |= 0xFF;
        GPIO_PORTD_DEN_R |= 0xFF;
        GPIO_PORTD_AFSEL_R = 0;
        GPIO_PORTD_PCTL_R = 0;
        GPIO_PORTD_AMSEL_R = 0;
      }
}
if (Port=='E')
{
      SYSCTL_RCGCGPIO_R |= PortE_Enable;
      if (Bus_Number==1)
      {
        SYSCTL_GPIOHBCTL_R |= PortE_Enable;
        GPIO_PORTE_AHB_DIR_R |= 0x00;
        GPIO_PORTE_AHB_DEN_R |= 0xFF;
        GPIO_PORTE_AHB_AFSEL_R = 0;
        GPIO_PORTE_AHB_PCTL_R = 0;
        GPIO_PORTE_AHB_AMSEL_R = 0;
      }
      else
      {
        SYSCTL_GPIOHBCTL_R &= ~PortE_Enable;
        GPIO_PORTE_DIR_R |= 0xFF;
        GPIO_PORTE_DEN_R |= 0xFF;
        GPIO_PORTE_AFSEL_R = 0;
        GPIO_PORTE_PCTL_R = 0;
        GPIO_PORTE_AMSEL_R = 0;
      }
}

if(Port=='F')
{    SYSCTL_RCGCGPIO_R |= PortF_Enable;
      if (Bus_Number==1)
      {
        SYSCTL_GPIOHBCTL_R |= PortF_Enable;
        GPIO_PORTF_AHB_DEN_R = 0x1F;
        GPIO_PORTF_AHB_DIR_R = 0x0E;
        GPIO_PORTF_AHB_AFSEL_R = 0;
        GPIO_PORTF_AHB_PCTL_R = 0;
        GPIO_PORTF_AHB_AMSEL_R = 0;
      }
      else
      {
        SYSCTL_GPIOHBCTL_R &= ~PortB_Enable;
        GPIO_PORTF_DIR_R = 0x0E;
        GPIO_PORTF_DEN_R = 0x1F;
        GPIO_PORTF_AFSEL_R = 0;
        GPIO_PORTF_PCTL_R = 0;
        GPIO_PORTF_AMSEL_R = 0;
      }
}
}

