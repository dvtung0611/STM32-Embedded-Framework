/**
 * File name: stm32f407xx_gpio_driver.h
 *
 * Created on: 20/4/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

/* ================================================== INCLUDES ================================================== */
#include "stm32f407xx.h"


/* ================================================== MACROS ================================================== */

/**
 * GPIO pin enable or disable
 */
#define GPIO_PIN_SET                        1
#define GPIO_PIN_RESET                      0

/**
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0                       0
#define GPIO_PIN_NO_1                       1
#define GPIO_PIN_NO_2                       2
#define GPIO_PIN_NO_3                       3
#define GPIO_PIN_NO_4                       4
#define GPIO_PIN_NO_5                       5
#define GPIO_PIN_NO_6                       6
#define GPIO_PIN_NO_7                       7
#define GPIO_PIN_NO_8                       8
#define GPIO_PIN_NO_9                       9
#define GPIO_PIN_NO_10                      10
#define GPIO_PIN_NO_11                      11
#define GPIO_PIN_NO_12                      12
#define GPIO_PIN_NO_13                      13
#define GPIO_PIN_NO_14                      14
#define GPIO_PIN_NO_15                      15

/**
 * @GPIO_PIN_MODES
 * GPIO pin possible modes
 */
#define GPIO_PIN_MODE_INPUT                 0
#define GPIO_PIN_MODE_OUTPUT                1
#define GPIO_PIN_MODE_ALTFN                 2
#define GPIO_PIN_MODE_ANALOG                3

/**
 * GPIO pin configured as input with interrupt trigger on rising/falling/both edge
 */
#define GPIO_PIN_MODE_INPUT_FT              4
#define GPIO_PIN_MODE_INPUT_RT              5
#define GPIO_PIN_MODE_INPUT_RFT             6

/**
 * @GPIO_PIN_OTPS
 * GPIO pin possible output types
 */
#define GPIO_PIN_OTYPE_PUSHPULL             0
#define GPIO_PIN_OTYPE_OPENDRAIN            1

/**
 * @GPIO_PIN_SPEEDS
 * GPIO pin possible output speeds
 */
#define GPIO_PIN_SPEED_LOW                  0
#define GPIO_PIN_SPEED_MEDIUM               1
#define GPIO_PIN_SPEED_HIGH                 2
#define GPIO_PIN_SPEED_VERYHIGH             3 

/**
 * @GPIO_PIN_PUPD
 * GPIO pin Pull-up/Pull-down configuration
 */
#define GPIO_PIN_NO_PUPD                    0
#define GPIO_PIN_PU                         1
#define GPIO_PIN_PD                         2

/**
 * @GPIO_PIN_ALTFN
 * GPIO pin Alternate function mode range
 */
#define GPIO_AF0                            0
#define GPIO_AF1                            1
#define GPIO_AF2                            2
#define GPIO_AF3                            3
#define GPIO_AF4                            4  
#define GPIO_AF5                            5
#define GPIO_AF6                            6
#define GPIO_AF7                            7
#define GPIO_AF8                            8
#define GPIO_AF9                            9
#define GPIO_AF10                           10
#define GPIO_AF11                           11
#define GPIO_AF12                           12
#define GPIO_AF13                           13
#define GPIO_AF14                           14
#define GPIO_AF15                           15


/* ================================================== DATA TYPES ================================================== */

/**
 * @brief GPIO pin configuration structure
 * @note  Used to configure individual GPIO pins
 */
typedef struct
{
	uint8_t GPIO_PinNumber;			/*!< Specifies the GPIO pin number               | Possible value: @GPIO_PIN_NUMBERS */
	uint8_t GPIO_PinMode;			/*!< Specifies the mode of the GPIO pin          | Possible value: @GPIO_PIN_MODES */
	uint8_t GPIO_PinOutputSpeed;	/*!< Specifies the speed of the GPIO pin         | Possible value: @GPIO_PIN_SPEEDS */
	uint8_t GPIO_PinPuPdControl;	/*!< Specifies Pull-up/Pull-down configuration   | Possible value: @GPIO_PIN_PUPD */
	uint8_t GPIO_PinOutputType;		/*!< Specifies output type                       | Possible value: @GPIO_PIN_OTPS */
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
 * @fn GPIO_PeriClock_Control
 * @brief Enable or disable clock for GPIO peripheral
 *
 * @param pGPIOx GPIO port base address (e.g. GPIOA, GPIOB)
 * @param En_or_DI ENABLE or DISABLE macro
 *
 * @note Controls corresponding bit in RCC_AHB1ENR register
 * 		 Must enable clock before using GPIO registers
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


void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_ReadFrom_InputPin(GPIO_RegDef_t const *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFrom_InputPort(GPIO_RegDef_t const *pGPIOx);

void GPIO_WriteTo_OutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteTo_OutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

void GPIO_Toggle_OutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

void GPIO_LockPinConfig(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

void GPIO_IRQ_Config(uint8_t IRQ_Number, uint8_t EN_or_DI);
void GPIO_IRQ_PriorityConfig(uint8_t IRQ_Number, uint8_t IRQ_Priority);
void GPIO_IRQ_Handling(uint8_t IRQ_Number);
void GPIO_ClearIRQFlag(uint8_t PinNumber);


#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
