/**
 * File name: gpio-driver.h
 *
 * Created on: 20/04/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_

#include "stm32f407xx.h"


/* ================================================== DEFINITIONS =================================================== */

/**
 * @GPIO_RESET_REGISTER_VALUE
 */
#define GPIOA_MODER_RESET_VALUE             (0xA8000000U)
#define GPIOB_MODER_RESET_VALUE             (0x00000280U)
#define GPIO_MODER_RESET_VALUE              (0x00U)

#define GPIO_OTYPER_RESET_VALUE             (0x00U)

#define GPIOA_OSPEEDR_RESET_VALUE           (0x0C000000U)
#define GPIOB_OSPEEDR_RESET_VALUE           (0x000000C0U)
#define GPIO_OSPEEDR_RESET_VALUE            (0x00U)

#define GPIOA_PUPDR_RESET_VALUE             (0x64000000U)
#define GPIOB_PUPDR_RESET_VALUE             (0x00000100U)
#define GPIO_PUPDR_RESET_VALUE              (0x00U)

#define GPIO_ODR_RESET_VALUE                (0x00U)

#define GPIO_BSRR_RESET_VALUE               (0x00U)

#define GPIO_LCKR_RESET_VALUE               (0x00U)

#define GPIO_AFRL_RESET_VALUE               (0x00U)
#define GPIO_AFRH_RESET_VALUE               (0x00U)


/**
 * @GPIO_PORT_CODE
 */
typedef enum
{
    GPIO_PORT_CODE_GPIOA = 0U,
    GPIO_PORT_CODE_GPIOB,
    GPIO_PORT_CODE_GPIOC,
    GPIO_PORT_CODE_GPIOD,
    GPIO_PORT_CODE_GPIOE,
    GPIO_PORT_CODE_GPIOF,
    GPIO_PORT_CODE_GPIOG,
    GPIO_PORT_CODE_GPIOH,
    GPIO_PORT_CODE_GPIOI,

    GPIO_MAX_PORTCODE = GPIO_PORT_CODE_GPIOI
} GPIO_PortCode_t;


/**
 * @GPIO_PIN_STATE
 */
typedef enum
{
    GPIO_PIN_STATE_RESET = 0U,
    GPIO_PIN_STATE_SET
} GPIO_PinState_t;


/**
 * @GPIO_PIN
 */
typedef enum
{
    GPIO_PIN_0 = 0U,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15
} GPIO_Pin_t;


/**
 * @GPIO_PIN_MODE
 */
typedef enum
{
    GPIO_PIN_MODE_INPUT = 0U,
    GPIO_PIN_MODE_OUTPUT,
    GPIO_PIN_MODE_ALTFN,
    GPIO_PIN_MODE_ANALOG
} GPIO_PinMode_t;


/**
 * @GPIO_PIN_OTYPE
 */
typedef enum
{
    GPIO_PIN_OTYPE_PUSHPULL = 0U,
    GPIO_PIN_OTYPE_OPENDRAIN
} GPIO_PinOType_t;


/**
 * @GPIO_PIN_SPEED
 */
typedef enum
{
    GPIO_PIN_SPEED_LOW = 0U,
    GPIO_PIN_SPEED_MEDIUM,
    GPIO_PIN_SPEED_HIGH,
    GPIO_PIN_SPEED_VERYHIGH
} GPIO_PinSpeed_t;


/**
 * @GPIO_PIN_PUPD
 */
typedef enum
{
    GPIO_PIN_NOPULL = 0U,
    GPIO_PIN_PULLUP,
    GPIO_PIN_PULLDOWN
} GPIO_PinPuPd_t;


/**
 * @GPIO_PIN_ALTFN
 */
typedef enum
{
    GPIO_AF0 = 0U,
    GPIO_AF1,
    GPIO_AF2,
    GPIO_AF3,
    GPIO_AF4,
    GPIO_AF5,
    GPIO_AF6,
    GPIO_AF7,
    GPIO_AF8,
    GPIO_AF9,
    GPIO_AF10,
    GPIO_AF11,
    GPIO_AF12,
    GPIO_AF13,
    GPIO_AF14,
    GPIO_AF15
} GPIO_AltFn_t;


/* ================================================== BIT POSITION ================================================== */

/**
 * @GPIO_MODER
 */
#define GPIO_MODER_MODER0_Pos                  (0U)
#define GPIO_MODER_MODER1_Pos                  (2U)
#define GPIO_MODER_MODER2_Pos                  (4U)
#define GPIO_MODER_MODER3_Pos                  (6U)
#define GPIO_MODER_MODER4_Pos                  (8U)
#define GPIO_MODER_MODER5_Pos                  (10U)
#define GPIO_MODER_MODER6_Pos                  (12U)
#define GPIO_MODER_MODER7_Pos                  (14U)
#define GPIO_MODER_MODER8_Pos                  (16U)
#define GPIO_MODER_MODER9_Pos                  (18U)
#define GPIO_MODER_MODER10_Pos                 (20U)
#define GPIO_MODER_MODER11_Pos                 (22U)
#define GPIO_MODER_MODER12_Pos                 (24U)
#define GPIO_MODER_MODER13_Pos                 (26U)
#define GPIO_MODER_MODER14_Pos                 (28U)
#define GPIO_MODER_MODER15_Pos                 (30U)


/**
 * @GPIO_OTYPER
 */
#define GPIO_OTYPER_OT0_Pos                    (0U)
#define GPIO_OTYPER_OT1_Pos                    (1U)
#define GPIO_OTYPER_OT2_Pos                    (2U)
#define GPIO_OTYPER_OT3_Pos                    (3U)
#define GPIO_OTYPER_OT4_Pos                    (4U)
#define GPIO_OTYPER_OT5_Pos                    (5U)
#define GPIO_OTYPER_OT6_Pos                    (6U)
#define GPIO_OTYPER_OT7_Pos                    (7U)
#define GPIO_OTYPER_OT8_Pos                    (8U)
#define GPIO_OTYPER_OT9_Pos                    (9U)
#define GPIO_OTYPER_OT10_Pos                   (10U)
#define GPIO_OTYPER_OT11_Pos                   (11U)
#define GPIO_OTYPER_OT12_Pos                   (12U)
#define GPIO_OTYPER_OT13_Pos                   (13U)
#define GPIO_OTYPER_OT14_Pos                   (14U)
#define GPIO_OTYPER_OT15_Pos                   (15U)


/**
 * @GPIO_OSPEEDR
 */
#define GPIO_OSPEEDR_OSPEEDR0_Pos              (0U)
#define GPIO_OSPEEDR_OSPEEDR1_Pos              (2U)
#define GPIO_OSPEEDR_OSPEEDR2_Pos              (4U)
#define GPIO_OSPEEDR_OSPEEDR3_Pos              (6U)
#define GPIO_OSPEEDR_OSPEEDR4_Pos              (8U)
#define GPIO_OSPEEDR_OSPEEDR5_Pos              (10U)
#define GPIO_OSPEEDR_OSPEEDR6_Pos              (12U)
#define GPIO_OSPEEDR_OSPEEDR7_Pos              (14U)
#define GPIO_OSPEEDR_OSPEEDR8_Pos              (16U)
#define GPIO_OSPEEDR_OSPEEDR9_Pos              (18U)
#define GPIO_OSPEEDR_OSPEEDR10_Pos             (20U)
#define GPIO_OSPEEDR_OSPEEDR11_Pos             (22U)
#define GPIO_OSPEEDR_OSPEEDR12_Pos             (24U)
#define GPIO_OSPEEDR_OSPEEDR13_Pos             (26U)
#define GPIO_OSPEEDR_OSPEEDR14_Pos             (28U)
#define GPIO_OSPEEDR_OSPEEDR15_Pos             (30U)


/**
 * @GPIO_PUPDR
 */
#define GPIO_PUPDR_PUPDR0_Pos                  (0U)
#define GPIO_PUPDR_PUPDR1_Pos                  (2U)
#define GPIO_PUPDR_PUPDR2_Pos                  (4U)
#define GPIO_PUPDR_PUPDR3_Pos                  (6U)
#define GPIO_PUPDR_PUPDR4_Pos                  (8U)
#define GPIO_PUPDR_PUPDR5_Pos                  (10U)
#define GPIO_PUPDR_PUPDR6_Pos                  (12U)
#define GPIO_PUPDR_PUPDR7_Pos                  (14U)
#define GPIO_PUPDR_PUPDR8_Pos                  (16U)
#define GPIO_PUPDR_PUPDR9_Pos                  (18U)
#define GPIO_PUPDR_PUPDR10_Pos                 (20U)
#define GPIO_PUPDR_PUPDR11_Pos                 (22U)
#define GPIO_PUPDR_PUPDR12_Pos                 (24U)
#define GPIO_PUPDR_PUPDR13_Pos                 (26U)
#define GPIO_PUPDR_PUPDR14_Pos                 (28U)
#define GPIO_PUPDR_PUPDR15_Pos                 (30U)


/**
 * @GPIO_IDR
 */
#define GPIO_IDR_IDR0_Pos                      (0U)
#define GPIO_IDR_IDR1_Pos                      (1U)
#define GPIO_IDR_IDR2_Pos                      (2U)
#define GPIO_IDR_IDR3_Pos                      (3U)
#define GPIO_IDR_IDR4_Pos                      (4U)
#define GPIO_IDR_IDR5_Pos                      (5U)
#define GPIO_IDR_IDR6_Pos                      (6U)
#define GPIO_IDR_IDR7_Pos                      (7U)
#define GPIO_IDR_IDR8_Pos                      (8U)
#define GPIO_IDR_IDR9_Pos                      (9U)
#define GPIO_IDR_IDR10_Pos                     (10U)
#define GPIO_IDR_IDR11_Pos                     (11U)
#define GPIO_IDR_IDR12_Pos                     (12U)
#define GPIO_IDR_IDR13_Pos                     (13U)
#define GPIO_IDR_IDR14_Pos                     (14U)
#define GPIO_IDR_IDR15_Pos                     (15U)


/**
 * @GPIO_ODR
 */
#define GPIO_ODR_ODR0_Pos                      (0U)
#define GPIO_ODR_ODR1_Pos                      (1U)
#define GPIO_ODR_ODR2_Pos                      (2U)
#define GPIO_ODR_ODR3_Pos                      (3U)
#define GPIO_ODR_ODR4_Pos                      (4U)
#define GPIO_ODR_ODR5_Pos                      (5U)
#define GPIO_ODR_ODR6_Pos                      (6U)
#define GPIO_ODR_ODR7_Pos                      (7U)
#define GPIO_ODR_ODR8_Pos                      (8U)
#define GPIO_ODR_ODR9_Pos                      (9U)
#define GPIO_ODR_ODR10_Pos                     (10U)
#define GPIO_ODR_ODR11_Pos                     (11U)
#define GPIO_ODR_ODR12_Pos                     (12U)
#define GPIO_ODR_ODR13_Pos                     (13U)
#define GPIO_ODR_ODR14_Pos                     (14U)
#define GPIO_ODR_ODR15_Pos                     (15U)


/**
 * @GPIO_BSRR
 */
#define GPIO_BSRR_BS0_Pos                      (0U)
#define GPIO_BSRR_BS1_Pos                      (1U)
#define GPIO_BSRR_BS2_Pos                      (2U)
#define GPIO_BSRR_BS3_Pos                      (3U)
#define GPIO_BSRR_BS4_Pos                      (4U)
#define GPIO_BSRR_BS5_Pos                      (5U)
#define GPIO_BSRR_BS6_Pos                      (6U)
#define GPIO_BSRR_BS7_Pos                      (7U)
#define GPIO_BSRR_BS8_Pos                      (8U)
#define GPIO_BSRR_BS9_Pos                      (9U)
#define GPIO_BSRR_BS10_Pos                     (10U)
#define GPIO_BSRR_BS11_Pos                     (11U)
#define GPIO_BSRR_BS12_Pos                     (12U)
#define GPIO_BSRR_BS13_Pos                     (13U)
#define GPIO_BSRR_BS14_Pos                     (14U)
#define GPIO_BSRR_BS15_Pos                     (15U)

#define GPIO_BSRR_BR0_Pos                      (16U)
#define GPIO_BSRR_BR1_Pos                      (17U)
#define GPIO_BSRR_BR2_Pos                      (18U)
#define GPIO_BSRR_BR3_Pos                      (19U)
#define GPIO_BSRR_BR4_Pos                      (20U)
#define GPIO_BSRR_BR5_Pos                      (21U)
#define GPIO_BSRR_BR6_Pos                      (22U)
#define GPIO_BSRR_BR7_Pos                      (23U)
#define GPIO_BSRR_BR8_Pos                      (24U)
#define GPIO_BSRR_BR9_Pos                      (25U)
#define GPIO_BSRR_BR10_Pos                     (26U)
#define GPIO_BSRR_BR11_Pos                     (27U)
#define GPIO_BSRR_BR12_Pos                     (28U)
#define GPIO_BSRR_BR13_Pos                     (29U)
#define GPIO_BSRR_BR14_Pos                     (30U)
#define GPIO_BSRR_BR15_Pos                     (31U)


/**
 * @GPIO_LCKR
 */
#define GPIO_LCKR_LCK0_Pos                     (0U)
#define GPIO_LCKR_LCK1_Pos                     (1U)
#define GPIO_LCKR_LCK2_Pos                     (2U)
#define GPIO_LCKR_LCK3_Pos                     (3U)
#define GPIO_LCKR_LCK4_Pos                     (4U)
#define GPIO_LCKR_LCK5_Pos                     (5U)
#define GPIO_LCKR_LCK6_Pos                     (6U)
#define GPIO_LCKR_LCK7_Pos                     (7U)
#define GPIO_LCKR_LCK8_Pos                     (8U)
#define GPIO_LCKR_LCK9_Pos                     (9U)
#define GPIO_LCKR_LCK10_Pos                    (10U)
#define GPIO_LCKR_LCK11_Pos                    (11U)
#define GPIO_LCKR_LCK12_Pos                    (12U)
#define GPIO_LCKR_LCK13_Pos                    (13U)
#define GPIO_LCKR_LCK14_Pos                    (14U)
#define GPIO_LCKR_LCK15_Pos                    (15U)
#define GPIO_LCKR_LCKK_Pos                     (16U)


/**
 * @GPIO_AFRL
 */
#define GPIO_AFRL_AFRL0_Pos                    (0U)
#define GPIO_AFRL_AFRL1_Pos                    (4U)
#define GPIO_AFRL_AFRL2_Pos                    (8U)
#define GPIO_AFRL_AFRL3_Pos                    (12U)
#define GPIO_AFRL_AFRL4_Pos                    (16U)
#define GPIO_AFRL_AFRL5_Pos                    (20U)
#define GPIO_AFRL_AFRL6_Pos                    (24U)
#define GPIO_AFRL_AFRL7_Pos                    (28U)


/**
 * @GPIO_AFRH
 */
#define GPIO_AFRH_AFRH8_Pos                    (0U)
#define GPIO_AFRH_AFRH9_Pos                    (4U)
#define GPIO_AFRH_AFRH10_Pos                   (8U)
#define GPIO_AFRH_AFRH11_Pos                   (12U)
#define GPIO_AFRH_AFRH12_Pos                   (16U)
#define GPIO_AFRH_AFRH13_Pos                   (20U)
#define GPIO_AFRH_AFRH14_Pos                   (24U)
#define GPIO_AFRH_AFRH15_Pos                   (28U)


/* =================================================== STRUCTURES =================================================== */

/**
 * @brief GPIO pin configuration structure
 * @note  Used to configure individual GPIO pins
 */
typedef struct
{
	GPIO_Pin_t GPIO_PinNumber;			    /*!< Specifies the GPIO pin number               | Possible value: @GPIO_PIN */
	GPIO_PinMode_t GPIO_PinMode;			/*!< Specifies the mode of the GPIO pin          | Possible value: @GPIO_PIN_MODE */
	GPIO_PinSpeed_t GPIO_PinOutputSpeed;    /*!< Specifies the speed of the GPIO pin         | Possible value: @GPIO_PIN_SPEED */
	GPIO_PinPuPd_t GPIO_PinPuPdControl;	    /*!< Specifies Pull-up/Pull-down configuration   | Possible value: @GPIO_PIN_PUPD */
	GPIO_PinOType_t GPIO_PinOutputType;		/*!< Specifies output type                       | Possible value: @GPIO_PIN_OTYPE */
	GPIO_AltFn_t GPIO_PinAltFunMode;	    /*!< Specifies alternate function mode           | Possible value: @GPIO_PIN_ALTFN */
} GPIO_Config_t;


/**
 * @brief GPIO handle structure
 * 
 * @note  Used to manage GPIO pin configuration and base address
 */
typedef struct
{
	GPIO_RegDef_t *pGPIOx;			/*!< Base address of GPIO port (e.g. GPIOA, GPIOB) */
	GPIO_Config_t GPIO_PinConfig;	/*!< GPIO pin configuration settings */
} GPIO_Handle_t;


/* ====================================================== APIs ====================================================== */

/**
 * @brief Enable or disable clock for GPIO peripheral
 * 
 * @param pGPIOx   GPIO port base address (e.g. GPIOA, GPIOB)
 * @param EN_or_DI ENABLE or DISABLE macro
 * 
 * @note Must enable clock before using GPIO registers
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Section 7.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
 */
void GPIO_PeriClock_Control(GPIO_RegDef_t *pGPIOx, uint8_t EN_or_DI);


/**
 * @brief Initialize and configure a GPIO pin
 * 
 * @param pGPIO_Handle Pointer to GPIO handle structure
 * 
 * @details This function configures the selected GPIO pin by:
 *          - Setting pin mode (Input, Output, Alternate, Analog)
 *          - Configuring output speed (for Output/Alternate mode)
 *          - Setting pull-up/pull-down resistors
 *          - Configuring output type (Push-pull/Open-drain)
 *          - Assigning alternate function
 * 
 *          The configuration is applied by modifying GPIO registers:
 *          MODER, OSPEEDR, PUPDR, OTYPER, AFRL/AFRH.
 * 
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 8.4 GPIO registers
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);


/**
 * @brief Reset the specified GPIO peripheral
 * 
 * @param pGPIOx Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * 
 * @details All GPIO registers will be restored to their default reset values.
 * 
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 7.3.5 RCC AHB1 peripheral reset register (RCC_AHB1RSTR)
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);


/**
 * @brief Read the logic level from a specific GPIO input pin
 * 
 * @param pGPIOx    Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * @param PinNumber GPIO pin number (0–15) | @GPIO_PIN
 * 
 * @return uint8_t Logic level of the pin (0 or 1)
 * 
 * @details Reads the corresponding bit from the IDR (Input Data Register)
 *          and returns its value.
 * 
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 8.4.5 GPIO port input data register (GPIOx_IDR)
 */
uint8_t GPIO_ReadFrom_InputPin(GPIO_RegDef_t const *pGPIOx, GPIO_Pin_t PinNumber);


/**
 * @brief Read the logic levels of all GPIO input pins in a port
 *
 * @param pGPIOx Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 *
 * @return uint16_t 16-bit value representing all pin states
 *
 * @details Returns the full content of the IDR (Input Data Register)
 * 
 * @note
 *
 * Refer to:
 * - RM0090 Reference Manual,   Section 8.4.5 GPIO port input data register (GPIOx_IDR)
 */
uint16_t GPIO_ReadFrom_InputPort(GPIO_RegDef_t const *pGPIOx);


/**
 * @brief Write a value to a specific GPIO output pin
 * 
 * @param pGPIOx    Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * @param PinNumber GPIO pin number (0–15) | @GPIO_PIN
 * @param Value     SET or CLEAR macro
 * 
 * @details Sets or clears the corresponding bit in the ODR (Output Data Register)
 *          to drive the pin HIGH or LOW.
 * 
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 8.4.6 GPIO port output data register (GPIOx_ODR)
 */
void GPIO_WriteTo_OutputPin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t PinNumber, uint8_t Value);


/**
 * @brief Write a value to the entire GPIO output port
 * 
 * @param pGPIOx Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * @param Value  16-bit value to be written to the port
 * 
 * @details Writes directly to the ODR (Output Data Register)
 * 
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual, Section 8.4.6 GPIO port output data register (GPIOx_ODR)
 */
void GPIO_WriteTo_OutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);


/**
 * @brief Toggle the state of a specific GPIO output pin
 * 
 * @param pGPIOx    Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * @param PinNumber GPIO pin number (0–15) | @GPIO_PIN
 * 
 * @details Inverts the current logic level of the selected pin by
 *          XORing the corresponding bit in the ODR (Output Data Register).
 */
void GPIO_Toggle_OutputPin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t PinNumber);


/**
 * @brief Lock the configuration of a specific GPIO pin
 * 
 * @param pGPIOx    Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * @param PinNumber GPIO pin number (0–15) | @GPIO_PIN
 * 
 * @details Locks the configuration of the selected pin by performing
 *          the required lock sequence on the LCKR register (LCKK bit).
 *          After locking, GPIO configuration registers cannot be modified
 *          until the next system reset.
 * 
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual, Section 8.4.8 GPIO port configuration lock register (GPIOx_LCKR)
 */
void GPIO_LockPinConfig(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t PinNumber);


/**
 * @brief Get GPIO port code from GPIO peripheral base address
 * 
 * @param pGPIOx Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * 
 * @return GPIO_PortCode_t Corresponding GPIO port code
 * 
 * @details Converts a GPIO peripheral base address into its associated
 *          port code value. The returned port code is typically used
 *          for EXTI configuration or peripheral mapping.
 */
GPIO_PortCode_t GPIO_GetPortCode(GPIO_RegDef_t *pGPIOx);


#endif /* INC_GPIO_DRIVER_H_ */