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
