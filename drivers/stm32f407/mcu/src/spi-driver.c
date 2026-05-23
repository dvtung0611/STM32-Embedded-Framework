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
        pSPIx->DR = *((uint16_t *)(pSPI_Handle->pCurrentTransfer->pTxBuffer));
        pSPI_Handle->pCurrentTransfer->TxLength -= 2;
        pSPI_Handle->pCurrentTransfer->pTxBuffer += 2;
    }
    else
    {
        // 8-bit data frame
        pSPIx->DR = *(pSPI_Handle->pCurrentTransfer->pTxBuffer);
        pSPI_Handle->pCurrentTransfer->TxLength -= 1;
        pSPI_Handle->pCurrentTransfer->pTxBuffer += 1;
    }

    // Close transmission
    if (pSPI_Handle->pCurrentTransfer->TxLength == 0)
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

    pSPI_Handle->pCurrentTransfer->pTxBuffer = NULL;
    pSPI_Handle->pCurrentTransfer->TxLength = 0;
    pSPI_Handle->pCurrentTransfer->TxState = SPI_PERI_STATE_READY;
}


static void SPI_RXNE_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{
    SPI_RegDef_t *pSPIx = pSPI_Handle->pSPIx;

    // Receive data
    if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF))
    {
        // 16-bit data frame
        *((uint16_t *)(pSPI_Handle->pCurrentTransfer->pRxBuffer)) = pSPIx->DR;
        pSPI_Handle->pCurrentTransfer->RxLength -= 2;
        pSPI_Handle->pCurrentTransfer->pRxBuffer += 2;
    }
    else
    {
        // 8-bit data frame
        *(pSPI_Handle->pCurrentTransfer->pRxBuffer) = (uint8_t)(pSPIx->DR);
        pSPI_Handle->pCurrentTransfer->RxLength -= 1;
        pSPI_Handle->pCurrentTransfer->pRxBuffer += 1;
    }

    // Close reception
    if (pSPI_Handle->pCurrentTransfer->RxLength == 0)
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

    pSPI_Handle->pCurrentTransfer->pRxBuffer = NULL;
    pSPI_Handle->pCurrentTransfer->RxLength = 0;
    pSPI_Handle->pCurrentTransfer->RxState = SPI_PERI_STATE_READY;
}


static void SPI_OVR_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{
    // Clear OVR flag
    if (pSPI_Handle->pCurrentTransfer->TxState != SPI_PERI_STATE_BUSY_TX)
    {
        SPI_ClearOVRFlag(pSPI_Handle->pSPIx);
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
    return pSPI_Handle->pCurrentTransfer->TxState == SPI_PERI_STATE_BUSY_TX;
}


uint8_t SPI_IsRxBusy(SPI_Handle_t *pSPI_Handle)
{
    return pSPI_Handle->pCurrentTransfer->RxState == SPI_PERI_STATE_BUSY_RX;
}


void SPI_ClearOVRFlag(SPI_RegDef_t *pSPIx)
{
    (void)pSPIx->DR;
    (void)pSPIx->SR;
}


SPI_FunctionStatus_t SPI_Transmit(SPI_RegDef_t *pSPIx, SPI_Transfer_t *pSPI_Transfer)
{
    if ((READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET) && (pSPI_Transfer->TxLength % 2 == 1))
        return SPI_FUNC_STATUS_ERROR;

    while (pSPI_Transfer->TxLength > 0)
    {
        // Wait until TX buffer is empty (TXE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) == RESET);
        
        // Send data
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame format is selected for transmission
            *((volatile uint16_t *)(&pSPIx->DR)) = *((uint16_t *)(pSPI_Transfer->pTxBuffer));
            pSPI_Transfer->TxLength -= 2;
            pSPI_Transfer->pTxBuffer += 2;
        }
        else
        {
            // 8-bit data frame format is selected for transmission
            *((volatile uint8_t *)(&pSPIx->DR)) = *((uint8_t *)(pSPI_Transfer->pTxBuffer));
            pSPI_Transfer->TxLength -= 1;
            pSPI_Transfer->pTxBuffer += 1;
        }
        
        // Wait until RX buffer is full (not empty) (RXNE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_RXNE) == RESET);
        
        // Read data
        (void)pSPIx->DR;
    }

    // Wait until SPI peripheral transmit and receive everything done
    while (SPI_GetFlagStatus(pSPIx, SPI_SR_BSY) == SET);

    return SPI_FUNC_STATUS_OK;
}


SPI_FunctionStatus_t SPI_Receive(SPI_RegDef_t *pSPIx, SPI_Transfer_t *pSPI_Transfer)
{
    if ((READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET) && (pSPI_Transfer->RxLength % 2 == 1))
        return SPI_FUNC_STATUS_ERROR;

    while (pSPI_Transfer->RxLength > 0)
    {
        // Wait until TX buffer is empty (TXE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) == RESET);
        
        // Send data
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame format is selected for transmission
            *((volatile uint16_t *)(&pSPIx->DR)) = 0xFFFF; // Send dummy frame
        }
        else
        {
            // 8-bit data frame format is selected for transmission
            *((volatile uint8_t *)(&pSPIx->DR)) = 0xFF; // Send dummy frame
        }

        // Wait until RX buffer is full (not empty) (RXNE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_RXNE) == RESET);

        // Read data
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame format is selected for reception
            *((uint16_t *)(pSPI_Transfer->pRxBuffer)) = *((volatile uint16_t *)(&pSPIx->DR));
            pSPI_Transfer->RxLength -= 2;
            pSPI_Transfer->pRxBuffer += 2;
        }
        else
        {
            // 8-bit data frame format is selected for reception
            *((uint8_t *)(pSPI_Transfer->pRxBuffer)) = *((volatile uint8_t *)(&pSPIx->DR));
            pSPI_Transfer->RxLength -= 1;
            pSPI_Transfer->pRxBuffer += 1;
        }
    }

    // Wait until SPI peripheral transmit and receive everything done
    while (SPI_GetFlagStatus(pSPIx, SPI_SR_BSY) == SET);

    return SPI_FUNC_STATUS_OK;
}


SPI_FunctionStatus_t SPI_TransmitReceive(SPI_RegDef_t *pSPIx, SPI_Transfer_t *pSPI_Transfer)
{
    if ((READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET) && 
        ((pSPI_Transfer->TxLength % 2 == 1) || (pSPI_Transfer->RxLength % 2 == 1)))
        return SPI_FUNC_STATUS_ERROR;

    while (pSPI_Transfer->RxLength > 0)
    {
        // Wait until TX buffer is empty (TXE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) == RESET);
        
        // Send data
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame format is selected for transmission
            *((volatile uint16_t *)(&pSPIx->DR)) = *((uint16_t *)(pSPI_Transfer->pTxBuffer));
            pSPI_Transfer->TxLength -= 2;
            pSPI_Transfer->pTxBuffer += 2;
        }
        else
        {
            // 8-bit data frame format is selected for transmission
            *((volatile uint8_t *)(&pSPIx->DR)) = *((uint8_t *)(pSPI_Transfer->pTxBuffer));
            pSPI_Transfer->TxLength -= 1;
            pSPI_Transfer->pTxBuffer += 1;
        }

        // Wait until RX buffer is full (not empty) (RXNE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_RXNE) == RESET);

        // Read data
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame format is selected for reception
            *((uint16_t *)(pSPI_Transfer->pRxBuffer)) = *((volatile uint16_t *)(&pSPIx->DR));
            pSPI_Transfer->RxLength -= 2;
            pSPI_Transfer->pRxBuffer += 2;
        }
        else
        {
            // 8-bit data frame format is selected for reception
            *((uint8_t *)(pSPI_Transfer->pRxBuffer)) = *((volatile uint8_t *)(&pSPIx->DR));
            pSPI_Transfer->RxLength -= 1;
            pSPI_Transfer->pRxBuffer += 1;
        }
    }

    // Wait until SPI peripheral transmit and receive everything done
    while (SPI_GetFlagStatus(pSPIx, SPI_SR_BSY) == SET);

    return SPI_FUNC_STATUS_OK;
}