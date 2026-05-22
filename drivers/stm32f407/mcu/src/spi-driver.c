/**
 * File name: spi-driver.c
 *
 * Created on: 01/05/2026
 * Author: Van Tung Dinh
 */

#include "stm32f407xx.h"
#include "spi-driver.h"


static void SPI_TXE_InterruptHandle(SPI_Handle_t *pSPI_Handle);
static void SPI_CloseTransmission(SPI_Handle_t *pSPI_Handle);

static void SPI_RXNE_InterruptHandle(SPI_Handle_t *pSPI_Handle);
static void SPI_CloseReception(SPI_Handle_t *pSPI_Handle);

static void SPI_OVR_InterruptHandle(SPI_Handle_t *pSPI_Handle);

static uint8_t SPI_IsTXEInterruptActive(SPI_Handle_t *pSPI_Handle);
static uint8_t SPI_IsRXNEInterruptActive(SPI_Handle_t *pSPI_Handle);
static uint8_t SPI_IsOVRInterruptActive(SPI_Handle_t *pSPI_Handle);

static uint32_t SPI_GetPendingEvents(SPI_Handle_t *pSPI_Handle);


/* ====================================================== APIs ====================================================== */

void SPI_PeriClock_Control(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI)
{
    if (EN_or_DI == ENABLE)
    {
        if (pSPIx == SPI1)
            SPI1_PCLK_EN();
        else if (pSPIx == SPI2)
            SPI2_PCLK_EN();
        else if (pSPIx == SPI3)
            SPI3_PCLK_EN();
    }
    else if (EN_or_DI == DISABLE)
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
    SPI_DeviceMode_t DeviceMode = pSPI_Handle->SPI_Config.SPI_DeviceMode;
    SPI_BusConfig_t BusConfig = pSPI_Handle->SPI_Config.SPI_BusConfig;
    SPI_SCLKSpeed_t SCLKSpeed = pSPI_Handle->SPI_Config.SPI_SCLKSpeed;
    SPI_DFF_t DFF = pSPI_Handle->SPI_Config.SPI_DFF;
    SPI_CPOL_t CPOL = pSPI_Handle->SPI_Config.SPI_CPOL;
    SPI_CPHA_t CPHA = pSPI_Handle->SPI_Config.SPI_CPHA;
    SPI_SSM_t SSM = pSPI_Handle->SPI_Config.SPI_SSM;

    // Enable clock for the SPI peripheral
    SPI_PeriClock_Control(pSPIx, ENABLE);

    // Reset the SPI Control Register 1
    pSPIx->CR1 = SPI_CR1_RESET_VALUE;

    // Configure the device mode
    pSPIx->CR1 |= (DeviceMode << SPI_CR1_MSTR);

    // Configure the communication mode
    if (BusConfig == SPI_BUSCONFIG_FULL_DUPLEX) // 2-line full duplex
    {
        CLEAR_BIT(pSPIx->CR1, SPI_CR1_BIDIMODE);
        CLEAR_BIT(pSPIx->CR1, SPI_CR1_RXONLY);
    }
    else if (BusConfig == SPI_BUSCONFIG_HALF_DUPLEX) // 1-line half duplex
    {
        WRITE_BIT(pSPIx->CR1, SPI_CR1_BIDIMODE);
        CLEAR_BIT(pSPIx->CR1, SPI_CR1_RXONLY);
        // TX mode: BIDIOE = 1
        // RX mode: BIDIOE = 0
        // Direction controlled at runtime
    }
    else if (BusConfig == SPI_BUSCONFIG_SIMPLEX_RX) // 2-line receive-only
    {
        CLEAR_BIT(pSPIx->CR1, SPI_CR1_BIDIMODE);
        WRITE_BIT(pSPIx->CR1, SPI_CR1_RXONLY);
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


SPI_FunctionStatus_t SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t DataLength)
{
    if ((pTxBuffer == NULL) || (DataLength == 0))
        return SPI_FUNC_STATUS_INVALID_PARAMETER;

    while (DataLength > 0)
    {
        // Wait until TXE is set (Tx buffer is empty)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) == RESET);

        // Check DFF (Data Frame Format)
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF))
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

    return SPI_FUNC_STATUS_OK;
}


SPI_FunctionStatus_t SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t DataLength)
{
    if ((pRxBuffer == NULL) || (DataLength == 0))
        return SPI_FUNC_STATUS_INVALID_PARAMETER;
    
    while (DataLength > 0)
    {
        // Wait until RXNE is set (Rx buffer is not empty = Rx buffer is full)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_RXNE) == RESET);

        // Check DFF (Data Frame Format)
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF))
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

    return SPI_FUNC_STATUS_OK;
}


void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI)
{
    if (EN_or_DI == ENABLE)
        WRITE_BIT(pSPIx->CR1, SPI_CR1_SPE);
    else if (EN_or_DI == DISABLE)
        CLEAR_BIT(pSPIx->CR1, SPI_CR1_SPE);
}


void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI)
{
    if (EN_or_DI == SET)
        WRITE_BIT(pSPIx->CR1, SPI_CR1_SSI);
    else if (EN_or_DI == RESET)
        CLEAR_BIT(pSPIx->CR1, SPI_CR1_SSI);
}


void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI)
{
    if (EN_or_DI == SET)
        WRITE_BIT(pSPIx->CR2, SPI_CR2_SSOE);
    else if (EN_or_DI == RESET)
        CLEAR_BIT(pSPIx->CR2, SPI_CR2_SSOE);
}


SPI_FunctionStatus_t SPI_SendDataIT(SPI_Handle_t *pSPI_Handle, uint8_t *pTxBuffer, uint32_t DataLength)
{
    if ((pSPI_Handle == NULL) || (pTxBuffer == NULL) || (DataLength == 0))
        return SPI_FUNC_STATUS_INVALID_PARAMETER;
    else if (pSPI_Handle->TxState != SPI_PERI_STATE_READY)
        return SPI_FUNC_STATUS_BUSY;
    
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

    // Save TX buffer pointer and transfer length
    pSPI_Handle->pTxBuffer = pTxBuffer;
    pSPI_Handle->TxLength = DataLength;

    // Set BUSY_IN_TX
    pSPI_Handle->TxState = SPI_PERI_STATE_BUSY_TX;

    // Enable ERRIE bit
    WRITE_BIT(pSPIx->CR2, SPI_CR2_ERRIE);

    // Enable TXEIE bit
    WRITE_BIT(pSPIx->CR2, SPI_CR2_TXEIE);

    return SPI_FUNC_STATUS_OK;
}


SPI_FunctionStatus_t SPI_ReceiveDataIT(SPI_Handle_t *pSPI_Handle, uint8_t *pRxBuffer, uint32_t DataLength)
{
    if ((pSPI_Handle == NULL) || (pRxBuffer == NULL) || (DataLength == 0))
        return SPI_FUNC_STATUS_INVALID_PARAMETER;
    else if (pSPI_Handle->RxState != SPI_PERI_STATE_READY)
        return SPI_FUNC_STATUS_BUSY;

    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

    // Save RX buffer pointer and transfer length
    pSPI_Handle->pRxBuffer = pRxBuffer;
    pSPI_Handle->RxLength = DataLength;

    // Set BUSY_IN_RX
    pSPI_Handle->RxState = SPI_PERI_STATE_BUSY_RX;

    // Enable ERRIE bit
    WRITE_BIT(pSPIx->CR2, SPI_CR2_ERRIE);

    // Enable RXNEIE bit
    WRITE_BIT(pSPIx->CR2, SPI_CR2_RXNEIE);

    return SPI_FUNC_STATUS_OK;
}


static uint8_t SPI_IsTXEInterruptActive(SPI_Handle_t *pSPI_Handle)
{
    return READ_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_TXEIE) & READ_BIT(pSPI_Handle->pSPIx->SR, SPI_SR_TXE);
}


static uint8_t SPI_IsRXNEInterruptActive(SPI_Handle_t *pSPI_Handle)
{
    return READ_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_RXNEIE) & READ_BIT(pSPI_Handle->pSPIx->SR, SPI_SR_RXNE);
}


static uint8_t SPI_IsOVRInterruptActive(SPI_Handle_t *pSPI_Handle)
{
    return READ_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_ERRIE) & READ_BIT(pSPI_Handle->pSPIx->SR, SPI_SR_OVR);
}


uint32_t SPI_GetPendingEvents(SPI_Handle_t *pSPI_Handle)
{
    uint32_t events = 0;

    if (SPI_IsTXEInterruptActive(pSPI_Handle))
        events |= SPI_IRQ_EVENT_TXE;
    
    if (SPI_IsRXNEInterruptActive(pSPI_Handle))
        events |= SPI_IRQ_EVENT_RXNE;
    
    if (SPI_IsOVRInterruptActive(pSPI_Handle))
        events |= SPI_IRQ_EVENT_OVR;
    
    return events;
}


void SPI_IRQHandling(SPI_Handle_t *pSPI_Handle)
{
    uint32_t events = SPI_GetPendingEvents(pSPI_Handle);

    if (events & SPI_IRQ_EVENT_TXE)
        SPI_TXE_InterruptHandle(pSPI_Handle);
    
    if (events & SPI_IRQ_EVENT_RXNE)
        SPI_RXNE_InterruptHandle(pSPI_Handle);

    if (events & SPI_IRQ_EVENT_OVR)
        SPI_OVR_InterruptHandle(pSPI_Handle);
}


static void SPI_TXE_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

    // Transmit data
    if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF))
    {
        // 16-bit data frame
        pSPIx->DR = *((uint16_t *)(pSPI_Handle->pTxBuffer));
        pSPI_Handle->TxLength -= 2;
        pSPI_Handle->pTxBuffer += 2;
    }
    else
    {
        // 8-bit data frame
        pSPIx->DR = *(pSPI_Handle->pTxBuffer);
        pSPI_Handle->TxLength -= 1;
        pSPI_Handle->pTxBuffer += 1;
    }

    // Close transmission
    if (pSPI_Handle->TxLength == 0)
    {
        SPI_CloseTransmission(pSPI_Handle);
        SPI_ApplicationEventCallBack(pSPI_Handle, SPI_APP_EVENT_TX_COMPLETE);
    }
}


static void SPI_CloseTransmission(SPI_Handle_t *pSPI_Handle)
{
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

    // Disable TXE interrupt
    CLEAR_BIT(pSPIx->CR2, SPI_CR2_TXEIE);

    pSPI_Handle->pTxBuffer = NULL;
    pSPI_Handle->TxLength = 0;
    pSPI_Handle->TxState = SPI_PERI_STATE_READY;
}


static void SPI_RXNE_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

    // Receive data
    if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF))
    {
        // 16-bit data frame
        *((uint16_t *)(pSPI_Handle->pRxBuffer)) = pSPIx->DR;
        pSPI_Handle->RxLength -= 2;
        pSPI_Handle->pRxBuffer += 2;
    }
    else
    {
        // 8-bit data frame
        *(pSPI_Handle->pRxBuffer) = (uint8_t)(pSPIx->DR);
        pSPI_Handle->RxLength -= 1;
        pSPI_Handle->pRxBuffer += 1;
    }

    // Close reception
    if (pSPI_Handle->RxLength == 0)
    {
        SPI_CloseReception(pSPI_Handle);
        SPI_ApplicationEventCallBack(pSPI_Handle, SPI_APP_EVENT_RX_COMPLETE);
    }
}


static void SPI_CloseReception(SPI_Handle_t *pSPI_Handle)
{
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

    // Disable RXNE interrupt
    CLEAR_BIT(pSPIx->CR2, SPI_CR2_RXNEIE);

    pSPI_Handle->pRxBuffer = NULL;
    pSPI_Handle->RxLength = 0;
    pSPI_Handle->RxState = SPI_PERI_STATE_READY;
}


static void SPI_OVR_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{
    // Clear OVR flag
    if (pSPI_Handle->TxState != SPI_PERI_STATE_BUSY_TX)
    {
        SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;
        (void)pSPIx->DR;
        (void)pSPIx->SR;

        SPI_ApplicationEventCallBack(pSPI_Handle, SPI_APP_EVENT_OVR_ERROR);
    }
}


__weak void SPI_ApplicationEventCallBack(SPI_Handle_t *pSPI_Handle, SPI_AppEvent_t SPI_AppEventFlag)
{
    (void)pSPI_Handle;
    (void)SPI_AppEventFlag;
}


uint8_t SPI_IsTxBusy(SPI_Handle_t *pSPI_Handle)
{
    return pSPI_Handle->TxState == SPI_PERI_STATE_BUSY_TX;
}


uint8_t SPI_IsRxBusy(SPI_Handle_t *pSPI_Handle)
{
    return pSPI_Handle->RxState == SPI_PERI_STATE_BUSY_RX;
}