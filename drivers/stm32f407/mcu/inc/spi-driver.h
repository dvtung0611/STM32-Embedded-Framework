/**
 * File name: spi-driver.h
 *
 * Created on: 01/05/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

#include <stdint.h>
#include "stm32f407xx.h"


/* ===================================================== MACROS ===================================================== */

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
typedef enum
{
    SPI_DEVICE_MODE_SLAVE = 0U,
    SPI_DEVICE_MODE_MASTER
} SPI_DeviceMode_t;


/**
 * @SPI_BUS_CONFIG
 */
typedef enum
{
    SPI_BUSCONFIG_FULL_DUPLEX = 0U,
    SPI_BUSCONFIG_HALF_DUPLEX,
    SPI_BUSCONFIG_SIMPLEX_RX
} SPI_BusConfig_t;


/**
 * @SPI_SCLK_SPEED
 */
typedef enum
{
    SPI_SCLK_SPEED_DIV_2 = 0U,
    SPI_SCLK_SPEED_DIV_4,
    SPI_SCLK_SPEED_DIV_8,
    SPI_SCLK_SPEED_DIV_16,
    SPI_SCLK_SPEED_DIV_32,
    SPI_SCLK_SPEED_DIV_64,
    SPI_SCLK_SPEED_DIV_128,
    SPI_SCLK_SPEED_DIV_256
} SPI_SCLKSpeed_t;


/**
 * @SPI_DATA_FRAME_FORMAT
 */
typedef enum
{
    SPI_DFF_8BITS = 0U,
    SPI_DFF_16BITS
} SPI_DFF_t;


/**
 * @SPI_CLOCK_POLARITY
 */
typedef enum
{
    SPI_CPOL_LOW = 0U,
    SPI_CPOL_HIGH
} SPI_CPOL_t;


/**
 * @SPI_CLOCK_PHASE
 */
typedef enum
{
    SPI_CPHA_FIRST_CLK = 0U,
    SPI_CPHA_SECOND_CLK
} SPI_CPHA_t;


/**
 * @SPI_SOFTWARE_SLAVE_MANAGEMENT
 */
typedef enum
{
    SPI_SSM_DISABLE = 0U,
    SPI_SSM_ENABLE
} SPI_SSM_t;


/**
 * @SPI_PERIPHERAL_STATE
 */
typedef enum
{
    SPI_PERI_STATE_READY = 0U,
    SPI_PERI_STATE_BUSY_RX,
    SPI_PERI_STATE_BUSY_TX
} SPI_PeripheralState_t;


/**
 * @SPI_FUNCTION_STATUS
 */
typedef enum
{
    SPI_FUNC_STATUS_OK = 0U,
    SPI_FUNC_STATUS_BUSY,
    SPI_FUNC_STATUS_ERROR,
    SPI_FUNC_STATUS_INVALID_PARAMETER
} SPI_FunctionStatus_t;


/**
 * @SPI_IRQ_EVENT
 */
typedef enum
{
    SPI_IRQ_EVENT_NONE = 1U,
    SPI_IRQ_EVENT_TXE = 2U,
    SPI_IRQ_EVENT_RXNE = 4U,
    SPI_IRQ_EVENT_OVR = 8U,
} SPI_IRQEvent_t;


/**
 * @SPI_APP_EVENT
 */
typedef enum
{
    SPI_APP_EVENT_TX_COMPLETE = 0U,
    SPI_APP_EVENT_RX_COMPLETE,
    SPI_APP_EVENT_OVR_ERROR
} SPI_AppEvent_t;


/* ================================================== BIT POSITION ================================================== */

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


/* ===================================================== FLAGS ====================================================== */

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


/* =================================================== STRUCTURES =================================================== */

/**
 * @brief SPI configuration structure
 *
 * @note This structure is used to configure SPI peripheral parameters
 *       such as mode, bus configuration, clock speed, data format, and clock polarity/phase.
 */
typedef struct
{
    SPI_DeviceMode_t SPI_DeviceMode;    /*!< Device mode selection                          | Possible value: @SPI_DEVICE_MODE */
    SPI_BusConfig_t SPI_BusConfig;      /*!< Bus configuration                              | Possible value: @SPI_BUS_CONFIG */
    SPI_SCLKSpeed_t SPI_SCLKSpeed;      /*!< Serial clock speed (baud rate prescaler)       | Possible value: @SPI_SCLK_SPEED */
    SPI_DFF_t SPI_DFF;                  /*!< Data frame format                              | Possible value: @SPI_DATA_FRAME_FORMAT */
    SPI_CPOL_t SPI_CPOL;                /*!< Clock polarity                                 | Possible value: @SPI_CLOCK_POLARITY */
    SPI_CPHA_t SPI_CPHA;                /*!< Clock phase                                    | Possible value: @SPI_CLOCK_PHASE */
    SPI_SSM_t SPI_SSM;                  /*!< Software slave management                      | Possible value: @SPI_SOFTWARE_SLAVE_MANAGEMENT */
} SPI_Config_t;


/**
 * @brief SPI handle structure
 * 
 * @note This structure is used to configure and operate SPI peripheral.
 *       It contains base address and configuration parameters.
 */
typedef struct
{
    SPI_RegDef_t *pSPIx;                    /*!< Base address of SPI peripheral (e.g. SPI1, SPI2, SPI3)*/
    SPI_Config_t SPI_Config;                /*!< SPI configuration settings */

    uint8_t *pTxBuffer;                     /*!< Pointer to TX buffer application data */
    uint8_t *pRxBuffer;                     /*!< Pointer to RX buffer application data */

    __IO uint32_t TxLength;                 /*!< Number of bytes remaining to transmit */
    __IO uint32_t RxLength;                 /*!< Number of bytes remaining to receive */

    __IO SPI_PeripheralState_t TxState;     /*!< Current TX transfer state */
    __IO SPI_PeripheralState_t RxState;     /*!< Current RX transfer state */
} SPI_Handle_t;


/* ====================================================== APIs ====================================================== */

/**
 * @brief Enable or disable clock for SPI peripheral
 * 
 * @param pSPIx    SPI peripheral base address (e.g. SPI1, SPI2)
 * @param EN_or_DI ENABLE or DISABLE macro
 * 
 * @note Must enable clock before using SPI registers
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Section 7.3.13 RCC APB1 peripheral clock enable register (RCC_APB1ENR)
 *                              Section 7.3.14 RCC APB2 peripheral clock enable register (RCC_APB2ENR)
 */
void SPI_PeriClock_Control(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI);


/**
 * @brief Initialize and configure the SPI peripheral
 * 
 * @param pSPI_Handle Pointer to SPI Handle struct
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
 *
 *          This configuration is applied by modifying SPI registers: CR1
 * 
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.5 SPI and I2S registers
 */
void SPI_Init(SPI_Handle_t *pSPI_Handle);


/**
 * @brief Reset SPI peripheral to default state
 * 
 * @param pSPIx SPI peripheral base address (e.g. SPI1, SPI2)
 * 
 * @note This function resets the selected SPI peripheral using RCC reset register.
 *       After reset, all SPI registers return to default values.
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 7.3.8 RCC APB1 peripheral reset register (RCC_APB1RSTR)
 *                              Section 7.3.9 RCC APB2 peripheral reset register (RCC_APB2RSTR)
 */
void SPI_DeInit(SPI_RegDef_t *pSPIx);


/**
 * @brief Returns the flag status of the SPI peripheral
 * 
 * @param pSPIx    SPI peripheral base address (e.g. SPI1, SPI2)
 * @param FlagName Flag name in the SPI_SR (SPI Status Register) | @SPI_FLAG
 * 
 * @return uint8_t Flag status is set or reset
 * 
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.5.3 SPI status register (SPI_SR)
 */
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint8_t FlagName);


/**
 * @brief Transmit data over SPI in blocking mode
 * 
 * @param pSPIx      SPI peripheral base address (e.g. SPI1, SPI2)
 * @param pTxBuffer  Pointer to transmit data buffer
 * @param DataLength Length of data (in bytes)
 * 
 * @return SPI_FunctionStatus_t SPI function status value
 * 
 * @note This function polls the TXE flag to ensure the transmit buffer is empty
 *       before loading new data into the data register (DR).
 * 
 * @warning This is a blocking API.
 */
SPI_FunctionStatus_t SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t DataLength);


/**
 * @brief Receive data over SPI in blocking mode
 * 
 * @param pSPIx      SPI peripheral base address (e.g. SPI1, SPI2)
 * @param pRxBuffer  Pointer to receive data buffer
 * @param DataLength Length of data (in bytes)
 * 
 * @return SPI_FunctionStatus_t SPI function status value
 * 
 * @note This function polls the RXNE flag (Receive buffer Not Empty)
 *       to check when data is available in the data register (DR).
 *       The received data is then read from DR into the buffer.
 * 
 *       In SPI, data reception is coupled with transmission.
 *       Clock must be generated (typically by sending dummy data)
 *       to receive data from the slave.
 * 
 * @warning This is a blocking API.
 */
SPI_FunctionStatus_t SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t DataLength);


/**
 * @brief Enable or disable the SPI peripheral
 * 
 * @param pSPIx    SPI peripheral base address (e.g. SPI1, SPI2)
 * @param EN_or_DI ENABLE or DISABLE macro
 * 
 * @details Set the SPE bit in the SPI_CR1 register:
 *          0: Peripheral disable
 *          1: Peripheral enable
 * 
 * @note 
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.5.1 SPI control register 1 (SPI_CR1)
 * 
 * @warning If enable the peripheral before configuring the SPI register.
 *          the configuration won't take effect.
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI);


/**
 * @brief Configure the SSI (Internal Slave Select) bit for the SPI peripheral
 * 
 * @param pSPIx    SPI peripheral base address (e.g. SPI1, SPI2)
 * @param EN_or_DI SET or RESET macro
 * 
 * @details This function sets or clears the SSI bit in the SPI_CR1 register.
 *          The SSI bit is used in master mode to control the internal 
 *          slave select signal when SSM (Software Slave Management) is enabled.
 *          0: SSI low (slave not selected)
 *          1: SSI high (slave selected)
 * 
 * @note This function should be called only when SSM is enabled in the SPI configuration.
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.5.1 SPI control register 1 (SPI_CR1)
 */
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI);


/**
 * @brief Configure the SSOE (SS output enable) bit for the SPI peripheral
 * 
 * @param pSPIx    SPI peripheral base address (e.g. SPI1, SPI2)
 * @param EN_or_DI SET or RESET macro
 * 
 * @details This function sets or clears the SSOE bit in the SPI_CR2 register.
 *          The SSOE bit is used only in master mode when hardware slave 
 *          management (SSM = 0) is selected.
 * 
 *          0: NSS output is disabled. The NSS pin is not driven by the SPI 
 *             peripheral and can be used for multi-master configurations or 
 *             controlled manually via GPIO.
 * 
 *          1: NSS output is enabled. When the SPI is enabled (SPE = 1), the 
 *             NSS pin is automatically driven LOW. When SPI is disabled 
 *             (SPE = 0), NSS is released HIGH. This allows the SPI hardware 
 *             to manage the NSS signal automatically.
 * 
 * @note In slave mode, NSS is always used as input and SSOE hasn't effect.
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.3.1 General description
 *                              Section 28.5.2 SPI control register 2 (SPI_CR2)         
 */
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI);


/**
 * @brief Send data over SPI using interrupt mode (non-blocking API)
 * 
 * @param pSPI_Handle Pointer to SPI handle structure
 * @param pTxBuffer   Pointer to transmit data buffer
 * @param DataLength  Length of data to transmit (in bytes)
 * 
 * @return SPI_FunctionStatus_t SPI function status value | @SPI_FUNCTION_STATUS
 * 
 * @details This API performs the following operations:
 *          - Save TX buffer pointer and transfer length
 *          - Set SPI state to SPI_BUSY_IN_TX
 *          - Enable TXE interrupt (TXEIE bit)
 * 
 * @note This function returns immediately after enabling the interrupt.
 *       Actual data transmission is handled inside the SPI ISR.
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.5.2 SPI control register 2 (SPI_CR2)
 */
SPI_FunctionStatus_t SPI_SendDataIT(SPI_Handle_t *pSPI_Handle, uint8_t *pTxBuffer, uint32_t DataLength);


/**
 * @brief Receive data over SPI using interrupt mode (non-blocking API)
 * 
 * @param pSPI_Handle Pointer to the SPI handle structure
 * @param pRxBuffer   Pointer to the receive data buffer
 * @param DataLength  Length of data to receive (in bytes)
 * 
 * @return SPI_FunctionStatus_t SPI function status value | @SPI_FUNCTION_STATUS
 * 
 * @details This API performs the following operations:
 *          - Saves RX buffer pointer and transfer length
 *          - Sets SPI state to SPI_BUSY_IN_RX
 *          - Enables RXNE interrupt (RXNEIE bit)
 * 
 * @note This function returns immediately after enabling the interrupt.
 *       Actual data reception is handled inside the SPI ISR.
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.5.2 SPI control register 2 (SPI_CR2)
 */
SPI_FunctionStatus_t SPI_ReceiveDataIT(SPI_Handle_t *pSPI_Handle, uint8_t *pRxBuffer, uint32_t DataLength);


/**
 * @brief Handle SPI interrupt events
 * 
 * @param pSPI_Handle Pointer to SPI handle structure
 * 
 * @details This function checks and handles SPI interrupt sources:
 *          - TXE  : Transmit buffer empty interrupt
 *          - RXNE : Receive buffer not empty interrupt
 *          - OVR  : Overrun error interrupt
 * 
 *          For each interrupt source:
 *          1. Check the corresponding status flag in SPI_SR register
 *          2. Check whether the interrupt is enabled in SPI_CR2 register
 *          3. Call the appropriate internal interrupt handler
 * 
 *          Internal handlers:
 *          - SPI_TXE_InterruptHandle()
 *          - SPI_RXNE_InterruptHandle()
 *          - SPI_OVR_InterruptHandle()
 * 
 * @note This function should be called inside the actual SPI IRQ handler
 *       implemented in the application layer.
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.5.2 SPI control register 2 (SPI_CR2)
 *                              Section 28.5.3 SPI status register (SPI_SR)
 */
void SPI_IRQHandling(SPI_Handle_t *pSPI_Handle);


/**
 * @brief Application callback function for SPI events
 * 
 * @param pSPI_Handle      Pointer to SPI handle structure
 * @param SPI_AppEventFlag SPI application event source | @SPI_APP_EVENT
 * 
 * @details This callback function is executed by the SPI driver when
 *          an interrupt event occurs during non-blocking communication.
 *          The user application should implement this function to handle
 *          SPI events.
 * 
 * @note This function is declared as __weak inside the driver source file,
 *       allowing the application to override it with a custom implementation.
 */
void SPI_ApplicationEventCallBack(SPI_Handle_t *pSPI_Handle, SPI_AppEvent_t SPI_AppEventFlag);


/**
 * @brief Check whether SPI transmission is busy
 * 
 * @param pSPI_Handle Pointer to SPI handle structure
 * 
 * @return uint8_t 0: SPI Tx is idle
 *                 1: SPI Tx is busy transmitting
 */
uint8_t SPI_IsTxBusy(SPI_Handle_t *pSPI_Handle);


/**
 * @brief Check whether SPI reception is busy
 * 
 * @param pSPI_Handle Pointer to SPI handle structure
 * 
 * @return uint8_t 0: SPI Rx is idle
 *                 1: SPI Rx is busy receiving
 */
uint8_t SPI_IsRxBusy(SPI_Handle_t *pSPI_Handle);


#endif /* INC_SPI_DRIVER_H_ */