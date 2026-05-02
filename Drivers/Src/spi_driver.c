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

    // 1. Reset the SPI Control Register 1
    SPIx->CR1 = 0x00;

    // 2. Configure the device mode
    SPIx->CR1 |= (DeviceMode << 2);

    // 3. Configure the communication mode
    if (BusConfig == SPI_BUSCONFIG_FULL_DUPLEX)
    {
        SPIx->CR1 &= ~(1U << 15); // Unidirectional data mode selected
    }
    else if (BusConfig == SPI_BUSCONFIG_RXONLY)
    {
        SPIx->CR1 &= ~(1U << 15); // Unidirectional data mode selected + Ignore the MOSI line
        SPIx->CR1 |= (1U << 10);
    }
    else if (BusConfig == SPI_BUSCONFIG_TXONLY)
    {
        SPIx->CR1 &= ~(1U << 15); // Unidirectional data mode selected + Ignore the MISO line
    }
    else if (BusConfig == SPI_BUSCONFIG_HALF_DUPLEX)
        SPIx->CR1 |= (1U << 15); // Bidirectional data mode selected

    // 4. Configure SCLK speed
    SPIx->CR1 |= (SCLKSpeed << 3);

    // 5. Configure data frame format
    SPIx->CR1 |= (DFF << 11);

    // 6. Configure CPOL
    SPIx->CR1 |= (CPOL << 1);

    // 7. Configure CPHA
    SPIx->CR1 |= (CPHA << 0);

    // 8. Configure SSM
    SPIx->CR1 |= (SSM << 9);
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