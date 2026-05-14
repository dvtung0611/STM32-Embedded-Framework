#include <stdint.h>


extern uint32_t _estack;
extern uint32_t _stext;
extern uint32_t _etext;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

extern int main(void);


typedef void (*ISR_Handler_t)(void);


/**
 * @brief Exception handlers
 * 
 * @note
 * Refer to:
 * - RM0090 Reference Manual,   Table 62. Vector table for STM32F405xx/07xx
 */
void Reset_Handler                      (void);
void Default_Handler                    (void);
void NMI_Handler 					    (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler 					    (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler   				    (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler  				    (void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void RCC_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI0_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI1_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI2_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI3_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI4_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler 		    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler 		    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler 		    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler 		    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler 		    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler 		    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler 		    (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler 		    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler 		    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler 	    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM4_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler 			    (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler  				    (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI2_IRQHandler 				    (void) __attribute__ ((weak, alias("Default_Handler")));
void USART1_IRQHandler  			    (void) __attribute__ ((weak, alias("Default_Handler")));
void USART2_IRQHandler  			    (void) __attribute__ ((weak, alias("Default_Handler")));
void USART3_IRQHandler   			    (void) __attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler   		    (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler    		    (void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler     	    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler   	    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler    	    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler 	    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler          	    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler     	    (void) __attribute__ ((weak, alias("Default_Handler")));
void FSMC_IRQHandler             	    (void) __attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler             	    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler             	    (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler             	    (void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler            	    (void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler            	    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler         	    (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler             	    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler     	    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler     	    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler     	    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler     	    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler     	    (void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_IRQHandler              	    (void) __attribute__ ((weak, alias("Default_Handler")));
void ETH_WKUP_IRQHandler         	    (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_TX_IRQHandler          	    (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX0_IRQHandler         	    (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX1_IRQHandler         	    (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_SCE_IRQHandler         	    (void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler           	    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler     	    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler     	    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler     	    (void) __attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler           	    (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler          	    (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler          	    (void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler   	    (void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler    	    (void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler      	    (void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler           	    (void) __attribute__ ((weak, alias("Default_Handler")));
void DCMI_IRQHandler             	    (void) __attribute__ ((weak, alias("Default_Handler")));
void CRYP_IRQHandler             	    (void) __attribute__ ((weak, alias("Default_Handler")));
void HASH_RNG_IRQHandler         	    (void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler              	    (void) __attribute__ ((weak, alias("Default_Handler")));


/**
 * @brief Vector table
 * 
 * @note
 * Refer to:
 * - RM0090 Reference Manual,   Table 62. Vector table for STM32F405xx/07xx
 */
const ISR_Handler_t vector_table[] __attribute__((section(".isr_vector"))) = {
    (ISR_Handler_t)&_estack,                 /* Initial Stack Pointer */

    Reset_Handler,                          /* Reset Handler */
    NMI_Handler,                            /* Non-maskable interrupt */
    HardFault_Handler,                      /* Hard fault interrupt */
    MemManage_Handler,                      /* Memory management fault */
    BusFault_Handler,                       /* Bus fault */
    UsageFault_Handler,                     /* Usage fault */

    0,                                      /* Reserved */
    0,                                      /* Reserved */
    0,                                      /* Reserved */
    0,                                      /* Reserved */

    SVC_Handler,                            /* SVCall interrupt */
    DebugMon_Handler,                       /* Debug monitor interrupt */

    0,                                      /* Reserved */

    PendSV_Handler,                         /* PendSV interrupt */
    SysTick_Handler,                        /* SysTick interrupt */

    WWDG_IRQHandler,                        /* Window watchdog interrupt */
    PVD_IRQHandler,                         /* PVD through EXTI line detection interrupt */
    TAMP_STAMP_IRQHandler,                  /* Tamper and time stamp interrupt */
    RTC_WKUP_IRQHandler,                    /* RTC wakeup interrupt */

    0,                                      /* Reserved */

    RCC_IRQHandler,                         /* RCC global interrupt */
    EXTI0_IRQHandler,                       /* EXTI line0 interrupt */
    EXTI1_IRQHandler,                       /* EXTI line1 interrupt */
    EXTI2_IRQHandler,                       /* EXTI line2 interrupt */
    EXTI3_IRQHandler,                       /* EXTI line3 interrupt */
    EXTI4_IRQHandler,                       /* EXTI line4 interrupt */

    DMA1_Stream0_IRQHandler,                /* DMA1 stream0 global interrupt */
    DMA1_Stream1_IRQHandler,                /* DMA1 stream1 global interrupt */
    DMA1_Stream2_IRQHandler,                /* DMA1 stream2 global interrupt */
    DMA1_Stream3_IRQHandler,                /* DMA1 stream3 global interrupt */
    DMA1_Stream4_IRQHandler,                /* DMA1 stream4 global interrupt */
    DMA1_Stream5_IRQHandler,                /* DMA1 stream5 global interrupt */
    DMA1_Stream6_IRQHandler,                /* DMA1 stream6 global interrupt */

    ADC_IRQHandler,                         /* ADC global interrupt */

    CAN1_TX_IRQHandler,                     /* CAN1 TX interrupt */
    CAN1_RX0_IRQHandler,                    /* CAN1 RX0 interrupt */
    CAN1_RX1_IRQHandler,                    /* CAN1 RX1 interrupt */
    CAN1_SCE_IRQHandler,                    /* CAN1 SCE interrupt */

    EXTI9_5_IRQHandler,                     /* EXTI line[9:5] interrupts */

    TIM1_BRK_TIM9_IRQHandler,               /* TIM1 break and TIM9 interrupt */
    TIM1_UP_TIM10_IRQHandler,               /* TIM1 update and TIM10 interrupt */
    TIM1_TRG_COM_TIM11_IRQHandler,          /* TIM1 trigger/commutation and TIM11 interrupt */
    TIM1_CC_IRQHandler,                     /* TIM1 capture compare interrupt */

    TIM2_IRQHandler,                        /* TIM2 global interrupt */
    TIM3_IRQHandler,                        /* TIM3 global interrupt */
    TIM4_IRQHandler,                        /* TIM4 global interrupt */

    I2C1_EV_IRQHandler,                     /* I2C1 event interrupt */
    I2C1_ER_IRQHandler,                     /* I2C1 error interrupt */

    I2C2_EV_IRQHandler,                     /* I2C2 event interrupt */
    I2C2_ER_IRQHandler,                     /* I2C2 error interrupt */

    SPI1_IRQHandler,                        /* SPI1 global interrupt */
    SPI2_IRQHandler,                        /* SPI2 global interrupt */

    USART1_IRQHandler,                      /* USART1 global interrupt */
    USART2_IRQHandler,                      /* USART2 global interrupt */
    USART3_IRQHandler,                      /* USART3 global interrupt */

    EXTI15_10_IRQHandler,                   /* EXTI line[15:10] interrupts */

    RTC_Alarm_IRQHandler,                   /* RTC alarm interrupt */
    OTG_FS_WKUP_IRQHandler,                 /* USB OTG FS wakeup interrupt */

    TIM8_BRK_TIM12_IRQHandler,              /* TIM8 break and TIM12 interrupt */
    TIM8_UP_TIM13_IRQHandler,               /* TIM8 update and TIM13 interrupt */
    TIM8_TRG_COM_TIM14_IRQHandler,          /* TIM8 trigger/commutation and TIM14 interrupt */
    TIM8_CC_IRQHandler,                     /* TIM8 capture compare interrupt */

    DMA1_Stream7_IRQHandler,                /* DMA1 stream7 global interrupt */

    FSMC_IRQHandler,                        /* FSMC global interrupt */
    SDIO_IRQHandler,                        /* SDIO global interrupt */

    TIM5_IRQHandler,                        /* TIM5 global interrupt */

    SPI3_IRQHandler,                        /* SPI3 global interrupt */

    UART4_IRQHandler,                       /* UART4 global interrupt */
    UART5_IRQHandler,                       /* UART5 global interrupt */

    TIM6_DAC_IRQHandler,                    /* TIM6 and DAC underrun interrupt */
    TIM7_IRQHandler,                        /* TIM7 global interrupt */

    DMA2_Stream0_IRQHandler,                /* DMA2 stream0 global interrupt */
    DMA2_Stream1_IRQHandler,                /* DMA2 stream1 global interrupt */
    DMA2_Stream2_IRQHandler,                /* DMA2 stream2 global interrupt */
    DMA2_Stream3_IRQHandler,                /* DMA2 stream3 global interrupt */
    DMA2_Stream4_IRQHandler,                /* DMA2 stream4 global interrupt */

    ETH_IRQHandler,                         /* Ethernet global interrupt */
    ETH_WKUP_IRQHandler,                    /* Ethernet wakeup interrupt */

    CAN2_TX_IRQHandler,                     /* CAN2 TX interrupt */
    CAN2_RX0_IRQHandler,                    /* CAN2 RX0 interrupt */
    CAN2_RX1_IRQHandler,                    /* CAN2 RX1 interrupt */
    CAN2_SCE_IRQHandler,                    /* CAN2 SCE interrupt */

    OTG_FS_IRQHandler,                      /* USB OTG FS global interrupt */

    DMA2_Stream5_IRQHandler,                /* DMA2 stream5 global interrupt */
    DMA2_Stream6_IRQHandler,                /* DMA2 stream6 global interrupt */
    DMA2_Stream7_IRQHandler,                /* DMA2 stream7 global interrupt */

    USART6_IRQHandler,                      /* USART6 global interrupt */

    I2C3_EV_IRQHandler,                     /* I2C3 event interrupt */
    I2C3_ER_IRQHandler,                     /* I2C3 error interrupt */

    OTG_HS_EP1_OUT_IRQHandler,              /* USB OTG HS endpoint 1 OUT interrupt */
    OTG_HS_EP1_IN_IRQHandler,               /* USB OTG HS endpoint 1 IN interrupt */
    OTG_HS_WKUP_IRQHandler,                 /* USB OTG HS wakeup interrupt */
    OTG_HS_IRQHandler,                      /* USB OTG HS global interrupt */

    DCMI_IRQHandler,                        /* DCMI global interrupt */

    CRYP_IRQHandler,                        /* Cryptographic processor global interrupt */
    HASH_RNG_IRQHandler,                    /* Hash and RNG global interrupt */

    FPU_IRQHandler                          /* Floating point unit interrupt */
};


void Default_Handler(void)
{
    while(1);
}


void Reset_Handler(void)
{
    // Copy .data section from FLASH to SRAM
    uint8_t *pDes = (uint8_t *)(&_sdata);
    uint8_t *pSrc = (uint8_t *)(&_sidata);
    uint32_t size = (uint32_t)(&_edata) - (uint32_t)(&_sdata);
    while (size--)
    {
        *pDes = *pSrc;
        pDes++;
        pSrc++;
    }

    // Initialize .bss section in SRAM
    uint8_t *pbss = (uint8_t *)(&_sbss);
    size = (uint32_t)(&_ebss) - (uint32_t)(&_sbss);
    while (size--)
    {
        *pbss = 0;
        pbss++;
    }

    // Call main function
    main();
}