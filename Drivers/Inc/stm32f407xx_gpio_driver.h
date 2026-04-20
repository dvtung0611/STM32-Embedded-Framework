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
#define __IO volatile


/* ================================================== DATA TYPES ================================================== */

/**
 * @brief GPIO pin configuration structure
 * @note  Used to configure individual GPIO pins
 */
typedef struct
{
	uint8_t GPIO_PinNumber;					/*| Specifies the GPIO pin number */
	uint8_t GPIO_PinMode;					/*| Specifies the mode of the GPIO pin (Input, Output, Alternate, Analog) */
	uint8_t GPIO_PinOutputSpeed;			/*| Specifies the speed of the GPIO pin */
	uint8_t GPIO_PinPuPdControl;			/*| Specifies Pull-up / Pull-down configuration */
	uint8_t GPIO_PinOutputType;				/*| Specifies output type (Push-pull / Open-drain) */
	uint8_t GPIO_PinAltFunMode;				/*| Specifies alternate function mode */
} GPIO_Config_t;

/**
 * @brief GPIO handle structure
 * @note  Used to manage GPIO pin configuration and base address
 */
typedef struct
{
	GPIO_RegDef_t *pGPIOx;					/*| Base address of GPIO port (e.g. GPIOA, GPIOB) */
	GPIO_Config_t GPIO_PinConfig;			/*| GPIO pin configuration settings */
} GPIO_Handle_t;


/* ================================================== APIs ================================================== */

/**
 * @brief Enable or disable clock for GPIO peripheral
 *
 * @param pGPIOx    GPIO port base address (e.g. GPIOA, GPIOB)
 * @param En_or_DI  ENABLE or DISABLE macro
 *
 * @note Controls corresponding bit in RCC_AHB1ENR register
 * 		 Must enable clock before using GPIO registers
 * Refer to:
 * - RM0090 Reference Manual,	Section 7.3.10 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
 */
void GPIO_PeriClock_Control(GPIO_RegDef_t *pGPIOx, uint8_t En_or_DI);

void GPIO_Init(void);
void GPIO_DeInit(void);

void GPIO_ReadFrom_InputPin(void);
void GPIO_ReadFrom_InputPort(void);
void GPIO_WriteTo_OutputPin(void);
void GPIO_WriteTo_OutputPort(void);
void GPIO_Toggle_OutputPin(void);

void GPIO_IRQ_Config(void);
void GPIO_IRQ_Handling(void);
void GPIO_IRQ_PriorityConfig(void);
void GPIO_ClearIRQFlag(void);

void GPIO_LockPinConfig(void);

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
