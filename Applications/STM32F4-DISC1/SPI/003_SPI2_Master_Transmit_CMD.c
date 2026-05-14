/**
 * File name: 003_SPI2_Master_Transmit_CMD.c
 *
 * Created on: 07/05/2026
 * Author: Van Tung Dinh
 *
 */

#include <stdint.h>
#include <stdio.h>
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


/**
 * 
 */
uint8_t SPI_VerifyResponse(uint8_t ack_byte);


/**
 * Arduino command code
 */
#define COMMAND_LED_CONTROL         0x50
#define COMMAND_SENSOR_READ         0x51
#define COMMAND_LED_READ            0x52
#define COMMAND_PRINT               0x53
#define COMMAND_ID_READ             0x54

#define LED_ON                      1
#define LED_OFF                     0


/**
 * Arduino analog pins
 */
#define ANALOG_PIN0                 0
#define ANALOG_PIN1                 1
#define ANALOG_PIN2                 2
#define ANALOG_PIN3                 3
#define ANALOG_PIN4                 4


/**
 * Arduino led
 */
#define LED_PIN                     9


int main(void)
{
    uint8_t dummy_write = 0xFF;
    uint8_t dummy_read;

    // Initialize peripherals
    Configure_GPIO_ButtonInit();
    Configure_GPIO_for_SPI();
    Configure_SPI2();

    // Enable hardware NSS output
    SPI_SSOEConfig(SPI2, ENABLE);

    while (1)
    {
        // I. LED CONTROL
        // Wait for button press
        while (GPIO_ReadFrom_InputPin(GPIOA, GPIO_PIN_NO_0) == GPIO_PIN_RESET);
        delay();

        // Enable SPI2 peripheral (SPE = 1 -> NSS = 0)
        SPI_PeripheralControl(SPI2, ENABLE);

        uint8_t cmd = COMMAND_LED_CONTROL;
        uint8_t ack_byte;

        SPI_SendData(SPI2, &cmd, 1); // Send command code
        SPI_ReceiveData(SPI2, &dummy_read, 1); // Receive dummy byte

        SPI_SendData(SPI2, &dummy_write, 1); // Send dummy byte
        SPI_ReceiveData(SPI2, &ack_byte, 1); // Receive ACK byte
        
        // Check the ACK byte
        if (SPI_VerifyResponse(ack_byte))
        {
            uint8_t arg[2] = {LED_PIN, LED_ON};
            SPI_SendData(SPI2, arg, sizeof(arg)); // Send arrguments
            SPI_ReceiveData(SPI2, &dummy_read, 1); // Receive dummy byte
        }

        printf("I. CONTROL LED: DONE\n");


        // II. READ SENSOR
        // Wait for button press
        while (GPIO_ReadFrom_InputPin(GPIOA, GPIO_PIN_NO_0) == GPIO_PIN_RESET);
        delay();

        cmd = COMMAND_SENSOR_READ;
        
        SPI_SendData(SPI2, &cmd, 1); // Send command code
        SPI_ReceiveData(SPI2, &dummy_read, 1); // Receive dummy byte

        SPI_SendData(SPI2, &dummy_write, 1); // Send dummy byte
        SPI_ReceiveData(SPI2, &ack_byte, 1); // Receive ACK byte

        if (SPI_VerifyResponse(ack_byte))
        {
            uint8_t arg[1] = {ANALOG_PIN0};
            SPI_SendData(SPI2, arg, sizeof(arg)); // Send argument
            SPI_ReceiveData(SPI2, &dummy_read, 1); // Receive dummy byte
        }

        // Wait until slave can ready with the data
        delay();

        uint8_t analog_read;
        SPI_SendData(SPI2, &dummy_write, 1); // Send dummy byte
        SPI_ReceiveData(SPI2, &analog_read, 1); // Receive analog value

        printf("II. READ SENSOR: DONE\n");


        // III. READ LED STATUS
        while (GPIO_ReadFrom_InputPin(GPIOA, GPIO_PIN_NO_0) == GPIO_PIN_RESET);
        delay();

        cmd = COMMAND_LED_READ;

        SPI_SendData(SPI2, &cmd, 1);
        SPI_ReceiveData(SPI2, &dummy_read, 1);

        SPI_SendData(SPI2, &dummy_write, 1);
        SPI_ReceiveData(SPI2, &ack_byte, 1);

        if (SPI_VerifyResponse(ack_byte))
        {
            uint8_t arg[1] = {LED_PIN};
            SPI_SendData(SPI2, arg, sizeof(arg));
            SPI_ReceiveData(SPI2, &dummy_read, 1);
        }

        // Wait until slave can ready with the data
        delay();

        uint8_t pin_read;
        SPI_SendData(SPI2, &dummy_write, 1); // Send dummy byte
        SPI_ReceiveData(SPI2, &pin_read, 1); // Receive analog value
        
        printf("PIN STATUS: %d \n", pin_read);
        printf("III. READ LED STATUS: DONE\n");
        

        // IV. PRINT MESSAGE
        while (GPIO_ReadFrom_InputPin(GPIOA, GPIO_PIN_NO_0) == GPIO_PIN_RESET);
        delay();

        cmd = COMMAND_PRINT;

        SPI_SendData(SPI2, &cmd, 1);
        SPI_ReceiveData(SPI2, &dummy_read, 1);

        SPI_SendData(SPI2, &dummy_write, 1);
        SPI_ReceiveData(SPI2, &ack_byte, 1);

        if (SPI_VerifyResponse(ack_byte))
        {
            uint8_t message[] = "Hello Embedded World";
            uint8_t size_message = sizeof(message);
            SPI_SendData(SPI2, &size_message, 1);
            SPI_ReceiveData(SPI2, &dummy_read, 1);

            delay();

            for (uint32_t i = 0; i < size_message; i += 1)
            {
                SPI_SendData(SPI2, &message[i], 1);
                SPI_ReceiveData(SPI2, &dummy_read, 1);
            }
        }

        printf("IV. PRINT MESSAGE: DONE\n");


        // V. ID READ
        while (GPIO_ReadFrom_InputPin(GPIOA, GPIO_PIN_NO_0) == GPIO_PIN_RESET);
        delay();

        cmd = COMMAND_ID_READ;

        SPI_SendData(SPI2, &cmd, 1);
        SPI_ReceiveData(SPI2, &dummy_read, 1);

        SPI_SendData(SPI2, &dummy_write, 1);
        SPI_ReceiveData(SPI2, &ack_byte, 1);

        if (SPI_VerifyResponse(ack_byte))
        {
            uint8_t id[11];
            for (uint32_t i = 0; i < 10; i += 1)
            {
                SPI_SendData(SPI2, &dummy_write, 1);
                SPI_ReceiveData(SPI2, &id[i], 1);
            }

            id[10] = '\0';
            printf("COMMAND_ID: %s\n", id);
        }

        printf("V. ID READ: DONE\n");


        // Disable SPI2 peripheral (SPE = 0 -> NSS = 1)
        SPI_PeripheralControl(SPI2, DISABLE);

        delay();
    }

    return 0;
}


uint8_t SPI_VerifyResponse(uint8_t ack_byte)
{
    if (ack_byte == 0xF5)
        return 1;
    return 0;
}


void delay()
{
    for (uint32_t i = 0; i < 500000; i += 1);
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