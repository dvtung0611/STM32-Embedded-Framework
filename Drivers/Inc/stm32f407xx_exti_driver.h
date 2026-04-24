/**
 * File name: stm32f407xx_exti_driver.h
 *
 * Created on: 24/04/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_STM32F407XX_EXTI_DRIVER_H_
#define INC_STM32F407XX_EXTI_DRIVER_H_

/* ================================================== INCLUDES ================================================== */
#include "stm32f407xx.h"


/* ================================================== MACROS ================================================== */

/**
 * @EXTI_LINE_NUMBERS
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


/* ================================================== DATA TYPES ================================================== */

/**
 * @brief EXTI configuration structure
 *
 * @note
 * Used to configure an EXTI line (0–22).
 * For lines 0–15, GPIO port mapping via SYSCFG is required. Lines 16–22 do not require EXTI_PortCode
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
 * @note
 * Holds EXTI configuration for initialization.
 */
typedef struct
{
    EXTI_Config_t EXTI_Config;
} EXTI_Handle_t;


/* ================================================== APIs ================================================== */


#endif /* INC_STM32F407XX_EXTI_DRIVER_H_ */