/**
 * File name: stm32f407xx_exti_driver.c
 *
 * Created on: 24/04/2026
 * Author: Van Tung Dinh
 */

/* ================================================== INCLUDES ================================================== */
#include "stm32f407xx_exti_driver.h"


/* ================================================== APIs ================================================== */

void EXTI_Init(EXTI_Handle_t *pEXTI_Handle)
{
    uint8_t LineNumber = pEXTI_Handle->EXTI_Config.EXTI_LineNumber;
    uint8_t Mode = pEXTI_Handle->EXTI_Config.EXTI_Mode;
    uint8_t Trigger = pEXTI_Handle->EXTI_Config.EXTI_Trigger;

    // 1. Configure trigger (clear both first to avoid residual config)
    EXTI->RTSR &= ~(1U << LineNumber);
    EXTI->FTSR &= ~(1U << LineNumber);
    if (Trigger == EXTI_TRIGGER_RISING)
    {
        EXTI->RTSR |= (1U << LineNumber); // Rising edge trigger
    }
    else if (Trigger == EXTI_TRIGGER_FALLING)
    {
        EXTI->FTSR |= (1U << LineNumber); // Falling edge trigger
    }
    else if (Trigger == EXTI_TRIGGER_BOTH)
    {
        EXTI->RTSR |= (1U << LineNumber); // Both edges
        EXTI->FTSR |= (1U << LineNumber);
    }

    // 2. Configure EXTI mode
    if (Mode == EXTI_MODE_INTERRUPT)
    {
        if (LineNumber > 22)
            return;
        else if (LineNumber < 16)
        {
            // 2.1 Map GPIO port to EXTI line (only for lines 0–15)
            uint8_t PortCode = pEXTI_Handle->EXTI_Config.EXTI_PortCode;
            uint8_t EXTICR_ID = LineNumber / 4, BIT_ID = LineNumber % 4;

            SYSCFG_PCLK_EN(); // Enable SYSCFG clock

            // Clear previous mapping and set new port
            SYSCFG->EXTICR[EXTICR_ID] &= ~(15U << (BIT_ID * 4U));
            SYSCFG->EXTICR[EXTICR_ID] |= (PortCode << (BIT_ID * 4U));
        }
        else if (LineNumber < 23)
        {
            // Lines 16–22: internal sources (no GPIO mapping required)
        }

        // 2.2 Enable interrupt delivery
        EXTI->IMR |= (1U << LineNumber);
    }
    else if (Mode == EXTI_MODE_EVENT)
    {
        // Event mode not implemented yet
    }
}