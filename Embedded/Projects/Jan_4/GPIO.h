#include <stdint.h>
#ifndef __GPIO_H__
#define __GPIO_H__

void GPIO_Port_DIGITAL_Init(uint32_t, char);
void experiment_port_init(void);

#define PortA_Enable  (1u);
#define PortB_Enable  (1U<<1);
#define PortC_Enable  (1U<<2);
#define PortD_Enable  (1U<<3);
#define PortE_Enable  (1U<<4);
#define PortF_Enable  (1U<<5);

#endif





