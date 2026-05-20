/**
 * File name: exti-driver.h
 *
 * Created on: 24/04/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_EXTI_DRIVER_H_
#define INC_EXTI_DRIVER_H_

#include "stm32f407xx.h"


/* ===================================================== MACROS ===================================================== */

/**
 * @EXTI_LINE_NUMBERS
 * 
 * @note
 * 0–15: GPIO
 * 16–22: Internal lines
 */
#define EXTI_LINE_0                 (0U)
#define EXTI_LINE_1                 (1U)
#define EXTI_LINE_2                 (2U)
#define EXTI_LINE_3                 (3U)
#define EXTI_LINE_4                 (4U)
#define EXTI_LINE_5                 (5U)
#define EXTI_LINE_6                 (6U)
#define EXTI_LINE_7                 (7U)
#define EXTI_LINE_8                 (8U)
#define EXTI_LINE_9                 (9U)
#define EXTI_LINE_10                (10U)
#define EXTI_LINE_11                (11U)
#define EXTI_LINE_12                (12U)
#define EXTI_LINE_13                (13U)
#define EXTI_LINE_14                (14U)
#define EXTI_LINE_15                (15U)
#define EXTI_LINE_16                (16U)
#define EXTI_LINE_17                (17U)
#define EXTI_LINE_18                (18U)
#define EXTI_LINE_19                (19U)
#define EXTI_LINE_20                (20U)
#define EXTI_LINE_21                (21U)
#define EXTI_LINE_22                (22U)
#define EXTI_MAX_LINE               (22U)


/**
 * @EXTI_MODES
 */
#define EXTI_MODE_INTERRUPT         (0U)
#define EXTI_MODE_EVENT             (1U)


/**
 * @EXTI_TRIGGERS
 */
#define EXTI_TRIGGER_RISING         (0U)
#define EXTI_TRIGGER_FALLING        (1U)
#define EXTI_TRIGGER_BOTH           (2U)


/* =================================================== STRUCTURES =================================================== */

/**
 * @brief EXTI configuration structure
 *
 * @note Used to configure an EXTI line (0–22).
 *       For lines 0–15, GPIO port mapping via SYSCFG is required. Lines 16–22 do not require EXTI_PortCode.
 */
typedef struct
{
    uint8_t EXTI_LineNumber;    /*!< EXTI line number (0–22)                | Possible value: @EXTI_LINE_NUMBERS */
    uint8_t EXTI_Mode;          /*!< Interrupt or Event mode                | Possible value: @EXTI_MODES */
    uint8_t EXTI_Trigger;       /*!< Rising / Falling / Both edges          | Possible value: @EXTI_TRIGGERS */
    uint8_t EXTI_PortCode;      /*!< GPIO port code (used for EXTI 0–15)    | Possible value: GPIO_BASEADDR_TO_CODE(x) */
} EXTI_Config_t;


/**
 * @brief EXTI handle structure
 *
 * @note Holds EXTI configuration for initialization.
 */
typedef struct
{
    EXTI_Config_t EXTI_Config;
} EXTI_Handle_t;


/* ====================================================== APIs ====================================================== */

/**
 * @brief Initialize EXTI line configuration.
 *        Configures trigger condition (rising/falling/both),
 *        selects GPIO port source for EXTI lines 0–15 via SYSCFG,
 *        and enables interrupt delivery through IMR.
 * 
 * @param pEXTI_Handle Pointer to EXTI handle structure containing configuration
 * 
 * @note Valid EXTI lines: 0–22
 *       EXTI lines 0–15 require GPIO port mapping (SYSCFG->EXTICR)
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 12.3.1 Interrupt mask register (EXTI_IMR)
 */
void EXTI_Init(EXTI_Handle_t *pEXTI_Handle);


/**
 * @brief Clear pending interrupt flag for a given EXTI line
 *
 * @details Clears the pending bit in EXTI Pending Register (PR)
 *          by writing 1 to the corresponding bit position.
 *
 * @param LineNumber EXTI line number (0–22)
 *
 * @note - Writing '1' clears the pending flag
 *       - Writing '0' has no effect
 *       - Do not use read-modify-write (|=) on this register
 *
 * Refer to:
 * - RM0090 Reference Manual,   Section 12.3.6 Pending register (EXTI_PR)
 */
void EXTI_ClearPending(uint8_t LineNumber);


/**
 * @brief Get pending interrupt status of a given EXTI line
 *
 * @details Reads the corresponding bit in the EXTI Pending Register (PR)
 *          to determine whether an interrupt event is pending.
 * 
 * @param LineNumber EXTI line number (0–22)
 * 
 * @return uint8_t
 *         - 1: Pending interrupt is active
 *         - 0: No pending interrupt
 * 
 * @note The pending bit is set by hardware when the configured
 *       trigger event occurs on the EXTI line.
 *       The pending bit must be cleared manually by software
 *       using EXTI_ClearPending().
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 12.3.6 Pending register (EXTI_PR)
 */
uint8_t EXTI_GetPending(uint8_t LineNumber);


#endif /* INC_EXTI_DRIVER_H_ */