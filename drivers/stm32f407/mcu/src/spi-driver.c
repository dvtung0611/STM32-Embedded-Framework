/**
 * File name: spi-driver.c
 *
 * Created on: 01/05/2026
 * Author: Van Tung Dinh
 */

#include "stm32f407xx.h"
#include "spi-driver.h"


static void SPI_TXE_InterruptHandle(SPI_Handle_t *pSPI_Handle);
static void SPI_RXNE_InterruptHandle(SPI_Handle_t *pSPI_Handle);
static void SPI_OVR_InterruptHandle(SPI_Handle_t *pSPI_Handle);


/* ====================================================== APIs ====================================================== */

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
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;
    uint8_t DeviceMode = pSPI_Handle->SPI_Config.SPI_DeviceMode;
    uint8_t BusConfig = pSPI_Handle->SPI_Config.SPI_BusConfig;
    uint8_t SCLKSpeed = pSPI_Handle->SPI_Config.SPI_SCLKSpeed;
    uint8_t DFF = pSPI_Handle->SPI_Config.SPI_DFF;
    uint8_t CPOL = pSPI_Handle->SPI_Config.SPI_CPOL;
    uint8_t CPHA = pSPI_Handle->SPI_Config.SPI_CPHA;
    uint8_t SSM = pSPI_Handle->SPI_Config.SPI_SSM;

    // Enable clock for the SPI peripheral
    SPI_PeriClock_Control(pSPIx, ENABLE);

    // Reset the SPI Control Register 1
    pSPIx->CR1 = SPI_CR1_RESET_VALUE;

    // Configure the device mode
    pSPIx->CR1 |= (DeviceMode << SPI_CR1_MSTR);

    // Configure the communication mode
    if (BusConfig == SPI_BUSCONFIG_FULL_DUPLEX) // 2-line full duplex
    {
        pSPIx->CR1 &= ~(1U << SPI_CR1_BIDIMODE);
        pSPIx->CR1 &= ~(1U << SPI_CR1_RXONLY);
    }
    else if (BusConfig == SPI_BUSCONFIG_HALF_DUPLEX) // 1-line half duplex
    {
        pSPIx->CR1 |= (1U << SPI_CR1_BIDIMODE);
        pSPIx->CR1 &= ~(1U << SPI_CR1_RXONLY);
        // TX mode: BIDIOE = 1
        // RX mode: BIDIOE = 0
        // Direction controlled at runtime
    }
    else if (BusConfig == SPI_BUSCONFIG_SIMPLEX_RX) // 2-line receive-only
    {
        pSPIx->CR1 &= ~(1U << SPI_CR1_BIDIMODE);
        pSPIx->CR1 |= (1U << SPI_CR1_RXONLY);
    }

    // Configure SCLK speed
    pSPIx->CR1 |= (SCLKSpeed << SPI_CR1_BR);

    // Configure data frame format
    pSPIx->CR1 |= (DFF << SPI_CR1_DFF);

    // Configure CPOL
    pSPIx->CR1 |= (CPOL << SPI_CR1_CPOL);

    // Configure CPHA
    pSPIx->CR1 |= (CPHA << SPI_CR1_CPHA);

    // Configure SSM
    pSPIx->CR1 |= (SSM << SPI_CR1_SSM);
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


void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t DataLength)
{
    while (DataLength > 0)
    {
        // Wait until TXE is set (Tx buffer is empty)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) == FLAG_RESET);

        // Check DFF (Data Frame Format)
        if ((pSPIx->CR1 >> SPI_CR1_DFF) & 1U)
        {
            // 16-bit data frame
            pSPIx->DR = *((uint16_t *)(pTxBuffer)); // Load the data into the DR
            DataLength -= 2; // Decrease by 2 bytes
            pTxBuffer += 2; // Increase pointer by 2 bytes
        }
        else
        {
            // 8-bit data frame
            pSPIx->DR = *pTxBuffer; // Load the data into the DR
            DataLength -= 1; // Decrease by 1 byte
            pTxBuffer += 1; // Increase pointer by 1 byte
        }
    }

    // Wait until the SPI is not busy
    while (SPI_GetFlagStatus(pSPIx, SPI_SR_BSY));
}


void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t DataLength)
{
    while (DataLength > 0)
    {
        // Wait until RXNE is set (Rx buffer is not empty = Rx buffer is full)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_RXNE) == FLAG_RESET);

        // Check DFF (Data Frame Format)
        if ((pSPIx->CR1 >> SPI_CR1_DFF) & 1U)
        {
            // 16-bit data frame
            *((uint16_t *)(pRxBuffer)) = pSPIx->DR; // Read data from the DR
            DataLength -= 2; // Decrease by 2 bytes
            pRxBuffer += 2; // Increase pointer by 2 bytes
        }
        else
        {
            // 8-bit data frame
            *pRxBuffer = (uint8_t)(pSPIx->DR); // Read data from the DR
            DataLength -= 1; // Decrease by 1 byte
            pRxBuffer += 1; // Increase pointer by 1 byte
        }
    }

    // Wait until the SPI is not busy
    while (SPI_GetFlagStatus(pSPIx, SPI_SR_BSY));
}


void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t En_or_DI)
{
    if (En_or_DI == ENABLE)
        pSPIx->CR1 |= (1U << SPI_CR1_SPE);
    else if (En_or_DI == DISABLE)
        pSPIx->CR1 &= ~(1U << SPI_CR1_SPE);
}


void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t En_or_DI)
{
    if (En_or_DI == ENABLE)
        pSPIx->CR1 |= (1U << SPI_CR1_SSI);
    else if (En_or_DI == DISABLE)
        pSPIx->CR1 &= ~(1U << SPI_CR1_SSI);
}


void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI)
{
    if (EN_or_DI == ENABLE)
        pSPIx->CR2 |= (1U << SPI_CR2_SSOE);
    else if (EN_or_DI == DISABLE)
        pSPIx->CR2 &= ~(1U << SPI_CR2_SSOE);
}


uint8_t SPI_SendDataIT(SPI_Handle_t *pSPI_Handle, uint8_t *pTxBuffer, uint32_t DataLength)
{
    uint8_t spi_state = pSPI_Handle->TxState;

    if (spi_state != SPI_READY)
        return spi_state;
    
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

    // Save TX buffer pointer and transfer length
    pSPI_Handle->pTxBuffer = pTxBuffer;
    pSPI_Handle->TxLength = DataLength;

    // Set BUSY_IN_TX
    pSPI_Handle->TxState = SPI_BUSY_IN_TX;
    spi_state = pSPI_Handle->TxState;

    // Enable TXEIE bit
    pSPIx->CR2 |= (1U << SPI_CR2_TXEIE);

    return spi_state;
}


uint8_t SPI_ReceiveDataIT(SPI_Handle_t *pSPI_Handle, uint8_t *pRxBuffer, uint32_t DataLength)
{
    uint8_t spi_state = pSPI_Handle->RxState;

    if (spi_state != SPI_READY)
        return spi_state;
    
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

    // Save RX buffer pointer and transfer length
    pSPI_Handle->pRxBuffer = pRxBuffer;
    pSPI_Handle->RxLength = DataLength;

    // Set BUSY_IN_RX
    pSPI_Handle->RxState = SPI_BUSY_IN_RX;
    spi_state = pSPI_Handle->RxState;

    // Enable RXNEIE bit
    pSPIx->CR2 |= (1U << SPI_CR2_RXNEIE);

    return spi_state;
}


void SPI_IRQHandling(SPI_Handle_t *pSPI_Handle)
{
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

    // Check for TXE
    uint8_t temp1 = ((pSPIx->SR >> SPI_SR_TXE) & 1U);
    uint8_t temp2 = ((pSPIx->CR2 >> SPI_CR2_TXEIE) & 1U);
    if (temp1 && temp2)
    {
        SPI_TXE_InterruptHandle(pSPI_Handle);
    }

    // Check for RXNE
    temp1 = ((pSPIx->SR >> SPI_SR_RXNE) & 1U);
    temp2 = ((pSPIx->CR2 >> SPI_CR2_RXNEIE) & 1U);
    if (temp1 && temp2)
    {
        SPI_RXNE_InterruptHandle(pSPI_Handle);
    }

    // Check for OVR
    temp1 = ((pSPIx->SR >> SPI_SR_OVR) & 1U);
    temp2 = ((pSPIx->CR2 >> SPI_CR2_ERRIE) & 1U);
    if (temp1 && temp2)
    {
        SPI_OVR_InterruptHandle(pSPI_Handle);
    }
}


static void SPI_TXE_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;
    SPI_Config_t SPI_Config = pSPI_Handle->SPI_Config;

    // Transmit data
    if (SPI_Config.SPI_DFF == SPI_DFF_16BITS)
    {
        pSPIx->DR = *((uint16_t *)(pSPI_Handle->pTxBuffer));
        pSPI_Handle->TxLength -= 2;
        pSPI_Handle->pTxBuffer += 2;
    }
    else if (SPI_Config.SPI_DFF == SPI_DFF_8BITS)
    {
        pSPIx->DR = *(pSPI_Handle->pTxBuffer);
        pSPI_Handle->TxLength -= 1;
        pSPI_Handle->pTxBuffer += 1;
    }

    // Close transmission
    if (pSPI_Handle->TxLength <= 0 && SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) && !SPI_GetFlagStatus(pSPIx, SPI_FLAG_RXNE))
    {
        pSPIx->CR2 &= ~(1U << SPI_CR2_TXEIE);
        pSPI_Handle->pTxBuffer = NULL;
        pSPI_Handle->TxLength = 0;
        pSPI_Handle->TxState = SPI_READY;

        SPI_ApplicationEventCallBack(pSPI_Handle, SPI_EVENT_TX_COMPLETE);
    }
}


static void SPI_RXNE_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;
    SPI_Config_t SPI_Config = pSPI_Handle->SPI_Config;

    // Receive data
    if (SPI_Config.SPI_DFF == SPI_DFF_16BITS)
    {
        *((uint16_t *)(pSPI_Handle->pRxBuffer)) = pSPIx->DR;
        pSPI_Handle->RxLength -= 2;
        pSPI_Handle->pRxBuffer += 2;
    }
    else if (SPI_Config.SPI_DFF == SPI_DFF_8BITS)
    {
        *(pSPI_Handle->pRxBuffer) = (uint8_t)(pSPIx->DR);
        pSPI_Handle->RxLength -= 1;
        pSPI_Handle->pRxBuffer += 1;
    }

    // Close reception
    if (pSPI_Handle->RxLength <= 0 && SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) && !SPI_GetFlagStatus(pSPIx, SPI_FLAG_RXNE))
    {
        pSPIx->CR2 &= ~(1U << SPI_CR2_RXNEIE);
        pSPI_Handle->pRxBuffer = NULL;
        pSPI_Handle->RxLength = 0;
        pSPI_Handle->RxState = SPI_READY;

        SPI_ApplicationEventCallBack(pSPI_Handle, SPI_EVENT_RX_COMPLETE);
    }
}


static void SPI_OVR_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{    
    // Clear OVR flag
    if (pSPI_Handle->TxState != SPI_BUSY_IN_TX)
    {
        SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

        (void)pSPIx->DR;
        (void)pSPIx->SR;

        SPI_ApplicationEventCallBack(pSPI_Handle, SPI_EVENT_OVR_ERROR);
    }
}


__weak void SPI_ApplicationEventCallBack(SPI_Handle_t * pSPI_Handle, uint8_t SPI_AppEventFlag)
{
    (void)pSPI_Handle;
    (void)SPI_AppEventFlag;
}