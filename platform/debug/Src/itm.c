/**
 * File name: itm.c
 *
 * Created on: 17/05/2026
 * Author: Van Tung Dinh
 */

#include <stdint.h>
#include "itm.h"


/* =================================================== FUNCTIONS ==================================================== */

void ITM_SendChar(uint8_t ch)
{
    if (ITM_TER & 1U)
    {
        while (ITM_STIM0 == 0U);
        ITM_STIM0 = ch;
    }
}