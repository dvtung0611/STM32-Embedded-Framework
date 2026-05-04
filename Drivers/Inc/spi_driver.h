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

/**
 * @SPI_RESET_REGISTER_VALUE
 */
#define SPI_CR1_RESET_VALUE                 (0x00U)
#define SPI_CR2_RESET_VALUE                 (0x00U)
#define SPI_SR_RESET_VALUE                  (0x02U)
#define SPI_DR_RESET_VALUE                  (0x00U)
#define SPI_CRCPR_RESET_VALUE               (0x07U)
#define SPI_RXCRCR_RESET_VALUE              (0x00U)
#define SPI_TXCRCR_RESET_VALUE              (0x00U)
#define SPI_I2SCFGR_RESET_VALUE             (0x00U)
#define SPI_I2SPR_RESET_VALUE               (0x02U)


/**
 * @SPI_DEVICE_MODE
 */
#define SPI_DEVICE_MODE_SLAVE                   (0U)
#define SPI_DEVICE_MODE_MASTER                  (1U)


/**
 * @SPI_BUS_CONFIG
 */
#define SPI_BUSCONFIG_FULL_DUPLEX               (0U)
#define SPI_BUSCONFIG_HALF_DUPLEX               (1U)
#define SPI_BUSCONFIG_TXONLY                    (2U)
#define SPI_BUSCONFIG_RXONLY                    (3U)


/**
 * @SPI_SCLK_SPEED
 */
#define SPI_SCLK_SPEED_DIV_2                    (0U)
#define SPI_SCLK_SPEED_DIV_4                    (1U)
#define SPI_SCLK_SPEED_DIV_8                    (2U)
#define SPI_SCLK_SPEED_DIV_16                   (3U)
#define SPI_SCLK_SPEED_DIV_32                   (4U)
#define SPI_SCLK_SPEED_DIV_64                   (5U)
#define SPI_SCLK_SPEED_DIV_128                  (6U)
#define SPI_SCLK_SPEED_DIV_256                  (7U)


/**
 * @SPI_DATA_FRAME_FORMAT
 */
#define SPI_DFF_8BITS                           (0U)
#define SPI_DFF_16BITS                          (1U)


/**
 * @SPI_CLOCK_POLARITY
 */
#define SPI_CPOL_LOW                            (0U)
#define SPI_CPOL_HIGH                           (1U)


/**
 * @SPI_CLOCK_PHASE
 */
#define SPI_CPHA_FIRST_CLK                      (0U)
#define SPI_CPHA_SECOND_CLK                     (1U)


/**
 * @SPI_SOFTWARE_SLAVE_MANAGEMENT
 */
#define SPI_SSM_DISABLE                         (0U)
#define SPI_SSM_ENABLE                          (1U)


/* ============================================= Bit Position Definition of SPI Peripheral ============================================= */

/**
 * @SPI_CR1
 */
#define SPI_CR1_CPHA            (0U)    /*!< Clock phase                            | Bit 0 */
#define SPI_CR1_CPOL            (1U)    /*!< Clock polarity                         | Bit 1 */
#define SPI_CR1_MSTR            (2U)    /*!< Master selection                       | Bit 2 */
#define SPI_CR1_BR              (3U)    /*!< Baud rate control                      | Bit 5:3 */
#define SPI_CR1_SPE             (6U)    /*!< SPI enable                             | Bit 6 */
#define SPI_CR1_LSBFIRST        (7U)    /*!< LSB/MSB transmission order             | Bit 7 */
#define SPI_CR1_SSI             (8U)    /*!< Internal slave select                  | Bit 8 */
#define SPI_CR1_SSM             (9U)    /*!< Software slave management              | Bit 9 */
#define SPI_CR1_RXONLY          (10U)   /*!< Receive only                           | Bit 10 */
#define SPI_CR1_DFF             (11U)   /*!< Data frame format                      | Bit 11 */
#define SPI_CR1_CRCNEXT         (12U)   /*!< CRC transfer next                      | Bit 12 */
#define SPI_CR1_CRCEN           (13U)   /*!< Hardware CRC calculation enable        | Bit 13 */
#define SPI_CR1_BIDIOE          (14U)   /*!< Output enable in bidirectional mode    | Bit 14 */
#define SPI_CR1_BIDIMODE        (15U)   /*!< Bidirectional data mode enable         | Bit 15 */


/**
 * @SPI_CR2
 */
#define SPI_CR2_RXDMAEN         (0U)    /*!< Rx buffer DMA enable                   | Bit 0 */
#define SPI_CR2_TXDMAEN         (1U)    /*!< Tx buffer DMA enable                   | Bit 1 */
#define SPI_CR2_SSOE            (2U)    /*!< SS output enable                       | Bit 2 */
#define SPI_CR2_FRF             (4U)    /*!< Frame format (Motorola/TI mode)        | Bit 4 */
#define SPI_CR2_ERRIE           (5U)    /*!< Error interrupt enable                 | Bit 5 */
#define SPI_CR2_RXNEIE          (6U)    /*!< RX buffer not empty interrupt enable   | Bit 6 */
#define SPI_CR2_TXEIE           (7U)    /*!< Tx buffer empty interrupt enable       | Bit 7 */


/**
 * @SPI_SR
 */
#define SPI_SR_RXNE             (0U)    /*!< Receive buffer not empty   | Bit 0 */
#define SPI_SR_TXE              (1U)    /*!< Transmit buffer empty      | Bit 1 */
#define SPI_SR_CHSIDE           (2U)    /*!< Channel side               | Bit 2 */
#define SPI_SR_UDR              (3U)    /*!< Underrun flag              | Bit 3 */
#define SPI_SR_CRCERR           (4U)    /*!< CRC error flag             | Bit 4 */
#define SPI_SR_MODF             (5U)    /*!< Mode fault                 | Bit 5 */
#define SPI_SR_OVR              (6U)    /*!< Overrun flag               | Bit 6 */
#define SPI_SR_BSY              (7U)    /*!< Busy flag                  | Bit 7 */
#define SPI_SR_FRE              (8U)    /*!< Frame format error         | Bit 8 */


/**
 * @SPI_FLAG
 */
#define SPI_FLAG_RXNE           (0U)    /*!< Receive buffer not empty   | Bit 0 */
#define SPI_FLAG_TXE            (1U)    /*!< Transmit buffer empty      | Bit 1 */
#define SPI_FLAG_CHSIDE         (2U)    /*!< Channel side               | Bit 2 */
#define SPI_FLAG_UDR            (3U)    /*!< Underrun flag              | Bit 3 */
#define SPI_FLAG_CRCERR         (4U)    /*!< CRC error flag             | Bit 4 */
#define SPI_FLAG_MODF           (5U)    /*!< Mode fault                 | Bit 5 */
#define SPI_FLAG_OVR            (6U)    /*!< Overrun flag               | Bit 6 */
#define SPI_FLAG_BSY            (7U)    /*!< Busy flag                  | Bit 7 */
#define SPI_FLAG_FRE            (8U)    /*!< Frame format error         | Bit 8 */


/* ================================================== FLAG OF SPI Peripheral ================================================== */

/**
 * @brief SPI configuration structure
 *
 * @note This structure is used to configure SPI peripheral parameters
 *       such as mode, bus configuration, clock speed, data format, and clock polarity/phase.
 */
typedef struct
{
    uint8_t SPI_DeviceMode;     /*!< Device mode selection                          | Possible value: @SPI_DEVICE_MODE */
    uint8_t SPI_BusConfig;      /*!< Bus configuration                              | Possible value: @SPI_BUS_CONFIG */
    uint8_t SPI_SCLKSpeed;      /*!< Serial clock speed (baud rate prescaler)       | Possible value: @SPI_SCLK_SPEED */
    uint8_t SPI_DFF;            /*!< Data frame format                              | Possible value: @SPI_DATA_FRAME_FORMAT */
    uint8_t SPI_CPOL;           /*!< Clock polarity                                 | Possible value: @SPI_CLOCK_POLARITY */
    uint8_t SPI_CPHA;           /*!< Clock phase                                    | Possible value: @SPI_CLOCK_PHASE */
    uint8_t SPI_SSM;            /*!< Software slave management                      | Possible value: @SPI_SOFTWARE_SLAVE_MANAGEMENT */
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

/**
 * @brief Enable or disable clock for SPI peripheral
 *
 * @param pSPIx SPI peripheral base address (e.g. SPI1, SPI2)
 * @param En_or_DI ENABLE or DISABLE macro
 *
 * @note Must enable clock before using SPI registers
 * Refer to:
 * - RM0090 Reference Manual,	Section 7.3.13 RCC APB1 peripheral clock enable register (RCC_APB1ENR)
 *                              Section 7.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)
 */
void SPI_PeriClock_Control(SPI_RegDef_t *pSPIx, uint8_t En_or_DI);


/**
 * @brief Initialize and configure the SPI peripheral
 * 
 * @param pSPI_Handle Pointer to SPI Handle struct containing base address
 *                    and configuration
 * 
 * @details This function configures the SPI peripherals by:
 *          - Select device mode (Master / Slave)
 *          - Select communication mode (Full duplex / Rx-only / Tx-only / Half duplex),
 *            note: Rx-only and Tx-only are Full duplex but ignore other line
 *          - Configure SCLK speed: div 2 / 4 / 8 / 16 / 32 / 64 / 128 / 256
 *          - Configure data frame format: 8-bits / 16-bits
 *          - Configure clock polarity: Clock is LOW / HIGH state when idle
 *          - Configure clock phase: first / second edge
 *          - Configure software slave management: disable / enable
 * This configuration is applied by modifying SPI registers: CR1
 * 
 * @note
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.5 SPI and I2S registers
 */
void SPI_Init(SPI_Handle_t *pSPI_Handle);


/**
 * @brief Reset SPI peripheral to default state
 *
 * @param pSPIx SPI instance (SPI1, SPI2, SPI3)
 *
 * @note This function resets the selected SPI peripheral using RCC reset register.
 *       After reset, all SPI registers return to default values.
 * Refer to:
 * - RM0090 Reference Manual,   Section 7.3.8 RCC APB1 peripheral reset register (RCC_APB1RSTR)
 *                              Section 7.3.9 RCC APB2 peripheral reset register (RCC_APB2RSTR)
 */
void SPI_DeInit(SPI_RegDef_t *pSPIx);


/**
 * @brief Returns the flag status of the SPI peripheral
 * 
 * @param pSPIx SPI instance (SPI1, SPI2, SPI3)
 * @param FlagName Flag name in the SPI_SR (SPI Status Register)
 * 
 * @return uint8_t  Flag status is set or reset
 * 
 * @note
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.5.3 SPI status register (SPI_SR)
 */
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint8_t FlagName);


/**
 * @brief  Transmit data over SPI in blocking mode
 *
 * @param  pSPIx SPI instance (SPI1, SPI2, SPI3)
 * @param  pTxData Pointer to transmit data buffer
 * @param  DataLength Length of data (in bytes)
 *
 * @note This function polls the TXE flag to ensure the transmit buffer is empty
 *       before loading new data into the data register (DR).
 *
 * @warning This is a blocking API.
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxData, uint32_t DataLength);


/**
 * @brief Enable or disable the SPI peripheral
 * 
 * @param pSPIx SPI instance (SPI1, SPI2, SPI3)
 * @param En_or_DI ENABLE or DISABLE macro
 * 
 * @details Set the SPE bit in the SPI_CR1 register:
 *          0: Peripheral disable
 *          1: Peripheral enable
 * 
 * @warning If enable the peripheral before configuring the SPI register.
 *          the configuration won't take effect.
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t En_or_DI);

#endif /* INC_SPI_DRIVER_H_ */