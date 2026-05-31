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


/* ================================================== BIT POSITION ================================================== */

/**
 * @I2C_CR1
 */
#define I2C_CR1_PE              (0U)    /*!< Peripheral enable                                  | Bit 0 */
#define I2C_CR1_SMBUS           (1U)    /*!< SMBus mode                                         | Bit 1 */
#define I2C_CR1_SMBTYPE         (3U)    /*!< SMBus type                                         | Bit 3 */
#define I2C_CR1_ENARP           (4U)    /*!< ARP enable                                         | Bit 4 */
#define I2C_CR1_ENPEC           (5U)    /*!< PEC enable                                         | Bit 5 */
#define I2C_CR1_ENGC            (6U)    /*!< General call enable                                | Bit 6 */
#define I2C_CR1_NOSTRETCH       (7U)    /*!< Clock stretching disable (Slave mode)              | Bit 7 */
#define I2C_CR1_START           (8U)    /*!< Start generation                                   | Bit 8 */
#define I2C_CR1_STOP            (9U)    /*!< Stop generation                                    | Bit 9 */
#define I2C_CR1_ACK             (10U)   /*!< Acknowledge enable                                 | Bit 10 */
#define I2C_CR1_POS             (11U)   /*!< Acknowledge/PEC Position (for data reception)      | Bit 11 */
#define I2C_CR1_PEC             (12U)   /*!< Packet error checking                              | Bit 12 */
#define I2C_CR1_ALERT           (13U)   /*!< SMBus alert                                        | Bit 13 */
#define I2C_CR1_SWRST           (15U)   /*!< Software reset                                     | Bit 15 */


/**
 * @I2C_CR2
 */
#define I2C_CR2_FREQ            (0U)    /*!< Peripheral clock frequency (5:0)           | Bits 5:0 */
#define I2C_CR2_ITERREN         (8U)    /*!< Error interrupt enable                     | Bit 8 */
#define I2C_CR2_ITEVTEN         (9U)    /*!< Event interrupt enable                     | Bit 9 */
#define I2C_CR2_ITBUFEN         (10U)   /*!< Buffer interrupt enable                    | Bit 10 */
#define I2C_CR2_DMAEN           (11U)   /*!< DMA requests enable                        | Bit 11 */
#define I2C_CR2_LAST            (12U)   /*!< DMA last transfer                          | Bit 12 */


/**
 * @I2C_OAR1
 */
#define I2C_OAR1_ADD0           (0U)    /*!< Interface address          | Bit 0 */
#define I2C_OAR1_ADD            (1U)    /*!< Interface address          | Bits 9:1 */
#define I2C_OAR1_ADDMODE        (15U)   /*!< Addressing mode            | Bit 15 */


/**
 * @I2C_OAR2
 */
#define I2C_OAR2_ENDUAL         (0U)    /*!< Dual addressing mode enable        | Bit 0 */
#define I2C_OAR2_ADD2           (1U)    /*!< Interface address (dual mode)      | Bits 7:1 */


/**
 * @I2C_DR
 */
#define I2C_DR_DR               (0U)    /*!< 8-bit data register        | Bits 7:0 */


/**
 * @I2C_SR1
 */
#define I2C_SR1_SB              (0U)    /*!< Start bit (Master mode)                                | Bit 0 */
#define I2C_SR1_ADDR            (1U)    /*!< Address sent (master mode)/matched (slave mode)        | Bit 1 */
#define I2C_SR1_BTF             (2U)    /*!< Byte transfer finished                                 | Bit 2 */
#define I2C_SR1_ADD10           (3U)    /*!< 10-bit header sent (Master mode)                       | Bit 3 */
#define I2C_SR1_STOPF           (4U)    /*!< Stop detection (slave mode)                            | Bit 4 */
#define I2C_SR1_RXNE            (6U)    /*!< Data register not empty (receivers)                    | Bit 6 */
#define I2C_SR1_TXE             (7U)    /*!< Data register empty (transmitters)                     | Bit 7 */
#define I2C_SR1_BERR            (8U)    /*!< Bus error                                              | Bit 8 */
#define I2C_SR1_ARLO            (9U)    /*!< Arbitration lost (master mode)                         | Bit 9 */
#define I2C_SR1_AF              (10U)   /*!< Acknowledge failure                                    | Bit 10 */
#define I2C_SR1_OVR             (11U)   /*!< Overrun/Underrun                                       | Bit 11 */
#define I2C_SR1_PECERR          (12U)   /*!< PEC error in reception                                 | Bit 12 */
#define I2C_SR1_TIMEOUT         (14U)   /*!< Timeout or Tlow error                                  | Bit 14 */
#define I2C_SR1_SMBALERT        (15U)   /*!< SMBus alert                                            | Bit 15 */


/**
 * @I2C_SR2
 */
#define I2C_SR2_MSL             (0U)    /*!< Master/slave                                   | Bit 0 */
#define I2C_SR2_BUSY            (1U)    /*!< Bus busy                                       | Bit 1 */
#define I2C_SR2_TRA             (2U)    /*!< Transmitter/receiver                           | Bit 2 */
#define I2C_SR2_GENCALL         (4U)    /*!< General call address (Slave mode)              | Bit 4 */
#define I2C_SR2_SMBDEFAULT      (5U)    /*!< SMBus device default address (Slave mode)      | Bit 5 */
#define I2C_SR2_SMBHOST         (6U)    /*!< SMBus host header (Slave mode)                 | Bit 6 */
#define I2C_SR2_DUALF           (7U)    /*!< Dual flag (Slave mode)                         | Bit 7 */
#define I2C_SR2_PEC             (8U)    /*!< Packet error checking register                 | Bits 15:8 */


/**
 * @I2C_CCR
 */
#define I2C_CCR_CCR             (0U)    /*!< Clock control register in Fm/Sm mode (Master mode)     | Bits 11:0 */
#define I2C_CCR_DUTY            (14U)   /*!< Fast mode duty cycle                                   | Bit 14 */
#define I2C_CCR_FS              (15U)   /*!< I2C master mode selection                              | Bit 15 */


/**
 * @I2C_TRISE
 */
#define I2C_TRISE_TRISE         (0U)    /*!< Maximum rise time in Fm/Sm mode (Master mode)      | Bits 5:0 */


/**
 * @I2C_FLTR
 */
#define I2C_FLTR_DNF            (0U)    /*!< Digital noise filter           | Bits 3:0 */
#define I2C_FLTR_ANOFF          (4U)    /*!< Analog noise filter OFF        | Bit 4 */


/* ===================================================== FLAGS ====================================================== */

/**
 * @I2C_FLAG Encoding
 * 
 * [31:16] : Register Offset
 * [15:0]  : Bit Position
 */
#define I2C_FLAG_SR1           (0x01U << 16U)
#define I2C_FLAG_SR2           (0x02U << 16U)


/**
 * @I2C_SR1 Flags
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
 * @I2C_SR2 Flags
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
 * @I2C_DUAL_ADDRESS
 */
typedef enum
{
    I2C_DUAL_ADDRESS_DISABLE = 0U,
    I2C_DUAL_ADDRESS_ENABLE
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
    I2C_SCLSpeed_t I2C_SCLSpeed;                /*!< SCL clock speed                    | Possible value: @I2C_SCL_SPEED */
    uint16_t I2C_DeviceAddress;                 /*!< Primary slave address (OAR1)       | Possible value: User configure */
    uint16_t I2C_SecondaryAddress;              /*!< Secondary slave address (OAR2)     | Possible value: User configure */

    I2C_ACKControl_t I2C_ACKControl;            /*!< ACK control                        | Possible value: @I2C_ACK_CONTROL */
    I2C_FMDutyCycle_t I2C_FMDutyCycle;          /*!< Fast mode duty cycle               | Possible value: @I2C_FM_DUTY_CYCLE */

    I2C_AddressMode_t I2C_AddressMode;          /*!< Addressing mode                    | Possible value: @I2C_ADDRESS_MODE */
    I2C_GeneralCall_t I2C_GeneralCall;          /*!< General call handling              | Possible value: @I2C_GENERAL_CALL */
    I2C_ClockStretch_t I2C_ClockStretch;        /*!< Clock stretching control           | Possible value: @I2C_CLOCK_STRETCH */
    I2C_DualAddress_t I2C_DualAddress;          /*!< Dual addressing mode               | Possible value: @I2C_DUAL_ADDRESS */
} I2C_Config_t;


typedef struct
{
    I2C_RegDef_t pI2Cx;         /*!< Pointer to I2C peripheral (I2C1, I2C2,...) */
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
 *         - I2C_FUNC_STATUS_OK    : Enable/Disable successfully 
 *         - I2C_FUNC_STATUS_ERROR : Enable/Disable failed
 * 
 * @note Must enable clock before using I2C registers
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Section 7.3.13 RCC APB1 peripheral clock enable register (RCC_APB1ENR)
 */
I2C_FunctionStatus_t I2C_PeriClock_Control(I2C_RegDef_t *pI2Cx, uint8_t EN_or_DI);


#endif /* INC_I2C_DRIVER_H_ */