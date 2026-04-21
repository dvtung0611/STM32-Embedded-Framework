/**
 * File name: stm32f407xx_gpio_driver.c
 *
 * Created on: 20/4/2026
 * Author: Van Tung Dinh
 */

/* ================================================== INCLUDES ================================================== */
#include "stm32f407xx_gpio_driver.h"


/* ================================================== APIs ================================================== */

void GPIO_PeriClock_Control(GPIO_RegDef_t *pGPIOx, uint8_t En_or_DI)
{
	if (En_or_DI == ENABLE)
	{
		if (pGPIOx == GPIOA)
			GPIOA_PCLK_EN();
		if (pGPIOx == GPIOB)
			GPIOB_PCLK_EN();
		if (pGPIOx == GPIOC)
			GPIOC_PCLK_EN();
		if (pGPIOx == GPIOD)
			GPIOD_PCLK_EN();
		if (pGPIOx == GPIOE)
			GPIOE_PCLK_EN();
		if (pGPIOx == GPIOF)
			GPIOF_PCLK_EN();
		if (pGPIOx == GPIOG)
			GPIOG_PCLK_EN();
		if (pGPIOx == GPIOH)
			GPIOH_PCLK_EN();
		if (pGPIOx == GPIOI)
			GPIOI_PCLK_EN();
	}
	else if (En_or_DI == DISABLE)
	{
		if (pGPIOx == GPIOA)
			GPIOA_PCLK_DI();
		if (pGPIOx == GPIOB)
			GPIOB_PCLK_DI();
		if (pGPIOx == GPIOC)
			GPIOC_PCLK_DI();
		if (pGPIOx == GPIOD)
			GPIOD_PCLK_DI();
		if (pGPIOx == GPIOE)
			GPIOE_PCLK_DI();
		if (pGPIOx == GPIOF)
			GPIOF_PCLK_DI();
		if (pGPIOx == GPIOG)
			GPIOG_PCLK_DI();
		if (pGPIOx == GPIOH)
			GPIOH_PCLK_DI();
		if (pGPIOx == GPIOI)
			GPIOI_PCLK_DI();
	}
}

void GPIO_Init(GPIO_Handle_t *pGPIO_Handle)
{
    GPIO_RegDef_t *pGPIOx = pGPIO_Handle->pGPIOx;
    GPIO_Config_t GPIO_PinConfig = pGPIO_Handle->GPIO_PinConfig;

    uint8_t PinNumber = GPIO_PinConfig.GPIO_PinNumber;
    uint8_t PinMode = GPIO_PinConfig.GPIO_PinMode;

    // 1. Configure the mode of GPIO Pin
    if (PinMode <= GPIO_PIN_MODE_ANALOG)
    {
        pGPIOx->MODER &= ~(3U << (PinNumber * 2U));
        pGPIOx->MODER |= (PinMode << (PinNumber * 2U));
    }
    else
    {
        // Interrupt mode
    }

    // 2. Configure the speed (if the mode of GPIO pin is output mode or altfn mode)
    if (PinMode == GPIO_PIN_MODE_OUTPUT || PinMode == GPIO_PIN_MODE_ALTFN)
    {
        uint8_t PinOutputSpeed = GPIO_PinConfig.GPIO_PinOutputSpeed;
        pGPIOx->OSPEEDR &= ~(3U << (PinNumber * 2U));
        pGPIOx->OSPEEDR |= (PinOutputSpeed << (PinNumber * 2U));
    }

    // 3. Configure the Pull-up/Pull-down
    uint8_t PinPuPd = GPIO_PinConfig.GPIO_PinPuPdControl;
    pGPIOx->PUPDR &= ~(3U << (PinNumber * 2U));
    pGPIOx->PUPDR |= (PinPuPd << (PinNumber * 2U));

    // 4. Configure the output type (Push-pull/Open-drain) (if the mode of GPIO pin is output mode or altfn mode)
    if (PinMode == GPIO_PIN_MODE_OUTPUT || PinMode == GPIO_PIN_MODE_ALTFN)
    {
        uint8_t PinOutputType = GPIO_PinConfig.GPIO_PinOutputType;
        pGPIOx->OTYPER &= ~(1U << PinNumber);
        pGPIOx->OTYPER |= (PinOutputType << PinNumber);
    }

    // 5. Configure the alternate functionality
    if (PinMode == GPIO_PIN_MODE_ALTFN)
    {
        uint8_t PinAltFuncMode = GPIO_PinConfig.GPIO_PinAltFunMode;
        if (PinNumber < 8)
        {
            pGPIOx->AFRL &= ~(15U << (PinNumber * 4));
            pGPIOx->AFRL |= (PinAltFuncMode << (PinNumber * 4));
        }
        else
        {
            pGPIOx->AFRH &= ~(15U << ((PinNumber % 8) * 4));
            pGPIOx->AFRH |= (PinAltFuncMode << ((PinNumber % 8) * 4));
        }
    }
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
    if (pGPIOx == GPIOA)
        GPIOA_REG_RESET();
    if (pGPIOx == GPIOB)
        GPIOB_REG_RESET();
    if (pGPIOx == GPIOC)
        GPIOC_REG_RESET();
    if (pGPIOx == GPIOD)
        GPIOD_REG_RESET();
    if (pGPIOx == GPIOE)
        GPIOE_REG_RESET();
    if (pGPIOx == GPIOF)
        GPIOF_REG_RESET();
    if (pGPIOx == GPIOG)
        GPIOG_REG_RESET();
    if (pGPIOx == GPIOH)
        GPIOH_REG_RESET();
    if (pGPIOx == GPIOI)
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
    {
        pGPIOx->ODR |= (1U << PinNumber);
    }
    else
    {
        pGPIOx->ODR &= ~(1U << PinNumber);
    }
}

void GPIO_WriteTo_OutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
    pGPIOx->ODR = Value;
}

void GPIO_Toggle_OutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
    pGPIOx->ODR ^= (1U << PinNumber);
}