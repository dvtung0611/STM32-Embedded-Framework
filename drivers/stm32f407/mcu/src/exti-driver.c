/**
 * File name: exti-driver.c
 *
 * Created on: 24/04/2026
 * Author: Van Tung Dinh
 */

#include "stm32f407xx.h"
#include "exti-driver.h"


/* ====================================================== APIs ====================================================== */

void EXTI_Init(EXTI_Handle_t *pEXTI_Handle)
{
    if (pEXTI_Handle == NULL)
        return;
    
    uint8_t LineNumber = pEXTI_Handle->EXTI_Config.EXTI_LineNumber;
    uint8_t Mode = pEXTI_Handle->EXTI_Config.EXTI_Mode;
    uint8_t Trigger = pEXTI_Handle->EXTI_Config.EXTI_Trigger;
    uint8_t PortCode = pEXTI_Handle->EXTI_Config.EXTI_GPIO_PortCode;

    if (LineNumber > EXTI_MAX_LINE || Trigger > EXTI_TRIGGER_BOTH || Mode > EXTI_MODE_EVENT)
        return;

    // Configure trigger (clear both first to avoid residual config)
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

    // Configure EXTI mode
    if (Mode == EXTI_MODE_INTERRUPT)
    {
        if (LineNumber < 16)
        {
            if (PortCode > GPIO_MAX_PORTCODE)
                return;
            
            // Map GPIO port to EXTI line (only for lines 0–15)
            uint8_t EXTICR_ID = LineNumber / 4, BIT_ID = LineNumber % 4;

            SYSCFG_PCLK_EN(); // Enable SYSCFG clock

            // Clear previous mapping and set new port
            SYSCFG->EXTICR[EXTICR_ID] &= ~(15U << (BIT_ID * 4U));
            SYSCFG->EXTICR[EXTICR_ID] |= (PortCode << (BIT_ID * 4U));
        }
        else if (LineNumber < 23)
        {
            // Lines 16–22: Internal sources (no GPIO mapping required)
        }

        // Enable interrupt delivery
        EXTI->PR = (1U << LineNumber);
        EXTI->IMR &= ~(1U << LineNumber);
        EXTI->IMR |= (1U << LineNumber);
    }
    else if (Mode == EXTI_MODE_EVENT)
    {
        // Event mode not implemented yet
    }
}


void EXTI_ClearPending(EXTI_LineNumber_t LineNumber)
{
    if (LineNumber > EXTI_MAX_LINE)
        return;

    EXTI->PR = (1U << LineNumber);
}


uint8_t EXTI_GetPending(EXTI_LineNumber_t LineNumber)
{
    return (EXTI->PR >> LineNumber) & 1U;
}