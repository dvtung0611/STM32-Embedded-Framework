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
    
    while (size > 0)
    {
        *p = (uint8_t)(value);
        p++;
        size--;
    }
    
    return ptr;
}