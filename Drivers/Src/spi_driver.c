/**
 * File name: spi_driver.c
 *
 * Created on: 01/05/2026
 * Author: Van Tung Dinh
 */

/* ================================================== INCLUDES ================================================== */

#include "spi_driver.h"


/* ================================================== APIs ================================================== */

void SPI_PeriClock_Control(SPI_RegDef_t *pSPIx, uint8_t En_or_DI)
{
    if (En_or_DI == ENABLE)
    {
        if (pSPIx == SPI1)
            SPI1_PCLK_EN();
        else if (pSPIx == SPI2)
            SPI2_PCLK_EN();
        else if (pSPIx == SPI3)
            SPI3_PCLK_EN();
    }
    else if (En_or_DI == DISABLE)
    {
        if (pSPIx == SPI1)
            SPI1_PCLK_DI();
        else if (pSPIx == SPI2)
            SPI2_PCLK_DI();
        else if (pSPIx == SPI3)
            SPI3_PCLK_DI();
    }
}


void SPI_Init(SPI_Handle_t *pSPI_Handle)
{
    SPI_RegDef_t *SPIx = pSPI_Handle->pSPIx;
    uint8_t DeviceMode = pSPI_Handle->SPI_Config.SPI_DeviceMode;
    uint8_t BusConfig = pSPI_Handle->SPI_Config.SPI_BusConfig;
    uint8_t SCLKSpeed = pSPI_Handle->SPI_Config.SPI_SCLKSpeed;
    uint8_t DFF = pSPI_Handle->SPI_Config.SPI_DFF;
    uint8_t CPOL = pSPI_Handle->SPI_Config.SPI_CPOL;
    uint8_t CPHA = pSPI_Handle->SPI_Config.SPI_CPHA;
    uint8_t SSM = pSPI_Handle->SPI_Config.SPI_SSM;

    // 1. Enable clock for the SPI peripheral
    SPI_PeriClock_Control(SPIx, ENABLE);

    // 2. Reset the SPI Control Register 1
    SPIx->CR1 = SPI_CR1_RESET_VALUE;

    // 3. Configure the device mode
    SPIx->CR1 |= (DeviceMode << SPI_CR1_MSTR);

    // 4. Configure the communication mode
    if (BusConfig == SPI_BUSCONFIG_FULL_DUPLEX)
    {
        SPIx->CR1 &= ~(1U << SPI_CR1_BIDIMODE); // Unidirectional data mode selected
    }
    else if (BusConfig == SPI_BUSCONFIG_RXONLY)
    {
        SPIx->CR1 &= ~(1U << SPI_CR1_BIDIMODE); // Unidirectional data mode selected + Ignore the MOSI line
        SPIx->CR1 |= (1U << SPI_CR1_RXONLY);
    }
    else if (BusConfig == SPI_BUSCONFIG_TXONLY)
    {
        SPIx->CR1 &= ~(1U << SPI_CR1_BIDIMODE); // Unidirectional data mode selected + Ignore the MISO line
    }
    else if (BusConfig == SPI_BUSCONFIG_HALF_DUPLEX)
        SPIx->CR1 |= (1U << SPI_CR1_BIDIMODE); // Bidirectional data mode selected

    // 5. Configure SCLK speed
    SPIx->CR1 |= (SCLKSpeed << SPI_CR1_BR);

    // 6. Configure data frame format
    SPIx->CR1 |= (DFF << SPI_CR1_DFF);

    // 7. Configure CPOL
    SPIx->CR1 |= (CPOL << SPI_CR1_CPOL);

    // 8. Configure CPHA
    SPIx->CR1 |= (CPHA << SPI_CR1_CPHA);

    // 9. Configure SSM
    SPIx->CR1 |= (SSM << SPI_CR1_SSM);
}


void SPI_DeInit(SPI_RegDef_t *pSPIx)
{
    if (pSPIx == SPI1)
        SPI1_REG_RESET();
    else if (pSPIx == SPI2)
        SPI2_REG_RESET();
    else if (pSPIx == SPI3)
        SPI3_REG_RESET();
}


uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint8_t FlagName)
{
    return ((pSPIx->SR >> FlagName) & 1U);
}


void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxData, uint32_t DataLength)
{
    while (DataLength > 0)
    {
        // 1. Wait until TXE is set (Tx buffer is empty)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) == FLAG_RESET);

        // 2. Check DFF (Data Frame Format)
        if ((pSPIx->CR1 >> SPI_CR1_DFF) & 1U)
        {
            // 16-bit data frame
            pSPIx->DR = *((uint16_t *)(pTxData)); // Load the data into the DR
            DataLength -= 2; // Decrease by 2 bytes
            pTxData += 2; // Increase pointer by 2 bytes
        }
        else
        {
            // 8-bit data frame
            pSPIx->DR = *(pTxData); // Load the data into the DR
            DataLength -= 1; // Decrease by 1 byte
            pTxData += 1; // Increase pointer by 1 byte
        }
    }
}


void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t En_or_DI)
{
    if (En_or_DI == ENABLE)
    {
        pSPIx->CR1 |= (1U << SPI_CR1_SPE);
    }
    else
    {
        pSPIx->CR1 &= ~(1U << SPI_CR1_SPE);
    }
}