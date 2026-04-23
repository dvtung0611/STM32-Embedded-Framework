/*
 * 003_led_button_external.c
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
	GPIO_Handle_t gpio_led, gpio_button;

	// 1. Configure external LED connect to GPIOA pin 8
	gpio_led.pGPIOx = GPIOA;
	gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
	gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_MODE_OUTPUT;
	gpio_led.GPIO_PinConfig.GPIO_PinOutputSpeed = GPIO_PIN_SPEED_HIGH;
	gpio_led.GPIO_PinConfig.GPIO_PinOutputType = GPIO_PIN_OTYPE_PUSHPULL;
	gpio_led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

    // 2. Configure button at GPIOB pin 12
    gpio_button.pGPIOx = GPIOB;
    gpio_button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    gpio_button.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_MODE_INPUT;

	// 3. Enable clock peripheral GPIOA & GPIOB
    GPIO_PeriClock_Control(GPIOA, ENABLE);
	GPIO_PeriClock_Control(GPIOB, ENABLE);

	// 4. Init gpio_button & gpio_led
    GPIO_Init(&gpio_button);
	GPIO_Init(&gpio_led);

	// 5. LED toggle
	while (1)
	{
        if (GPIO_ReadFrom_InputPin(GPIOB, GPIO_PIN_NO_12) == GPIO_PIN_SET)
        {
            GPIO_Toggle_OutputPin(GPIOA, GPIO_PIN_NO_8);
            delay_function();
        }
	}

	return 0;
}

void delay_function(void)
{
	for (uint32_t i = 0; i < 100000; i += 1);
}
