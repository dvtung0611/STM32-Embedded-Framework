/**
 * File name: nvic-driver.h
 *
 * Created on: 27/04/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_NVIC_DRIVER_H_
#define INC_NVIC_DRIVER_H_

#include "stm32f407xx.h"


/* ===================================================== MACROS ===================================================== */

/**
 * @NVIC_PRIORITY_LEVEL
 */
#define NVIC_IRQ_PRIORITY_0                 (0U)
#define NVIC_IRQ_PRIORITY_1                 (1U)
#define NVIC_IRQ_PRIORITY_2                 (2U)
#define NVIC_IRQ_PRIORITY_3                 (3U)
#define NVIC_IRQ_PRIORITY_4                 (4U)
#define NVIC_IRQ_PRIORITY_5                 (5U)
#define NVIC_IRQ_PRIORITY_6                 (6U)
#define NVIC_IRQ_PRIORITY_7                 (7U)
#define NVIC_IRQ_PRIORITY_8                 (8U)
#define NVIC_IRQ_PRIORITY_9                 (9U)
#define NVIC_IRQ_PRIORITY_10                (10U)
#define NVIC_IRQ_PRIORITY_11                (11U)
#define NVIC_IRQ_PRIORITY_12                (12U)
#define NVIC_IRQ_PRIORITY_13                (13U)
#define NVIC_IRQ_PRIORITY_14                (14U)
#define NVIC_IRQ_PRIORITY_15                (15U)
#define NVIC_IRQ_MAX_PRIORITY               (15U)


/* ====================================================== APIs ====================================================== */

/**
 * @brief Enable or disable a IRQ in NVIC
 *
 * @param IRQNumber IRQ number (0–81 for STM32F407)
 * @param En_or_DI  ENABLE to enable interrupt, DISABLE to disable interrupt
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
void NVIC_IRQ_InterruptConfig(uint8_t IRQNumber, uint8_t En_or_DI);


/**
 * @brief Configure priority for a given IRQ
 *
 * @details Sets the priority of the interrupt in NVIC.
 *          Only the upper 4 bits [7:4] of each priority byte are implemented
 *          in Cortex-M4 (STM32F4), so the priority value is shifted accordingly.
 *
 * @param IRQNumber   IRQ number (0–81 for STM32F407)
 * @param IRQPriority Priority level (0–15, lower value = higher priority)
 *
 * @note
 * Refer to:
 * - ARM Cortex-M4 Generic User Guide,  Section 4.2.7 Interrupt Priority Registers
 */
void NVIC_IRQ_PriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority);


#endif /* INC_NVIC_DRIVER_H_ */