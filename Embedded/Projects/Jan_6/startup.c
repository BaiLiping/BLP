extern int CSTACK$$Limit;
void __iar_program_start(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void HardFault_Handler(void);
void Unused_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
extern void assert_failed (char const *file, int line);

int const __vector_table[]  @".intvec" ={

0x20000400,  //Initial Stack Pointer Value
(int)__iar_program_start, //Reset
(int)&NMI_Handler, //Non_Maskable Interrupt
(int)&HardFault_Handler,
(int)&MemManage_Handler,
(int)&BusFault_Handler,
(int)&UsageFault_Handler,
0,//reserved
0,//reserved
0,//reserved
0,//reserved
(int)&SVC_Handler, //Superior Call
(int)&DebugMon_Handler, //Debug Monitor
0,//reserved
(int)&PendSV_Handler,//Pending Service
(int)&SysTick_Handler


};

__stackless void HardFault_Handler(void){
 assert_failed("HardFault",__LINE__);
}

__stackless void NMI_Handler(void){
 assert_failed("HardFault",__LINE__);
}

__stackless void MemManage_Handler(void){
 assert_failed("HardFault",__LINE__);
}

__stackless void BusFault_Handler(void){
 assert_failed("HardFault",__LINE__);
}

__stackless void UsageFault_Handler(void){
 assert_failed("HardFault",__LINE__);
}

__stackless void Unused_Handler(void){
 assert_failed("HardFault",__LINE__);
}

#pragma weak SVC_Handler             = Unused_Handler
#pragma weak DebugMon_Handler             = Unused_Handler
#pragma weak PendSV_Handler             = Unused_Handler
#pragma weak SysTick_Handler             = Unused_Handler