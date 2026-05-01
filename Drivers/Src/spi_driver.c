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
        if (pSPIx == SPI2)
            SPI2_PCLK_EN();
        if (pSPIx == SPI3)
            SPI3_PCLK_EN();
    }
    else if (En_or_DI == DISABLE)
    {
        if (pSPIx == SPI1)
            SPI1_PCLK_DI();
        if (pSPIx == SPI2)
            SPI2_PCLK_DI();
        if (pSPIx == SPI3)
            SPI3_PCLK_DI();
    }
}