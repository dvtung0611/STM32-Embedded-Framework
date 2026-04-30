/**
 * File name: 001_led_toggle.c
 *
 * Created on: 22/04/2026
 * Author: Van Tung Dinh
 */

#include <stdio.h>
#include <stdint.h>
#include "stm32f407xx.h"


void delay_function(void);


int main(void)
{
	GPIO_Handle_t gpio_led;

	// 1. Configure LD4 on board STM32F407-DISC1
	gpio_led.pGPIOx = GPIOD;
	gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_MODE_OUTPUT;
	gpio_led.GPIO_PinConfig.GPIO_PinOutputSpeed = GPIO_PIN_SPEED_HIGH;
	gpio_led.GPIO_PinConfig.GPIO_PinOutputType = GPIO_PIN_OTYPE_PUSHPULL;
	gpio_led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

	// 2. Enable clock peripheral
	GPIO_PeriClock_Control(GPIOD, ENABLE);

	// 3. Init LD4 (GPIO Init)
	GPIO_Init(&gpio_led);

	// 4. LED toggle
	while (1)
	{
		GPIO_Toggle_OutputPin(GPIOD, GPIO_PIN_NO_15);
		delay_function();
	}

	return 0;
}

void delay_function(void)
{
	for (uint32_t i = 0; i < 100000; i += 1);
}
