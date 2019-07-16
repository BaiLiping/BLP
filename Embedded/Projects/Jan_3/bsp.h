#include <stdint.h>
#include "tm4C123gh6pm.h"

#ifndef __BSP_H__
#define    __BSP_H__

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

#endif

