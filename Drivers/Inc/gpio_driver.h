/**
 * File name: gpio_driver.h
 *
 * Created on: 20/04/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_

/* ================================================== INCLUDES ================================================== */

#include "stm32f407xx.h"


/* ================================================== MACROS ================================================== */

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
 * @GPIO_PIN_STATE
 */
#define GPIO_PIN_SET                        (1U)
#define GPIO_PIN_RESET                      (0u)


/**
 * @GPIO_PIN_NUMBER
 */
#define GPIO_PIN_NO_0                       (0U)
#define GPIO_PIN_NO_1                       (1U)
#define GPIO_PIN_NO_2                       (2U)
#define GPIO_PIN_NO_3                       (3U)
#define GPIO_PIN_NO_4                       (4U)
#define GPIO_PIN_NO_5                       (5U)
#define GPIO_PIN_NO_6                       (6U)
#define GPIO_PIN_NO_7                       (7U)
#define GPIO_PIN_NO_8                       (8U)
#define GPIO_PIN_NO_9                       (9U)
#define GPIO_PIN_NO_10                      (10U)
#define GPIO_PIN_NO_11                      (11U)
#define GPIO_PIN_NO_12                      (12U)
#define GPIO_PIN_NO_13                      (13U)
#define GPIO_PIN_NO_14                      (14U)
#define GPIO_PIN_NO_15                      (15U)


/**
 * @GPIO_PIN_MODE
 */
#define GPIO_PIN_MODE_INPUT                 (0U)
#define GPIO_PIN_MODE_OUTPUT                (1U)
#define GPIO_PIN_MODE_ALTFN                 (2U)
#define GPIO_PIN_MODE_ANALOG                (3U)


/**
 * @GPIO_PIN_OTYPE
 */
#define GPIO_PIN_OTYPE_PUSHPULL             (0U)
#define GPIO_PIN_OTYPE_OPENDRAIN            (1U)


/**
 * @GPIO_PIN_SPEED
 */
#define GPIO_PIN_SPEED_LOW                  (0U)
#define GPIO_PIN_SPEED_MEDIUM               (1U)
#define GPIO_PIN_SPEED_HIGH                 (2U)
#define GPIO_PIN_SPEED_VERYHIGH             (3U)


/**
 * @GPIO_PIN_PUPD
 */
#define GPIO_PIN_NO_PUPD                    (0U)
#define GPIO_PIN_PU                         (1U)
#define GPIO_PIN_PD                         (2U)


/**
 * @GPIO_PIN_ALTFN
 */
#define GPIO_PIN_ALTFN_0                    (0U)
#define GPIO_PIN_ALTFN_1                    (1U)
#define GPIO_PIN_ALTFN_2                    (2U)
#define GPIO_PIN_ALTFN_3                    (3U)
#define GPIO_PIN_ALTFN_4                    (4U)
#define GPIO_PIN_ALTFN_5                    (5U)
#define GPIO_PIN_ALTFN_6                    (6U)
#define GPIO_PIN_ALTFN_7                    (7U)
#define GPIO_PIN_ALTFN_8                    (8U)
#define GPIO_PIN_ALTFN_9                    (9U)
#define GPIO_PIN_ALTFN_10                   (10U)
#define GPIO_PIN_ALTFN_11                   (11U)
#define GPIO_PIN_ALTFN_12                   (12U)
#define GPIO_PIN_ALTFN_13                   (13U)
#define GPIO_PIN_ALTFN_14                   (14U)
#define GPIO_PIN_ALTFN_15                   (15U)


/* ============================================= Bit Position Definition of GPIO Peripheral ============================================= */

/**
 * @GPIO_MODER
 */
#define GPIO_MODER_MODER0                  (0U)
#define GPIO_MODER_MODER1                  (2U)
#define GPIO_MODER_MODER2                  (4U)
#define GPIO_MODER_MODER3                  (6U)
#define GPIO_MODER_MODER4                  (8U)
#define GPIO_MODER_MODER5                  (10U)
#define GPIO_MODER_MODER6                  (12U)
#define GPIO_MODER_MODER7                  (14U)
#define GPIO_MODER_MODER8                  (16U)
#define GPIO_MODER_MODER9                  (18U)
#define GPIO_MODER_MODER10                 (20U)
#define GPIO_MODER_MODER11                 (22U)
#define GPIO_MODER_MODER12                 (24U)
#define GPIO_MODER_MODER13                 (26U)
#define GPIO_MODER_MODER14                 (28U)
#define GPIO_MODER_MODER15                 (30U)


/**
 * @GPIO_OTYPER
 */
#define GPIO_OTYPER_OT0                    (0U)
#define GPIO_OTYPER_OT1                    (1U)
#define GPIO_OTYPER_OT2                    (2U)
#define GPIO_OTYPER_OT3                    (3U)
#define GPIO_OTYPER_OT4                    (4U)
#define GPIO_OTYPER_OT5                    (5U)
#define GPIO_OTYPER_OT6                    (6U)
#define GPIO_OTYPER_OT7                    (7U)
#define GPIO_OTYPER_OT8                    (8U)
#define GPIO_OTYPER_OT9                    (9U)
#define GPIO_OTYPER_OT10                   (10U)
#define GPIO_OTYPER_OT11                   (11U)
#define GPIO_OTYPER_OT12                   (12U)
#define GPIO_OTYPER_OT13                   (13U)
#define GPIO_OTYPER_OT14                   (14U)
#define GPIO_OTYPER_OT15                   (15U)


/**
 * @GPIO_OSPEEDR
 */
#define GPIO_OSPEEDR_OSPEEDR0              (0U)
#define GPIO_OSPEEDR_OSPEEDR1              (2U)
#define GPIO_OSPEEDR_OSPEEDR2              (4U)
#define GPIO_OSPEEDR_OSPEEDR3              (6U)
#define GPIO_OSPEEDR_OSPEEDR4              (8U)
#define GPIO_OSPEEDR_OSPEEDR5              (10U)
#define GPIO_OSPEEDR_OSPEEDR6              (12U)
#define GPIO_OSPEEDR_OSPEEDR7              (14U)
#define GPIO_OSPEEDR_OSPEEDR8              (16U)
#define GPIO_OSPEEDR_OSPEEDR9              (18U)
#define GPIO_OSPEEDR_OSPEEDR10             (20U)
#define GPIO_OSPEEDR_OSPEEDR11             (22U)
#define GPIO_OSPEEDR_OSPEEDR12             (24U)
#define GPIO_OSPEEDR_OSPEEDR13             (26U)
#define GPIO_OSPEEDR_OSPEEDR14             (28U)
#define GPIO_OSPEEDR_OSPEEDR15             (30U)


/**
 * @GPIO_PUPDR
 */
#define GPIO_PUPDR_PUPDR0                  (0U)
#define GPIO_PUPDR_PUPDR1                  (2U)
#define GPIO_PUPDR_PUPDR2                  (4U)
#define GPIO_PUPDR_PUPDR3                  (6U)
#define GPIO_PUPDR_PUPDR4                  (8U)
#define GPIO_PUPDR_PUPDR5                  (10U)
#define GPIO_PUPDR_PUPDR6                  (12U)
#define GPIO_PUPDR_PUPDR7                  (14U)
#define GPIO_PUPDR_PUPDR8                  (16U)
#define GPIO_PUPDR_PUPDR9                  (18U)
#define GPIO_PUPDR_PUPDR10                 (20U)
#define GPIO_PUPDR_PUPDR11                 (22U)
#define GPIO_PUPDR_PUPDR12                 (24U)
#define GPIO_PUPDR_PUPDR13                 (26U)
#define GPIO_PUPDR_PUPDR14                 (28U)
#define GPIO_PUPDR_PUPDR15                 (30U)


/**
 * @GPIO_IDR
 */
#define GPIO_IDR_IDR0                      (0U)
#define GPIO_IDR_IDR1                      (1U)
#define GPIO_IDR_IDR2                      (2U)
#define GPIO_IDR_IDR3                      (3U)
#define GPIO_IDR_IDR4                      (4U)
#define GPIO_IDR_IDR5                      (5U)
#define GPIO_IDR_IDR6                      (6U)
#define GPIO_IDR_IDR7                      (7U)
#define GPIO_IDR_IDR8                      (8U)
#define GPIO_IDR_IDR9                      (9U)
#define GPIO_IDR_IDR10                     (10U)
#define GPIO_IDR_IDR11                     (11U)
#define GPIO_IDR_IDR12                     (12U)
#define GPIO_IDR_IDR13                     (13U)
#define GPIO_IDR_IDR14                     (14U)
#define GPIO_IDR_IDR15                     (15U)


/**
 * @GPIO_ODR
 */
#define GPIO_ODR_ODR0                      (0U)
#define GPIO_ODR_ODR1                      (1U)
#define GPIO_ODR_ODR2                      (2U)
#define GPIO_ODR_ODR3                      (3U)
#define GPIO_ODR_ODR4                      (4U)
#define GPIO_ODR_ODR5                      (5U)
#define GPIO_ODR_ODR6                      (6U)
#define GPIO_ODR_ODR7                      (7U)
#define GPIO_ODR_ODR8                      (8U)
#define GPIO_ODR_ODR9                      (9U)
#define GPIO_ODR_ODR10                     (10U)
#define GPIO_ODR_ODR11                     (11U)
#define GPIO_ODR_ODR12                     (12U)
#define GPIO_ODR_ODR13                     (13U)
#define GPIO_ODR_ODR14                     (14U)
#define GPIO_ODR_ODR15                     (15U)


/**
 * @GPIO_BSRR
 */
#define GPIO_BSRR_BS0                      (0U)
#define GPIO_BSRR_BS1                      (1U)
#define GPIO_BSRR_BS2                      (2U)
#define GPIO_BSRR_BS3                      (3U)
#define GPIO_BSRR_BS4                      (4U)
#define GPIO_BSRR_BS5                      (5U)
#define GPIO_BSRR_BS6                      (6U)
#define GPIO_BSRR_BS7                      (7U)
#define GPIO_BSRR_BS8                      (8U)
#define GPIO_BSRR_BS9                      (9U)
#define GPIO_BSRR_BS10                     (10U)
#define GPIO_BSRR_BS11                     (11U)
#define GPIO_BSRR_BS12                     (12U)
#define GPIO_BSRR_BS13                     (13U)
#define GPIO_BSRR_BS14                     (14U)
#define GPIO_BSRR_BS15                     (15U)

#define GPIO_BSRR_BR0                      (16U)
#define GPIO_BSRR_BR1                      (17U)
#define GPIO_BSRR_BR2                      (18U)
#define GPIO_BSRR_BR3                      (19U)
#define GPIO_BSRR_BR4                      (20U)
#define GPIO_BSRR_BR5                      (21U)
#define GPIO_BSRR_BR6                      (22U)
#define GPIO_BSRR_BR7                      (23U)
#define GPIO_BSRR_BR8                      (24U)
#define GPIO_BSRR_BR9                      (25U)
#define GPIO_BSRR_BR10                     (26U)
#define GPIO_BSRR_BR11                     (27U)
#define GPIO_BSRR_BR12                     (28U)
#define GPIO_BSRR_BR13                     (29U)
#define GPIO_BSRR_BR14                     (30U)
#define GPIO_BSRR_BR15                     (31U)


/**
 * @GPIO_LCKR
 */
#define GPIO_LCKR_LCK0                     (0U)
#define GPIO_LCKR_LCK1                     (1U)
#define GPIO_LCKR_LCK2                     (2U)
#define GPIO_LCKR_LCK3                     (3U)
#define GPIO_LCKR_LCK4                     (4U)
#define GPIO_LCKR_LCK5                     (5U)
#define GPIO_LCKR_LCK6                     (6U)
#define GPIO_LCKR_LCK7                     (7U)
#define GPIO_LCKR_LCK8                     (8U)
#define GPIO_LCKR_LCK9                     (9U)
#define GPIO_LCKR_LCK10                    (10U)
#define GPIO_LCKR_LCK11                    (11U)
#define GPIO_LCKR_LCK12                    (12U)
#define GPIO_LCKR_LCK13                    (13U)
#define GPIO_LCKR_LCK14                    (14U)
#define GPIO_LCKR_LCK15                    (15U)
#define GPIO_LCKR_LCKK                     (16U)


/**
 * @GPIO_AFRL
 */
#define GPIO_AFRL_AFRL0                    (0U)
#define GPIO_AFRL_AFRL1                    (4U)
#define GPIO_AFRL_AFRL2                    (8U)
#define GPIO_AFRL_AFRL3                    (12U)
#define GPIO_AFRL_AFRL4                    (16U)
#define GPIO_AFRL_AFRL5                    (20U)
#define GPIO_AFRL_AFRL6                    (24U)
#define GPIO_AFRL_AFRL7                    (28U)


/**
 * @GPIO_AFRH
 */
#define GPIO_AFRH_AFRH8                    (0U)
#define GPIO_AFRH_AFRH9                    (4U)
#define GPIO_AFRH_AFRH10                   (8U)
#define GPIO_AFRH_AFRH11                   (12U)
#define GPIO_AFRH_AFRH12                   (16U)
#define GPIO_AFRH_AFRH13                   (20U)
#define GPIO_AFRH_AFRH14                   (24U)
#define GPIO_AFRH_AFRH15                   (28U)


/* ================================================== DATA TYPES ================================================== */

/**
 * @brief GPIO pin configuration structure
 * @note  Used to configure individual GPIO pins
 */
typedef struct
{
	uint8_t GPIO_PinNumber;			/*!< Specifies the GPIO pin number               | Possible value: @GPIO_PIN_NUMBER */
	uint8_t GPIO_PinMode;			/*!< Specifies the mode of the GPIO pin          | Possible value: @GPIO_PIN_MODE */
	uint8_t GPIO_PinOutputSpeed;	/*!< Specifies the speed of the GPIO pin         | Possible value: @GPIO_PIN_SPEED */
	uint8_t GPIO_PinPuPdControl;	/*!< Specifies Pull-up/Pull-down configuration   | Possible value: @GPIO_PIN_PUPD */
	uint8_t GPIO_PinOutputType;		/*!< Specifies output type                       | Possible value: @GPIO_PIN_OTYPE */
	uint8_t GPIO_PinAltFunMode;		/*!< Specifies alternate function mode           | Possible value: @GPIO_PIN_ALTFN */
} GPIO_Config_t;


/**
 * @brief GPIO handle structure
 * @note  Used to manage GPIO pin configuration and base address
 */
typedef struct
{
	GPIO_RegDef_t *pGPIOx;			/*!< Base address of GPIO port (e.g. GPIOA, GPIOB) */
	GPIO_Config_t GPIO_PinConfig;	/*!< GPIO pin configuration settings */
} GPIO_Handle_t;


/* ================================================== APIs ================================================== */

/**
 * @brief Enable or disable clock for GPIO peripheral
 *
 * @param pGPIOx GPIO port base address (e.g. GPIOA, GPIOB)
 * @param En_or_DI ENABLE or DISABLE macro
 *
 * @note Must enable clock before using GPIO registers
 * Refer to:
 * - RM0090 Reference Manual,	Section 7.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
 */
void GPIO_PeriClock_Control(GPIO_RegDef_t *pGPIOx, uint8_t En_or_DI);


/**
 * @brief  Initialize and configure a GPIO pin
 *
 * @param  pGPIO_Handle  Pointer to GPIO handle structure containing
 *                       port base address and pin configuration
 *
 * @details This function configures the selected GPIO pin by:
 *          - Setting pin mode (Input, Output, Alternate, Analog)
 *          - Configuring output speed (for Output/Alternate mode)
 *          - Setting pull-up/pull-down resistors
 *          - Configuring output type (Push-pull/Open-drain)
 *          - Assigning alternate function
 * The configuration is applied by modifying GPIO registers:
 * MODER, OSPEEDR, PUPDR, OTYPER, AFRL/AFRH.
 * 
 * @note
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
 * Refer to:
 * - RM0090 Reference Manual, Section 7.3.5 RCC AHB1 peripheral reset register (RCC_AHB1RSTR)
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);


/**
 * @brief  Read the logic level from a specific GPIO input pin
 *
 * @param  pGPIOx     Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * @param  PinNumber  GPIO pin number (0–15)
 *
 * @return uint8_t    Logic level of the pin (0 or 1)
 *
 * @details Reads the corresponding bit from the IDR (Input Data Register)
 *          and returns its value.
 * 
 * @note
 * Refer to:
 * - RM0090 Reference Manual, Section 8.4.5 GPIO port input data register (GPIOx_IDR)
 */
uint8_t GPIO_ReadFrom_InputPin(GPIO_RegDef_t const *pGPIOx, uint8_t PinNumber);


/**
 * @brief  Read the logic levels of all GPIO input pins in a port
 *
 * @param  pGPIOx  Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 *
 * @return uint16_t  16-bit value representing all pin states
 *
 * @details Returns the full content of the IDR (Input Data Register)
 * 
 * @note
 * Refer to:
 * - RM0090 Reference Manual, Section 8.4.5 GPIO port input data register (GPIOx_IDR)
 */
uint16_t GPIO_ReadFrom_InputPort(GPIO_RegDef_t const *pGPIOx);


/**
 * @brief  Write a value to a specific GPIO output pin
 *
 * @param  pGPIOx     Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * @param  PinNumber  GPIO pin number (0–15)
 * @param  Value      GPIO_PIN_SET or GPIO_PIN_RESET
 *
 * @details Sets or clears the corresponding bit in the ODR (Output Data Register)
 *          to drive the pin HIGH or LOW.
 * 
 * @note
 * Refer to:
 * - RM0090 Reference Manual, Section 8.4.6 GPIO port output data register (GPIOx_ODR)
 */
void GPIO_WriteTo_OutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);


/**
 * @brief  Write a value to the entire GPIO output port
 *
 * @param  pGPIOx  Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * @param  Value   16-bit value to be written to the port
 *
 * @details Writes directly to the ODR (Output Data Register)
 * 
 * @note
 * Refer to:
 * - RM0090 Reference Manual, Section 8.4.6 GPIO port output data register (GPIOx_ODR)
 */
void GPIO_WriteTo_OutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);


/**
 * @brief  Toggle the state of a specific GPIO output pin
 *
 * @param  pGPIOx     Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * @param  PinNumber  GPIO pin number (0–15)
 *
 * @details Inverts the current logic level of the selected pin by
 *          XORing the corresponding bit in the ODR (Output Data Register).
 */
void GPIO_Toggle_OutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/**
 * @brief  Lock the configuration of a specific GPIO pin
 *
 * @param  pGPIOx     Pointer to GPIO port (e.g. GPIOA, GPIOB, ...)
 * @param  PinNumber  GPIO pin number (0–15)
 *
 * @details Locks the configuration of the selected pin by performing
 *          the required lock sequence on the LCKR register (LCKK bit).
 *          After locking, GPIO configuration registers cannot be modified
 *          until the next system reset.
 *
 * @note
 * Refer to:
 * - RM0090 Reference Manual, Section 8.4.8 GPIO port configuration lock register (GPIOx_LCKR)
 */
void GPIO_LockPinConfig(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


#endif /* INC_GPIO_DRIVER_H_ */
