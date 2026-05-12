/**
 * File name: string.c
 *
 * Created on: 12/05/2026
 * Author: Van Tung Dinh
 */

/* ================================================== INCLUDES ================================================== */

#include <stdint.h>
#include "string.h"


/* ================================================== APIs ================================================== */

void *memset(void *ptr, int32_t value, uint32_t size)
{
    uint8_t *p = (uint8_t *)(ptr);
    
    while (size--)
    {
        *p = (uint8_t)(value);
        p++;
    }

    return ptr;
}


void *memcpy(void *dest, const void *src, uint32_t size)
{
    uint8_t *pdest = (uint8_t *)(dest);
    const uint8_t *psrc = (uint8_t *)(src);

    while (size--)
    {
        *pdest = *psrc;
        pdest++;
        psrc++;
    }

    return dest;
}