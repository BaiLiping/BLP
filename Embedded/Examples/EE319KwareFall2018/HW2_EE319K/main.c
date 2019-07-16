// HW2gradermain.c
// Runs on LM4F120/TM4C123
// Used to grade HW2
// Jonathan Valvano Valvano
// August 31, 2018

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2018

 Copyright 2018 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1
#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

#include "PLL.h"
#include "UART.h"
void InitPB6(void); 
void SetPB6(void); 
void Inc16(void); 
void Dec8(void); 
void Set4Clear28(void);
extern uint16_t icount;
extern int8_t bcount;
extern uint8_t keepOut;
extern uint32_t N;
extern char myEID[]; // student EID
uint32_t M=0;

//------------Random256------------
// Return R0= random number
// Linear congruential generator 
// from Numerical Recipes by Press et al.
uint32_t Random256(void){
	M=1664525*M+1013904223 ;
  return M>>24;  // 0 to 255
}
uint32_t Random128(void){
	M=1664525*M+1013904223 ;
  return M>>25;  // 0 to 127
}
uint32_t Random2(void){
	M=1664525*M+1013904223 ;
  return M>>31;  // 0 to 1
}
uint32_t Random9(void){
	M=1664525*M+1013904223 ;
  return M/477218589; // 0 to 8
}
uint32_t Random10(void){
	M=1664525*M+1013904223 ;
  return M/429496730; // 0 to 9
}
uint32_t Random26(void){
	M=1664525*M+1013904223 ;
  return M/165191050; // 0 to 25
}
char RandomChar(void){uint32_t n;
	M=1664525*M+1013904223 ;
  n = M/69273667; // 0 to 61
	if(n<10){
		return '0'+n; // '0' to '9'
	}
	if(n < 36){
		return 'A'+n-10; // 'A' to 'Z'
	}
	return 'a'+n-36;  // 'a' to 'z'
}
char upper(char letter){
	if((letter >= 'a')&&(letter <= 'z')){
		return letter-0x20; // lower to upper
	}
	return letter;
}
char Secret[28];
char Encode[14];
char Message[28];
char const key[28] = {0x02, 0x07, 0x04, 0x05, 0x01, 0x07, 0x02, 0x03, 0x02, 0x05, 0x04, 0x06,0x03,0x01,
                      0x07, 0x01, 0x02, 0x07, 0x06, 0x03, 0x04, 0x06, 0x04, 0x01, 0x03, 0x05,0x02,0x03};
int const Shuffle[28]   = { 5,21,12,19, 7,14,10,27, 2,25,11,20, 3,17,13,15, 4,26, 0,23, 1,16, 6,18, 8,22, 9,24};
//                          0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
int const unShuffle[28] = {18,20, 8,12,16, 0,22, 4,24,26, 6,10, 2,14, 5,15,21,13,23, 3,11, 1,25,19,27, 9,17, 7};
//uint32_t x9,x10,x26;
//char x;
// encode score into secret output
// score is 0 to 100
// hw is 0 to 127
void Encrypt(uint32_t score,uint32_t hw){int i;
	M = NVIC_ST_CURRENT_R; // seed
//  ASCII characters 0x30 (40) to 0x5A (90) 
// create the 14 character code
  // EID 9 characters (convert to upper case, fill rest of characters with random lower case letters
  // score 2 characters 00 to 99 (if 100, randomly choose 91 to 99, which means 100)
	// random number/upper/lower case character
  // HW is number from 0 to 255
	// random number/upper/lower case character
// 1) shuffle the characters position
// 2) EOR bottom 4 bits with key  
	i=0;
	while(myEID[i]&&(i<9)){
		Encode[i] = upper(myEID[i]);
		i++;
	}
	while(i<9){
		Encode[i] = 'a'+Random26(); // 'a' to 'z'
		i++;
	}
	if(score>100) score = 0;
	if(score==100){
		score = 91+Random9(); // 0 to 99, 91-99 means 100
	}
	Encode[9] = Random128(); // 0 to 127
	Encode[10] = score;      // 0 to 100
	Encode[11] = Random128(); // 0 to 127
	Encode[12] = hw;
	Encode[13] = Random128(); // 0 to 127
	for(i=0; i<14; i++){
	  Message[2*i] = 'A'+Encode[i]/16; // top 4 bits
	  Message[2*i+1] = 'A'+Encode[i]%16; // bottom 4 bits
	}
	for(i=0; i<28; i++){
//		Secret[i] = 0x20*Random2()+((Message[i]-1)^key[i])+1;
		Secret[Shuffle[i]] = 0x20*Random2()+((Message[i]-1)^key[i])+1;
	}
}
char Message2[28];
char Encode2[14];
uint32_t Score2,hw2;
char myEID2[10];
void Decrypt(void){ int i;
	for(i=0; i<28; i++){
		Message2[unShuffle[i]] = (~0x20)&((Secret[i]-1)^key[unShuffle[i]])+1;
	}
	for(i=0;i<14;i++){
		Encode2[i] = (Message2[2*i]-'A')*16 +(Message2[2*i+1]-'A'); 
	}
	Score2 = Encode2[10];
	if(Score2>90)Score2 = 100;
	hw2 = Encode2[12];
	i=0;
	while((Encode2[i]<'Z')&&(i<9)){
		myEID2[i] = Encode2[i];
		i++;
	}
	myEID2[i] = 0;
}
//debug code
int main(void){uint32_t score=0; uint32_t Ntest,Ncorrect,i,ok;

  PLL_Init(Bus80MHz);       // 80  MHz
  NVIC_ST_CTRL_R = 0x05;
  NVIC_ST_RELOAD_R = 0xFFFFFF; // used for random num generator
	
//	while(1){
//		x9 = Random9();
//		x10 = Random10();
//		x26 = Random26();
//    x = RandomChar();
//	}
	
  UART_Init();              // initialize UART

  UART_OutString("\n\r HW2 grader-Fall 2018, EID=");
  UART_OutString(myEID);
  
  UART_OutString("\n\r InitPB6 test ");
  InitPB6(); // call student program
  if(SYSCTL_RCGCGPIO_R&0x02){
    UART_OutString("Clock on, ");
    if(SYSCTL_RCGCGPIO_R&0x2C){
      UART_OutString(" **ERROR**, turned on other clocks ");
    }else{
      score += 10;
    }
    if(GPIO_PORTB_DIR_R&0x40){
      UART_OutString(" PB6 output, ");
      if(GPIO_PORTB_DIR_R&~0x40){
        UART_OutString(" **ERROR**, turned on DIR bits ");
      }else{
        score += 5;
      }
    }
    if(GPIO_PORTB_DEN_R&0x40){
      UART_OutString(" PB6 enabled, ");
      if(GPIO_PORTB_DEN_R&~0x40){
        UART_OutString(" **ERROR**, turned on DEN bits ");
      }else{
        score += 5;
      }
    }
  }else{
    UART_OutString(" **ERROR**, Port B Clock is off ");
  }
  if(score == 20){
    UART_OutString("\n\r SetPB5 test ");
    GPIO_PORTB_DIR_R |= 0xBF; // activate 7,5,4,3,2,1,0
    GPIO_PORTB_DEN_R |= 0xBF; // activate 7,5,4,3,2,1,0
    GPIO_PORTB_DATA_R = 0xA5; // 10100101
    SetPB6();
    if((GPIO_PORTB_DATA_R&0x40) != 0x40){
      UART_OutString("PB6 not high");
    }else{
      UART_OutString("PB6 is high, "); score += 10;
      if(GPIO_PORTB_DATA_R != 0xE5){
        UART_OutString("not friendly");
      }else{
        UART_OutString("friendly"); score += 10;
      }
    }  
  }else{
    UART_OutString("\n\r SetPB6 test skipped because InitPB5 not perfect ");
  }   
  
  UART_OutString("\n\r Inc16 test ");
  icount = 40000; bcount = -5; keepOut = 57; N = 1000;
  Inc16();
  if((icount != 40001)||(bcount != -5)){
    UART_OutString("incorrect");
  }else{
    UART_OutString("correct"); score += 10;
  }  
  if((bcount == -5)&&(keepOut == 57)&&(N == 1000)){
    score += 10;
  }else{
    UART_OutString(" your Inc16 writes outside of icount variable");
  }

  UART_OutString("\n\r Dec8 test ");
  icount = 50000; bcount = -7; keepOut = 31; N = 21234;
  Dec8();
  if(bcount != -8){
    UART_OutString("incorrect");
  }else{
    UART_OutString("correct"); score += 10;
  }  
  if((icount == 50000)&&(keepOut == 31)&&(N == 21234)){
    score += 10;
  }else{
    UART_OutString(" your Dec8 writes outside of bcount variable");
  }
  
  Ntest = 0xC34FF4E7; ok=1;
  UART_OutString("\n\r Set4Clear28 test ");
  for(i=0;i<5;i++){
    icount = 4+(int16_t)i; bcount = 71+2*i; keepOut = 33+i; 
    N = Ntest;
    Ncorrect = (N&(~(1<<28)))|(1<<4); // clear bit 29 set bit 4
    Set4Clear28();
    if(N != Ncorrect){
     UART_OutString("\n\rincorrect. Init=0x");UART_OutUHex(Ntest);
     UART_OutString(" Your=0x");UART_OutUHex(N);
     UART_OutString(" Ans =0x");UART_OutUHex(Ncorrect);
     ok = 0;
    }else{
      score += 2;
    }  
    if((icount == 4+(int16_t)i)&&(bcount == 71+2*i)&&(keepOut == 33+i)){
      score += 2;
    }else{
      UART_OutString(" your Set4Clear28 writes outside of N variable\n\r");
     ok = 0;
    }
    Ntest = Ntest*1664525+1013904223;
  }
  if(ok){
    UART_OutString("correct");
  }
  else{
    UART_OutString("... Set4Clear28 has bugs");
  }
  UART_OutString("\n\r HW2 total score = ");UART_OutUDec(score);
  Encrypt(score,2);
  UART_OutString("\n\r Magic code = ");
	for(i=0;i<28;i++)UART_OutChar(Secret[i]);
  UART_OutString("\n\r");
	Decrypt();
  while(1){};

}
