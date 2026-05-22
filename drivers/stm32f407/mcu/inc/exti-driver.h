/**
 * File name: exti-driver.h
 *
 * Created on: 24/04/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_EXTI_DRIVER_H_
#define INC_EXTI_DRIVER_H_

#include "gpio-driver.h"
#include "stm32f407xx.h"


/* ================================================== DEFINITIONS =================================================== */

/**
 * @EXTI_LINE_NUMBER
 * 
 * @note
 * 0–15: GPIO
 * 16–22: Internal lines
 */
typedef enum
{
    EXTI_LINE_0 = 0U,
    EXTI_LINE_1,
    EXTI_LINE_2,
    EXTI_LINE_3,
    EXTI_LINE_4,
    EXTI_LINE_5,
    EXTI_LINE_6,
    EXTI_LINE_7,
    EXTI_LINE_8,
    EXTI_LINE_9,
    EXTI_LINE_10,
    EXTI_LINE_11,
    EXTI_LINE_12,
    EXTI_LINE_13,
    EXTI_LINE_14,
    EXTI_LINE_15,
    EXTI_LINE_16,
    EXTI_LINE_17,
    EXTI_LINE_18,
    EXTI_LINE_19,
    EXTI_LINE_20,
    EXTI_LINE_21,
    EXTI_LINE_22,

    EXTI_MAX_LINE = EXTI_LINE_22
} EXTI_LineNumber_t;


/**
 * @EXTI_MODE
 */
typedef enum
{
    EXTI_MODE_INTERRUPT = 0U,
    EXTI_MODE_EVENT
} EXTI_Mode_t;


/**
 * @EXTI_TRIGGER
 */
typedef enum
{
    EXTI_TRIGGER_RISING = 0U,
    EXTI_TRIGGER_FALLING,
    EXTI_TRIGGER_BOTH
} EXTI_Trigger_t;


/* =================================================== STRUCTURES =================================================== */

/**
 * @brief EXTI configuration structure
 *
 * @note Used to configure an EXTI line (0–22).
 *       For lines 0–15, GPIO port mapping via SYSCFG is required. Lines 16–22 do not require EXTI_PortCode.
 */
typedef struct
{
    EXTI_LineNumber_t EXTI_LineNumber;      /*!< EXTI line number (0–22)                | Possible value: @EXTI_LINE_NUMBER */
    EXTI_Mode_t EXTI_Mode;                  /*!< Interrupt or Event mode                | Possible value: @EXTI_MODE */
    EXTI_Trigger_t EXTI_Trigger;            /*!< Rising / Falling / Both edges          | Possible value: @EXTI_TRIGGER */
    GPIO_PortCode_t EXTI_GPIO_PortCode;     /*!< GPIO port code (used for EXTI 0–15)    | Possible value: @GPIO_PORT_CODE */
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
 * @param pEXTI_Handle Pointer to EXTI handle structure
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
 * @param LineNumber EXTI line number (0–22) | @EXTI_LINE_NUMBER
 *
 * @note - Writing '1' clears the pending flag
 *       - Writing '0' has no effect
 *       - Do not use read-modify-write (|=) on this register
 *
 * Refer to:
 * - RM0090 Reference Manual,   Section 12.3.6 Pending register (EXTI_PR)
 */
void EXTI_ClearPending(EXTI_LineNumber_t LineNumber);


/**
 * @brief Get pending interrupt status of a given EXTI line
 *
 * @details Reads the corresponding bit in the EXTI Pending Register (PR)
 *          to determine whether an interrupt event is pending.
 * 
 * @param LineNumber EXTI line number (0–22) | @EXTI_LINE_NUMBER
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
uint8_t EXTI_GetPending(EXTI_LineNumber_t LineNumber);


#endif /* INC_EXTI_DRIVER_H_ */