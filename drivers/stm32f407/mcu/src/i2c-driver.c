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

I2C_FunctionStatus_t I2C_PeriClock_Control(I2C_RegDef_t *pI2Cx, uint8_t EN_or_DI)
{
    if (EN_or_DI == ENABLE)
    {
        if (pI2Cx == I2C1)
        {
            RCC_EnablePeripheralClock(RCC_PERIPHERAL_I2C1);
            return I2C_FUNC_STATUS_OK;
        }
        else if (pI2Cx == I2C2)
        {
            RCC_EnablePeripheralClock(RCC_PERIPHERAL_I2C2);
            return I2C_FUNC_STATUS_OK;
        }
        else if (pI2Cx == I2C3)
        {
            RCC_EnablePeripheralClock(RCC_PERIPHERAL_I2C3);
            return I2C_FUNC_STATUS_OK;
        }
    }
    else if (EN_or_DI == DISABLE)
    {
        if (pI2Cx == I2C1)
        {
            RCC_DisablePeripheralClock(RCC_PERIPHERAL_I2C1);
            return I2C_FUNC_STATUS_OK;
        }
        else if (pI2Cx == I2C2)
        {
            RCC_DisablePeripheralClock(RCC_PERIPHERAL_I2C2);
            return I2C_FUNC_STATUS_OK;
        }
        else if (pI2Cx == I2C3)
        {
            RCC_DisablePeripheralClock(RCC_PERIPHERAL_I2C3);
            return I2C_FUNC_STATUS_OK;
        }
    }

    return I2C_FUNC_STATUS_ERROR;
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
        pI2Cx->CR1 |= (1U << I2C_CR1_PE);
        return I2C_FUNC_STATUS_OK;
    }
    else if (EN_or_DI == DISABLE)
    {
        pI2Cx->CR1 &= ~(1U << I2C_CR1_PE);
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