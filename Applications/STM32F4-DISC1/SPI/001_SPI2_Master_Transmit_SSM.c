/**
 * File name: 001_SPI2_Master_Transmit_SSM.c
 *
 * Created on: 03/05/2026
 * Author: Van Tung Dinh
 * 
 * @brief   SPI2 Master transmit example using software NSS (SSM)
 *
 * @details
 * - Configure SPI2 (Master, full-duplex, 8-bit)
 * - Use software slave management (SSM = ENABLE)
 * - Transmit a string using polling (blocking API)
 *
 * NSS handling:
 * - NSS pin is not used
 * - Internal NSS is set via SSI bit
 *
 * Connection:
 * - PB13 -> SCLK
 * - PB15 -> MOSI
 *
 * @note
 * - Transmit-only example (MISO not used)
 * - SPI_SendData() is blocking (polling TXE flag)
 */

#include <stdint.h>
#include <string.h>
#include "stm32f407xx.h"


/**
 * @brief  Configure SPI2 GPIO pins (AF5)
 *
 * Pins:
 * - PB13: SCLK
 * - PB15: MOSI
 *
 * @note
 * - NSS and MISO are not used in this example
 */
void Configure_GPIO_for_SPI(void);


/**
 * @brief  Initialize SPI2 in Master mode
 *
 * Config:
 * - Full duplex, 8-bit
 * - f_PCLK / 2 (~8 MHz)
 * - CPOL = 0, CPHA = 0
 * - Software NSS (SSM = ENABLE)
 *
 * @note
 * - SSI must be set to avoid MODF error
 */
void Configure_SPI2(void);


int main(void)
{
    // Configure SPI2 GPIO and peripheral
    Configure_GPIO_for_SPI();
    Configure_SPI2();

    // Enable internal NSS (required when SSM = ENABLE)
    SPI_SSIConfig(SPI2, ENABLE);

    // Enable SPI peripheral
    SPI_PeripheralControl(SPI2, ENABLE);

    // Transmit data (blocking)
    char data[] = "Hello World!";
    SPI_SendData(SPI2, (uint8_t *)(data), strlen(data));

    // Disable SPI after transmission
    SPI_PeripheralControl(SPI2, DISABLE);

    while (1);

    return 0;
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

    // SPI_Pin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    // GPIO_Init(&SPI_Pin);

    SPI_Pin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GPIO_Init(&SPI_Pin);

    // SPI_Pin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
    // GPIO_Init(&SPI_Pin);

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
    SPI2_Handle.SPI_Config.SPI_SCLKSpeed = SPI_SCLK_SPEED_DIV_2; // 8MHz
    SPI2_Handle.SPI_Config.SPI_CPOL = SPI_CPOL_LOW;
    SPI2_Handle.SPI_Config.SPI_CPHA = SPI_CPHA_FIRST_CLK;
    SPI2_Handle.SPI_Config.SPI_SSM = SPI_SSM_ENABLE;

    SPI_Init(&SPI2_Handle);
}