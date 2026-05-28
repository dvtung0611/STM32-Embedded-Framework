/**
 * File name: spi-driver.c
 *
 * Created on: 01/05/2026
 * Author: Van Tung Dinh
 */

#include "stm32f407xx.h"
#include "spi-driver.h"


static uint32_t SPI_GetPendingInterrupts(SPI_RegDef_t *pSPIx);

static uint8_t SPI_TXE_InterruptActive(SPI_RegDef_t *pSPIx);
static uint8_t SPI_RXNE_InterruptActive(SPI_RegDef_t *pSPIx);
static uint8_t SPI_OVR_InterruptActive(SPI_RegDef_t *pSPIx);

static void SPI_TXE_InterruptHandle(SPI_Handle_t *pSPI_Handle);
static void SPI_RXNE_InterruptHandle(SPI_Handle_t *pSPI_Handle);
static void SPI_OVR_InterruptHandle(SPI_Handle_t *pSPI_Handle);

static void SPI_CloseTxRx(SPI_Handle_t *pSPI_Handle);

static void SPI_ClearOVRFlag(SPI_RegDef_t *pSPIx);

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
        SET_BIT(pSPIx->CR1, SPI_CR1_BIDIMODE);
        CLEAR_BIT(pSPIx->CR1, SPI_CR1_RXONLY);
        // TX mode: BIDIOE = 1
        // RX mode: BIDIOE = 0
        // Direction controlled at runtime
    }
    else if (BusConfig == SPI_BUSCONFIG_SIMPLEX_RX) // 2-line receive-only
    {
        CLEAR_BIT(pSPIx->CR1, SPI_CR1_BIDIMODE);
        SET_BIT(pSPIx->CR1, SPI_CR1_RXONLY);
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
        SET_BIT(pSPIx->CR1, SPI_CR1_SPE);
    else if (EN_or_DI == DISABLE)
        CLEAR_BIT(pSPIx->CR1, SPI_CR1_SPE);
}


void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t SE_or_CL)
{
    if (SE_or_CL == SET)
        SET_BIT(pSPIx->CR1, SPI_CR1_SSI);
    else if (SE_or_CL == CLEAR)
        CLEAR_BIT(pSPIx->CR1, SPI_CR1_SSI);
}


void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t SE_or_CL)
{
    if (SE_or_CL == SET)
        SET_BIT(pSPIx->CR2, SPI_CR2_SSOE);
    else if (SE_or_CL == CLEAR)
        CLEAR_BIT(pSPIx->CR2, SPI_CR2_SSOE);
}


static uint8_t SPI_TXE_InterruptActive(SPI_RegDef_t *pSPIx)
{
    return READ_BIT(pSPIx->SR, SPI_SR_TXE) & READ_BIT(pSPIx->CR2, SPI_CR2_TXEIE);
}


static uint8_t SPI_RXNE_InterruptActive(SPI_RegDef_t *pSPIx)
{
    return READ_BIT(pSPIx->SR, SPI_SR_RXNE) & READ_BIT(pSPIx->CR2, SPI_CR2_RXNEIE);
}


static uint8_t SPI_OVR_InterruptActive(SPI_RegDef_t *pSPIx)
{
    return READ_BIT(pSPIx->SR, SPI_SR_OVR) & READ_BIT(pSPIx->CR2, SPI_CR2_ERRIE);
}


static uint32_t SPI_GetPendingInterrupts(SPI_RegDef_t *pSPIx)
{
    uint32_t events = 0;

    if (SPI_TXE_InterruptActive(pSPIx))
        events |= SPI_IRQ_EVENT_TXE;
    
    if (SPI_RXNE_InterruptActive(pSPIx))
        events |= SPI_IRQ_EVENT_RXNE;
    
    if (SPI_OVR_InterruptActive(pSPIx))
        events |= SPI_IRQ_EVENT_ERROR_OVR;
    
    return events;
}


void SPI_IRQHandling(SPI_Handle_t *pSPI_Handle)
{
    uint32_t events = SPI_GetPendingInterrupts(pSPI_Handle->pSPIx);

    if (events & SPI_IRQ_EVENT_ERROR_OVR)
        SPI_OVR_InterruptHandle(pSPI_Handle);
    
    if (events & SPI_IRQ_EVENT_RXNE)
        SPI_RXNE_InterruptHandle(pSPI_Handle);
    
    if (events & SPI_IRQ_EVENT_TXE)
        SPI_TXE_InterruptHandle(pSPI_Handle);
}


static void SPI_TXE_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{
    // Transmit dummy data
    if (pSPI_Handle->Mode == SPI_TRANSFER_MODE_RECEIVE_ONLY)
    {
        if (pSPI_Handle->CurrentTransfer.RxLength > 0)
        {
            if (READ_BIT(pSPI_Handle->pSPIx->CR1, SPI_CR1_DFF) == SET)
                *((volatile uint16_t *)(&pSPI_Handle->pSPIx->DR)) = (uint16_t)(0xFFFF);
            else
                *((volatile uint8_t *)(&pSPI_Handle->pSPIx->DR)) = (uint8_t)(0xFF);
        }
        return;
    }

    // Transmit true data
    if (pSPI_Handle->CurrentTransfer.TxLength > 0)
    {
        if (READ_BIT(pSPI_Handle->pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame
            *((volatile uint16_t *)(&pSPI_Handle->pSPIx->DR)) = *((uint16_t *)(pSPI_Handle->CurrentTransfer.pTxBuffer));
            pSPI_Handle->CurrentTransfer.TxLength -= 2;
            pSPI_Handle->CurrentTransfer.pTxBuffer += 2;
        }
        else
        {
            // 8-bit data frame
            *((volatile uint8_t *)(&pSPI_Handle->pSPIx->DR)) = *((uint8_t *)(pSPI_Handle->CurrentTransfer.pTxBuffer));
            pSPI_Handle->CurrentTransfer.TxLength -= 1;
            pSPI_Handle->CurrentTransfer.pTxBuffer += 1;
        }
    }
    
    if (pSPI_Handle->CurrentTransfer.TxLength == 0)
    {
        CLEAR_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_TXEIE);
        pSPI_Handle->CurrentTransfer.TxDone = SET;

        if (pSPI_Handle->Mode == SPI_TRANSFER_MODE_TRANSMIT_ONLY)
            pSPI_Handle->State = SPI_PERI_STATE_WAIT_CLOSE;
    }
}


static void SPI_RXNE_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{
    // Receive dummy data
    if (pSPI_Handle->Mode == SPI_TRANSFER_MODE_TRANSMIT_ONLY)
    {
        (void)(pSPI_Handle->pSPIx->DR);
        return;
    }

    // Receive true data
    if (pSPI_Handle->CurrentTransfer.RxLength > 0)
    {
        if (READ_BIT(pSPI_Handle->pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame
            *((uint16_t *)(pSPI_Handle->CurrentTransfer.pRxBuffer)) = *((volatile uint16_t *)(&pSPI_Handle->pSPIx->DR));
            pSPI_Handle->CurrentTransfer.RxLength -= 2;
            pSPI_Handle->CurrentTransfer.pRxBuffer += 2;
        }
        else
        {
            // 8-bit data frame
            *((uint8_t *)(pSPI_Handle->CurrentTransfer.pRxBuffer)) = *((volatile uint8_t *)(&pSPI_Handle->pSPIx->DR));
            pSPI_Handle->CurrentTransfer.RxLength -= 1;
            pSPI_Handle->CurrentTransfer.pRxBuffer += 1;
        }
    }
    
    if (pSPI_Handle->CurrentTransfer.RxLength == 0)
    {
        CLEAR_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_RXNEIE);
        CLEAR_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_TXEIE);
        pSPI_Handle->CurrentTransfer.RxDone = SET;
        pSPI_Handle->State = SPI_PERI_STATE_WAIT_CLOSE;
    }
}


SPI_FunctionStatus_t SPI_FinalProcess(SPI_Handle_t *pSPI_Handle)
{
    if (pSPI_Handle->State == SPI_PERI_STATE_WAIT_CLOSE)
    {
        if (SPI_GetFlagStatus(pSPI_Handle->pSPIx, SPI_FLAG_BSY) == CLEAR)
        {
            if (pSPI_Handle->CurrentTransfer.TxDone == SET && pSPI_Handle->CurrentTransfer.RxDone == SET)
            {
                SPI_CloseTxRx(pSPI_Handle);
                SPI_ApplicationEventCallBack(pSPI_Handle, SPI_APP_EVENT_TX_RX_COMPLETE);
                return SPI_FUNC_STATUS_OK;
            }
            else if (pSPI_Handle->CurrentTransfer.TxDone == SET)
            {
                SPI_CloseTxRx(pSPI_Handle);
                SPI_ApplicationEventCallBack(pSPI_Handle, SPI_APP_EVENT_TX_COMPLETE);
                return SPI_FUNC_STATUS_OK;
            }
            else if (pSPI_Handle->CurrentTransfer.RxDone == SET)
            {
                SPI_CloseTxRx(pSPI_Handle);
                SPI_ApplicationEventCallBack(pSPI_Handle, SPI_APP_EVENT_RX_COMPLETE);
                return SPI_FUNC_STATUS_OK;
            }
            
            return SPI_FUNC_STATUS_ERROR;
        }
    }

    return SPI_FUNC_STATUS_BUSY;
}


static void SPI_CloseTxRx(SPI_Handle_t *pSPI_Handle)
{
    CLEAR_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_RXNEIE);
    CLEAR_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_TXEIE);
    CLEAR_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_ERRIE);

    pSPI_Handle->CurrentTransfer.pTxBuffer = NULL;
    pSPI_Handle->CurrentTransfer.TxLength = 0;
    pSPI_Handle->CurrentTransfer.pRxBuffer = NULL;
    pSPI_Handle->CurrentTransfer.RxLength = 0;
    pSPI_Handle->CurrentTransfer.TxDone = CLEAR;
    pSPI_Handle->CurrentTransfer.RxDone = CLEAR;
    pSPI_Handle->Mode = SPI_TRANSFER_MODE_NONE;
    pSPI_Handle->State = SPI_PERI_STATE_READY;
}


static void SPI_OVR_InterruptHandle(SPI_Handle_t *pSPI_Handle)
{
    SPI_ClearOVRFlag(pSPI_Handle->pSPIx);

    CLEAR_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_RXNEIE);
    CLEAR_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_TXEIE);
    CLEAR_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_ERRIE);

    pSPI_Handle->State = SPI_PERI_STATE_ERROR;
    pSPI_Handle->Error = SPI_PERI_ERROR_OVR;

    SPI_ApplicationEventCallBack(pSPI_Handle, SPI_APP_EVENT_ERROR_OVR);
}


static void SPI_ClearOVRFlag(SPI_RegDef_t *pSPIx)
{
    (void)pSPIx->DR;
    (void)pSPIx->SR;
}


__weak void SPI_ApplicationEventCallBack(SPI_Handle_t *pSPI_Handle, SPI_AppEvent_t SPI_AppEventFlag)
{
    (void)(pSPI_Handle);
    (void)(SPI_AppEventFlag);
}


SPI_FunctionStatus_t SPI_TransmitIT(SPI_Handle_t *pSPI_Handle, uint8_t *pTxBuffer, uint32_t TxLength)
{
    if (pSPI_Handle == NULL || pTxBuffer == NULL || TxLength == 0)
        return SPI_FUNC_STATUS_INVALID_PARAMETER;
    
    if (pSPI_Handle->SPI_Config.SPI_DFF == SPI_DFF_16BITS && TxLength % 2 == 1)
        return SPI_FUNC_STATUS_INVALID_PARAMETER;
    
    if (pSPI_Handle->State != SPI_PERI_STATE_READY)
        return SPI_FUNC_STATUS_BUSY;

    pSPI_Handle->CurrentTransfer.pTxBuffer = pTxBuffer;
    pSPI_Handle->CurrentTransfer.TxLength = TxLength;
    pSPI_Handle->CurrentTransfer.pRxBuffer = NULL;
    pSPI_Handle->CurrentTransfer.RxLength = 0;
    pSPI_Handle->CurrentTransfer.TxDone = CLEAR;
    pSPI_Handle->CurrentTransfer.RxDone = CLEAR;

    pSPI_Handle->Mode = SPI_TRANSFER_MODE_TRANSMIT_ONLY;
    pSPI_Handle->State = SPI_PERI_STATE_BUSY_TX;

    // Enable ERROR interrupt
    SET_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_ERRIE);

    // Enable RXNE interrupt
    SET_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_RXNEIE);

    // Enable TXE interrupt
    SET_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_TXEIE);

    return SPI_FUNC_STATUS_OK;
}


SPI_FunctionStatus_t SPI_ReceiveIT(SPI_Handle_t *pSPI_Handle, uint8_t *pRxBuffer, uint32_t RxLength)
{
    if (pSPI_Handle == NULL || pRxBuffer == NULL || RxLength == 0)
        return SPI_FUNC_STATUS_INVALID_PARAMETER;
    
    if (pSPI_Handle->SPI_Config.SPI_DFF == SPI_DFF_16BITS && RxLength % 2 == 1)
        return SPI_FUNC_STATUS_INVALID_PARAMETER;
    
    if (pSPI_Handle->State != SPI_PERI_STATE_READY)
        return SPI_FUNC_STATUS_BUSY;

    pSPI_Handle->CurrentTransfer.pTxBuffer = NULL;
    pSPI_Handle->CurrentTransfer.TxLength = 0;
    pSPI_Handle->CurrentTransfer.pRxBuffer = pRxBuffer;
    pSPI_Handle->CurrentTransfer.RxLength = RxLength;
    pSPI_Handle->CurrentTransfer.TxDone = CLEAR;
    pSPI_Handle->CurrentTransfer.RxDone = CLEAR;

    pSPI_Handle->Mode = SPI_TRANSFER_MODE_RECEIVE_ONLY;
    pSPI_Handle->State = SPI_PERI_STATE_BUSY_RX;

    // Enable ERROR interrupt
    SET_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_ERRIE);

    // Enable RXNE interrupt
    SET_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_RXNEIE);

    // Enable TXE interrupt
    SET_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_TXEIE);

    return SPI_FUNC_STATUS_OK;
}


SPI_FunctionStatus_t SPI_TransmitReceiveIT(SPI_Handle_t *pSPI_Handle, uint8_t *pTxBuffer, uint32_t TxLength, uint8_t *pRxBuffer, uint32_t RxLength)
{
    if (pSPI_Handle == NULL || pTxBuffer == NULL || TxLength == 0 || pRxBuffer == NULL || RxLength == 0 || TxLength != RxLength)
        return SPI_FUNC_STATUS_INVALID_PARAMETER;
    
    if (pSPI_Handle->SPI_Config.SPI_DFF == SPI_DFF_16BITS && (TxLength % 2 == 1 || RxLength % 2 == 1))
        return SPI_FUNC_STATUS_INVALID_PARAMETER;
    
    if (pSPI_Handle->State != SPI_PERI_STATE_READY)
        return SPI_FUNC_STATUS_BUSY;

    pSPI_Handle->CurrentTransfer.pTxBuffer = pTxBuffer;
    pSPI_Handle->CurrentTransfer.TxLength = TxLength;
    pSPI_Handle->CurrentTransfer.pRxBuffer = pRxBuffer;
    pSPI_Handle->CurrentTransfer.RxLength = RxLength;
    pSPI_Handle->CurrentTransfer.TxDone = CLEAR;
    pSPI_Handle->CurrentTransfer.RxDone = CLEAR;

    pSPI_Handle->Mode = SPI_TRANSFER_MODE_TRANSMIT_RECEIVE;
    pSPI_Handle->State = SPI_PERI_STATE_BUSY_TX_RX;

    // Enable ERROR interrupt
    SET_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_ERRIE);

    // Enable RXNE interrupt
    SET_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_RXNEIE);

    // Enable TXE interrupt
    SET_BIT(pSPI_Handle->pSPIx->CR2, SPI_CR2_TXEIE);

    return SPI_FUNC_STATUS_OK;
}


SPI_FunctionStatus_t SPI_Transmit(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t TxLength)
{
    if ((READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET) && (TxLength % 2 == 1))
        return SPI_FUNC_STATUS_INVALID_PARAMETER;

    while (TxLength > 0)
    {
        // Wait until TX buffer is empty (TXE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) == CLEAR);
        
        // Send data
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame format is selected for transmission
            *((volatile uint16_t *)(&pSPIx->DR)) = *((uint16_t *)(pTxBuffer));
            TxLength -= 2;
            pTxBuffer += 2;
        }
        else
        {
            // 8-bit data frame format is selected for transmission
            *((volatile uint8_t *)(&pSPIx->DR)) = *((uint8_t *)(pTxBuffer));
            TxLength -= 1;
            pTxBuffer += 1;
        }
        
        // Wait until RX buffer is full (not empty) (RXNE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_RXNE) == CLEAR);
        
        // Read data
        (void)pSPIx->DR;
    }

    // Wait until SPI peripheral transmit and receive everything done
    while (SPI_GetFlagStatus(pSPIx, SPI_SR_BSY) == SET);

    return SPI_FUNC_STATUS_OK;
}


SPI_FunctionStatus_t SPI_Receive(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t RxLength)
{
    if ((READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET) && (RxLength % 2 == 1))
        return SPI_FUNC_STATUS_INVALID_PARAMETER;

    while (RxLength > 0)
    {
        // Wait until TX buffer is empty (TXE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) == CLEAR);
        
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
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_RXNE) == CLEAR);

        // Read data
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame format is selected for reception
            *((uint16_t *)(pRxBuffer)) = *((volatile uint16_t *)(&pSPIx->DR));
            RxLength -= 2;
            pRxBuffer += 2;
        }
        else
        {
            // 8-bit data frame format is selected for reception
            *((uint8_t *)(pRxBuffer)) = *((volatile uint8_t *)(&pSPIx->DR));
            RxLength -= 1;
            pRxBuffer += 1;
        }
    }

    // Wait until SPI peripheral transmit and receive everything done
    while (SPI_GetFlagStatus(pSPIx, SPI_SR_BSY) == SET);

    return SPI_FUNC_STATUS_OK;
}


SPI_FunctionStatus_t SPI_TransmitReceive(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t TxLength, uint8_t *pRxBuffer, uint32_t RxLength)
{
    if ((READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET) && ((TxLength % 2 == 1) || (RxLength % 2 == 1)))
        return SPI_FUNC_STATUS_INVALID_PARAMETER;
    if (TxLength != RxLength)
        return SPI_FUNC_STATUS_INVALID_PARAMETER;

    while (RxLength > 0)
    {
        // Wait until TX buffer is empty (TXE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_TXE) == CLEAR);
        
        // Send data
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame format is selected for transmission
            *((volatile uint16_t *)(&pSPIx->DR)) = *((uint16_t *)(pTxBuffer));
            TxLength -= 2;
            pTxBuffer += 2;
        }
        else
        {
            // 8-bit data frame format is selected for transmission
            *((volatile uint8_t *)(&pSPIx->DR)) = *((uint8_t *)(pTxBuffer));
            TxLength -= 1;
            pTxBuffer += 1;
        }

        // Wait until RX buffer is full (not empty) (RXNE = SET)
        while (SPI_GetFlagStatus(pSPIx, SPI_FLAG_RXNE) == CLEAR);

        // Read data
        if (READ_BIT(pSPIx->CR1, SPI_CR1_DFF) == SET)
        {
            // 16-bit data frame format is selected for reception
            *((uint16_t *)(pRxBuffer)) = *((volatile uint16_t *)(&pSPIx->DR));
            RxLength -= 2;
            pRxBuffer += 2;
        }
        else
        {
            // 8-bit data frame format is selected for reception
            *((uint8_t *)(pRxBuffer)) = *((volatile uint8_t *)(&pSPIx->DR));
            RxLength -= 1;
            pRxBuffer += 1;
        }
    }

    // Wait until SPI peripheral transmit and receive everything done
    while (SPI_GetFlagStatus(pSPIx, SPI_SR_BSY) == SET);

    return SPI_FUNC_STATUS_OK;
}