/**
 * File name: itm.h
 *
 * Created on: 17/05/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_ITM_H_
#define INC_ITM_H_

#include <stdint.h>


/* ===================================================== MACROS ===================================================== */

#define ITM_STIM0               (*(volatile uint32_t *)(0xE0000000U))
#define ITM_TER                 (*(volatile uint32_t *)(0xE0000E00U))


/* =================================================== FUNCTIONS ==================================================== */

/**
 * @brief Send a character through ITM Stimulus Port 0
 *
 * @param ch Character to be transmitted
 *
 * @note This function is typically used for SWO/SWV debugging output
 *       via the Instrumentation Trace Macrocell (ITM).
 *       Data is sent only if ITM stimulus port 0 is enabled.
 *
 * @warning This is a blocking function because it waits until the
 *          stimulus port becomes ready before writing data.
 */
void ITM_SendChar(uint8_t ch);


#endif /* INC_ITM_H_ */