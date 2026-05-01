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
#define GPIO_AF0                            (0U)
#define GPIO_AF1                            (1U)
#define GPIO_AF2                            (2U)
#define GPIO_AF3                            (3U)
#define GPIO_AF4                            (4U)
#define GPIO_AF5                            (5U)
#define GPIO_AF6                            (6U)
#define GPIO_AF7                            (7U)
#define GPIO_AF8                            (8U)
#define GPIO_AF9                            (9U)
#define GPIO_AF10                           (10U)
#define GPIO_AF11                           (11U)
#define GPIO_AF12                           (12U)
#define GPIO_AF13                           (13U)
#define GPIO_AF14                           (14U)
#define GPIO_AF15                           (15U)


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
