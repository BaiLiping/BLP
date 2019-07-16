#ifndef __CONFIGURE_H
#define __CONFIGURE_H




//declaring global variables
uint32_t phased_array[10];
uint32_t * iterators[10];
const uint32_t half_wave=51;  //emperically findout 51cycles for 40Khz
const uint32_t number_of_transducers=8;

//declaring functions
void Init_Board(void);
void Init_UART1(void);
const uint32_t * Phased(void);

#endif
