/* Board Support Package */
#include "tm4C123gh6pm.h"
//#include "tm4c_cmsis.h"


__stackless void assert_failed (char const *file, int line) {
    /* TBD: damage control */
    NVIC_SystemReset(); /* reset the system */
}

void SysTick_Handler(void) {
    GPIOF_AHB_DATA_BITS_R[LED_RED] ^= LED_RED;
}