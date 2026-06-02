/**
 * File name: gpio-driver.c
 *
 * Created on: 20/04/2026
 * Author: Van Tung Dinh
 */

#include "stm32f407xx.h"
#include "gpio-driver.h"
#include "rcc-driver.h"

/* ====================================================== APIs ====================================================== */

void GPIO_PeriClock_Control(GPIO_RegDef_t *pGPIOx, uint8_t EN_or_DI)
{
	if (EN_or_DI == ENABLE)
	{
		if (pGPIOx == GPIOA)
			RCC_EnablePeripheralClock(RCC_PERIPHERAL_GPIOA);
		else if (pGPIOx == GPIOB)
			RCC_EnablePeripheralClock(RCC_PERIPHERAL_GPIOB);
		else if (pGPIOx == GPIOC)
			RCC_EnablePeripheralClock(RCC_PERIPHERAL_GPIOC);
		else if (pGPIOx == GPIOD)
			RCC_EnablePeripheralClock(RCC_PERIPHERAL_GPIOD);
		else if (pGPIOx == GPIOE)
			RCC_EnablePeripheralClock(RCC_PERIPHERAL_GPIOE);
		else if (pGPIOx == GPIOF)
			RCC_EnablePeripheralClock(RCC_PERIPHERAL_GPIOF);
		else if (pGPIOx == GPIOG)
			RCC_EnablePeripheralClock(RCC_PERIPHERAL_GPIOG);
		else if (pGPIOx == GPIOH)
			RCC_EnablePeripheralClock(RCC_PERIPHERAL_GPIOH);
		else if (pGPIOx == GPIOI)
			RCC_EnablePeripheralClock(RCC_PERIPHERAL_GPIOI);
	}
	else if (EN_or_DI == DISABLE)
	{
		if (pGPIOx == GPIOA)
			RCC_DisablePeripheralClock(RCC_PERIPHERAL_GPIOA);
		else if (pGPIOx == GPIOB)
			RCC_DisablePeripheralClock(RCC_PERIPHERAL_GPIOB);
		else if (pGPIOx == GPIOC)
			RCC_DisablePeripheralClock(RCC_PERIPHERAL_GPIOC);
		else if (pGPIOx == GPIOD)
			RCC_DisablePeripheralClock(RCC_PERIPHERAL_GPIOD);
		else if (pGPIOx == GPIOE)
			RCC_DisablePeripheralClock(RCC_PERIPHERAL_GPIOE);
		else if (pGPIOx == GPIOF)
			RCC_DisablePeripheralClock(RCC_PERIPHERAL_GPIOF);
		else if (pGPIOx == GPIOG)
			RCC_DisablePeripheralClock(RCC_PERIPHERAL_GPIOG);
		else if (pGPIOx == GPIOH)
			RCC_DisablePeripheralClock(RCC_PERIPHERAL_GPIOH);
		else if (pGPIOx == GPIOI)
			RCC_DisablePeripheralClock(RCC_PERIPHERAL_GPIOI);
	}
}


void GPIO_Init(GPIO_Handle_t *pGPIO_Handle)
{
    GPIO_RegDef_t *pGPIOx = pGPIO_Handle->pGPIOx; // (x = A, B, ..., I)
    uint8_t PinNumber = pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber;
    uint8_t PinMode = pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode;
    uint8_t PinOutputSpeed = pGPIO_Handle->GPIO_PinConfig.GPIO_PinOutputSpeed;
    uint8_t PinPuPd = pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl;
    uint8_t PinOutputType = pGPIO_Handle->GPIO_PinConfig.GPIO_PinOutputType;
    uint8_t PinAltFuncMode = pGPIO_Handle->GPIO_PinConfig.GPIO_PinAltFunMode;

    // Enable clock for the GPIO peripheral.
    GPIO_PeriClock_Control(pGPIOx, ENABLE);

    // Configure the mode of GPIO Pin
    if (PinMode == GPIO_PIN_MODE_INPUT || PinMode == GPIO_PIN_MODE_OUTPUT ||
        PinMode == GPIO_PIN_MODE_ANALOG || PinMode == GPIO_PIN_MODE_ALTFN)
    {
        pGPIOx->MODER &= ~(3U << (PinNumber * 2U));
        pGPIOx->MODER |= (PinMode << (PinNumber * 2U));
    }

    // Configure the speed (if the mode of GPIO pin is output mode or altfn mode)
    if (PinMode == GPIO_PIN_MODE_OUTPUT || PinMode == GPIO_PIN_MODE_ALTFN)
    {
        pGPIOx->OSPEEDR &= ~(3U << (PinNumber * 2U));
        pGPIOx->OSPEEDR |= (PinOutputSpeed << (PinNumber * 2U));
    }

    // Configure the Pull-up/Pull-down
    pGPIOx->PUPDR &= ~(3U << (PinNumber * 2U));
    pGPIOx->PUPDR |= (PinPuPd << (PinNumber * 2U));

    // Configure the output type (Push-pull/Open-drain) (if the mode of GPIO pin is output mode or altfn mode)
    if (PinMode == GPIO_PIN_MODE_OUTPUT || PinMode == GPIO_PIN_MODE_ALTFN)
    {
        pGPIOx->OTYPER &= ~(1U << PinNumber);
        pGPIOx->OTYPER |= (PinOutputType << PinNumber);
    }

    // Configure the alternate functionality
    if (PinMode == GPIO_PIN_MODE_ALTFN)
    {
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
        RCC_ResetPeripheral(RCC_PERIPHERAL_GPIOA);
    else if (pGPIOx == GPIOB)
        RCC_ResetPeripheral(RCC_PERIPHERAL_GPIOB);
    else if (pGPIOx == GPIOC)
        RCC_ResetPeripheral(RCC_PERIPHERAL_GPIOC);
    else if (pGPIOx == GPIOD)
        RCC_ResetPeripheral(RCC_PERIPHERAL_GPIOD);
    else if (pGPIOx == GPIOE)
        RCC_ResetPeripheral(RCC_PERIPHERAL_GPIOE);
    else if (pGPIOx == GPIOF)
        RCC_ResetPeripheral(RCC_PERIPHERAL_GPIOF);
    else if (pGPIOx == GPIOG)
        RCC_ResetPeripheral(RCC_PERIPHERAL_GPIOG);
    else if (pGPIOx == GPIOH)
        RCC_ResetPeripheral(RCC_PERIPHERAL_GPIOH);
    else if (pGPIOx == GPIOI)
        RCC_ResetPeripheral(RCC_PERIPHERAL_GPIOI);
}


uint8_t GPIO_ReadFrom_InputPin(GPIO_RegDef_t const *pGPIOx, GPIO_Pin_t PinNumber)
{
    uint8_t res = (uint8_t)((pGPIOx->IDR >> PinNumber) & 1U);
    return res;
}


uint16_t GPIO_ReadFrom_InputPort(GPIO_RegDef_t const *pGPIOx)
{
    uint16_t res = (uint16_t)(pGPIOx->IDR);
    return res;
}


void GPIO_WriteTo_OutputPin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t PinNumber, uint8_t Value)
{
    if (Value == SET)
        pGPIOx->ODR |= (1U << PinNumber);
    else if (Value == CLEAR)
        pGPIOx->ODR &= ~(1U << PinNumber);
}


void GPIO_WriteTo_OutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
    pGPIOx->ODR = Value;
}


void GPIO_Toggle_OutputPin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t PinNumber)
{
    pGPIOx->ODR ^= (1U << PinNumber);
}


void GPIO_LockPinConfig(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t PinNumber)
{
    pGPIOx->LCKR |= (1U << PinNumber);

    pGPIOx->LCKR |= (1U << GPIO_LCKR_LCKK_Pos);
    pGPIOx->LCKR &= ~(1U << GPIO_LCKR_LCKK_Pos);
    pGPIOx->LCKR |= (1U << GPIO_LCKR_LCKK_Pos);

    (void)pGPIOx->LCKR;
    (void)pGPIOx->LCKR;
}


GPIO_PortCode_t GPIO_GetPortCode(GPIO_RegDef_t *pGPIOx)
{
    if (pGPIOx == GPIOA)
        return GPIO_PORT_CODE_GPIOA;
    else if (pGPIOx == GPIOB)
        return GPIO_PORT_CODE_GPIOB;
    else if (pGPIOx == GPIOC)
        return GPIO_PORT_CODE_GPIOC;
    else if (pGPIOx == GPIOD)
        return GPIO_PORT_CODE_GPIOD;
    else if (pGPIOx == GPIOE)
        return GPIO_PORT_CODE_GPIOE;
    else if (pGPIOx == GPIOF)
        return GPIO_PORT_CODE_GPIOF;
    else if (pGPIOx == GPIOG)
        return GPIO_PORT_CODE_GPIOG;
    else if (pGPIOx == GPIOH)
        return GPIO_PORT_CODE_GPIOH;
    else if (pGPIOx == GPIOI)
        return GPIO_PORT_CODE_GPIOI;
    else
        return GPIO_PORT_CODE_GPIOA;
}