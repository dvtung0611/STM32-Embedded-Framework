/**
 * File name: nvic_driver.c
 *
 * Created on: 27/04/2026
 * Author: Van Tung Dinh
 */

/* ================================================== INCLUDES ================================================== */

#include "nvic_driver.h"


/* ================================================== APIs ================================================== */

void NVIC_IRQInterruptConfig(uint8_t IRQNumber, uint8_t En_or_DI)
{
    if (IRQNumber > IRQ_MAX_NUMBER)
        return;

    if (En_or_DI == ENABLE)
    {
        uint8_t ISER_id = IRQNumber / 32;
        uint8_t pos = IRQNumber % 32;
        NVIC->ISER[ISER_id] |= (1U << pos);
    }
    else if (En_or_DI == DISABLE)
    {
        uint8_t ICER_id = IRQNumber / 32;
        uint8_t pos = IRQNumber % 32;
        NVIC->ICER[ICER_id] |= (1U << pos);
    }
}


void NVIC_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority)
{
    if (IRQNumber > IRQ_MAX_NUMBER || IRQPriority > NVIC_IRQ_MAX_PRIORITY)
        return;

    NVIC->IPR[IRQNumber] &= ~(15U << 4U);
    NVIC->IPR[IRQNumber] |= (IRQPriority << 4U);
}