/**
 * 004_button_interrupt.c
 *
 * Created on: 28/04/2026
 * Author: Van Tung Dinh
 */

#include <stdint.h>
#include <string.h>
#include "stm32f407xx.h"


void delay(void);


__IO uint8_t button_flag = 0;


int main(void)
{
    // 1. Configure GPIO Button and GPIO LED
    GPIO_Handle_t gpio_button, gpio_led;

    memset(&gpio_button, 0, sizeof(gpio_button));
    memset(&gpio_led, 0, sizeof(gpio_led));

    gpio_button.pGPIOx = GPIOD;
    gpio_button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_6;
    gpio_button.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_MODE_INPUT;
    gpio_button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

    gpio_led.pGPIOx = GPIOD;
    gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7;
    gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_MODE_OUTPUT;
    gpio_led.GPIO_PinConfig.GPIO_PinOutputSpeed = GPIO_PIN_SPEED_HIGH;
    gpio_led.GPIO_PinConfig.GPIO_PinOutputType = GPIO_PIN_OTYPE_PUSHPULL;

    GPIO_PeriClock_Control(GPIOD, ENABLE);

    GPIO_Init(&gpio_button);
    GPIO_Init(&gpio_led);


    // 2. Configure EXTI Button
    EXTI_Handle_t exti_button;

    exti_button.EXTI_Config.EXTI_LineNumber = EXTI_LINE_6;
    exti_button.EXTI_Config.EXTI_Mode = EXTI_MODE_INTERRUPT;
    exti_button.EXTI_Config.EXTI_PortCode = GPIO_BASEADDR_TO_CODE(GPIOD);
    exti_button.EXTI_Config.EXTI_Trigger = EXTI_TRIGGER_RISING;

    EXTI_Init(&exti_button);

    // 3. Configure NVIC
    NVIC_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);
    NVIC_IRQPriorityConfig(IRQ_NO_EXTI9_5, NVIC_IRQ_PRIORITY_5);

    while(1)
    {
        if (button_flag)
        {
            delay();
            GPIO_Toggle_OutputPin(GPIOD, GPIO_PIN_NO_7);
            button_flag = 0;
        }
    }
}

void delay(void)
{
    for (uint32_t i = 0; i < 50000; i += 1);
}

void EXTI9_5_IRQHandler(void)
{
    EXTI_ClearPending(EXTI_LINE_6);
    button_flag = 1;
}