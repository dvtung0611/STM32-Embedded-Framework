/**
 * File name: syscalls.c
 *
 * Created on: 13/05/2026
 * Author: Van Tung Dinh
 */

#include <stdint.h>
#include "itm.h"


int _write(int file, char *ptr, int len)
{
    (void)(file);

    char *pData = ptr;

    for (int i = 0; i < len; i += 1)
    {
        ITM_SendChar((uint8_t)(*pData++));
    }
    return len;
}