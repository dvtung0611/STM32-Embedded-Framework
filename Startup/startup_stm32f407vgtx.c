#include <stdint.h>

/**
 * @brief Initial memory macros
 * 
 * @note
 * Refer to:
 * - RM0090 Reference Manual,   Section 2.1 System architecture
 *                              Section 2.3.1 Embedded SRAM
 * - ARM Cortex-M4 Generic User Guide,  Section 2.1.2 Stacks
 */
#define SRAM_START              (0x20000000U)
#define SRAM_SIZE               ((128U) * (1024U))
#define SRAM_END                (SRAM_START + SRAM_SIZE)

#define STACK_START             (SRAM_END)


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
const uint32_t vector_table[] __attribute__((section(".isr_vector"))) = {
    STACK_START,                                        /* Initial Stack Pointer */
    (uint32_t)(Reset_Handler),                          /* Reset Handler */
    (uint32_t)(NMI_Handler),                            /* Non-maskable interrupt */
    (uint32_t)(HardFault_Handler),                      /* Hard fault interrupt */
    (uint32_t)(MemManage_Handler),                      /* Memory management fault */
    (uint32_t)(BusFault_Handler),                       /* Bus fault */
    (uint32_t)(UsageFault_Handler),                     /* Usage fault */
    0,                                                  /* Reserved */
    0,                                                  /* Reserved */
    0,                                                  /* Reserved */
    0,                                                  /* Reserved */

    (uint32_t)(SVC_Handler),                            /* SVCall interrupt */
    (uint32_t)(DebugMon_Handler),                       /* Debug monitor interrupt */
    0,                                                  /* Reserved */

    (uint32_t)(PendSV_Handler),                         /* PendSV interrupt */
    (uint32_t)(SysTick_Handler),                        /* SysTick interrupt */

    (uint32_t)(WWDG_IRQHandler),                        /* Window watchdog interrupt */
    (uint32_t)(PVD_IRQHandler),                         /* PVD through EXTI line detection interrupt */
    (uint32_t)(TAMP_STAMP_IRQHandler),                  /* Tamper and time stamp interrupt */
    (uint32_t)(RTC_WKUP_IRQHandler),                    /* RTC wakeup interrupt */
    0,                                                  /* Reserved */

    (uint32_t)(RCC_IRQHandler),                         /* RCC global interrupt */
    (uint32_t)(EXTI0_IRQHandler),                       /* EXTI line0 interrupt */
    (uint32_t)(EXTI1_IRQHandler),                       /* EXTI line1 interrupt */
    (uint32_t)(EXTI2_IRQHandler),                       /* EXTI line2 interrupt */
    (uint32_t)(EXTI3_IRQHandler),                       /* EXTI line3 interrupt */
    (uint32_t)(EXTI4_IRQHandler),                       /* EXTI line4 interrupt */
    (uint32_t)(DMA1_Stream0_IRQHandler),                /* DMA1 stream0 global interrupt */
    (uint32_t)(DMA1_Stream1_IRQHandler),                /* DMA1 stream1 global interrupt */
    (uint32_t)(DMA1_Stream2_IRQHandler),                /* DMA1 stream2 global interrupt */
    (uint32_t)(DMA1_Stream3_IRQHandler),                /* DMA1 stream3 global interrupt */
    (uint32_t)(DMA1_Stream4_IRQHandler),                /* DMA1 stream4 global interrupt */
    (uint32_t)(DMA1_Stream5_IRQHandler),                /* DMA1 stream5 global interrupt */
    (uint32_t)(DMA1_Stream6_IRQHandler),                /* DMA1 stream6 global interrupt */
    (uint32_t)(ADC_IRQHandler),                         /* ADC global interrupt */
    (uint32_t)(CAN1_TX_IRQHandler),                     /* CAN1 TX interrupt */
    (uint32_t)(CAN1_RX0_IRQHandler),                    /* CAN1 RX0 interrupt */
    (uint32_t)(CAN1_RX1_IRQHandler),                    /* CAN1 RX1 interrupt */
    (uint32_t)(CAN1_SCE_IRQHandler),                    /* CAN1 SCE interrupt */
    (uint32_t)(EXTI9_5_IRQHandler),                     /* EXTI line[9:5] interrupts */
    (uint32_t)(TIM1_BRK_TIM9_IRQHandler),               /* TIM1 break and TIM9 interrupt */
    (uint32_t)(TIM1_UP_TIM10_IRQHandler),               /* TIM1 update and TIM10 interrupt */
    (uint32_t)(TIM1_TRG_COM_TIM11_IRQHandler),          /* TIM1 trigger/commutation and TIM11 interrupt */
    (uint32_t)(TIM1_CC_IRQHandler),                     /* TIM1 capture compare interrupt */
    (uint32_t)(TIM2_IRQHandler),                        /* TIM2 global interrupt */
    (uint32_t)(TIM3_IRQHandler),                        /* TIM3 global interrupt */
    (uint32_t)(TIM4_IRQHandler),                        /* TIM4 global interrupt */
    (uint32_t)(I2C1_EV_IRQHandler),                     /* I2C1 event interrupt */
    (uint32_t)(I2C1_ER_IRQHandler),                     /* I2C1 error interrupt */
    (uint32_t)(I2C2_EV_IRQHandler),                     /* I2C2 event interrupt */
    (uint32_t)(I2C2_ER_IRQHandler),                     /* I2C2 error interrupt */
    (uint32_t)(SPI1_IRQHandler),                        /* SPI1 global interrupt */
    (uint32_t)(SPI2_IRQHandler),                        /* SPI2 global interrupt */
    (uint32_t)(USART1_IRQHandler),                      /* USART1 global interrupt */
    (uint32_t)(USART2_IRQHandler),                      /* USART2 global interrupt */
    (uint32_t)(USART3_IRQHandler),                      /* USART3 global interrupt */
    (uint32_t)(EXTI15_10_IRQHandler),                   /* EXTI line[15:10] interrupts */
    (uint32_t)(RTC_Alarm_IRQHandler),                   /* RTC alarm interrupt */
    (uint32_t)(OTG_FS_WKUP_IRQHandler),                 /* USB OTG FS wakeup interrupt */
    (uint32_t)(TIM8_BRK_TIM12_IRQHandler),              /* TIM8 break and TIM12 interrupt */
    (uint32_t)(TIM8_UP_TIM13_IRQHandler),               /* TIM8 update and TIM13 interrupt */
    (uint32_t)(TIM8_TRG_COM_TIM14_IRQHandler),          /* TIM8 trigger/commutation and TIM14 interrupt */
    (uint32_t)(TIM8_CC_IRQHandler),                     /* TIM8 capture compare interrupt */
    (uint32_t)(DMA1_Stream7_IRQHandler),                /* DMA1 stream7 global interrupt */
    (uint32_t)(FSMC_IRQHandler),                        /* FSMC global interrupt */
    (uint32_t)(SDIO_IRQHandler),                        /* SDIO global interrupt */
    (uint32_t)(TIM5_IRQHandler),                        /* TIM5 global interrupt */
    (uint32_t)(SPI3_IRQHandler),                        /* SPI3 global interrupt */
    (uint32_t)(UART4_IRQHandler),                       /* UART4 global interrupt */
    (uint32_t)(UART5_IRQHandler),                       /* UART5 global interrupt */
    (uint32_t)(TIM6_DAC_IRQHandler),                    /* TIM6 and DAC underrun interrupt */
    (uint32_t)(TIM7_IRQHandler),                        /* TIM7 global interrupt */
    (uint32_t)(DMA2_Stream0_IRQHandler),                /* DMA2 stream0 global interrupt */
    (uint32_t)(DMA2_Stream1_IRQHandler),                /* DMA2 stream1 global interrupt */
    (uint32_t)(DMA2_Stream2_IRQHandler),                /* DMA2 stream2 global interrupt */
    (uint32_t)(DMA2_Stream3_IRQHandler),                /* DMA2 stream3 global interrupt */
    (uint32_t)(DMA2_Stream4_IRQHandler),                /* DMA2 stream4 global interrupt */
    (uint32_t)(ETH_IRQHandler),                         /* Ethernet global interrupt */
    (uint32_t)(ETH_WKUP_IRQHandler),                    /* Ethernet wakeup interrupt */
    (uint32_t)(CAN2_TX_IRQHandler),                     /* CAN2 TX interrupt */
    (uint32_t)(CAN2_RX0_IRQHandler),                    /* CAN2 RX0 interrupt */
    (uint32_t)(CAN2_RX1_IRQHandler),                    /* CAN2 RX1 interrupt */
    (uint32_t)(CAN2_SCE_IRQHandler),                    /* CAN2 SCE interrupt */
    (uint32_t)(OTG_FS_IRQHandler),                      /* USB OTG FS global interrupt */
    (uint32_t)(DMA2_Stream5_IRQHandler),                /* DMA2 stream5 global interrupt */
    (uint32_t)(DMA2_Stream6_IRQHandler),                /* DMA2 stream6 global interrupt */
    (uint32_t)(DMA2_Stream7_IRQHandler),                /* DMA2 stream7 global interrupt */
    (uint32_t)(USART6_IRQHandler),                      /* USART6 global interrupt */
    (uint32_t)(I2C3_EV_IRQHandler),                     /* I2C3 event interrupt */
    (uint32_t)(I2C3_ER_IRQHandler),                     /* I2C3 error interrupt */
    (uint32_t)(OTG_HS_EP1_OUT_IRQHandler),              /* USB OTG HS endpoint 1 OUT interrupt */
    (uint32_t)(OTG_HS_EP1_IN_IRQHandler),               /* USB OTG HS endpoint 1 IN interrupt */
    (uint32_t)(OTG_HS_WKUP_IRQHandler),                 /* USB OTG HS wakeup interrupt */
    (uint32_t)(OTG_HS_IRQHandler),                      /* USB OTG HS global interrupt */
    (uint32_t)(DCMI_IRQHandler),                        /* DCMI global interrupt */
    (uint32_t)(CRYP_IRQHandler),                        /* Cryptographic processor global interrupt */
    (uint32_t)(HASH_RNG_IRQHandler),                    /* Hash and RNG global interrupt */
    (uint32_t)(FPU_IRQHandler),                         /* Floating point unit interrupt */
};


void Default_Handler(void)
{
    while(1);
}

void Reset_Handler(void)
{
    
}