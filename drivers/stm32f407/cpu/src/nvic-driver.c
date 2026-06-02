/**
 * File name: nvic-driver.c
 *
 * Created on: 27/04/2026
 * Author: Van Tung Dinh
 */

#include "stm32f407xx.h"
#include "nvic-driver.h"


/* ====================================================== APIs ====================================================== */

void NVIC_IRQ_InterruptConfig(IRQNumber_t IRQNumber, uint8_t EN_or_DI)
{
    if (IRQNumber > IRQ_MAX_NUMBER)
        return;
    
    if (EN_or_DI == ENABLE)
    {
        uint8_t ISER_id = IRQNumber / 32;
        uint8_t pos = IRQNumber % 32;
        NVIC->ISER[ISER_id] |= (1U << pos);
    }
    else if (EN_or_DI == DISABLE)
    {
        uint8_t ICER_id = IRQNumber / 32;
        uint8_t pos = IRQNumber % 32;
        NVIC->ICER[ICER_id] |= (1U << pos);
    }
}


void NVIC_IRQ_PriorityConfig(IRQNumber_t IRQNumber, NVIC_PriorityLevel IRQPriority)
{
    if (IRQNumber > IRQ_MAX_NUMBER || IRQPriority > NVIC_IRQ_MAX_PRIORITY)
        return;
    
    NVIC->IPR[IRQNumber] &= ~(15U << 4U);
    NVIC->IPR[IRQNumber] |= (IRQPriority << 4U);
}