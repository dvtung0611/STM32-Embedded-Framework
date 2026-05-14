/**
 * File name: 002_SPI2_Master_Transmit_Polling.c
 *
 * Created on: 05/05/2026
 * Author: Van Tung Dinh
 *
 * @brief   SPI2 Master transmit example using hardware NSS (SSOE)
 *
 * @details
 * - Trigger transmission by button (PA0)
 * - Send frame: [length (1B)] + [payload (N bytes)]
 * - Hardware controls NSS automatically (SSM = DISABLE, SSOE = ENABLE)
 *
 * Flow:
 * - Wait button press
 * - Enable SPI → NSS LOW
 * - Send length + data
 * - Disable SPI → NSS HIGH
 *
 * @note
 * - Blocking (polling TXE)
 * - Simple delay used for debouncing
 */

#include <stdint.h>
#include <string.h>
#include "stm32f407xx.h"


/**
 * @brief  Simple blocking delay
 */
void delay();


/**
 * @brief  Initialize button (PA0 as input)
 *
 * @note   Pull-up/down depends on board hardware
 * Refer to:
 * - MB997_STM32F407VGT6-E01_Schematic
 */
void Configure_GPIO_ButtonInit(void);


/**
 * @brief  Configure SPI2 GPIO pins (PB12–PB15, AF5)
 *
 * @details
 * Pins:
 * - PB12: NSS  (hardware CS)
 * - PB13: SCLK
 * - PB14: MISO
 * - PB15: MOSI
 *
 * @note Required for hardware NSS management
 */
void Configure_GPIO_for_SPI(void);


/**
 * @brief  Initialize SPI2 (Master mode)
 *
 * @details
 * Config:
 * - Full duplex, 8-bit
 * - f_PCLK / 8 (~2 MHz)
 * - CPOL = 0, CPHA = 0
 * - Hardware NSS (SSM = DISABLE)
 *
 * @note SSOE must be enabled separately
 */
void Configure_SPI2(void);


int main(void)
{
    // Initialize peripherals
    Configure_GPIO_ButtonInit();
    Configure_GPIO_for_SPI();
    Configure_SPI2();

    // Enable hardware NSS output
    SPI_SSOEConfig(SPI2, ENABLE);

    char data[] = "Hello World!";
    uint8_t data_len = strlen(data);

    while (1)
    {
        // Wait for button press
        while (GPIO_ReadFrom_InputPin(GPIOA, GPIO_PIN_NO_0) == GPIO_PIN_RESET);
        delay();

        // Enable SPI2 peripheral (SPE = 1 -> NSS = 0)
        SPI_PeripheralControl(SPI2, ENABLE);

        // Send data length first
        SPI_SendData(SPI2, &data_len, 1); // 1 byte
        
        // Send actual payload
        SPI_SendData(SPI2, (uint8_t *)(data), data_len);

        // Disable SPI2 peripheral (SPE = 0 -> NSS = 1)
        SPI_PeripheralControl(SPI2, DISABLE);

        delay();
    }

    return 0;
}


void delay()
{
    for (uint32_t i = 0; i < 100000; i += 1);
}


void Configure_GPIO_ButtonInit(void)
{
    GPIO_PeriClock_Control(GPIOA, ENABLE);

    GPIO_Handle_t Button;
    memset(&Button, 0, sizeof(Button));

    Button.pGPIOx = GPIOA;
    Button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    Button.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_MODE_INPUT;

    GPIO_Init(&Button);
}


void Configure_GPIO_for_SPI(void)
{
    GPIO_PeriClock_Control(GPIOB, ENABLE);

    GPIO_Handle_t SPI_Pin;
    memset(&SPI_Pin, 0, sizeof(SPI_Pin));

    SPI_Pin.pGPIOx = GPIOB;
    SPI_Pin.GPIO_PinConfig.GPIO_PinMode = GPIO_PIN_MODE_ALTFN;
    SPI_Pin.GPIO_PinConfig.GPIO_PinAltFunMode = GPIO_PIN_ALTFN_5;
    SPI_Pin.GPIO_PinConfig.GPIO_PinOutputSpeed = GPIO_PIN_SPEED_HIGH;
    SPI_Pin.GPIO_PinConfig.GPIO_PinOutputType = GPIO_PIN_OTYPE_PUSHPULL;
    SPI_Pin.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_NO_PUPD;

    SPI_Pin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GPIO_Init(&SPI_Pin);

    SPI_Pin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GPIO_Init(&SPI_Pin);

    SPI_Pin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    GPIO_Init(&SPI_Pin);

    SPI_Pin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
    GPIO_Init(&SPI_Pin);
}


void Configure_SPI2(void)
{
    SPI_PeriClock_Control(SPI2, ENABLE);

    SPI_Handle_t SPI2_Handle;
    memset(&SPI2_Handle, 0, sizeof(SPI2_Handle));

    SPI2_Handle.pSPIx = SPI2;
    SPI2_Handle.SPI_Config.SPI_BusConfig = SPI_BUSCONFIG_FULL_DUPLEX;
    SPI2_Handle.SPI_Config.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
    SPI2_Handle.SPI_Config.SPI_DFF = SPI_DFF_8BITS;
    SPI2_Handle.SPI_Config.SPI_SCLKSpeed = SPI_SCLK_SPEED_DIV_8; // 2MHz
    SPI2_Handle.SPI_Config.SPI_CPOL = SPI_CPOL_LOW;
    SPI2_Handle.SPI_Config.SPI_CPHA = SPI_CPHA_FIRST_CLK;
    SPI2_Handle.SPI_Config.SPI_SSM = SPI_SSM_DISABLE;

    SPI_Init(&SPI2_Handle);
}