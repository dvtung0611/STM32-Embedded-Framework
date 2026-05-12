/**
 * File name: string.h
 *
 * Created on: 12/05/2026
 * Author: Van Tung Dinh
 */

#ifndef STRING_H
#define STRING_H

/**
 * @brief  Fill a block of memory with a specified value
 *
 * @param  ptr   Pointer to the starting memory address
 * @param  value Value to be written into memory (byte value)
 * @param  size   Number of bytes to fill
 *
 * @return Pointer to the filled memory block
 *
 * @note This function writes the specified value byte-by-byte
 *       into the memory region starting at ptr.
 */
void *memset(void *ptr, int value, unsigned int size);

#endif /* STRING_H_ */