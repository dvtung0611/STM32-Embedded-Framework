/**
 * File name: i2c-driver.h
 *
 * Created on: 31/05/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_I2C_DRIVER_H_
#define INC_I2C_DRIVER_H_

#include <stdint.h>
#include "stm32f407xx.h"


/* ===================================================== MACROS ===================================================== */

/**
 * @I2C_RESET_REGISTER_VALUE
 */
#define I2C_CR1_RESET_VALUE                 (0x00U)
#define I2C_CR2_RESET_VALUE                 (0x00U)
#define I2C_OAR1_RESET_VALUE                (0x00U)
#define I2C_OAR2_RESET_VALUE                (0x00U)
#define I2C_DR_RESET_VALUE                  (0x07U)
#define I2C_SR1_RESET_VALUE                 (0x00U)
#define I2C_SR2_RESET_VALUE                 (0x00U)
#define I2C_CCR_RESET_VALUE                 (0x00U)
#define I2C_TRISE_RESET_VALUE               (0x02U)

#define I2C_TRISE_MASK                      (0x3FU)


/* ================================================== BIT POSITION ================================================== */

/**
 * @I2C_CR1
 */
#define I2C_CR1_PE_Pos              (0U)    /*!< Peripheral enable                                  | Bit 0 */
#define I2C_CR1_SMBUS_Pos           (1U)    /*!< SMBus mode                                         | Bit 1 */
#define I2C_CR1_SMBTYPE_Pos         (3U)    /*!< SMBus type                                         | Bit 3 */
#define I2C_CR1_ENARP_Pos           (4U)    /*!< ARP enable                                         | Bit 4 */
#define I2C_CR1_ENPEC_Pos           (5U)    /*!< PEC enable                                         | Bit 5 */
#define I2C_CR1_ENGC_Pos            (6U)    /*!< General call enable                                | Bit 6 */
#define I2C_CR1_NOSTRETCH_Pos       (7U)    /*!< Clock stretching disable (Slave mode)              | Bit 7 */
#define I2C_CR1_START_Pos           (8U)    /*!< Start generation                                   | Bit 8 */
#define I2C_CR1_STOP_Pos            (9U)    /*!< Stop generation                                    | Bit 9 */
#define I2C_CR1_ACK_Pos             (10U)   /*!< Acknowledge enable                                 | Bit 10 */
#define I2C_CR1_POS_Pos             (11U)   /*!< Acknowledge/PEC Position (for data reception)      | Bit 11 */
#define I2C_CR1_PEC_Pos             (12U)   /*!< Packet error checking                              | Bit 12 */
#define I2C_CR1_ALERT_Pos           (13U)   /*!< SMBus alert                                        | Bit 13 */
#define I2C_CR1_SWRST_Pos           (15U)   /*!< Software reset                                     | Bit 15 */


/**
 * @I2C_CR2
 */
#define I2C_CR2_FREQ_Pos            (0U)    /*!< Peripheral clock frequency (5:0)           | Bits 5:0 */
#define I2C_CR2_ITERREN_Pos         (8U)    /*!< Error interrupt enable                     | Bit 8 */
#define I2C_CR2_ITEVTEN_Pos         (9U)    /*!< Event interrupt enable                     | Bit 9 */
#define I2C_CR2_ITBUFEN_Pos         (10U)   /*!< Buffer interrupt enable                    | Bit 10 */
#define I2C_CR2_DMAEN_Pos           (11U)   /*!< DMA requests enable                        | Bit 11 */
#define I2C_CR2_LAST_Pos            (12U)   /*!< DMA last transfer                          | Bit 12 */


/**
 * @I2C_OAR1
 */
#define I2C_OAR1_ADD10_Pos           (0U)    /*!< Interface address          | Bit 9:0 */
#define I2C_OAR1_ADD7_Pos            (1U)    /*!< Interface address          | Bits 7:1 */
#define I2C_OAR1_ADDMODE_Pos        (15U)   /*!< Addressing mode            | Bit 15 */


/**
 * @I2C_OAR2
 */
#define I2C_OAR2_ENDUAL_Pos         (0U)    /*!< Dual addressing mode enable        | Bit 0 */
#define I2C_OAR2_ADD2_Pos           (1U)    /*!< Interface address (dual mode)      | Bits 7:1 */


/**
 * @I2C_DR
 */
#define I2C_DR_DR_Pos               (0U)    /*!< 8-bit data register        | Bits 7:0 */


/**
 * @I2C_SR1
 */
#define I2C_SR1_SB_Pos              (0U)    /*!< Start bit (Master mode)                                | Bit 0 */
#define I2C_SR1_ADDR_Pos            (1U)    /*!< Address sent (master mode)/matched (slave mode)        | Bit 1 */
#define I2C_SR1_BTF_Pos             (2U)    /*!< Byte transfer finished                                 | Bit 2 */
#define I2C_SR1_ADD10_Pos           (3U)    /*!< 10-bit header sent (Master mode)                       | Bit 3 */
#define I2C_SR1_STOPF_Pos           (4U)    /*!< Stop detection (slave mode)                            | Bit 4 */
#define I2C_SR1_RXNE_Pos            (6U)    /*!< Data register not empty (receivers)                    | Bit 6 */
#define I2C_SR1_TXE_Pos             (7U)    /*!< Data register empty (transmitters)                     | Bit 7 */
#define I2C_SR1_BERR_Pos            (8U)    /*!< Bus error                                              | Bit 8 */
#define I2C_SR1_ARLO_Pos            (9U)    /*!< Arbitration lost (master mode)                         | Bit 9 */
#define I2C_SR1_AF_Pos              (10U)   /*!< Acknowledge failure                                    | Bit 10 */
#define I2C_SR1_OVR_Pos             (11U)   /*!< Overrun/Underrun                                       | Bit 11 */
#define I2C_SR1_PECERR_Pos          (12U)   /*!< PEC error in reception                                 | Bit 12 */
#define I2C_SR1_TIMEOUT_Pos         (14U)   /*!< Timeout or Tlow error                                  | Bit 14 */
#define I2C_SR1_SMBALERT_Pos        (15U)   /*!< SMBus alert                                            | Bit 15 */


/**
 * @I2C_SR2
 */
#define I2C_SR2_MSL_Pos             (0U)    /*!< Master/slave                                   | Bit 0 */
#define I2C_SR2_BUSY_Pos            (1U)    /*!< Bus busy                                       | Bit 1 */
#define I2C_SR2_TRA_Pos             (2U)    /*!< Transmitter/receiver                           | Bit 2 */
#define I2C_SR2_GENCALL_Pos         (4U)    /*!< General call address (Slave mode)              | Bit 4 */
#define I2C_SR2_SMBDEFAULT_Pos      (5U)    /*!< SMBus device default address (Slave mode)      | Bit 5 */
#define I2C_SR2_SMBHOST_Pos         (6U)    /*!< SMBus host header (Slave mode)                 | Bit 6 */
#define I2C_SR2_DUALF_Pos           (7U)    /*!< Dual flag (Slave mode)                         | Bit 7 */
#define I2C_SR2_PEC_Pos             (8U)    /*!< Packet error checking register                 | Bits 15:8 */


/**
 * @I2C_CCR
 */
#define I2C_CCR_CCR_Pos             (0U)    /*!< Clock control register in Fm/Sm mode (Master mode)     | Bits 11:0 */
#define I2C_CCR_DUTY_Pos            (14U)   /*!< Fast mode duty cycle                                   | Bit 14 */
#define I2C_CCR_FS_Pos              (15U)   /*!< I2C master mode selection                              | Bit 15 */


/**
 * @I2C_TRISE
 */
#define I2C_TRISE_TRISE_Pos         (0U)    /*!< Maximum rise time in Fm/Sm mode (Master mode)      | Bits 5:0 */


/**
 * @I2C_FLTR
 */
#define I2C_FLTR_DNF_Pos            (0U)    /*!< Digital noise filter           | Bits 3:0 */
#define I2C_FLTR_ANOFF_Pos          (4U)    /*!< Analog noise filter OFF        | Bit 4 */


/* ===================================================== FLAGS ====================================================== */

/**
 * @I2C_FLAG_ENCODING
 * 
 * [31:16] : Register Offset
 * [15:0]  : Flag Position
 */
#define I2C_FLAG_SR1            (1U << 16U)
#define I2C_FLAG_SR2            (2U << 16U)
#define I2C_SR_MASK             (0xFFFF0000U)
#define I2C_FLAGPOS_MASK        (0x0000FFFFU)


/**
 * @I2C_SR1_FLAG
 */
#define I2C_FLAG_SB            (I2C_FLAG_SR1 | 0U)      /*!< Start bit                     */
#define I2C_FLAG_ADDR          (I2C_FLAG_SR1 | 1U)      /*!< Address sent/matched          */
#define I2C_FLAG_BTF           (I2C_FLAG_SR1 | 2U)      /*!< Byte transfer finished        */
#define I2C_FLAG_ADD10         (I2C_FLAG_SR1 | 3U)      /*!< 10-bit header sent            */
#define I2C_FLAG_STOPF         (I2C_FLAG_SR1 | 4U)      /*!< Stop detection                */
#define I2C_FLAG_RXNE          (I2C_FLAG_SR1 | 6U)      /*!< Data register not empty       */
#define I2C_FLAG_TXE           (I2C_FLAG_SR1 | 7U)      /*!< Data register empty           */
#define I2C_FLAG_BERR          (I2C_FLAG_SR1 | 8U)      /*!< Bus error                     */
#define I2C_FLAG_ARLO          (I2C_FLAG_SR1 | 9U)      /*!< Arbitration lost              */
#define I2C_FLAG_AF            (I2C_FLAG_SR1 | 10U)     /*!< Acknowledge failure           */
#define I2C_FLAG_OVR           (I2C_FLAG_SR1 | 11U)     /*!< Overrun/Underrun              */
#define I2C_FLAG_PECERR        (I2C_FLAG_SR1 | 12U)     /*!< PEC error                     */
#define I2C_FLAG_TIMEOUT       (I2C_FLAG_SR1 | 14U)     /*!< Timeout/Tlow error            */
#define I2C_FLAG_SMBALERT      (I2C_FLAG_SR1 | 15U)     /*!< SMBus alert                   */


/**
 * @I2C_SR2_FLAG
 */
#define I2C_FLAG_MSL           (I2C_FLAG_SR2 | 0U)      /*!< Master/slave                  */
#define I2C_FLAG_BUSY          (I2C_FLAG_SR2 | 1U)      /*!< Bus busy                      */
#define I2C_FLAG_TRA           (I2C_FLAG_SR2 | 2U)      /*!< Transmitter/receiver          */
#define I2C_FLAG_GENCALL       (I2C_FLAG_SR2 | 4U)      /*!< General call address          */
#define I2C_FLAG_SMBDEFAULT    (I2C_FLAG_SR2 | 5U)      /*!< SMBus default address         */
#define I2C_FLAG_SMBHOST       (I2C_FLAG_SR2 | 6U)      /*!< SMBus host header             */
#define I2C_FLAG_DUALF         (I2C_FLAG_SR2 | 7U)      /*!< Dual address matched          */


/* ================================================== DEFINITIONS =================================================== */

/**
 * @I2C_SCL_SPEED
 */
typedef enum
{
    I2C_SCL_SPEED_STANDARD_MODE = 100000U,
    I2C_SCL_SPEED_FAST_MODE_200K = 200000U,
    I2C_SCL_SPEED_FAST_MODE_400K = 400000U
} I2C_SCLSpeed_t;


/**
 * @I2C_MAX_RISE_TIME
 */
typedef enum
{
    I2C_MAX_RISE_TIME_STANDARD_NS = 1000U,
    I2C_MAX_RISE_TIME_FAST_NS = 300U
} I2C_Max_RiseTime_t;


/**
 * @I2C_ACK_CONTROL
 */
typedef enum
{
    I2C_ACK_CONTROL_DISABLE = 0U,
    I2C_ACK_CONTROL_ENABLE
} I2C_ACKControl_t;


/**
 * @I2C_FM_DUTY_CYCLE
 */
typedef enum
{
    I2C_FM_DUTY_CYCLE_2 = 0U,
    I2C_FM_DUTY_CYCLE_16_9
} I2C_FMDutyCycle_t;


/**
 * @I2C_ADDRESS_MODE
 */
typedef enum
{
    I2C_ADDRESS_MODE_7BIT = 0U,
    I2C_ADDRESS_MODE_10BIT
} I2C_AddressMode_t;


/**
 * @I2C_GENERAL_CALL
 */
typedef enum
{
    I2C_GENERAL_CALL_DISABLE = 0U,
    I2C_GENERAL_CALL_ENABLE
} I2C_GeneralCall_t;


/**
 * @I2C_CLOCK_STRETCH
 */
typedef enum
{
    I2C_CLOCK_STRETCH_ENABLE = 0U,
    I2C_CLOCK_STRETCH_DISABLE
} I2C_ClockStretch_t;


/**
 * @I2C_DUAL_ADDRESS_MODE
 */
typedef enum
{
    I2C_DUAL_ADDRESS_MODE_DISABLE = 0U,
    I2C_DUAL_ADDRESS_MODE_ENABLE
} I2C_DualAddress_t;


/**
 * @I2C_FUNCTION_STATUS
 */
typedef enum
{
    I2C_FUNC_STATUS_OK = 0U,
    I2C_FUNC_STATUS_BUSY,
    I2C_FUNC_STATUS_ERROR,
    I2C_FUNC_STATUS_INVALID_PARAMETER
} I2C_FunctionStatus_t;


/* =================================================== STRUCTURES =================================================== */

/**
 * @brief I2C configuration structure
 *
 * @details This structure is used to configure I2C peripheral parameters
 *          such as clock speed, device addressing, acknowledge control,
 *          fast mode duty cycle, general call handling, clock stretching,
 *          and dual addressing mode.
 */
typedef struct
{
    I2C_ACKControl_t I2C_ACKControl;            /*!< ACK control                        | Possible value: @I2C_ACK_CONTROL */

    I2C_AddressMode_t I2C_AddressMode;          /*!< Addressing mode                    | Possible value: @I2C_ADDRESS_MODE */
    I2C_DualAddress_t I2C_DualAddressMode;      /*!< Dual addressing mode               | Possible value: @I2C_DUAL_ADDRESS_MODE */
    uint16_t I2C_DeviceAddress;                 /*!< Primary slave address (OAR1)       | Possible value: User configure */
    uint16_t I2C_SecondaryAddress;              /*!< Secondary slave address (OAR2)     | Possible value: User configure */

    I2C_SCLSpeed_t I2C_SCLSpeed;                /*!< SCL clock speed                    | Possible value: @I2C_SCL_SPEED */
    I2C_FMDutyCycle_t I2C_FMDutyCycle;          /*!< Fast mode duty cycle               | Possible value: @I2C_FM_DUTY_CYCLE */
    
    I2C_ClockStretch_t I2C_ClockStretch;        /*!< Clock stretching control           | Possible value: @I2C_CLOCK_STRETCH */
    I2C_GeneralCall_t I2C_GeneralCall;          /*!< General call handling              | Possible value: @I2C_GENERAL_CALL */
} I2C_Config_t;


typedef struct
{
    I2C_RegDef_t *pI2Cx;        /*!< Pointer to I2C peripheral (I2C1, I2C2,...) */
    I2C_Config_t I2C_Config;    /*!< I2C configuration settings */
} I2C_Handle_t;


/* ====================================================== APIs ====================================================== */

/**
 * @brief Enable or disable clock for I2C peripheral
 * 
 * @param pI2Cx    Pointer to I2C peripheral (I2C1, I2C2,...)
 * @param EN_or_DI ENABLE or DISABLE macro
 * 
 * @return I2C_FunctionStatus_t
 *         - I2C_FUNC_STATUS_OK    : Enable/Disable operation succeeded
 *         - I2C_FUNC_STATUS_ERROR : Enable/Disable operation failed
 * 
 * @note Must enable clock before using I2C registers
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Section 7.3.13 RCC APB1 peripheral clock enable register (RCC_APB1ENR)
 */
I2C_FunctionStatus_t I2C_PeripheralClockControl(I2C_RegDef_t *pI2Cx, uint8_t EN_or_DI);


/**
 * @brief Initialize an I2C peripheral.
 * 
 * @param pI2C_Handle Pointer to the I2C handle structure containing
 *        the peripheral instance and configuration parameters.
 * 
 * @return I2C_FunctionStatus_t
 *      - I2C_FUNC_STATUS_OK                : Initialization completed successfully.
 *      - I2C_FUNC_STATUS_INVALID_PARAMETER : One or more configuration parameters are invalid.
 * 
 * @details This function configures the selected I2C peripheral according
 *          to the parameters stored in the I2C handle structure.
 * 
 *          The following configurations are applied:
 *          - Enable peripheral clock.
 *          - ACK control.
 *          - 7-bit or 10-bit own address mode.
 *          - Dual addressing mode.
 *          - General call response.
 *          - Clock stretching.
 *          - Peripheral clock frequency (CR2.FREQ).
 *          - Standard mode or Fast mode timing (CCR).
 *          - Fast mode duty cycle selection.
 * 
 *          Supported bus speeds:
 *          - Standard Mode : 100 kHz
 *          - Fast Mode     : 200 kHz, 400 kHz
 * 
 *          CCR is calculated according to the selected operating mode:
 * 
 *          Standard Mode:
 *              CCR = FPCLK1 / (2 × FSCL)
 * 
 *          Fast Mode (Duty = 2):
 *              CCR = FPCLK1 / (3 × FSCL)
 * 
 *          Fast Mode (Duty = 16/9):
 *              CCR = FPCLK1 / (25 × FSCL)
 * 
 * @note This function configures the peripheral registers only.
 *       It does not enable the I2C peripheral (PE bit).
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 27.3 I2C Functional description
 *                              Section 27.6 I2C registers
 */

I2C_FunctionStatus_t I2C_Init(I2C_Handle_t *pI2C_Handle);


/**
 * @brief Reset the I2C peripheral to its default state
 * 
 * @param pI2Cx Pointer to I2C peripheral (I2C1, I2C2, ...)
 * 
 * @return I2C_FunctionStatus_t
 *         - I2C_FUNC_STATUS_OK    : De-initialized successfully
 *         - I2C_FUNC_STATUS_ERROR : De-initialization failed
 * 
 * @note This function resets the selected I2C peripheral using the RCC reset register.
 *       After the reset, all I2C registers are returned to their default values.
 * 
 * Reference:
 * - RM0090 Reference Manual, Section 7.3.8 RCC APB1 peripheral reset register (RCC_APB1RSTR)
 */
I2C_FunctionStatus_t I2C_DeInit(I2C_RegDef_t *pI2Cx);


/**
 * @brief Enable or disable the I2C peripheral
 * 
 * @param pI2Cx    Pointer to I2C peripheral (I2C1, I2C2,...)
 * @param EN_or_DI ENABLE or DISABLE macro
 * 
 * @return I2C_FunctionStatus_t
 *         - I2C_FUNC_STATUS_OK    : Enable/Disable operation succeeded
 *         - I2C_FUNC_STATUS_ERROR : Enable/Disable operation failed
 * 
 * @details Set the PE bit in the I2C_CR1 register:
 *          0: Peripheral disable
 *          1: Peripheral enable
 * 
 * @note If this bit is reset while a communication is on going, the peripheral is disabled at the 
 *       end of the current communication, when back to IDLE state. 
 *       All bit resets due to PE = 0 occur at the end of the communication.
 *       In master mode, this bit must not be reset before the end of the communication.
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 27.6.1 I2C Control register 1 (I2C_CR1)
 */
I2C_FunctionStatus_t I2C_PeripheralControl(I2C_RegDef_t *pI2Cx, uint8_t EN_or_DI);


/**
 * @brief Returns the flag status of the I2C peripheral
 * 
 * @param pI2Cx    Pointer to I2C peripheral (I2C1, I2C2,...)
 * @param FlagName Flag name in the I2C_SRx (x = 1 or 2) | @I2C_SR1_FLAG / @I2C_SR2_FLAG
 * 
 * @return uint8_t Flag status is set or reset
 * 
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Section 27.6.6 I2C Status register 1 (I2C_SR1)
 *                              Section 27.6.7 I2C Status register 2 (I2C_SR2)
 */
uint8_t I2C_GetFlagStatus(I2C_RegDef_t *pI2Cx, uint32_t FlagName);


/**
 * @brief  Enable or disable ACK generation in I2C peripheral.
 * 
 * @param pI2Cx Pointer to I2C peripheral (I2C1, I2C2,...)
 * @param EN_or_DI ENABLE or DISABLE macro
 * 
 * @return I2C_FunctionStatus_t
 *         - I2C_FUNC_STATUS_OK    : Enable/Disable operation succeeded
 *         - I2C_FUNC_STATUS_ERROR : Enable/Disable operation failed
 * 
 * @note   This function configures the ACK bit (CR1.ACK).
 *         When ACK is enabled, the I2C peripheral automatically
 *         acknowledges received bytes.
 * 
 *         In Master Receiver mode:
 *         - ACK = 1 : Continue receiving next byte.
 *         - ACK = 0 : NACK the next received byte, typically used
 *                     before receiving the last byte.
 */
I2C_FunctionStatus_t I2C_ACKConfig(I2C_RegDef_t *pI2Cx, uint8_t EN_or_DI);


/**
 * @brief  Transmit data from Master to Slave in polling mode.
 * 
 * @param  pI2C_Handle   Pointer to I2C handle structure.
 * @param  pTxBuffer     Pointer to transmit data buffer.
 * @param  DataLength    Number of bytes to transmit.
 * @param  SlaveAddress  Target slave address.
 * 
 * @return I2C_FUNC_STATUS_OK                : Data transmitted successfully.
 *         I2C_FUNC_STATUS_ERROR             : Slave failed to acknowledge the address phase (AF flag set).
 *         I2C_FUNC_STATUS_INVALID_PARAMETER : One or more input parameters are invalid.
 * 
 * @note   This function performs a complete I2C Master transmission sequence:
 *         - Wait until the I2C bus becomes free.
 *         - Generate a START condition.
 *         - Send slave address with write operation.
 *         - Wait for address acknowledgment.
 *         - Clear the ADDR flag.
 *         - Transmit all data bytes.
 *         - Wait for TXE and BTF flags.
 *         - Generate a STOP condition.
 * 
 * @note Only 7-bit addressing mode is currently supported.
 * 
 * @warning This is a blocking API.
 */
I2C_FunctionStatus_t I2C_MasterSendData(I2C_Handle_t *pI2C_Handle, uint8_t *pTxBuffer, uint32_t DataLength, uint16_t SlaveAddress);


#endif /* INC_I2C_DRIVER_H_ */