/**
 * File name: tiny-string.h
 *
 * Created on: 12/05/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_TINY_STRING_H
#define INC_TINY_STRING_H

#include <stdint.h>


/**
 * @brief Fill a block of memory with a specified value
 *
 * @param ptr   Pointer to the starting memory address
 * @param value Value to be written into memory (byte value)
 * @param num   Number of bytes to fill
 *
 * @return Pointer to the filled memory block
 *
 * @note This function writes the specified value byte-by-byte
 *       into the memory region starting at ptr.
 */
void *memset(void *ptr, int value, size_t num);


/**
 * @brief Copy a block of memory from source to destination
 *
 * @param dest Pointer to the destination memory address
 * @param src  Pointer to the source memory address
 * @param num  Number of bytes to copy
 *
 * @return Pointer to the destination memory block
 *
 * @note This function copies data byte-by-byte from the source
 *       memory region to the destination memory region.
 *
 * @warning Source and destination memory regions must not overlap.
 *          Use memmove() for overlapping memory regions.
 */
void *memcpy(void *dest, const void *src, size_t num);


#endif /* INC_TINY_STRING_H */