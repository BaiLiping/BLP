#include "TM4C123GH6PM.h"

extern uint32_t phased_array[10];
extern uint32_t * iterators[10];
extern const uint32_t half_wave;
extern const uint32_t number_of_transducers;

const uint32_t * Phased(){
  //setup the basic 3/2 pi wave
  const uint32_t n = 3*half_wave;
  uint32_t * gpio_data = (uint32_t*) malloc(n * sizeof(uint32_t));
  for (uint32_t i = 0; i <3; ++i) {
          gpio_data[i*half_wave] = (i % 2 == 0) ? 1 : 0;
          for (uint32_t j=1; j<half_wave; ++j){

           gpio_data[i*half_wave+j]=gpio_data[i*half_wave];
          }
  }

  const uint32_t phase = 1;

  for (int i=0;i<number_of_transducers;++i){
	  phased_array[i]=i%17;
	 }

  for (int i=0; i<number_of_transducers; ++i){
         iterators[i]=gpio_data+phased_array[i]*phase;
  }

  //the actual phased array wave
   const uint32_t wave_length=2*half_wave;
   uint32_t * st_ptr = (uint32_t*) malloc(wave_length * sizeof(uint32_t));

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
 return st_ptr;
}
