/**
 * File name: stm32f407xx.h
 *
 * Created on: 14/4/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_


#include <stdint.h>


/* ======================================== FLASH + SRAM + SYSTEM MEMORY ======================================== */

/**
 * @brief Base address of FLASH, SRAM and SYSTEM memory
 *
 * @note
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
#define FLASH_SIZE									(1014UL * 1024UL)				// 1 MB

#define SRAM_BASEADDR								(0x20000000UL)
#define SRAM1_BASEADDR								SRAM_BASEADDR
#define SRAM1_SIZE									(112UL * 1024UL) 				// 112 KB

#define SRAM2_BASEADDR								(SRAM1_BASEADDR + SRAM1_SIZE)
#define SRAM2_SIZE									(16UL * 1024UL) 				// 16 KB

#define SYSTEM_MEMORY_BASEADDR						(0x1FFF0000UL)
#define SYSTEM_MEMORY_SIZE							(30UL * 1024UL)					// 30 KB


/* ======================================== APBx and AHBx Bus Interfaces ======================================== */

/**
 * @brief Base address of the bus interfaces
 *
 * @note
 * Refer to:
 * - RM0090 Reference Manual,	Table 1. STM32F4xx register boundary addresses
 */
#define PERIPHERAL_BASEADDR							(0x40000000UL)
#define APB1_PERIPHERAL_BASEADDR					(PERIPHERAL_BASEADDR)
#define APB2_PERIPHERAL_BASEADDR					(0x40010000UL)
#define	AHB1_PERIPHERAL_BASEADDR					(0x40020000UL)
#define AHB2_PERIPHERAL_BASEADDR					(0x50000000UL)
#define AHB3_PERIPHERAL_BASEADDR					(0xA0000000UL)


/* ======================================== AHB1 Peripherals ======================================== */

/**
 * @brief Base address of the peripherals connected to the AHB1 bus
 *
 * @note
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
#define GPIOJ_BASEADDR								(0x40022400UL)
#define GPIOK_BASEADDR								(0x40022800UL)

#define CRC_BASEADDR								(0x40023000UL)

#define RCC_BASEADDR								(0x40023800UL)

#define FLASH_INTERFACE_REG_BASEADDR				(0x40023C00UL)

#define BKPSRAM_BASEADDR							(0x40024000UL)

#define DMA1_BASEADDR								(0x40026000UL)
#define DMA2_BASEADDR								(0x40026400UL)

#define ETHERNET_MAC_BASEADDR						(0x40028000UL)

#define DMA2D_BASEADDR								(0x4002B000UL)

#define USB_OTG_HS_BASEADDR							(0x40040000UL)


/* ======================================== APB1 Peripherals ======================================== */

/**
 * @brief Base address of the peripherals connected to the APB1 bus
 *
 * @note
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

#define I2S2ext_BASEADDR                            (0x40003400UL)

#define SPI2_I2S2_BASEADDR                          (0x40003800UL)
#define SPI3_I2S3_BASEADDR                          (0x40003C00UL)

#define I2S3ext_BASEADDR                            (0x40004000UL)

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

#define UART7_BASEADDR                              (0x40007800UL)
#define UART8_BASEADDR                              (0x40007C00UL)


/* ======================================== APB2 Peripherals ======================================== */

/**
 * @brief Base address of the peripherals connected to the APB2 bus
 *
 * @note
 * Refer to:
 * - RM0090 Reference Manual,	Table 1. STM32F4xx register boundary addresses
 */
#define TIM1_BASEADDR                               (APB2_PERIPHERAL_BASEADDR)
#define TIM8_BASEADDR                               (0x40010400UL)

#define USART1_BASEADDR                             (0x40011000UL)
#define USART6_BASEADDR                             (0x40011400UL)

#define ADC_COMMON_BASEADDR                         (0x40012000UL) // ADC1, ADC2, ADC3

#define SDIO_BASEADDR                               (0x40012C00UL)

#define SPI1_BASEADDR                               (0x40013000UL)
#define SPI4_BASEADDR                               (0x40013400UL)

#define SYSCFG_BASEADDR                             (0x40013800UL)

#define EXTI_BASEADDR                               (0x40013C00UL)

#define TIM9_BASEADDR                               (0x40014000UL)
#define TIM10_BASEADDR                              (0x40014400UL)
#define TIM11_BASEADDR                              (0x40014800UL)

#define SPI5_BASEADDR                               (0x40015000UL)
#define SPI6_BASEADDR                               (0x40015400UL)

#define SAI1_BASEADDR                               (0x40015800UL)

#define LTDC_BASEADDR                               (0x40016800UL) // LCD-TFT


/* =================================== Peripheral Register Definition Structures  =================================== */

/**
 * @brief GPIO register definition structure (memory-mapped)
 *
 * @note Must match RM0090 register layout and offsets
 * Refer to:
 * - RM0090 Reference Manual,	Section 8.4 GPIO registers
 */
typedef struct
{
	volatile uint32_t MODER;	/*| GPIO port mode register	 				| Offset: 0x00 */
	volatile uint32_t OTYPER;	/*| GPIO port output type register			| Offset: 0x04 */
	volatile uint32_t OSPEEDR;	/*| GPIO port output speed register			| Offset: 0x08 */
	volatile uint32_t PUPDR;	/*| GPIO port pull-up/pull-down register	| Offset: 0x0C */
	volatile uint32_t IDR;		/*| GPIO port input data register			| Offset: 0x10 */
	volatile uint32_t ODR;		/*| GPIO port output data register			| Offset: 0x14 */
	volatile uint32_t BSRR;		/*| GPIO port bit set/reset register		| Offset: 0x18 */
	volatile uint32_t LCKR;		/*| GPIO port configuration lock register	| Offset: 0x1C */
	volatile uint32_t AFRL;		/*| GPIO alternate function low register	| Offset: 0x20 */
	volatile uint32_t AFRH;		/*| GPIO alternate function high register	| Offset: 0x24 */
} GPIO_RegDef_t;


#endif /* INC_STM32F407XX_H_ */
