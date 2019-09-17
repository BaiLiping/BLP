#include "tm4c_cmsis.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    //initialize port B
    SYSCTL->RCGCGPIO = 0xFF; //enable it
    SYSCTL->GPIOHBCTL = 0xFF; //enable HBC bus
    GPIOB_HS->DIR = 0xFF; //set direction as output for all pins
    GPIOB_HS->DEN = 0xFF; //enable all pins


  //setup the basic 3/2 pi wave
  const uint32_t half_wave=15;
  const uint32_t n = 3*half_wave;
  uint32_t *gpio_data = (uint32_t*) malloc(n * sizeof(*gpio_data));
  for (uint32_t i = 0; i <3; ++i) {
          gpio_data[i*half_wave] = (i % 2 == 0) ? 1 : 0;
          for (uint32_t j=1; j<half_wave; ++j){

           gpio_data[i*half_wave+j]=gpio_data[i*half_wave];
	  }
  }
  /*
  //ask user about the number of transducers
  uint32_t number_of_transducers;
  printf("pls enter the number of transducers used in this experiment: \n");
  scanf("%u",&number_of_transducers);
  printf("you are using %u of transducers for this experiment \n", number_of_transducers);
  */
  uint32_t number_of_transducers=1;

  //get the phase-array from user

  uint32_t *start = gpio_data;
  const uint32_t phase = half_wave/5;


  uint32_t *phased_array;
  /*printf("pls enter the phased array: \n");
  for (int i=0;i<number_of_transducers;++i){
	  scanf("%u",&phased_array[i]);
	 }
  printf("you've entered: \n");

  for (int i=0;i<number_of_transducers;++i){
      printf("%d\n",phased_array[i]);
  } */

  for (int i=0;i<number_of_transducers;++i){
	  phased_array[i]=i%6;
	 }

  //stepup starting pointer based on the phased_array
  uint32_t **iterators;
  for (int i=0;i<number_of_transducers;++i){
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
          if(*(iterators[j]+i)==1) {
         *(st_ptr+i) = *(st_ptr+i) | (1U << j);
        }
          else{
            *(st_ptr+i) = *(st_ptr+i) & ~ (1U << j);
          }
        ++iterators[j];
       }
    }
    while (1) {
      //uint32_t wave_length=10000;
      for(uint32_t i=0;i<wave_length;++i){
        GPIO_PORTB_AHB_DATA_BITS_R[0xFF]=*(st_ptr+i);
      }
    }
}
