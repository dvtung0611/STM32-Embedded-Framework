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


/* ================================================== DEFINITIONS =================================================== */

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
 * @SPI_PERIPHERAL_STATE
 */
typedef enum
{
    SPI_PERI_STATE_READY = 0U,

    SPI_PERI_STATE_BUSY_TX_RX,
    SPI_PERI_STATE_TX_RX_COMPLETE,

    SPI_PERI_STATE_BUSY_TX,
    SPI_PERI_STATE_TX_COMPLETE,

    SPI_PERI_STATE_BUSY_RX,
    SPI_PERI_STATE_RX_COMPLETE,

    SPI_PERI_STATE_WAIT_CLOSE,

    SPI_PERI_STATE_ERROR
} SPI_PeripheralState_t;


/**
 * @SPI_PERIPERAL_ERROR
 */
typedef enum
{
    SPI_PERI_ERROR_NONE = 0U,
    SPI_PERI_ERROR_OVR = 1U,
    SPI_PERI_ERROR_MODF = 2U
} SPI_PeripheralError_t;


/**
 * @SPI_IRQ_EVENT
 */
typedef enum
{
    SPI_IRQ_EVENT_NONE = 0U,
    SPI_IRQ_EVENT_TXE = 1U,
    SPI_IRQ_EVENT_RXNE = 2U,
    SPI_IRQ_EVENT_ERROR_OVR = 4U,
    SPI_IRQ_EVENT_ERROR_MODF = 8U
} SPI_IRQEvent_t;


/**
 * @SPI_APP_EVENT
 */
typedef enum
{
    SPI_APP_EVENT_NONE = 0U,
    SPI_APP_EVENT_TX_RX_COMPLETE,
    SPI_APP_EVENT_TX_COMPLETE,
    SPI_APP_EVENT_RX_COMPLETE,
    SPI_APP_EVENT_ERROR_OVR,
    SPI_APP_EVENT_ERROR_MODF
} SPI_AppEvent_t;


/**
 * @SPI_TRANSFER_MODE
 */
typedef enum
{
    SPI_TRANSFER_MODE_NONE = 0U,
    SPI_TRANSFER_MODE_TRANSMIT_ONLY,
    SPI_TRANSFER_MODE_RECEIVE_ONLY,
    SPI_TRANSFER_MODE_TRANSMIT_RECEIVE
} SPI_TransferMode_t;


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
 * @details This structure is used to configure SPI peripheral parameters
 *          such as mode, bus configuration, clock speed, data format, and clock polarity/phase.
 */
typedef struct
{
    __IO SPI_DeviceMode_t SPI_DeviceMode;    /*!< Device mode selection                          | Possible value: @SPI_DEVICE_MODE */
    __IO SPI_BusConfig_t SPI_BusConfig;      /*!< Bus configuration                              | Possible value: @SPI_BUS_CONFIG */
    __IO SPI_SCLKSpeed_t SPI_SCLKSpeed;      /*!< Serial clock speed (baud rate prescaler)       | Possible value: @SPI_SCLK_SPEED */
    __IO SPI_DFF_t SPI_DFF;                  /*!< Data frame format                              | Possible value: @SPI_DATA_FRAME_FORMAT */
    __IO SPI_CPOL_t SPI_CPOL;                /*!< Clock polarity                                 | Possible value: @SPI_CLOCK_POLARITY */
    __IO SPI_CPHA_t SPI_CPHA;                /*!< Clock phase                                    | Possible value: @SPI_CLOCK_PHASE */
    __IO SPI_SSM_t SPI_SSM;                  /*!< Software slave management                      | Possible value: @SPI_SOFTWARE_SLAVE_MANAGEMENT */
} SPI_Config_t;


/**
 * @brief SPI transfer structure
 * 
 * @details This is structure is used to configure SPI transfer
 */
typedef struct
{ 
    __IO uint8_t *pTxBuffer;                /*!< Pointer to TX buffer application data */
    __IO uint8_t *pRxBuffer;                /*!< Pointer to RX buffer application data */
    
    __IO uint32_t TxLength;                 /*!< Number of bytes remaining to transmit */
    __IO uint32_t RxLength;                 /*!< Number of bytes remaining to receive */

    __IO uint8_t TxDone;                    /*!< Set flag when TxLength = 0 and wait close */
    __IO uint8_t RxDone;                    /*!< Set flag when RxLength = 0 and wait close */
} SPI_Transfer_t;


/**
 * @brief SPI handle structure
 * 
 * @details This structure is used to configure and operate SPI peripheral.
 *          It contains base address and configuration parameters.
 */
typedef struct
{
    SPI_RegDef_t *pSPIx;                    /*!< Pointer to SPI peripheral (SPI1, SPI2,...) */
    __IO SPI_Config_t SPI_Config;           /*!< SPI configuration settings */

    __IO SPI_Transfer_t CurrentTransfer;    /*!< Current SPI transfer */
    __IO SPI_TransferMode_t Mode;           /*!< Transfer mode */

    __IO SPI_PeripheralState_t State;       /*!< Current SPI peripheral state */

    __IO uint32_t Error;                    /*!< Current error */
} SPI_Handle_t;


/* ====================================================== APIs ====================================================== */

/**
 * @brief Enable or disable clock for SPI peripheral
 * 
 * @param pSPIx    Pointer to SPI peripheral (SPI1, SPI2,...)
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
 * @param pSPIx Pointer to SPI peripheral (SPI1, SPI2,...)
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
 * @param pSPIx    Pointer to SPI peripheral (SPI1, SPI2,...)
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
 * @brief Enable or disable the SPI peripheral
 * 
 * @param pSPIx    Pointer to SPI peripheral (SPI1, SPI2,...)
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
 * @param pSPIx    Pointer to SPI peripheral (SPI1, SPI2,...)
 * @param SE_or_CL SET or CLEAR macro
 * 
 * @details This function sets or clears the SSI bit in the SPI_CR1 register.
 *          The SSI bit is used only in master mode to control the internal 
 *          slave select signal when SSM (Software Slave Management) is enabled.
 *          0: SSI low (slave not selected)
 *          1: SSI high (slave selected)
 * 
 * @note This function should be called only when SSM is enabled in the SPI configuration.
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 28.5.1 SPI control register 1 (SPI_CR1)
 */
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t SE_or_CL);


/**
 * @brief Configure the SSOE (SS output enable) bit for the SPI peripheral
 * 
 * @param pSPIx    Pointer to SPI peripheral (SPI1, SPI2,...)
 * @param SE_or_CL SET or CLEAR macro
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
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t SE_or_CL);


/**
 * @brief Handle SPI interrupt events
 * 
 * @param pSPI_Handle Pointer to SPI handle structure
 * 
 * @details This function checks and handles SPI interrupt sources:
 *          - TXE  : Transmit buffer empty interrupt
 *          - RXNE : Receive buffer not empty interrupt
 *          - OVR  : Overrun error interrupt
 *          - MODF : Master mode fault interrupt
 * 
 *          For each interrupt source:
 *          - Check the corresponding status flag in SPI_SR register
 *          - Check whether the interrupt is enabled in SPI_CR2 register
 *          - Call the appropriate internal interrupt handler
 * 
 *          Internal handlers:
 *          - SPI_TXE_InterruptHandle()
 *          - SPI_RXNE_InterruptHandle()
 *          - SPI_OVR_InterruptHandle()
 *          - SPI_MODF_InterruptHandle()
 * 
 * @note This function should be called inside the actual SPI IRQ handler (SPIx_IRQHandler, x = 1, 2, 3)
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
 * 
 * @note This function is declared as __weak inside the driver source file,
 *       allowing the application to override it with a custom implementation.
 */
void SPI_ApplicationEventCallBack(SPI_Handle_t *pSPI_Handle, SPI_AppEvent_t SPI_AppEventFlag);


/**
 * @brief Transmit data over SPI in blocking mode
 * 
 * @param pSPIx      Pointer to SPI peripheral instance (SPI1, SPI2, ...)
 * @param pTxBuffer  Pointer to transmit data buffer
 * @param TxLength   Number of bytes to transmit
 * 
 * @return SPI_FunctionStatus_t
 *         - SPI_FUNC_STATUS_OK                : Transmission completed successfully
 *         - SPI_FUNC_STATUS_INVALID_PARAMETER : Invalid parameter or transfer error
 * 
 * @details This function uses polling mode to transmit data frame-by-frame.
 *          The function waits until:
 *          - TXE flag is set before writing new data to DR
 *          - RXNE flag is set before reading and discarding received data
 *          - BSY flag is cleared before returning
 * 
 * @note The received data is discarded to prevent RX buffer overrun (OVR).
 * 
 * @warning This is a blocking function. The CPU will wait until the entire
 *          transfer is completed.
 */
SPI_FunctionStatus_t SPI_Transmit(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t TxLength);


/**
 * @brief Receive data over SPI in blocking mode
 * 
 * @param pSPIx      Pointer to SPI peripheral instance (SPI1, SPI2, ...)
 * @param pRxBuffer  Pointer to receive data buffer
 * @param RxLength   Number of bytes to receive
 * 
 * @return SPI_FunctionStatus_t
 *         - SPI_FUNC_STATUS_OK                : Reception completed successfully
 *         - SPI_FUNC_STATUS_INVALID_PARAMETER : Invalid parameter or transfer error
 * 
 * @details SPI reception requires dummy frame transmission to generate clock.
 *          The function waits for:
 *          - TXE before sending dummy frame
 *          - RXNE before reading received data
 *          - BSY cleared before returning
 * 
 * @warning This is a blocking function.
 */
SPI_FunctionStatus_t SPI_Receive(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t RxLength);


/**
 * @brief Transmit and receive data over SPI in blocking mode
 * 
 * @param pSPIx      Pointer to SPI peripheral instance (SPI1, SPI2, ...)
 * @param pTxBuffer  Pointer to transmit data buffer
 * @param TxLength   Number of bytes to transmit
 * @param pRxBuffer  Pointer to receive data buffer
 * @param RxLength   Number of bytes to receive
 * 
 * @return SPI_FunctionStatus_t
 *         - SPI_FUNC_STATUS_OK                : Transfer completed successfully
 *         - SPI_FUNC_STATUS_INVALID_PARAMETER : Invalid parameter or transfer error
 * 
 * @details SPI transmit and receive operations occur simultaneously.
 *          The function waits for:
 *          - TXE before writing transmit data
 *          - RXNE before reading received data
 *          - BSY cleared before returning
 * 
 * @warning This is a blocking function.
 */
SPI_FunctionStatus_t SPI_TransmitReceive(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t TxLength, uint8_t *pRxBuffer, uint32_t RxLength);


/**
 * @brief  Transmit data over SPI using interrupt mode
 * 
 * @param  pSPI_Handle Pointer to SPI handle structure
 * @param  pTxBuffer Pointer to transmit data buffer
 * @param  TxLength Length of data to transmit (in bytes)
 * 
 * @return SPI_FunctionStatus_t
 *         - SPI_FUNC_STATUS_OK                : Transmission started successfully
 *         - SPI_FUNC_STATUS_BUSY              : SPI peripheral is busy
 *         - SPI_FUNC_STATUS_INVALID_PARAMETER : Invalid input parameters
 * 
 * @details
 *  - This function initializes an interrupt-based transmit operation.
 *  - TXE interrupt is used to load data into the data register.
 *  - RXNE interrupt is enabled to clear received dummy data generated
 *    during SPI transmission.
 *  - ERR interrupt is enabled to detect SPI errors such as OVR, MODF, etc.
 */
SPI_FunctionStatus_t SPI_TransmitIT(SPI_Handle_t *pSPI_Handle, uint8_t *pTxBuffer, uint32_t TxLength);


/**
 * @brief  Receive data over SPI using interrupt mode
 * 
 * @param  pSPI_Handle Pointer to SPI handle structure
 * @param  pRxBuffer Pointer to receive data buffer
 * @param  RxLength Length of data to receive (in bytes)
 * 
 * @return SPI_FunctionStatus_t
 *         - SPI_FUNC_STATUS_OK                : Reception started successfully
 *         - SPI_FUNC_STATUS_BUSY              : SPI peripheral is busy
 *         - SPI_FUNC_STATUS_INVALID_PARAMETER : Invalid input parameters
 * 
 * @details
 *  - This function initializes an interrupt-based receive operation.
 *  - Since SPI is full-duplex, dummy data will be transmitted automatically
 *    to generate clock pulses for reception.
 *  - RXNE interrupt is used to retrieve received data from the data register.
 *  - TXE interrupt is enabled to continuously send dummy frames.
 *  - ERR interrupt is enabled to detect SPI errors such as OVR, MODF, etc.
 */
SPI_FunctionStatus_t SPI_ReceiveIT(SPI_Handle_t *pSPI_Handle, uint8_t *pRxBuffer, uint32_t RxLength);


/**
 * @brief  Transmit and receive data simultaneously over SPI using interrupt mode
 * 
 * @param  pSPI_Handle Pointer to SPI handle structure
 * @param  pTxBuffer Pointer to transmit data buffer
 * @param  TxLength Length of data to transmit (in bytes)
 * @param  pRxBuffer Pointer to receive data buffer
 * @param  RxLength Length of data to receive (in bytes)
 * 
 * @return SPI_FunctionStatus_t
 *         - SPI_FUNC_STATUS_OK                : Full-duplex transfer started successfully
 *         - SPI_FUNC_STATUS_BUSY              : SPI peripheral is busy
 *         - SPI_FUNC_STATUS_INVALID_PARAMETER : Invalid input parameters
 * 
 * @details
 *  - This function initializes an interrupt-based full-duplex SPI transfer.
 *  - TXE interrupt is used to transmit data frames.
 *  - RXNE interrupt is used to receive incoming data frames.
 *  - ERR interrupt is enabled to detect SPI errors such as OVR, MODF, etc.
 */
SPI_FunctionStatus_t SPI_TransmitReceiveIT(SPI_Handle_t *pSPI_Handle, uint8_t *pTxBuffer, uint32_t TxLength, uint8_t *pRxBuffer, uint32_t RxLength);


/**
 * @brief  Finalize an SPI interrupt transfer after communication completes
 * 
 * @param  pSPI_Handle Pointer to SPI handle structure
 * 
 * @return SPI_FunctionStatus_t
 *         - SPI_FUNC_STATUS_OK    : Transfer successfully finalized
 *         - SPI_FUNC_STATUS_ERROR : Invalid completion state detected
 *         - SPI_FUNC_STATUS_BUSY  : Transfer still in progress
 * 
 * @details
 *  - This function is intended to be called repeatedly from the
 *    application layer after starting a non-blocking SPI transfer using:
 *      - SPI_TransmitIT()
 *      - SPI_ReceiveIT()
 *      - SPI_TransmitReceiveIT()
 * 
 *  - The function checks:
 *      1. Whether the SPI state is SPI_PERI_STATE_WAIT_CLOSE
 *      2. Whether the BSY flag is cleared, indicating that the last
 *         frame has completely finished on the SPI bus
 * 
 *  - Once the transfer is fully completed:
 *      - SPI interrupts are disabled
 *      - Transfer states and buffers are cleared
 *      - The SPI state returns to SPI_PERI_STATE_READY
 *      - The corresponding application callback event is generated:
 *          - SPI_APP_EVENT_TX_COMPLETE
 *          - SPI_APP_EVENT_RX_COMPLETE
 *          - SPI_APP_EVENT_TX_RX_COMPLETE
 * @example
 * SPI_TransmitIT(...);
 * while (SPI_FinalProcess(...) != SPI_FUNC_STATUS_OK);
 * 
 * SPI_ReceiveIT(...);
 * while (SPI_FinalProcess(...) != SPI_FUNC_STATUS_OK);
 * 
 * SPI_TransmitReceiveIT(...);
 * while (SPI_FinalProcess(...) != SPI_FUNC_STATUS_OK);
 */
SPI_FunctionStatus_t SPI_FinalProcess(SPI_Handle_t *pSPI_Handle);


#endif /* INC_SPI_DRIVER_H_ */