/**
 * File name: gpio-driver.c
 *
 * Created on: 20/04/2026
 * Author: Van Tung Dinh
 */

#include "stm32f407xx.h"
#include "gpio-driver.h"


/* ====================================================== APIs ====================================================== */

void GPIO_PeriClock_Control(GPIO_RegDef_t *pGPIOx, uint8_t En_or_DI)
{
	if (En_or_DI == ENABLE)
	{
		if (pGPIOx == GPIOA)
			GPIOA_PCLK_EN();
		else if (pGPIOx == GPIOB)
			GPIOB_PCLK_EN();
		else if (pGPIOx == GPIOC)
			GPIOC_PCLK_EN();
		else if (pGPIOx == GPIOD)
			GPIOD_PCLK_EN();
		else if (pGPIOx == GPIOE)
			GPIOE_PCLK_EN();
		else if (pGPIOx == GPIOF)
			GPIOF_PCLK_EN();
		else if (pGPIOx == GPIOG)
			GPIOG_PCLK_EN();
		else if (pGPIOx == GPIOH)
			GPIOH_PCLK_EN();
		else if (pGPIOx == GPIOI)
			GPIOI_PCLK_EN();
	}
	else if (En_or_DI == DISABLE)
	{
		if (pGPIOx == GPIOA)
			GPIOA_PCLK_DI();
		else if (pGPIOx == GPIOB)
			GPIOB_PCLK_DI();
		else if (pGPIOx == GPIOC)
			GPIOC_PCLK_DI();
		else if (pGPIOx == GPIOD)
			GPIOD_PCLK_DI();
		else if (pGPIOx == GPIOE)
			GPIOE_PCLK_DI();
		else if (pGPIOx == GPIOF)
			GPIOF_PCLK_DI();
		else if (pGPIOx == GPIOG)
			GPIOG_PCLK_DI();
		else if (pGPIOx == GPIOH)
			GPIOH_PCLK_DI();
		else if (pGPIOx == GPIOI)
			GPIOI_PCLK_DI();
	}
}


void GPIO_Init(GPIO_Handle_t *pGPIO_Handle)
{
    GPIO_RegDef_t *GPIOx = pGPIO_Handle->pGPIOx; // (x = A, B, ..., I)
    uint8_t PinNumber = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber;
    uint8_t PinMode = pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode;
    uint8_t PinOutputSpeed = pGPIO_Handle->GPIO_PinConfig.GPIO_PinOutputSpeed;
    uint8_t PinPuPd = pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl;
    uint8_t PinOutputType = pGPIO_Handle->GPIO_PinConfig.GPIO_PinOutputType;
    uint8_t PinAltFuncMode = pGPIO_Handle->GPIO_PinConfig.GPIO_PinAltFunMode;

    // Enable clock for the GPIO peripheral.
    GPIO_PeriClock_Control(GPIOx, ENABLE);

    // Configure the mode of GPIO Pin
    if (PinMode == GPIO_PIN_MODE_INPUT || PinMode == GPIO_PIN_MODE_OUTPUT ||
        PinMode == GPIO_PIN_MODE_ANALOG || PinMode == GPIO_PIN_MODE_ALTFN)
    {
        GPIOx->MODER &= ~(3U << (PinNumber * 2U));
        GPIOx->MODER |= (PinMode << (PinNumber * 2U));
    }

    // Configure the speed (if the mode of GPIO pin is output mode or altfn mode)
    if (PinMode == GPIO_PIN_MODE_OUTPUT || PinMode == GPIO_PIN_MODE_ALTFN)
    {
        GPIOx->OSPEEDR &= ~(3U << (PinNumber * 2U));
        GPIOx->OSPEEDR |= (PinOutputSpeed << (PinNumber * 2U));
    }

    // Configure the Pull-up/Pull-down
    GPIOx->PUPDR &= ~(3U << (PinNumber * 2U));
    GPIOx->PUPDR |= (PinPuPd << (PinNumber * 2U));

    // Configure the output type (Push-pull/Open-drain) (if the mode of GPIO pin is output mode or altfn mode)
    if (PinMode == GPIO_PIN_MODE_OUTPUT || PinMode == GPIO_PIN_MODE_ALTFN)
    {
        GPIOx->OTYPER &= ~(1U << PinNumber);
        GPIOx->OTYPER |= (PinOutputType << PinNumber);
    }

    // Configure the alternate functionality
    if (PinMode == GPIO_PIN_MODE_ALTFN)
    {
        if (PinNumber < 8)
        {
            GPIOx->AFRL &= ~(15U << (PinNumber * 4));
            GPIOx->AFRL |= (PinAltFuncMode << (PinNumber * 4));
        }
        else
        {
            GPIOx->AFRH &= ~(15U << ((PinNumber % 8) * 4));
            GPIOx->AFRH |= (PinAltFuncMode << ((PinNumber % 8) * 4));
        }
    }
}


void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
    if (pGPIOx == GPIOA)
        GPIOA_REG_RESET();
    else if (pGPIOx == GPIOB)
        GPIOB_REG_RESET();
    else if (pGPIOx == GPIOC)
        GPIOC_REG_RESET();
    else if (pGPIOx == GPIOD)
        GPIOD_REG_RESET();
    else if (pGPIOx == GPIOE)
        GPIOE_REG_RESET();
    else if (pGPIOx == GPIOF)
        GPIOF_REG_RESET();
    else if (pGPIOx == GPIOG)
        GPIOG_REG_RESET();
    else if (pGPIOx == GPIOH)
        GPIOH_REG_RESET();
    else if (pGPIOx == GPIOI)
        GPIOI_REG_RESET();
}


uint8_t GPIO_ReadFrom_InputPin(GPIO_RegDef_t const *pGPIOx, uint8_t PinNumber)
{
    uint8_t res = (uint8_t)((pGPIOx->IDR >> PinNumber) & 1U);
    return res;
}


uint16_t GPIO_ReadFrom_InputPort(GPIO_RegDef_t const *pGPIOx)
{
    uint16_t res = (uint16_t)(pGPIOx->IDR);
    return res;
}


void GPIO_WriteTo_OutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
    if (Value == GPIO_PIN_SET)
        pGPIOx->ODR |= (1U << PinNumber);
    else
        pGPIOx->ODR &= ~(1U << PinNumber);
}


void GPIO_WriteTo_OutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
    pGPIOx->ODR = Value;
}


void GPIO_Toggle_OutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    pGPIOx->ODR ^= (1U << PinNumber);
}


void GPIO_LockPinConfig(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    pGPIOx->LCKR |= (1U << PinNumber);

    pGPIOx->LCKR |= (1U << GPIO_LCKR_LCKK);
    pGPIOx->LCKR &= ~(1U << GPIO_LCKR_LCKK);
    pGPIOx->LCKR |= (1U << GPIO_LCKR_LCKK);

    (void)pGPIOx->LCKR;
    (void)pGPIOx->LCKR;
}