/**
 * File name: stm32f407xx.h
 *
 * Created on: 14/04/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include <stddef.h>


/* ===================================================== MACROS ===================================================== */

#define __IO 			volatile
#define __weak          __attribute__((weak))

#define ENABLE			(1U)
#define DISABLE			(0U)
#define SET				(1U)
#define RESET			(0U)

#define FLAG_RESET      (0U)
#define FLAG_SET        (1U)


/* ========================================== FLASH + SRAM + SYSTEM MEMORY ========================================== */

/**
 * @brief Base address of FLASH, SRAM and SYSTEM memory
 *
 * @note
 * 
 * Refer to:
 * - STM32F407VG, 				Figure 18. STM32F40xxx memory map
 *
 * - RM0090 Reference Manual, 	Section 2.1 System architecture,
 * 								Section 2.3.1 Embedded SRAM,
 * 								Section 3.3 Embedded flash memory in STM32F405xx/07xx and STM32F415xx/17xx,
 * 								Table 3 Memory mapping vs. Boot mode/physical remap in STM32F405xx/07xx and STM32F415xx/17xx,
 * 								Table 5 Flash module organization (STM32F40x and STM32F41x)
 */
#define FLASH_BASEADDR                          	(0x08000000UL)
#define FLASH_SIZE									(1024UL * 1024UL)				// 1 MB

#define SRAM_BASEADDR								(0x20000000UL)
#define SRAM1_BASEADDR								SRAM_BASEADDR
#define SRAM1_SIZE									(112UL * 1024UL) 				// 112 KB

#define SRAM2_BASEADDR								(SRAM1_BASEADDR + SRAM1_SIZE)
#define SRAM2_SIZE									(16UL * 1024UL) 				// 16 KB

#define SYSTEM_MEMORY_BASEADDR						(0x1FFF0000UL)
#define SYSTEM_MEMORY_SIZE							(30UL * 1024UL)					// 30 KB


/* ============================================ ARM Cortex-M4 PERIPHERALS =========================================== */

/**
 * @brief Base address of the ARM Cortex-M4 peripherals
 * 
 * @note
 *
 * Refer to:
 * - ARM Cortex-M4 Generic User Guide,  Section 4.1 About the Cortex-M4 peripherals
 */
#define NVIC_BASEADDR                       (0xE000E100UL)   /*!< Nested Vectored Interrupt Controller */
#define SCB_BASEADDR                        (0xE000ED00UL)   /*!< System Control Block */
#define SysTick_BASEADDR                    (0xE000E010UL)   /*!< SysTick Timer */
#define MPU_BASEADDR                        (0xE000ED90UL)   /*!< Memory Protection Unit */
#define FPU_BASEADDR                        (0xE000EF30UL)   /*!< Floating Point Unit */


/* ========================================== APBx and AHBx BUS INTERFACES ========================================== */

/**
 * @brief Base address of the bus interfaces
 *
 * @note
 *
 * Refer to:
 * - RM0090 Reference Manual,	Table 1. STM32F4xx register boundary addresses
 */
#define PERIPHERAL_BASEADDR							(0x40000000UL)
#define APB1_PERIPHERAL_BASEADDR					(PERIPHERAL_BASEADDR)
#define APB2_PERIPHERAL_BASEADDR					(0x40010000UL)
#define	AHB1_PERIPHERAL_BASEADDR					(0x40020000UL)
#define AHB2_PERIPHERAL_BASEADDR					(0x50000000UL)
#define AHB3_PERIPHERAL_BASEADDR					(0xA0000000UL)


/* ================================================ AHB1 PERIPHERALS ================================================ */

/**
 * @brief Base address of the peripherals connected to the AHB1 bus
 *
 * @note
 *
 * Refer to:
 * - RM0090 Reference Manual,	Table 1. STM32F4xx register boundary addresses
 */
#define GPIOA_BASEADDR								(AHB1_PERIPHERAL_BASEADDR)
#define GPIOB_BASEADDR								(0x40020400UL)
#define GPIOC_BASEADDR								(0x40020800UL)
#define GPIOD_BASEADDR								(0x40020C00UL)
#define GPIOE_BASEADDR								(0x40021000UL)
#define GPIOF_BASEADDR    							(0x40021400UL)
#define GPIOG_BASEADDR								(0x40021800UL)
#define GPIOH_BASEADDR								(0x40021C00UL)
#define GPIOI_BASEADDR								(0x40022000UL)

#define CRC_BASEADDR								(0x40023000UL)

#define RCC_BASEADDR								(0x40023800UL)

#define FLASH_REG_BASEADDR				            (0x40023C00UL)

#define BKPSRAM_BASEADDR							(0x40024000UL)

#define DMA1_BASEADDR								(0x40026000UL)
#define DMA2_BASEADDR								(0x40026400UL)

#define ETHERNET_MAC_BASEADDR						(0x40028000UL)

#define USB_OTG_HS_BASEADDR							(0x40040000UL)


/* ================================================ APB1 PERIPHERALS ================================================ */

/**
 * @brief Base address of the peripherals connected to the APB1 bus
 *
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Table 1. STM32F4xx register boundary addresses
 */
#define TIM2_BASEADDR                               (APB1_PERIPHERAL_BASEADDR)
#define TIM3_BASEADDR                               (0x40000400UL)
#define TIM4_BASEADDR                               (0x40000800UL)
#define TIM5_BASEADDR                               (0x40000C00UL)
#define TIM6_BASEADDR                               (0x40001000UL)
#define TIM7_BASEADDR                               (0x40001400UL)
#define TIM12_BASEADDR                              (0x40001800UL)
#define TIM13_BASEADDR                              (0x40001C00UL)
#define TIM14_BASEADDR                              (0x40002000UL)

#define RTC_BKP_REGS_BASEADDR                       (0x40002800UL)

#define WWDG_BASEADDR                               (0x40002C00UL)

#define IWDG_BASEADDR                               (0x40003000UL)

#define I2S2EXT_BASEADDR                            (0x40003400UL)

#define SPI2_I2S2_BASEADDR                          (0x40003800UL)
#define SPI3_I2S3_BASEADDR                          (0x40003C00UL)

#define I2S3EXT_BASEADDR                            (0x40004000UL)

#define USART2_BASEADDR                             (0x40004400UL)
#define USART3_BASEADDR                             (0x40004800UL)
#define UART4_BASEADDR                              (0x40004C00UL)
#define UART5_BASEADDR                              (0x40005000UL)

#define I2C1_BASEADDR                               (0x40005400UL)
#define I2C2_BASEADDR                               (0x40005800UL)
#define I2C3_BASEADDR                               (0x40005C00UL)

#define CAN1_BASEADDR                               (0x40006400UL)
#define CAN2_BASEADDR                               (0x40006800UL)

#define PWR_BASEADDR                                (0x40007000UL)

#define DAC_BASEADDR                                (0x40007400UL)


/* ================================================= APB2 PERIPHERALS =============================================== */

/**
 * @brief Base address of the peripherals connected to the APB2 bus
 *
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Table 1. STM32F4xx register boundary addresses
 */
#define TIM1_BASEADDR                               (APB2_PERIPHERAL_BASEADDR)
#define TIM8_BASEADDR                               (0x40010400UL)

#define USART1_BASEADDR                             (0x40011000UL)
#define USART6_BASEADDR                             (0x40011400UL)

#define ADC_COMMON_BASEADDR                         (0x40012000UL) /*!< ADC1, ADC2, ADC3 */

#define SDIO_BASEADDR                               (0x40012C00UL)

#define SPI1_BASEADDR                               (0x40013000UL)

#define SYSCFG_BASEADDR                             (0x40013800UL)

#define EXTI_BASEADDR                               (0x40013C00UL)

#define TIM9_BASEADDR                               (0x40014000UL)
#define TIM10_BASEADDR                              (0x40014400UL)
#define TIM11_BASEADDR                              (0x40014800UL)


/* ================================================ STRUCTURES (CPU) ================================================ */

/**
 * @brief NVIC register definition structure (memory-mapped)
 *
 * @note
 *
 * Refer to:
 * - ARM Cortex-M4 Generic User Guide,  Section 4.2 Nested Vectored Interrupt Controller
 */
typedef struct
{
    __IO uint32_t ISER[8];          /*<! Interrupt Set-enable Registers         | Address: 0xE000E100 - 0xE000E11C */
    __IO uint32_t RESERVED0[24];    /*<!                                                                           */

    __IO uint32_t ICER[8];          /*<! Interrupt Clear-enable Registers       | Address: 0XE000E180 - 0xE000E19C */
    __IO uint32_t RESERVED1[24];    /*<!                                                                           */

    __IO uint32_t ISPR[8];          /*<! Interrupt Set-pending Registers        | Address: 0XE000E200 - 0xE000E21C */
    __IO uint32_t RESERVED2[24];    /*<!                                                                           */

    __IO uint32_t ICPR[8];          /*<! Interrupt Clear-pending Registers      | Address: 0XE000E280 - 0xE000E29C */
    __IO uint32_t RESERVED3[24];    /*<!                                                                           */

    __IO uint32_t IABR[8];          /*<! Interrupt Active Bit Registers         | Address: 0xE000E300 - 0xE000E31C */
    __IO uint32_t RESERVED4[56];    /*<!                                                                           */

    __IO uint8_t IPR[240];          /*<! Interrupt Priority Registers           | Address: 0xE000E400 - 0xE000E4EF */
    __IO uint32_t RESERVED5[644];   /*<!                                                                           */

    __IO uint32_t STIR;             /*<! Software Trigger Interrupt Registers   | Address: 0xE000EF00              */
} NVIC_RegDef_t;


/* =============================================== PERIPHERALS (CPU) ================================================ */

/**
 * @brief NVIC peripheral definition (memory-mapped base addresses)
 * Provides typed access to NVIC registers using NVIC_RegDef_t
 */
#define NVIC            ((NVIC_RegDef_t* const)(NVIC_BASEADDR))


/* ================================================ STRUCTURES (MCU) ================================================ */

/**
 * @brief GPIO register definition structure (memory-mapped)
 *
 * @note Must match RM0090 register layout and offsets
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Section 8.4 GPIO registers
 */
typedef struct
{
	__IO uint32_t MODER;	/*!< GPIO port mode register	 		    | Offset: 0x00 */
	__IO uint32_t OTYPER;	/*!< GPIO port output type register			| Offset: 0x04 */
	__IO uint32_t OSPEEDR;	/*!< GPIO port output speed register	    | Offset: 0x08 */
	__IO uint32_t PUPDR;	/*!< GPIO port pull-up/pull-down register	| Offset: 0x0C */
	__IO uint32_t IDR;		/*!< GPIO port input data register			| Offset: 0x10 */
	__IO uint32_t ODR;		/*!< GPIO port output data register			| Offset: 0x14 */
	__IO uint32_t BSRR;		/*!< GPIO port bit set/reset register		| Offset: 0x18 */
	__IO uint32_t LCKR;		/*!< GPIO port configuration lock register	| Offset: 0x1C */
	__IO uint32_t AFRL;		/*!< GPIO alternate function low register   | Offset: 0x20 */
	__IO uint32_t AFRH;		/*!< GPIO alternate function high register	| Offset: 0x24 */
} GPIO_RegDef_t;


/**
 * @brief RCC register definition structure (memory-mapped)
 *
 * @note Must match RM0090 register layout and offsets
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Section 7.3 RCC registers
 */
typedef struct
{
	__IO uint32_t CR;			/*!< RCC clock control register	 									| Offset: 0x00 */
	__IO uint32_t PLLCFGR;		/*!< RCC PLL configuration register									| Offset: 0x04 */
	__IO uint32_t CFGR;			/*!< RCC clock configuration register								| Offset: 0x08 */
	__IO uint32_t CIR;			/*!< RCC clock interrupt register									| Offset: 0x0C */
	__IO uint32_t AHB1RSTR;		/*!< RCC AHB1 peripheral reset register								| Offset: 0x10 */
	__IO uint32_t AHB2RSTR;		/*!< RCC AHB2 peripheral reset register								| Offset: 0x14 */
	__IO uint32_t AHB3RSTR;		/*!< RCC AHB3 peripheral reset register								| Offset: 0x18 */
	__IO uint32_t RESERVED0;	/*!< 																| Offset: 0x1C */

	__IO uint32_t APB1RSTR;		/*!< RCC APB1 peripheral reset register								| Offset: 0x20 */
	__IO uint32_t APB2RSTR;		/*!< RCC APB2 peripheral reset register								| Offset: 0x24 */
	__IO uint32_t RESERVED1[2];	/*!< 																| Offset: 0x28, 0x2C */

	__IO uint32_t AHB1ENR;		/*!< RCC AHB1 peripheral clock enable register						| Offset: 0x30 */
	__IO uint32_t AHB2ENR;		/*!< RCC AHB2 peripheral clock enable register						| Offset: 0x34 */
	__IO uint32_t AHB3ENR;		/*!< RCC AHB3 peripheral clock enable register						| Offset: 0x38 */
	__IO uint32_t RESERVED2;	/*!< 																| Offset: 0x3C */

	__IO uint32_t APB1ENR;		/*!< RCC APB1 peripheral clock enable register						| Offset: 0x40 */
	__IO uint32_t APB2ENR;		/*!< RCC APB2 peripheral clock enable register						| Offset: 0x44 */
	__IO uint32_t RESERVED3[2];	/*!< 																| Offset: 0x48, 0x4C */

	__IO uint32_t AHB1LPENR;	/*!< RCC AHB1 peripheral clock enable in low power mode register	| Offset: 0x50 */
	__IO uint32_t AHB2LPENR;	/*!< RCC AHB2 peripheral clock enable in low power mode register	| Offset: 0x54 */
	__IO uint32_t AHB3LPENR;	/*!< RCC AHB3 peripheral clock enable in low power mode register	| Offset: 0x58 */
	__IO uint32_t RESERVED4;	/*!< 																| Offset: 0x5C */

	__IO uint32_t APB1LPENR;	/*!< RCC APB1 peripheral clock enable in low power mode register	| Offset: 0x60 */
	__IO uint32_t APB2LPENR;	/*!< RCC APB2 peripheral clock enabled in low power mode register	| Offset: 0x64 */
	__IO uint32_t RESERVED5[2];	/*!< 																| Offset: 0x68, 0x6C */

	__IO uint32_t BDCR;			/*!< RCC Backup domain control register								| Offset: 0x70 */
	__IO uint32_t CSR;			/*!< RCC clock control & status register							| Offset: 0x74 */
	__IO uint32_t RESERVED6[2];	/*!< 															    | Offset: 0x78, 0x7C */

	__IO uint32_t SSCGR;		/*!< RCC spread spectrum clock generation register					| Offset: 0x80 */
	__IO uint32_t PLLI2SCFGR;	/*!< RCC PLLI2S configuration register								| Offset: 0x84 */
} RCC_RegDef_t;


/**
 * @brief EXTI register definition structure (memory-mapped)
 *
 * @note Must match RM0090 register layout and offsets
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Section 12.3 EXTI registers
 */
typedef struct
{
    __IO uint32_t IMR;      /*!< Interrupt mask register                | Offset: 0x00 */
    __IO uint32_t EMR;      /*!< Event mask register                    | Offset: 0x04 */
    __IO uint32_t RTSR;     /*!< Rising trigger selection register      | Offset: 0x08 */
    __IO uint32_t FTSR;     /*!< Falling trigger selection register     | Offset: 0x0C */
    __IO uint32_t SWIER;    /*!< Software interrupt event register      | Offset: 0x10 */
    __IO uint32_t PR;       /*!< Pending register                       | Offset: 0x14 */
} EXTI_RegDef_t;


/**
 * @brief SYSCFG register definition structure (memory-mapped)
 *
 * @note Must match RM0090 register layout and offsets
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Section 9.2 SYSCFG registers for STM32F405xx/07xx
 */
typedef struct
{
    __IO uint32_t MEMRMP;           /*!< SYSCFG memory remap register                                   | Offset: 0x00 */
    __IO uint32_t PMC;              /*!< SYSCFG peripheral mode configuration register                  | Offset: 0x04 */
    __IO uint32_t EXTICR[4];        /*!< SYSCFG external interrupt configuration register 1, 2, 3, 4    | Offset: 0x08 */
    __IO uint32_t RESERVED0[2];     /*!<                                                                | Offset: 0x18, 0x1C*/
    __IO uint32_t CMPCR;            /*!< Compensation cell control register                             | Offset: 0x20 */
} SYSCFG_RegDef_t;


/**
 * @brief SPI register definition structure (memory-mapped)
 * 
 * @note Must match RM0090 register layout and offsets
 * 
 * Refer to:
 * - RM0090 Reference Manual,	Section 28.5 SPI and I2S register
 */
typedef struct 
{
    __IO uint32_t CR1;          /*!< SPI control register 1 (not used in I2S mode)          | Offset: 0x00 */
    __IO uint32_t CR2;          /*!< SPI control register 2                                 | Offset: 0x04 */
    __IO uint32_t SR;           /*!< SPI status register                                    | Offset: 0x08 */
    __IO uint32_t DR;           /*!< SPI data register                                      | Offset: 0x0C */
    __IO uint32_t CRCPR;        /*!< SPI CRC polynomial register (not used in I2S mode)     | Offset: 0x10 */
    __IO uint32_t RXCRCR;       /*!< SPI RX CRC register (not used in I2S mode)             | Offset: 0x14 */
    __IO uint32_t TXCRCR;       /*!< SPI TX CRC register (not used in I2S mode)             | Offset: 0x18 */
    __IO uint32_t I2SCFGR;      /*!< SPI_I2S configuration register                         | Offset: 0x1C */
    __IO uint32_t I2SPR;        /*!< SPI_I2S prescaler register                             | Offset: 0x20 */
} SPI_RegDef_t;


/* =============================================== PERIPHERALS (MCU) ================================================ */

/**
 * @brief GPIO peripheral definitions (memory-mapped base addresses)
 * 
 * @details Provides typed access to GPIO registers using GPIO_RegDef_t
 */
#define GPIOA 			((GPIO_RegDef_t* const)(GPIOA_BASEADDR))
#define GPIOB 			((GPIO_RegDef_t* const)(GPIOB_BASEADDR))
#define GPIOC 			((GPIO_RegDef_t* const)(GPIOC_BASEADDR))
#define GPIOD 			((GPIO_RegDef_t* const)(GPIOD_BASEADDR))
#define GPIOE 			((GPIO_RegDef_t* const)(GPIOE_BASEADDR))
#define GPIOF 			((GPIO_RegDef_t* const)(GPIOF_BASEADDR))
#define GPIOG 			((GPIO_RegDef_t* const)(GPIOG_BASEADDR))
#define GPIOH 			((GPIO_RegDef_t* const)(GPIOH_BASEADDR))
#define GPIOI 			((GPIO_RegDef_t* const)(GPIOI_BASEADDR))


/**
 * @brief RCC peripheral definition (memory-mapped base addresses)
 *
 * @details Provides typed access to RCC registers using RCC_RegDef_t
 */
#define RCC             ((RCC_RegDef_t* const)(RCC_BASEADDR))


/**
 * @brief EXTI peripheral definition (memory-mapped base addresses)
 * 
 * @details Provides typed access to EXTI registers using EXTI_RegDef_t
 */
#define EXTI            ((EXTI_RegDef_t* const)(EXTI_BASEADDR))


/**
 * @brief SYSCFG peripheral definition (memory-mapped base addresses)
 * 
 * @details Provides typed access to SYSCFG registers using SYSCFG_RegDef_t
 */
#define SYSCFG          ((SYSCFG_RegDef_t* const)(SYSCFG_BASEADDR))


/**
 * @brief SPI peripheral definition (memory-mapped base addresses)
 *
 * @details Provides typed access to SPI registers using SPI_RegDef_t
 */
#define SPI1            ((SPI_RegDef_t* const)(SPI1_BASEADDR))
#define SPI2            ((SPI_RegDef_t* const)(SPI2_I2S2_BASEADDR))
#define SPI3            ((SPI_RegDef_t* const)(SPI3_I2S3_BASEADDR))


/* =============================================== MACROS PERIPHERALS =============================================== */

/**
 * @brief Enable the GPIO peripheral clock on the AHB1 bus
 * 
 * @details These macros enable the GPIO peripheral clock via the RCC AHB1ENR register.
 */
#define GPIOA_PCLK_EN()				(RCC->AHB1ENR |= (1U << 0))
#define GPIOB_PCLK_EN()				(RCC->AHB1ENR |= (1U << 1))
#define GPIOC_PCLK_EN()				(RCC->AHB1ENR |= (1U << 2))
#define GPIOD_PCLK_EN()				(RCC->AHB1ENR |= (1U << 3))
#define GPIOE_PCLK_EN()				(RCC->AHB1ENR |= (1U << 4))
#define GPIOF_PCLK_EN()				(RCC->AHB1ENR |= (1U << 5))
#define GPIOG_PCLK_EN()				(RCC->AHB1ENR |= (1U << 6))
#define GPIOH_PCLK_EN()				(RCC->AHB1ENR |= (1U << 7))
#define GPIOI_PCLK_EN()				(RCC->AHB1ENR |= (1U << 8))


/**
 * @brief Disable the GPIO peripheral clock on the AHB1 bus
 * 
 * @details These macros disable the GPIO peripheral clock via the RCC AHB1ENR register.
 */
#define GPIOA_PCLK_DI()				(RCC->AHB1ENR &= ~(1U << 0))
#define GPIOB_PCLK_DI()				(RCC->AHB1ENR &= ~(1U << 1))
#define GPIOC_PCLK_DI()				(RCC->AHB1ENR &= ~(1U << 2))
#define GPIOD_PCLK_DI()				(RCC->AHB1ENR &= ~(1U << 3))
#define GPIOE_PCLK_DI()				(RCC->AHB1ENR &= ~(1U << 4))
#define GPIOF_PCLK_DI()				(RCC->AHB1ENR &= ~(1U << 5))
#define GPIOG_PCLK_DI()				(RCC->AHB1ENR &= ~(1U << 6))
#define GPIOH_PCLK_DI()				(RCC->AHB1ENR &= ~(1U << 7))
#define GPIOI_PCLK_DI()				(RCC->AHB1ENR &= ~(1U << 8))


/**
 * @brief Reset GPIO ports
 * 
 * @details These macros reset the GPIO peripheral via the RCC AHB1RSTR register.
 */
#define GPIOA_REG_RESET()           do {(RCC->AHB1RSTR |= (1U << 0)); (RCC->AHB1RSTR &= ~(1U << 0));} while(0)
#define GPIOB_REG_RESET()           do {(RCC->AHB1RSTR |= (1U << 1)); (RCC->AHB1RSTR &= ~(1U << 1));} while(0)
#define GPIOC_REG_RESET()           do {(RCC->AHB1RSTR |= (1U << 2)); (RCC->AHB1RSTR &= ~(1U << 2));} while(0)
#define GPIOD_REG_RESET()           do {(RCC->AHB1RSTR |= (1U << 3)); (RCC->AHB1RSTR &= ~(1U << 3));} while(0)
#define GPIOE_REG_RESET()           do {(RCC->AHB1RSTR |= (1U << 4)); (RCC->AHB1RSTR &= ~(1U << 4));} while(0)
#define GPIOF_REG_RESET()           do {(RCC->AHB1RSTR |= (1U << 5)); (RCC->AHB1RSTR &= ~(1U << 5));} while(0)
#define GPIOG_REG_RESET()           do {(RCC->AHB1RSTR |= (1U << 6)); (RCC->AHB1RSTR &= ~(1U << 6));} while(0)
#define GPIOH_REG_RESET()           do {(RCC->AHB1RSTR |= (1U << 7)); (RCC->AHB1RSTR &= ~(1U << 7));} while(0)
#define GPIOI_REG_RESET()           do {(RCC->AHB1RSTR |= (1U << 8)); (RCC->AHB1RSTR &= ~(1U << 8));} while(0)


/**
 * @brief Enable the I2C peripheral clock on the APB1 bus
 * 
 * @details These macros enable the I2C peripheral clock via the RCC APB1ENR register.
 */
#define I2C1_PCLK_EN()				(RCC->APB1ENR |= (1U << 21))
#define I2C2_PCLK_EN()				(RCC->APB1ENR |= (1U << 22))
#define I2C3_PCLK_EN()				(RCC->APB1ENR |= (1U << 23))


/**
 * @brief Disable the I2C peripheral clock on the APB1 bus
 * 
 * @details These macros disable the I2C peripheral clock via the RCC APB1ENR register.
 */
#define I2C1_PCLK_DI()				(RCC->APB1ENR &= ~(1U << 21))
#define I2C2_PCLK_DI()				(RCC->APB1ENR &= ~(1U << 22))
#define I2C3_PCLK_DI()				(RCC->APB1ENR &= ~(1U << 23))


/**
 * @brief Enable the SPI peripheral clock on the APB1 and APB2 buses
 * 
 * @details These macros enable the SPI peripheral clock via the RCC APB1ENR and RCC APB2ENR registers.
 */
#define SPI1_PCLK_EN()				(RCC->APB2ENR |= (1U << 12))
#define SPI2_PCLK_EN()				(RCC->APB1ENR |= (1U << 14))
#define SPI3_PCLK_EN()				(RCC->APB1ENR |= (1U << 15))


/**
 * @brief Disable the SPI peripheral clock on the APB1 and APB2 buses
 * 
 * @details These macros disable the SPI peripheral clock via the RCC APB1ENR and RCC APB2ENR registers.
 */
#define SPI1_PCLK_DI()				(RCC->APB2ENR &= ~(1U << 12))
#define SPI2_PCLK_DI()				(RCC->APB1ENR &= ~(1U << 14))
#define SPI3_PCLK_DI()				(RCC->APB1ENR &= ~(1U << 15))


/**
 * @brief Reset the SPI peripheral registers
 * 
 * @details These macros reset the SPI peripheral via the RCC APB1RSTR and RCC APB2RSTR register.
 */
#define SPI1_REG_RESET()            do {(RCC->APB2RSTR |= (1U << 12)); (RCC->APB2RSTR &= ~(1U << 12));} while(0)
#define SPI2_REG_RESET()            do {(RCC->APB1RSTR |= (1U << 14)); (RCC->APB1RSTR &= ~(1U << 14));} while(0)
#define SPI3_REG_RESET()            do {(RCC->APB1RSTR |= (1U << 15)); (RCC->APB1RSTR &= ~(1U << 15));} while(0)


/**
 * @brief Enable the USART/UART peripheral clock on the APB1 and APB2 buses
 * 
 * @details These macros enable the USART/UART peripheral clock via the RCC APB1ENR and RCC APB2ENR registers.
 */
#define USART1_PCLK_EN()			(RCC->APB2ENR |= (1U << 4))
#define USART2_PCLK_EN()			(RCC->APB1ENR |= (1U << 17))
#define USART3_PCLK_EN()			(RCC->APB1ENR |= (1U << 18))
#define USART6_PCLK_EN()			(RCC->APB2ENR |= (1U << 5))
#define UART4_PCLK_EN()				(RCC->APB1ENR |= (1U << 19))
#define UART5_PCLK_EN()				(RCC->APB1ENR |= (1U << 20))


/**
 * @brief Disable the USART/UART peripheral clock on the APB1 and APB2 buses
 * 
 * @details These macros disable the USART/UART peripheral clock via the RCC APB1ENR and RCC APB2ENR registers.
 */
#define USART1_PCLK_DI()			(RCC->APB2ENR &= ~(1U << 4))
#define USART2_PCLK_DI()			(RCC->APB1ENR &= ~(1U << 17))
#define USART3_PCLK_DI()			(RCC->APB1ENR &= ~(1U << 18))
#define USART6_PCLK_DI()			(RCC->APB2ENR &= ~(1U << 5))
#define UART4_PCLK_DI()				(RCC->APB1ENR &= ~(1U << 19))
#define UART5_PCLK_DI()				(RCC->APB1ENR &= ~(1U << 20))


/**
 * @brief Enable the SYSCFG peripheral clock on the APB2 bus
 * 
 * @details These macros enable the SYSCFG peripheral clock via the RCC APB2ENR registers.
 */
#define SYSCFG_PCLK_EN()			(RCC->APB2ENR |= (1U << 14))


/**
 * @brief Disable the SYSCFG peripheral clock on the APB2 bus
 * 
 * @details These macros disable the SYSCFG peripheral clock via the RCC APB2ENR registers.
 */
#define SYSCFG_PCLK_DI()			(RCC->APB2ENR &= ~(1U << 14))


/**
 * @brief Return port code for given GPIOx base address
 */
#define GPIO_BASEADDR_TO_CODE(x)    (   (x == GPIOA) ? 0 :\
                                        (x == GPIOB) ? 1 :\
                                        (x == GPIOC) ? 2 :\
                                        (x == GPIOD) ? 3 :\
                                        (x == GPIOE) ? 4 :\
                                        (x == GPIOF) ? 5 :\
                                        (x == GPIOG) ? 6 :\
                                        (x == GPIOH) ? 7 :\
                                        (x == GPIOI) ? 8 : 0xFF)
#define GPIO_MAX_PORTCODE           (8U)


/**
 * @brief IRQ (Interrupt request) number of STM32F407XX MCU
 * 
 * @note
 * 
 * Refer to:
 * - RM0090 Reference Manual,   Table 62. Vector table for STM32F405xx/07xx
 */
#define IRQ_NO_WWDG                     0    /* Window Watchdog interrupt */
#define IRQ_NO_PVD                      1    /* PVD through EXTI Line detection interrupt */
#define IRQ_NO_TAMP_STAMP               2    /* Tamper and TimeStamp interrupts through EXTI line */
#define IRQ_NO_RTC_WKUP                 3    /* RTC Wakeup interrupt through EXTI line */
#define IRQ_NO_FLASH                    4    /* Flash global interrupt */
#define IRQ_NO_RCC                      5    /* RCC global interrupt */
#define IRQ_NO_EXTI0                    6    /* EXTI Line0 interrupt */
#define IRQ_NO_EXTI1                    7    /* EXTI Line1 interrupt */
#define IRQ_NO_EXTI2                    8    /* EXTI Line2 interrupt */
#define IRQ_NO_EXTI3                    9    /* EXTI Line3 interrupt */
#define IRQ_NO_EXTI4                    10   /* EXTI Line4 interrupt */
#define IRQ_NO_DMA1_STREAM0             11   /* DMA1 Stream0 global interrupt */
#define IRQ_NO_DMA1_STREAM1             12   /* DMA1 Stream1 global interrupt */
#define IRQ_NO_DMA1_STREAM2             13   /* DMA1 Stream2 global interrupt */
#define IRQ_NO_DMA1_STREAM3             14   /* DMA1 Stream3 global interrupt */
#define IRQ_NO_DMA1_STREAM4             15   /* DMA1 Stream4 global interrupt */
#define IRQ_NO_DMA1_STREAM5             16   /* DMA1 Stream5 global interrupt */
#define IRQ_NO_DMA1_STREAM6             17   /* DMA1 Stream6 global interrupt */
#define IRQ_NO_ADC                      18   /* ADC1, ADC2 and ADC3 global interrupts */
#define IRQ_NO_CAN1_TX                  19   /* CAN1 TX interrupts */
#define IRQ_NO_CAN1_RX0                 20   /* CAN1 RX0 interrupts */
#define IRQ_NO_CAN1_RX1                 21   /* CAN1 RX1 interrupts */
#define IRQ_NO_CAN1_SCE                 22   /* CAN1 SCE interrupt */
#define IRQ_NO_EXTI9_5                  23   /* EXTI Line[9:5] interrupts */
#define IRQ_NO_TIM1_BRK_TIM9            24   /* TIM1 Break and TIM9 interrupts */
#define IRQ_NO_TIM1_UP_TIM10            25   /* TIM1 Update and TIM10 interrupts */
#define IRQ_NO_TIM1_TRG_COM_TIM11       26   /* TIM1 Trigger/Commutation and TIM11 interrupts */
#define IRQ_NO_TIM1_CC                  27   /* TIM1 Capture Compare interrupt */
#define IRQ_NO_TIM2                     28   /* TIM2 global interrupt */
#define IRQ_NO_TIM3                     29   /* TIM3 global interrupt */
#define IRQ_NO_TIM4                     30   /* TIM4 global interrupt */
#define IRQ_NO_I2C1_EV                  31   /* I2C1 event interrupt */
#define IRQ_NO_I2C1_ER                  32   /* I2C1 error interrupt */
#define IRQ_NO_I2C2_EV                  33   /* I2C2 event interrupt */
#define IRQ_NO_I2C2_ER                  34   /* I2C2 error interrupt */
#define IRQ_NO_SPI1                     35   /* SPI1 global interrupt */
#define IRQ_NO_SPI2                     36   /* SPI2 global interrupt */
#define IRQ_NO_USART1                   37   /* USART1 global interrupt */
#define IRQ_NO_USART2                   38   /* USART2 global interrupt */
#define IRQ_NO_USART3                   39   /* USART3 global interrupt */
#define IRQ_NO_EXTI15_10                40   /* EXTI Line[15:10] interrupts */
#define IRQ_NO_RTC_ALARM                41   /* RTC Alarm (A and B) through EXTI line interrupt */
#define IRQ_NO_OTG_FS_WKUP              42   /* USB OTG FS Wakeup through EXTI line interrupt */
#define IRQ_NO_TIM8_BRK_TIM12           43   /* TIM8 Break and TIM12 interrupts */
#define IRQ_NO_TIM8_UP_TIM13            44   /* TIM8 Update and TIM13 interrupts */
#define IRQ_NO_TIM8_TRG_COM_TIM14       45   /* TIM8 Trigger/Commutation and TIM14 interrupts */
#define IRQ_NO_TIM8_CC                  46   /* TIM8 Capture Compare interrupt */
#define IRQ_NO_DMA1_STREAM7             47   /* DMA1 Stream7 global interrupt */
#define IRQ_NO_FSMC                     48   /* FSMC global interrupt */
#define IRQ_NO_SDIO                     49   /* SDIO global interrupt */
#define IRQ_NO_TIM5                     50   /* TIM5 global interrupt */
#define IRQ_NO_SPI3                     51   /* SPI3 global interrupt */
#define IRQ_NO_UART4                    52   /* UART4 global interrupt */
#define IRQ_NO_UART5                    53   /* UART5 global interrupt */
#define IRQ_NO_TIM6_DAC                 54   /* TIM6 global and DAC underrun error interrupt */
#define IRQ_NO_TIM7                     55   /* TIM7 global interrupt */
#define IRQ_NO_DMA2_STREAM0             56   /* DMA2 Stream0 global interrupt */
#define IRQ_NO_DMA2_STREAM1             57   /* DMA2 Stream1 global interrupt */
#define IRQ_NO_DMA2_STREAM2             58   /* DMA2 Stream2 global interrupt */
#define IRQ_NO_DMA2_STREAM3             59   /* DMA2 Stream3 global interrupt */
#define IRQ_NO_DMA2_STREAM4             60   /* DMA2 Stream4 global interrupt */
#define IRQ_NO_ETH                      61   /* Ethernet global interrupt */
#define IRQ_NO_ETH_WKUP                 62   /* Ethernet Wakeup through EXTI line interrupt */
#define IRQ_NO_CAN2_TX                  63   /* CAN2 TX interrupts */
#define IRQ_NO_CAN2_RX0                 64   /* CAN2 RX0 interrupts */
#define IRQ_NO_CAN2_RX1                 65   /* CAN2 RX1 interrupts */
#define IRQ_NO_CAN2_SCE                 66   /* CAN2 SCE interrupt */
#define IRQ_NO_OTG_FS                   67   /* USB OTG FS global interrupt */
#define IRQ_NO_DMA2_STREAM5             68   /* DMA2 Stream5 global interrupt */
#define IRQ_NO_DMA2_STREAM6             69   /* DMA2 Stream6 global interrupt */
#define IRQ_NO_DMA2_STREAM7             70   /* DMA2 Stream7 global interrupt */
#define IRQ_NO_USART6                   71   /* USART6 global interrupt */
#define IRQ_NO_I2C3_EV                  72   /* I2C3 event interrupt */
#define IRQ_NO_I2C3_ER                  73   /* I2C3 error interrupt */
#define IRQ_NO_OTG_HS_EP1_OUT           74   /* USB OTG HS End Point 1 Out global interrupt */
#define IRQ_NO_OTG_HS_EP1_IN            75   /* USB OTG HS End Point 1 In global interrupt */
#define IRQ_NO_OTG_HS_WKUP              76   /* USB OTG HS Wakeup through EXTI interrupt */
#define IRQ_NO_OTG_HS                   77   /* USB OTG HS global interrupt */
#define IRQ_NO_DCMI                     78   /* DCMI global interrupt */
#define IRQ_NO_CRYP                     79   /* CRYP crypto global interrupt */
#define IRQ_NO_HASH_RNG                 80   /* Hash and RNG global interrupt */
#define IRQ_NO_FPU                      81   /* FPU global interrupt */
#define IRQ_MAX_NUMBER                  81


#endif /* INC_STM32F407XX_H_ */