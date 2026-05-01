/**
 * File name: spi_driver.h
 *
 * Created on: 01/05/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

/* ================================================== INCLUDES ================================================== */

#include "stm32f407xx.h"


/* ================================================== MACROS ================================================== */


/* ================================================== DATA TYPES ================================================== */

/**
 * @brief SPI configuration structure
 *
 * @note This structure is used to configure SPI peripheral parameters
 *       such as mode, bus configuration, clock speed, data format, and clock polarity/phase.
 */
typedef struct
{
    uint8_t SPI_DeviceMode;     /*!< Device mode selection*/
    uint8_t SPI_BusConfig;      /*!< Bus configuration */
    uint8_t SPI_SCLKSpeed;      /*!< Serial clock speed (baud rate prescaler) */
    uint8_t SPI_DFF;            /*!< Data frame format */
    uint8_t SPI_CPOL;           /*!< Clock polarity */
    uint8_t SPI_CPHA;           /*!< Clock phase */
    uint8_t SPI_SSM;            /*!< Software slave management */
} SPI_Config_t;

/**
 * @brief SPI handle structure
 * @note This structure is used to configure and operate SPI peripheral.
 *       It contains base address and configuration parameters.
 */
typedef struct 
{
    __IO SPI_RegDef_t *pSPIx;       /*!< Base address of SPI peripheral (e.g. SPI1, SPI2, SPI3)*/
    SPI_Config_t SPI_Config;        /*!< SPI configuration settings */
} SPI_Handle_t;


/* ================================================== APIs ================================================== */


#endif /* INC_SPI_DRIVER_H_ */