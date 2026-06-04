/**
 * File name: rcc-driver.c
 *
 * Created on: 02/06/2026
 * Author: Van Tung Dinh
 */

#include <stdint.h>
#include "stm32f407xx.h"
#include "rcc-driver.h"


uint16_t AHB_Prescaler[] = {2, 4, 8, 16, 64, 128, 256, 512};
uint8_t APB_Prescaler[] = {2, 4, 8, 16};


/* ====================================================== APIs ====================================================== */

RCC_FunctionStatus_t RCC_PeripheralClockControl(RCC_Peripheral_t peripheral, uint8_t EN_or_DI)
{
    uint32_t bus = ((uint32_t)(peripheral) & RCC_BUS_MASK);
    uint32_t bit_position = ((uint32_t)(peripheral) & RCC_BITPOS_MASK);

    if (EN_or_DI == ENABLE)
    {
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
    }
    else if (EN_or_DI == DISABLE)
    {
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


RCC_SystemClockSource_t RCC_GetSystemClockSource(void)
{
    uint8_t temp = (RCC->CFGR >> RCC_CFGR_SWS_Pos) & 3U;
    return (RCC_SystemClockSource_t)(temp);
}


RCC_PLLClockSource_t RCC_GetPLLClockSource(void)
{
    uint8_t temp = READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Pos);
    return (RCC_PLLClockSource_t)(temp);
}


uint32_t RCC_GetSystemClockFreq(void)
{
    RCC_SystemClockSource_t source = RCC_GetSystemClockSource();
    if (source == RCC_SYSTEM_CLOCK_SOURCE_HSI)
        return 16000000; // 16 Mhz
    else if (source == RCC_SYSTEM_CLOCK_SOURCE_HSE)
        return HSE_VALUE; // define in rcc-driver.h

    uint32_t PLLM = (RCC->PLLCFGR >> RCC_PLLCFGR_PLLM_Pos) & 63U;
    uint32_t PLLN = (RCC->PLLCFGR >> RCC_PLLCFGR_PLLN_Pos) & 511U;
    uint32_t PLLP = 2U * (((RCC->PLLCFGR >> RCC_PLLCFGR_PLLP_Pos) & 3U) + 1);

    uint32_t pll_source = 16000000;

    if (RCC_GetPLLClockSource() == RCC_PLL_CLOCK_SOURCE_HSI)
        pll_source = 16000000;
    else if (RCC_GetPLLClockSource() == RCC_PLL_CLOCK_SOURCE_HSE)
        pll_source = HSE_VALUE;
    
    pll_source = (pll_source * PLLN / PLLM) / PLLP;
    return pll_source;
}


uint32_t RCC_GetHCLKFreq(void)
{
    uint32_t system_clock = RCC_GetSystemClockFreq();
    uint32_t temp = ((RCC->CFGR >> RCC_CFGR_HPRE_Pos) & 15U);

    if (temp <= 7)
        return system_clock;
    
    return system_clock / AHB_Prescaler[temp - 8U];
}


uint32_t RCC_GetPCLK1Freq(void)
{
    uint32_t hclk = RCC_GetHCLKFreq();
    uint32_t temp = ((RCC->CFGR >> RCC_CFGR_PPRE1_Pos) & 7U);

    if (temp <= 3)
        return hclk;

    return hclk / APB_Prescaler[temp - 4U];
}


uint32_t RCC_GetPCLK2Freq(void)
{
    uint32_t hclk = RCC_GetHCLKFreq();
    uint32_t temp = ((RCC->CFGR >> RCC_CFGR_PPRE2_Pos) & 7U);

    if (temp <= 3)
        return hclk;

    return hclk / APB_Prescaler[temp - 4U];
}


uint32_t RCC_GetI2CClockFreq(void)
{
    return RCC_GetPCLK1Freq();
}


uint8_t RCC_IsHSIReady(void)
{
    return READ_BIT(RCC->CR, RCC_CR_HSIRDY_Pos);
}


uint8_t RCC_IsHSEReady(void)
{
    return READ_BIT(RCC->CR, RCC_CR_HSERDY_Pos);
}


uint8_t RCC_IsPLLReady(void)
{
    return READ_BIT(RCC->CR, RCC_CR_PLLRDY_Pos);
}


RCC_FunctionStatus_t RCC_SetSystemClock(RCC_SystemClockSource_t source)
{
    RCC->CFGR &= ~(3U << RCC_CFGR_SW_Pos);
    if (source == RCC_SYSTEM_CLOCK_SOURCE_HSI)
    {
        RCC->CFGR |= (0U << RCC_CFGR_SW_Pos);
        return RCC_FUNC_STATUS_OK;
    }
    else if (source == RCC_SYSTEM_CLOCK_SOURCE_HSE)
    {
        RCC->CFGR |= (1U << RCC_CFGR_SW_Pos);
        return RCC_FUNC_STATUS_OK;
    }
    else if (source == RCC_SYSTEM_CLOCK_SOURCE_PLL)
    {
        RCC->CFGR |= (2U << RCC_CFGR_SW_Pos);
        return RCC_FUNC_STATUS_OK;
    }

    return RCC_FUNC_STATUS_ERROR;
}


RCC_FunctionStatus_t RCC_ClockSourceControl(RCC_SystemClockSource_t source, uint8_t EN_or_DI)
{
    if (EN_or_DI == ENABLE)
    {
        if (source == RCC_SYSTEM_CLOCK_SOURCE_HSI)
        {
            RCC->CR |= (1U << RCC_CR_HSION_Pos);
            return RCC_FUNC_STATUS_OK;
        }
        else if (source == RCC_SYSTEM_CLOCK_SOURCE_HSE)
        {
            RCC->CR |= (1U << RCC_CR_HSEON_Pos);
            return RCC_FUNC_STATUS_OK;
        }
        else if (source == RCC_SYSTEM_CLOCK_SOURCE_PLL)
        {
            RCC->CR |= (1U << RCC_CR_PLLON_Pos);
            return RCC_FUNC_STATUS_OK;
        }
    }
    else if (EN_or_DI == DISABLE)
    {
        if (source == RCC_SYSTEM_CLOCK_SOURCE_HSI)
        {
            RCC->CR &= ~(1U << RCC_CR_HSION_Pos);
            return RCC_FUNC_STATUS_OK;
        }
        else if (source == RCC_SYSTEM_CLOCK_SOURCE_HSE)
        {
            RCC->CR &= ~(1U << RCC_CR_HSEON_Pos);
            return RCC_FUNC_STATUS_OK;
        }
        else if (source == RCC_SYSTEM_CLOCK_SOURCE_PLL)
        {
            RCC->CR &= ~(1U << RCC_CR_PLLON_Pos);
            return RCC_FUNC_STATUS_OK;
        }
    }

    return RCC_FUNC_STATUS_ERROR;
}