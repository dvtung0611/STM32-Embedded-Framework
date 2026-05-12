/**
 * File name: string.h
 *
 * Created on: 12/05/2026
 * Author: Van Tung Dinh
 */

#ifndef STRING_H
#define STRING_H

/* ================================================== INCLUDES ================================================== */

#include <stdint.h>


/* ================================================== APIs ================================================== */

/**
 * @brief  Fill a block of memory with a specified value
 *
 * @param  ptr      Pointer to the starting memory address
 * @param  value    Value to be written into memory (byte value)
 * @param  size     Number of bytes to fill
 *
 * @return Pointer to the filled memory block
 *
 * @note This function writes the specified value byte-by-byte
 *       into the memory region starting at ptr.
 */
void *memset(void *ptr, int32_t value, uint32_t size);


/**
 * @brief  Copy a block of memory from source to destination
 *
 * @param dest Pointer to the destination memory address
 * @param src  Pointer to the source memory address
 * @param size Number of bytes to copy
 *
 * @return Pointer to the destination memory block
 *
 * @note This function copies data byte-by-byte from the source
 *       memory region to the destination memory region.
 *
 * @warning Source and destination memory regions must not overlap.
 *          Use memmove() for overlapping memory regions.
 */
void *memcpy(void *dest, const void *src, uint32_t size);


#endif /* STRING_H_ */