#include "TM4C123GH6PM.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



//declaring global variables
uint32_t phased_array[10];
uint32_t * iterators[10];






int main() {
      SYSCTL->RCC=(1U<<5);//enable internal clock 16MHz
  const uint32_t number_of_transducers=8;
    //printf("testing uart\n");
    //initialize port B
    SYSCTL->RCGCGPIO = 0xFF; //enable it
    SYSCTL->GPIOHBCTL = 0xFF; //enable HBC bus
    GPIOB_AHB->DIR = 0xFF; //set direction as output for all pins
    GPIOB_AHB->DEN = 0xFF; //enable all pins


  //setup the basic 3/2 pi wave
  const uint32_t half_wave=51;
  const uint32_t n = 3*half_wave;
  uint32_t *gpio_data = (uint32_t*) malloc(n * sizeof(*gpio_data));
  for (uint32_t i = 0; i <3; ++i) {
          gpio_data[i*half_wave] = (i % 2 == 0) ? 1 : 0;
          for (uint32_t j=1; j<half_wave; ++j){

           gpio_data[i*half_wave+j]=gpio_data[i*half_wave];
          }
  }

  uint32_t * start = gpio_data;
  const uint32_t phase = 1;

  for (int i=0;i<number_of_transducers;++i){
	  phased_array[i]=i%17;
	 }


  for (int i=0; i<number_of_transducers; ++i){
         iterators[i]=start+phased_array[i]*phase;
  }



  //the actual phased array wave
   const uint32_t wave_length=2*half_wave;
   uint32_t * gpio_data_with_phase = (uint32_t*) malloc(wave_length * sizeof(*gpio_data_with_phase));
   uint32_t * st_ptr = gpio_data_with_phase;

 //initialize everything to zero
 for(uint32_t i=0;i<wave_length;++i){
	 *(st_ptr+i)=0;
 }
 //put set_mask into the wave
    for (uint32_t j=0; j<number_of_transducers; ++j){
      for(uint32_t i=0;i<wave_length;++i){
          if(*(iterators[j])==1) {
         *(st_ptr+i) = *(st_ptr+i) | (1U << j);
        }
          else{
            *(st_ptr+i) = *(st_ptr+i) & ~ (1U << j);
          }
        ++iterators[j];
       }
    }
    while (1) {
      for(uint32_t i=0;i<2*half_wave;++i){
        GPIOB_AHB->DATA_Bits[0xFF]=*(st_ptr+i);
      }
    }
}
