/**
 * File name: i2c-driver.c
 *
 * Created on: 31/05/2026
 * Author: Van Tung Dinh
 */

#include <stdint.h>
#include "stm32f407xx.h"
#include "i2c-driver.h"
#include "rcc-driver.h"


/* ====================================================== APIs ====================================================== */

I2C_FunctionStatus_t I2C_PeripheralClockControl(I2C_RegDef_t *pI2Cx, uint8_t EN_or_DI)
{
    if (pI2Cx == I2C1)
    {
        RCC_PeripheralClockControl(RCC_PERIPHERAL_I2C1, EN_or_DI);
        return I2C_FUNC_STATUS_OK;
    }
    else if (pI2Cx == I2C2)
    {
        RCC_PeripheralClockControl(RCC_PERIPHERAL_I2C2, EN_or_DI);
        return I2C_FUNC_STATUS_OK;
    }
    else if (pI2Cx == I2C3)
    {
        RCC_PeripheralClockControl(RCC_PERIPHERAL_I2C3, EN_or_DI);
        return I2C_FUNC_STATUS_OK;
    }

    return I2C_FUNC_STATUS_ERROR;
}


I2C_FunctionStatus_t I2C_Init(I2C_Handle_t *pI2C_Handle)
{
    if (pI2C_Handle == NULL)
        return I2C_FUNC_STATUS_INVALID_PARAMETER;
    
    I2C_RegDef_t *pI2Cx = pI2C_Handle->pI2Cx;
    I2C_ACKControl_t ACKControl = pI2C_Handle->I2C_Config.I2C_ACKControl;
    I2C_AddressMode_t AddressMode = pI2C_Handle->I2C_Config.I2C_AddressMode;
    I2C_DualAddress_t DualAddressMode = pI2C_Handle->I2C_Config.I2C_DualAddressMode;
    uint16_t DeviceAddress = pI2C_Handle->I2C_Config.I2C_DeviceAddress;
    uint16_t SecondaryAddress = pI2C_Handle->I2C_Config.I2C_SecondaryAddress;
    I2C_SCLSpeed_t SCLSpeed = pI2C_Handle->I2C_Config.I2C_SCLSpeed;
    I2C_FMDutyCycle_t FMDutyCycle = pI2C_Handle->I2C_Config.I2C_FMDutyCycle;
    I2C_ClockStretch_t ClockStretch = pI2C_Handle->I2C_Config.I2C_ClockStretch;
    I2C_GeneralCall_t GeneralCall = pI2C_Handle->I2C_Config.I2C_GeneralCall;
    
    // Enable clock for the I2C peripheral
    I2C_PeripheralClockControl(pI2Cx, ENABLE);

    // Configure ACK
    if (ACKControl == I2C_ACK_CONTROL_ENABLE)
        pI2Cx->CR1 |= (1U << I2C_CR1_ACK_Pos);
    else if (ACKControl == I2C_ACK_CONTROL_DISABLE)
        pI2Cx->CR1 &= ~(1U << I2C_CR1_ACK_Pos);
    else
        return I2C_FUNC_STATUS_INVALID_PARAMETER;

    // Configure address mode (7 or 10 bits) and dual address mode
    pI2Cx->OAR1 &= ~(1023U << I2C_OAR1_ADD10_Pos);
    pI2Cx->OAR1 |= (1U << 14); // Bit 14 should always be kept at 1 by software (RM0090 Reference Manual)
    if (AddressMode == I2C_ADDRESS_MODE_7BIT)
    {
        pI2Cx->OAR1 |= (DeviceAddress << I2C_OAR1_ADD7_Pos);
        pI2Cx->OAR1 &= ~(1U << I2C_OAR1_ADDMODE_Pos);

        if (DualAddressMode == I2C_DUAL_ADDRESS_MODE_ENABLE)
        {
            pI2Cx->OAR2 &= ~(127U << I2C_OAR2_ADD2_Pos);
            pI2Cx->OAR2 |= (SecondaryAddress << I2C_OAR2_ADD2_Pos);
            pI2Cx->OAR2 |= (1U << I2C_OAR2_ENDUAL_Pos);
        }
        else if (DualAddressMode == I2C_DUAL_ADDRESS_MODE_DISABLE)
        {
            pI2Cx->OAR2 &= ~(127U << I2C_OAR2_ADD2_Pos);
            pI2Cx->OAR2 &= ~(1U << I2C_OAR2_ENDUAL_Pos);
        }
        else
            return I2C_FUNC_STATUS_INVALID_PARAMETER;
    }
    else if (AddressMode == I2C_ADDRESS_MODE_10BIT)
    {
        pI2Cx->OAR1 |= (DeviceAddress << I2C_OAR1_ADD10_Pos);
        pI2Cx->OAR1 |= (1U << I2C_OAR1_ADDMODE_Pos);
    }
    else
        return I2C_FUNC_STATUS_INVALID_PARAMETER;
    
    // Configure the FREQ field
    uint32_t freq = (RCC_GetI2CClockFreq() / 1000000U);
    pI2Cx->CR2 &= ~(63U << I2C_CR2_FREQ_Pos);
    pI2Cx->CR2 |= (freq << I2C_CR2_FREQ_Pos);

    // CCR calculations
    pI2Cx->CCR &= ~(4095U << I2C_CCR_CCR_Pos);
    uint32_t f_pclk1 = RCC_GetPCLK1Freq();
    uint32_t ccr_value = 0;

    if (SCLSpeed == I2C_SCL_SPEED_STANDARD_MODE)
    {
        pI2Cx->CCR &= ~(1U << I2C_CCR_FS_Pos);

        ccr_value = f_pclk1 / SCLSpeed / 2;
    }
    else if (SCLSpeed == I2C_SCL_SPEED_FAST_MODE_200K || SCLSpeed == I2C_SCL_SPEED_FAST_MODE_400K)
    {
        pI2Cx->CCR |= (1U << I2C_CCR_FS_Pos);

        if (FMDutyCycle == I2C_FM_DUTY_CYCLE_2)
        {
            pI2Cx->CCR &= ~(1U << I2C_CCR_DUTY_Pos);
            ccr_value = f_pclk1 / SCLSpeed / 3;
        }
        else if (FMDutyCycle == I2C_FM_DUTY_CYCLE_16_9)
        {
            pI2Cx->CCR |= (1U << I2C_CCR_DUTY_Pos);
            ccr_value = f_pclk1 / SCLSpeed / 25;
        }
        else
            return I2C_FUNC_STATUS_INVALID_PARAMETER;
    }
    else
        return I2C_FUNC_STATUS_INVALID_PARAMETER;

    pI2Cx->CCR |= (ccr_value << I2C_CCR_CCR_Pos);

    // Configure general call
    if (GeneralCall == I2C_GENERAL_CALL_DISABLE)
        pI2Cx->CR1 &= ~(1U << I2C_CR1_ENGC_Pos);
    else if (GeneralCall == I2C_GENERAL_CALL_ENABLE)
        pI2Cx->CR1 |= (1U << I2C_CR1_ENGC_Pos);
    else
        return I2C_FUNC_STATUS_INVALID_PARAMETER;
    
    // Configure clock stretching
    if (ClockStretch == I2C_CLOCK_STRETCH_DISABLE)
        pI2Cx->CR1 |= (1U << I2C_CR1_NOSTRETCH_Pos);
    else if (ClockStretch == I2C_CLOCK_STRETCH_ENABLE)
        pI2Cx->CR1 &= ~(1U << I2C_CR1_NOSTRETCH_Pos);
    else
        return I2C_FUNC_STATUS_INVALID_PARAMETER;
    
    return I2C_FUNC_STATUS_OK;
}


I2C_FunctionStatus_t I2C_DeInit(I2C_RegDef_t *pI2Cx)
{
    if (pI2Cx == I2C1)
    {
        RCC_ResetPeripheral(RCC_PERIPHERAL_I2C1);
        return I2C_FUNC_STATUS_OK;
    }
    else if (pI2Cx == I2C2)
    {
        RCC_ResetPeripheral(RCC_PERIPHERAL_I2C2);
        return I2C_FUNC_STATUS_OK;
    }
    else if (pI2Cx == I2C3)
    {
        RCC_ResetPeripheral(RCC_PERIPHERAL_I2C3);
        return I2C_FUNC_STATUS_OK;
    }
    
    return I2C_FUNC_STATUS_ERROR;
}


I2C_FunctionStatus_t I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t EN_or_DI)
{
    if (EN_or_DI == ENABLE)
    {
        pI2Cx->CR1 |= (1U << I2C_CR1_PE_Pos);
        return I2C_FUNC_STATUS_OK;
    }
    else if (EN_or_DI == DISABLE)
    {
        pI2Cx->CR1 &= ~(1U << I2C_CR1_PE_Pos);
        return I2C_FUNC_STATUS_OK;
    }

    return I2C_FUNC_STATUS_ERROR;
}


uint8_t I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx, uint8_t FlagName)
{
    uint16_t SR1_or_SR2 = FlagName >> 16U;
    uint16_t flag_position = FlagName & 0xFFFF;

    if (SR1_or_SR2 == 1U)
        return ((pI2Cx->SR1 >> flag_position) & 1U);
    else if (SR1_or_SR2 == 2U)
        return ((pI2Cx->SR2 >> flag_position) & 1U);
    
    return 0;
}


I2C_FunctionStatus_t I2C_ACKConfig(I2C_RegDef_t *pI2Cx, uint8_t EN_or_DI)
{
    if (EN_or_DI == ENABLE)
    {
        pI2Cx->CR1 |= (1U << I2C_CR1_ACK_Pos);
        return I2C_FUNC_STATUS_OK;
    }
    else if (EN_or_DI == DISABLE)
    {
        pI2Cx->CR1 &= ~(1U << I2C_CR1_ACK_Pos);
        return I2C_FUNC_STATUS_OK;
    }

    return I2C_FUNC_STATUS_ERROR;
}


