#include "TM4C123GH6PM.h"
#include "Configure.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
  Init_Board();
  Init_UART1();
  const uint32_t * start = Phased();
    while (1) {
      for(uint32_t i=0;i<2*half_wave;++i){
        GPIOB_AHB->DATA_Bits[0xFF]=*(start+i);
      }
    }
}
