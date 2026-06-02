/**
 * File name: rcc-driver.c
 *
 * Created on: 02/06/2026
 * Author: Van Tung Dinh
 */

#include <stdint.h>
#include "stm32f407xx.h"
#include "rcc-driver.h"

/* ====================================================== APIs ====================================================== */

RCC_FunctionStatus_t RCC_EnablePeripheralClock(RCC_Peripheral_t peripheral)
{
    uint32_t bus = ((uint32_t)(peripheral) & RCC_BUS_MASK);
    uint32_t bit_position = ((uint32_t)(peripheral) & RCC_BITPOS_MASK);

    if (bus == RCC_BUS_AHB1)
    {
        RCC->AHB1ENR |= (1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_AHB2)
    {
        RCC->AHB2ENR |= (1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_AHB3)
    {
        RCC->AHB3ENR |= (1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_APB1)
    {
        RCC->APB1ENR |= (1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_APB2)
    {
        RCC->APB2ENR |= (1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }

    return RCC_FUNC_STATUS_ERROR;
}


RCC_FunctionStatus_t RCC_DisablePeripheralClock(RCC_Peripheral_t peripheral)
{
    uint32_t bus = ((uint32_t)(peripheral) & RCC_BUS_MASK);
    uint32_t bit_position = ((uint32_t)(peripheral) & RCC_BITPOS_MASK);

    if (bus == RCC_BUS_AHB1)
    {
        RCC->AHB1ENR &= ~(1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_AHB2)
    {
        RCC->AHB2ENR &= ~(1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_AHB3)
    {
        RCC->AHB3ENR &= ~(1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_APB1)
    {
        RCC->APB1ENR &= ~(1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_APB2)
    {
        RCC->APB2ENR &= ~(1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }

    return RCC_FUNC_STATUS_ERROR;
}


RCC_FunctionStatus_t RCC_ResetPeripheral(RCC_Peripheral_t peripheral)
{
    uint32_t bus = ((uint32_t)(peripheral) & RCC_BUS_MASK);
    uint32_t bit_position = ((uint32_t)(peripheral) & RCC_BITPOS_MASK);

    if (bus == RCC_BUS_AHB1)
    {
        RCC->AHB1RSTR |= (1U << bit_position);
        RCC->AHB1RSTR &= ~(1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_AHB2)
    {
        RCC->AHB2RSTR |= (1U << bit_position);
        RCC->AHB2RSTR &= ~(1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_AHB3)
    {
        RCC->AHB3RSTR |= (1U << bit_position);
        RCC->AHB3RSTR &= ~(1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_APB1)
    {
        RCC->APB1RSTR |= (1U << bit_position);
        RCC->APB1RSTR &= ~(1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }
    else if (bus == RCC_BUS_APB2)
    {
        RCC->APB2RSTR |= (1U << bit_position);
        RCC->APB2RSTR &= ~(1U << bit_position);
        return RCC_FUNC_STATUS_OK;
    }

    return RCC_FUNC_STATUS_ERROR;
}