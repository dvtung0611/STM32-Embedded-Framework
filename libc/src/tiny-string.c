/**
 * File name: tiny-string.c
 *
 * Created on: 12/05/2026
 * Author: Van Tung Dinh
 */

#include <stdint.h>
#include <stddef.h>
#include "tiny-string.h"


void *memset(void *ptr, int value, size_t num)
{
    uint8_t *p = (uint8_t *)(ptr);
    
    while (num--)
    {
        *p++ = (uint8_t)(value);
    }

    return ptr;
}


void *memcpy(void *dest, const void *src, size_t num)
{
    uint8_t *pdest = (uint8_t *)(dest);
    const uint8_t *psrc = (const uint8_t *)(src);

    while (num--)
    {
        *pdest++ = *psrc++;
    }

    return dest;
}