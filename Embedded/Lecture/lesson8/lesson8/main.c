#include "lm4f120h5qr.h"

#define LED_RED   (1U << 0)
#define LED_BLUE  (1U << 1)
#define LED_GREEN (1U << 2)

void delay(int iter);

void delay(int iter) {
    int volatile counter;
    counter = 0;
    while (counter < iter) {  // delay loop
        ++counter;
    }
}

int main() {
    SYSCTL_RCGCGPIO_R = 0xFF;  /* enable clock for GPIOF */
    SYSCTL_GPIOHBCTL_R = 0xFF; /* enable AHB for GPIOF */
    GPIO_PORTB_AHB_DIR_R = 0xFF;
    GPIO_PORTB_AHB_DEN_R = 0xFF;

    GPIO_PORTB_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
    while (1) {
        GPIO_PORTB_AHB_DATA_BITS_R[0xFF] = 0xFF;

        delay(1000000);

        GPIO_PORTB_AHB_DATA_BITS_R[0xFF] = 0;

        delay(1000000);
    }
    //return 0;
}
