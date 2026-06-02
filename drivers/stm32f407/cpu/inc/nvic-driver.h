/**
 * File name: nvic-driver.h
 *
 * Created on: 27/04/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_NVIC_DRIVER_H_
#define INC_NVIC_DRIVER_H_

#include "stm32f407xx.h"


/* ================================================== DEFINITIONS =================================================== */

/**
 * @NVIC_PRIORITY_LEVEL
 */
typedef enum
{
    NVIC_IRQ_PRIORITY_0 = 0U,
    NVIC_IRQ_PRIORITY_1,
    NVIC_IRQ_PRIORITY_2,
    NVIC_IRQ_PRIORITY_3,
    NVIC_IRQ_PRIORITY_4,
    NVIC_IRQ_PRIORITY_5,
    NVIC_IRQ_PRIORITY_6,
    NVIC_IRQ_PRIORITY_7,
    NVIC_IRQ_PRIORITY_8,
    NVIC_IRQ_PRIORITY_9,
    NVIC_IRQ_PRIORITY_10,
    NVIC_IRQ_PRIORITY_11,
    NVIC_IRQ_PRIORITY_12,
    NVIC_IRQ_PRIORITY_13,
    NVIC_IRQ_PRIORITY_14,
    NVIC_IRQ_PRIORITY_15,

    NVIC_IRQ_MAX_PRIORITY = NVIC_IRQ_PRIORITY_15
} NVIC_PriorityLevel;


/* ====================================================== APIs ====================================================== */

/**
 * @brief Enable or disable a IRQ in NVIC
 * 
 * @param IRQNumber IRQ number (0–81 for STM32F407) | @IRQ_NUMBER
 * @param EN_or_DI  ENABLE or DISABLE macro
 * 
 * @details Each ISER/ICER register controls 32 IRQs. IRQNumber is mapped to register index and bit position:
 *          Register index = IRQNumber / 32
 *          Bit position   = IRQNumber % 32
 *          - Set 1 to ISER enables the interrupt
 *          - Set 1 to ICER disables the interrupt
 * 
 * @note
 * Refer to:
 * - ARM Cortex-M4 Generic User Guide,  Section 4.2.2 Interrupt Set-enable Registers
 *                                      Section 4.2.3 Interrupt Clear-enable Registers
 */
void NVIC_IRQ_InterruptConfig(IRQNumber_t IRQNumber, uint8_t EN_or_DI);


/**
 * @brief Configure priority for a given IRQ
 *
 * @details Sets the priority of the interrupt in NVIC.
 *          Only the upper 4 bits [7:4] of each priority byte are implemented
 *          in Cortex-M4 (STM32F4), so the priority value is shifted accordingly.
 * 
 * @param IRQNumber   IRQ number (0–81 for STM32F407) | @IRQ_NUMBER
 * @param IRQPriority Priority level (0–15, lower value = higher priority) | @NVIC_PRIORITY_LEVEL
 * 
 * @note
 * Refer to:
 * - ARM Cortex-M4 Generic User Guide,  Section 4.2.7 Interrupt Priority Registers
 */
void NVIC_IRQ_PriorityConfig(IRQNumber_t IRQNumber, NVIC_PriorityLevel IRQPriority);


#endif /* INC_NVIC_DRIVER_H_ */