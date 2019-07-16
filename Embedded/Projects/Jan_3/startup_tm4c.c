/* startup code for TM4C MCU */
#include "tm4c_cmsis.h"
#include <stdint.h>
extern int CSTACK$$Limit;
void __iar_program_start(void);
void Unused_Handler(void);

void (*const __vector_table[])()__attribute__((section(".intvec"))) = {
    (void (*)(void))((uint32_t)&CSTACK$$Limit),
    __iar_program_start,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,  /* Reserved */
    0,  /* Reserved */
    0,  /* Reserved */
    0,  /* Reserved */
    SVC_Handler,
    DebugMon_Handler,
    0,  /* Reserved */
    PendSV_Handler,
    SysTick_Handler,

    /* external interrupts (IRQs) ... */
    GPIOPortA_IRQHandler,    /* GPIO Port A                  */
    GPIOPortB_IRQHandler,    /* GPIO Port B                  */
    GPIOPortC_IRQHandler,    /* GPIO Port C                  */
    GPIOPortD_IRQHandler,    /* GPIO Port D                  */
    GPIOPortE_IRQHandler,    /* GPIO Port E                  */
    UART0_IRQHandler,        /* UART0 Rx and Tx              */
    UART1_IRQHandler,        /* UART1 Rx and Tx              */
    SSI0_IRQHandler,         /* SSI0 Rx and Tx               */
    I2C0_IRQHandler,         /* I2C0 Master and Slave        */
    PWMFault_IRQHandler,     /* PWM Fault                    */
    PWMGen0_IRQHandler,      /* PWM Generator 0              */
    PWMGen1_IRQHandler,      /* PWM Generator 1              */
    PWMGen2_IRQHandler,      /* PWM Generator 2              */
    QEI0_IRQHandler,         /* Quadrature Encoder 0         */
    ADCSeq0_IRQHandler,      /* ADC Sequence 0               */
    ADCSeq1_IRQHandler,      /* ADC Sequence 1               */
    ADCSeq2_IRQHandler,      /* ADC Sequence 2               */
    ADCSeq3_IRQHandler,      /* ADC Sequence 3               */
    Watchdog_IRQHandler,     /* Watchdog timer               */
    Timer0A_IRQHandler,      /* Timer 0 subtimer A           */
    Timer0B_IRQHandler,      /* Timer 0 subtimer B           */
    Timer1A_IRQHandler,      /* Timer 1 subtimer A           */
    Timer1B_IRQHandler,      /* Timer 1 subtimer B           */
    Timer2A_IRQHandler,      /* Timer 2 subtimer A           */
    Timer2B_IRQHandler,      /* Timer 2 subtimer B           */
    Comp0_IRQHandler,        /* Analog Comparator 0          */
    Comp1_IRQHandler,        /* Analog Comparator 1          */
    Comp2_IRQHandler,        /* Analog Comparator 2          */
    SysCtrl_IRQHandler,      /* System Control (PLL,OSC,BO)  */
    FlashCtrl_IRQHandler,    /* FLASH Control                */
    GPIOPortF_IRQHandler,    /* GPIO Port F                  */
    UART2_IRQHandler,        /* UART2 Rx and Tx              */
    SSI1_IRQHandler ,        /* SSI1 Rx and Tx               */
    Timer3A_IRQHandler,      /* Timer 3 subtimer A           */
    Timer3B_IRQHandler,      /* Timer 3 subtimer B           */
    I2C1_IRQHandler,         /* I2C1 Master and Slave        */
    QEI1_IRQHandler,         /* Quadrature Encoder 1         */
    CAN0_IRQHandler,         /* CAN0                         */
    CAN1_IRQHandler,         /* CAN1                         */
    CAN2_IRQHandler,         /* CAN2                         */
    0,                             /* Reserved                     */
    Hibernate_IRQHandler,    /* Hibernate                    */
    USB0_IRQHandler,         /* USB0                         */
    PWMGen3_IRQHandler,      /* PWM Generator 3              */
    uDMAST_IRQHandler,       /* uDMA Software Transfer       */
    uDMAError_IRQHandler,    /* uDMA Error                   */
    ADC1Seq0_IRQHandler,     /* ADC1 Sequence 0              */
    ADC1Seq1_IRQHandler,     /* ADC1 Sequence 1              */
    ADC1Seq2_IRQHandler,     /* ADC1 Sequence 2              */
    ADC1Seq3_IRQHandler,     /* ADC1 Sequence 3              */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    SSI2_IRQHandler,         /* SSI2 Rx and Tx               */
    SSI3_IRQHandler,         /* SSI3 Rx and Tx               */
    UART3_IRQHandler,        /* UART3 Rx and Tx              */
    UART4_IRQHandler,        /* UART4 Rx and Tx              */
    UART5_IRQHandler,        /* UART5 Rx and Tx              */
    UART6_IRQHandler,        /* UART6 Rx and Tx              */
    UART7_IRQHandler,        /* UART7 Rx and Tx              */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    I2C2_IRQHandler,         /* I2C2 Master and Slave        */
    I2C3_IRQHandler,         /* I2C3 Master and Slave        */
    Timer4A_IRQHandler,      /* Timer 4 subtimer A           */
    Timer4B_IRQHandler,      /* Timer 4 subtimer B           */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    Timer5A_IRQHandler,      /* Timer 5 subtimer A           */
    Timer5B_IRQHandler,      /* Timer 5 subtimer B           */
    WideTimer0A_IRQHandler,  /* Wide Timer 0 subtimer A      */
    WideTimer0B_IRQHandler,  /* Wide Timer 0 subtimer B      */
    WideTimer1A_IRQHandler,  /* Wide Timer 1 subtimer A      */
    WideTimer1B_IRQHandler,  /* Wide Timer 1 subtimer B      */
    WideTimer2A_IRQHandler,  /* Wide Timer 2 subtimer A      */
    WideTimer2B_IRQHandler,  /* Wide Timer 2 subtimer B      */
    WideTimer3A_IRQHandler,  /* Wide Timer 3 subtimer A      */
    WideTimer3B_IRQHandler,  /* Wide Timer 3 subtimer B      */
    WideTimer4A_IRQHandler,  /* Wide Timer 4 subtimer A      */
    WideTimer4B_IRQHandler,  /* Wide Timer 4 subtimer B      */
    WideTimer5A_IRQHandler,  /* Wide Timer 5 subtimer A      */
    WideTimer5B_IRQHandler,  /* Wide Timer 5 subtimer B      */
    FPU_IRQHandler,          /* FPU                          */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    I2C4_IRQHandler,         /* I2C4 Master and Slave        */
    I2C5_IRQHandler,         /* I2C5 Master and Slave        */
    GPIOPortM_IRQHandler,    /* GPIO Port M                  */
    GPIOPortN_IRQHandler,    /* GPIO Port N                  */
    QEI2_IRQHandler,         /* Quadrature Encoder 2         */
    0,                             /* Reserved                     */
    0,                             /* Reserved                     */
    PWM1Gen0_IRQHandler,     /* PWM 1 Generator 0            */
    PWM1Gen1_IRQHandler,     /* PWM 1 Generator 1            */
    PWM1Gen2_IRQHandler,     /* PWM 1 Generator 2            */
    PWM1Gen3_IRQHandler,     /* PWM 1 Generator 3            */
    PWM1Fault_IRQHandler     /* PWM 1 Fault                  */

};

__stackless void HardFault_Handler(void) {
    assert_failed("HardFault", __LINE__);
}

__stackless void NMI_Handler(void) {
    assert_failed("NMI", __LINE__);
}

__stackless void MemManage_Handler(void) {
    assert_failed("MemManage", __LINE__);
}

__stackless void BusFault_Handler(void) {
    assert_failed("BusFault", __LINE__);
}

__stackless void UsageFault_Handler(void) {
    assert_failed("UsageFault", __LINE__);
}

__stackless void Unused_Handler(void) {
    assert_failed("Unused", __LINE__);
}

#pragma weak SVC_Handler       = Unused_Handler
#pragma weak DebugMon_Handler  = Unused_Handler
#pragma weak PendSV_Handler    = Unused_Handler
#pragma weak SysTick_Handler   = Unused_Handler

#pragma weak GPIOPortA_IRQHandler   = Unused_Handler
#pragma weak GPIOPortB_IRQHandler   = Unused_Handler
#pragma weak GPIOPortC_IRQHandler   = Unused_Handler
#pragma weak GPIOPortD_IRQHandler   = Unused_Handler
#pragma weak GPIOPortE_IRQHandler   = Unused_Handler
#pragma weak UART0_IRQHandler       = Unused_Handler
#pragma weak UART1_IRQHandler       = Unused_Handler
#pragma weak SSI0_IRQHandler        = Unused_Handler
#pragma weak I2C0_IRQHandler        = Unused_Handler
#pragma weak PWMFault_IRQHandler    = Unused_Handler
#pragma weak PWMGen0_IRQHandler     = Unused_Handler
#pragma weak PWMGen1_IRQHandler     = Unused_Handler
#pragma weak PWMGen2_IRQHandler     = Unused_Handler
#pragma weak QEI0_IRQHandler        = Unused_Handler
#pragma weak ADCSeq0_IRQHandler     = Unused_Handler
#pragma weak ADCSeq1_IRQHandler     = Unused_Handler
#pragma weak ADCSeq2_IRQHandler     = Unused_Handler
#pragma weak ADCSeq3_IRQHandler     = Unused_Handler
#pragma weak Watchdog_IRQHandler    = Unused_Handler
#pragma weak Timer0A_IRQHandler     = Unused_Handler
#pragma weak Timer0B_IRQHandler     = Unused_Handler
#pragma weak Timer1A_IRQHandler     = Unused_Handler
#pragma weak Timer1B_IRQHandler     = Unused_Handler
#pragma weak Timer2A_IRQHandler     = Unused_Handler
#pragma weak Timer2B_IRQHandler     = Unused_Handler
#pragma weak Comp0_IRQHandler       = Unused_Handler
#pragma weak Comp1_IRQHandler       = Unused_Handler
#pragma weak Comp2_IRQHandler       = Unused_Handler
#pragma weak SysCtrl_IRQHandler     = Unused_Handler
#pragma weak FlashCtrl_IRQHandler   = Unused_Handler
#pragma weak GPIOPortF_IRQHandler   = Unused_Handler
#pragma weak UART2_IRQHandler       = Unused_Handler
#pragma weak SSI1_IRQHandler        = Unused_Handler
#pragma weak Timer3A_IRQHandler     = Unused_Handler
#pragma weak Timer3B_IRQHandler     = Unused_Handler
#pragma weak I2C1_IRQHandler        = Unused_Handler
#pragma weak QEI1_IRQHandler        = Unused_Handler
#pragma weak CAN0_IRQHandler        = Unused_Handler
#pragma weak CAN1_IRQHandler        = Unused_Handler
#pragma weak CAN2_IRQHandler        = Unused_Handler
#pragma weak Hibernate_IRQHandler   = Unused_Handler
#pragma weak USB0_IRQHandler        = Unused_Handler
#pragma weak PWMGen3_IRQHandler     = Unused_Handler
#pragma weak uDMAST_IRQHandler      = Unused_Handler
#pragma weak uDMAError_IRQHandler   = Unused_Handler
#pragma weak ADC1Seq0_IRQHandler    = Unused_Handler
#pragma weak ADC1Seq1_IRQHandler    = Unused_Handler
#pragma weak ADC1Seq2_IRQHandler    = Unused_Handler
#pragma weak ADC1Seq3_IRQHandler    = Unused_Handler
#pragma weak I2S0_IRQHandler        = Unused_Handler
#pragma weak EBI0_IRQHandler        = Unused_Handler
#pragma weak GPIOPortJ_IRQHandler   = Unused_Handler
#pragma weak GPIOPortK_IRQHandler   = Unused_Handler
#pragma weak GPIOPortL_IRQHandler   = Unused_Handler
#pragma weak SSI2_IRQHandler        = Unused_Handler
#pragma weak SSI3_IRQHandler        = Unused_Handler
#pragma weak UART3_IRQHandler       = Unused_Handler
#pragma weak UART4_IRQHandler       = Unused_Handler
#pragma weak UART5_IRQHandler       = Unused_Handler
#pragma weak UART6_IRQHandler       = Unused_Handler
#pragma weak UART7_IRQHandler       = Unused_Handler
#pragma weak I2C2_IRQHandler        = Unused_Handler
#pragma weak I2C3_IRQHandler        = Unused_Handler
#pragma weak Timer4A_IRQHandler     = Unused_Handler
#pragma weak Timer4B_IRQHandler     = Unused_Handler
#pragma weak Timer5A_IRQHandler     = Unused_Handler
#pragma weak Timer5B_IRQHandler     = Unused_Handler
#pragma weak WideTimer0A_IRQHandler = Unused_Handler
#pragma weak WideTimer0B_IRQHandler = Unused_Handler
#pragma weak WideTimer1A_IRQHandler = Unused_Handler
#pragma weak WideTimer1B_IRQHandler = Unused_Handler
#pragma weak WideTimer2A_IRQHandler = Unused_Handler
#pragma weak WideTimer2B_IRQHandler = Unused_Handler
#pragma weak WideTimer3A_IRQHandler = Unused_Handler
#pragma weak WideTimer3B_IRQHandler = Unused_Handler
#pragma weak WideTimer4A_IRQHandler = Unused_Handler
#pragma weak WideTimer4B_IRQHandler = Unused_Handler
#pragma weak WideTimer5A_IRQHandler = Unused_Handler
#pragma weak WideTimer5B_IRQHandler = Unused_Handler
#pragma weak FPU_IRQHandler         = Unused_Handler
#pragma weak PECI0_IRQHandler       = Unused_Handler
#pragma weak LPC0_IRQHandler        = Unused_Handler
#pragma weak I2C4_IRQHandler        = Unused_Handler
#pragma weak I2C5_IRQHandler        = Unused_Handler
#pragma weak GPIOPortM_IRQHandler   = Unused_Handler
#pragma weak GPIOPortN_IRQHandler   = Unused_Handler
#pragma weak QEI2_IRQHandler        = Unused_Handler
#pragma weak Fan0_IRQHandler        = Unused_Handler
#pragma weak PWM1Gen0_IRQHandler    = Unused_Handler
#pragma weak PWM1Gen1_IRQHandler    = Unused_Handler
#pragma weak PWM1Gen2_IRQHandler    = Unused_Handler
#pragma weak PWM1Gen3_IRQHandler    = Unused_Handler
#pragma weak PWM1Fault_IRQHandler   = Unused_Handler

