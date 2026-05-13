/**
 * File name: syscalls.c
 *
 * Created on: 13/05/2026
 * Author: Van Tung Dinh
 */

/* ================================================== INCLUDES ================================================== */

#include <stdint.h>


/* ================================================== MACROS ================================================== */

#define ITM_STIM0               (*(volatile uint32_t *)(0xE0000000U))
#define ITM_TER                 (*(volatile uint32_t *)(0xE0000E00U))


/* ================================================== FUNCTIONS ================================================== */

static inline void ITM_SendChar(uint8_t ch)
{
    if (ITM_TER & 1U)
    {
        while (ITM_STIM0 == 0U);
        ITM_STIM0 = ch;
    }
}


int _write(int file, char *ptr, int len)
{
    (void)(file);

    char *pData = ptr;
    for (int i = 0; i < len; i += 1)
    {
        ITM_SendChar((uint8_t)(*pData));
        pData++;
    }
    return len;
}