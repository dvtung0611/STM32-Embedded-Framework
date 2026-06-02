/**
 * File name: rcc-driver.h
 *
 * Created on: 02/06/2026
 * Author: Van Tung Dinh
 */

#ifndef INC_RCC_DRIVER_H_
#define INC_RCC_DRIVER_H_

#include <stdint.h>
#include "stm32f407xx.h"


/* ===================================================== MACROS ===================================================== */

#define RCC_BUS_MASK      0xFFFF0000U
#define RCC_BITPOS_MASK   0x0000FFFFU


/* ================================================== BIT POSITION ================================================== */

/**
 * @RCC_CR
 */
#define RCC_CR_HSION            (0U)    /*!< Internal high-speed clock enable       | Bit 0 */
#define RCC_CR_HSIRDY           (1U)    /*!< Internal high-speed clock ready flag   | Bit 1 */
#define RCC_CR_HSITRIM          (3U)    /*!< Internal high-speed clock trimming     | Bit 7:3 */
#define RCC_CR_HSICAL           (8U)    /*!< Internal high-speed clock calibration  | Bit 15:8 */
#define RCC_CR_HSEON            (16U)   /*!< HSE clock enable                       | Bit 16 */
#define RCC_CR_HSERDY           (17U)   /*!< HSE clock ready flag                   | Bit 17 */
#define RCC_CR_HSEBYP           (18U)   /*!< HSE clock bypass                       | Bit 18 */
#define RCC_CR_CSSON            (19U)   /*!< Clock security system enable           | Bit 19 */
#define RCC_CR_PLLON            (24U)   /*!< Main PLL (PLL) enable                  | Bit 24 */
#define RCC_CR_PLLRDY           (25U)   /*!< Main PLL (PLL) clock ready flag        | Bit 25 */
#define RCC_CR_PLLI2SON         (26U)   /*!< PLLI2S enable                          | Bit 26 */
#define RCC_CR_PLLI2SRDY        (27U)   /*!< PLLI2S clock ready flag                | Bit 27 */


/**
 * @RCC_PLLCFGR
 */
#define RCC_PLLCFGR_PLLM        (0U)    /*!< Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock  | Bits 5:0  */
#define RCC_PLLCFGR_PLLN        (6U)    /*!< Main PLL (PLL) multiplication factor for VCO                               | Bits 14:6 */
#define RCC_PLLCFGR_PLLP        (16U)   /*!< Main PLL (PLL) division factor for main system clock                       | Bits 17:16 */
#define RCC_PLLCFGR_PLLSRC      (22U)   /*!< Main PLL (PLL) and audio PLL (PLLI2S) entry clock source                   | Bit 22 */
#define RCC_PLLCFGR_PLLQ        (24U)   /*!< Main PLL (PLL) division factor for USB OTG, SDIO...                        | Bits 27:24 */


/**
 * @RCC_CFGR
 */
#define RCC_CFGR_SW             (0U)    /*!< System clock switch                            | Bits 1:0 */
#define RCC_CFGR_SWS            (2U)    /*!< System clock switch status                     | Bits 3:2 */
#define RCC_CFGR_HPRE           (4U)    /*!< AHB prescaler                                  | Bits 7:4 */
#define RCC_CFGR_PPRE1          (10U)   /*!< APB Low-speed prescaler (APB1)                 | Bits 12:10 */
#define RCC_CFGR_PPRE2          (13U)   /*!< APB High-speed prescaler (APB2)                | Bits 15:13 */
#define RCC_CFGR_RTCPRE         (16U)   /*!< HSE division factor for RTC clock              | Bits 20:16 */
#define RCC_CFGR_MCO1           (21U)   /*!< Microcontroller clock output 1                 | Bits 22:21 */
#define RCC_CFGR_I2SSRC         (23U)   /*!< I2S clock selection                            | Bit 23 */
#define RCC_CFGR_MCO1PRE        (24U)   /*!< MCO1 prescaler                                 | Bits 26:24 */
#define RCC_CFGR_MCO2PRE        (27U)   /*!< MCO2 prescaler                                 | Bits 29:27 */
#define RCC_CFGR_MCO2           (30U)   /*!< Microcontroller clock output 2                 | Bits 31:30 */


/**
 * @RCC_CIR
 */
#define RCC_CIR_LSIRDYF         (0U)    /*!< LSI ready interrupt flag                       | Bit 0  */
#define RCC_CIR_LSERDYF         (1U)    /*!< LSE ready interrupt flag                       | Bit 1  */
#define RCC_CIR_HSIRDYF         (2U)    /*!< HSI ready interrupt flag                       | Bit 2  */
#define RCC_CIR_HSERDYF         (3U)    /*!< HSE ready interrupt flag                       | Bit 3  */
#define RCC_CIR_PLLRDYF         (4U)    /*!< Main PLL ready interrupt flag                  | Bit 4  */
#define RCC_CIR_PLLI2SRDYF      (5U)    /*!< PLLI2S ready interrupt flag                    | Bit 5  */
#define RCC_CIR_CSSF            (7U)    /*!< Clock security system interrupt flag           | Bit 7  */
#define RCC_CIR_LSIRDYIE        (8U)    /*!< LSI ready interrupt enable                     | Bit 8  */
#define RCC_CIR_LSERDYIE        (9U)    /*!< LSE ready interrupt enable                     | Bit 9  */
#define RCC_CIR_HSIRDYIE        (10U)   /*!< HSI ready interrupt enable                     | Bit 10 */
#define RCC_CIR_HSERDYIE        (11U)   /*!< HSE ready interrupt enable                     | Bit 11 */
#define RCC_CIR_PLLRDYIE        (12U)   /*!< Main PLL ready interrupt enable                | Bit 12 */
#define RCC_CIR_PLLI2SRDYIE     (13U)   /*!< PLLI2S ready interrupt enable                  | Bit 13 */
#define RCC_CIR_LSIRDYC         (16U)   /*!< LSI ready interrupt clear                      | Bit 16 */
#define RCC_CIR_LSERDYC         (17U)   /*!< LSE ready interrupt clear                      | Bit 17 */
#define RCC_CIR_HSIRDYC         (18U)   /*!< HSI ready interrupt clear                      | Bit 18 */
#define RCC_CIR_HSERDYC         (19U)   /*!< HSE ready interrupt clear                      | Bit 19 */
#define RCC_CIR_PLLRDYC         (20U)   /*!< Main PLL ready interrupt clear                 | Bit 20 */
#define RCC_CIR_PLLI2SRDYC      (21U)   /*!< PLLI2S ready interrupt clear                   | Bit 21 */
#define RCC_CIR_CSSC            (23U)   /*!< Clock security system interrupt clear          | Bit 23 */


/**
 * @RCC_AHB1RSTR
 */
#define RCC_AHB1RSTR_GPIOARST   (0U)    /*!< IO port A reset            | Bit 0 */
#define RCC_AHB1RSTR_GPIOBRST   (1U)    /*!< IO port B reset            | Bit 1 */
#define RCC_AHB1RSTR_GPIOCRST   (2U)    /*!< IO port C reset            | Bit 2 */
#define RCC_AHB1RSTR_GPIODRST   (3U)    /*!< IO port D reset            | Bit 3 */
#define RCC_AHB1RSTR_GPIOERST   (4U)    /*!< IO port E reset            | Bit 4 */
#define RCC_AHB1RSTR_GPIOFRST   (5U)    /*!< IO port F reset            | Bit 5 */
#define RCC_AHB1RSTR_GPIOGRST   (6U)    /*!< IO port G reset            | Bit 6 */
#define RCC_AHB1RSTR_GPIOHRST   (7U)    /*!< IO port H reset            | Bit 7 */
#define RCC_AHB1RSTR_GPIOIRST   (8U)    /*!< IO port I reset            | Bit 8 */
#define RCC_AHB1RSTR_CRCRST     (12U)   /*!< CRC reset                  | Bit 12 */
#define RCC_AHB1RSTR_DMA1RST    (21U)   /*!< DMA1 reset                 | Bit 21 */
#define RCC_AHB1RSTR_DMA2RST    (22U)   /*!< DMA2 reset                 | Bit 22 */
#define RCC_AHB1RSTR_ETHMACRST  (25U)   /*!< Ethernet MAC reset         | Bit 25 */
#define RCC_AHB1RSTR_OTGHSRST   (29U)   /*!< USB OTG HS module reset    | Bit 29 */


/**
 * @RCC_AHB2RSTR
 */
#define RCC_AHB2RSTR_OTGFSRST   (7U)    /*!< USB OTG FS reset           | Bit 7 */


/**
 * @RCC_AHB3RSTR
 */
#define RCC_AHB3RSTR_FSMCRST    (0U)    /*!< FSMC reset                 | Bit 0 */


/**
 * @RCC_APB1RSTR
 */
#define RCC_APB1RSTR_TIM2RST    (0U)    /*!< TIM2 reset                 | Bit 0 */
#define RCC_APB1RSTR_TIM3RST    (1U)    /*!< TIM3 reset                 | Bit 1 */
#define RCC_APB1RSTR_TIM4RST    (2U)    /*!< TIM4 reset                 | Bit 2 */
#define RCC_APB1RSTR_TIM5RST    (3U)    /*!< TIM5 reset                 | Bit 3 */
#define RCC_APB1RSTR_TIM6RST    (4U)    /*!< TIM6 reset                 | Bit 4 */
#define RCC_APB1RSTR_TIM7RST    (5U)    /*!< TIM7 reset                 | Bit 5 */
#define RCC_APB1RSTR_TIM12RST   (6U)    /*!< TIM12 reset                | Bit 6 */
#define RCC_APB1RSTR_TIM13RST   (7U)    /*!< TIM13 reset                | Bit 7 */
#define RCC_APB1RSTR_TIM14RST   (8U)    /*!< TIM14 reset                | Bit 8 */
#define RCC_APB1RSTR_WWDGRST    (11U)   /*!< Window watchdog reset      | Bit 11 */
#define RCC_APB1RSTR_SPI2RST    (14U)   /*!< SPI2 reset                 | Bit 14 */
#define RCC_APB1RSTR_SPI3RST    (15U)   /*!< SPI3 reset                 | Bit 15 */
#define RCC_APB1RSTR_USART2RST  (17U)   /*!< USART2 reset               | Bit 17 */
#define RCC_APB1RSTR_USART3RST  (18U)   /*!< USART3 reset               | Bit 18 */
#define RCC_APB1RSTR_UART4RST   (19U)   /*!< UART4 reset                | Bit 19 */
#define RCC_APB1RSTR_UART5RST   (20U)   /*!< UART5 reset                | Bit 20 */
#define RCC_APB1RSTR_I2C1RST    (21U)   /*!< I2C1 reset                 | Bit 21 */
#define RCC_APB1RSTR_I2C2RST    (22U)   /*!< I2C2 reset                 | Bit 22 */
#define RCC_APB1RSTR_I2C3RST    (23U)   /*!< I2C3 reset                 | Bit 23 */
#define RCC_APB1RSTR_CAN1RST    (25U)   /*!< CAN1 reset                 | Bit 25 */
#define RCC_APB1RSTR_CAN2RST    (26U)   /*!< CAN2 reset                 | Bit 26 */
#define RCC_APB1RSTR_PWRRST     (28U)   /*!< Power interface reset      | Bit 28 */
#define RCC_APB1RSTR_DACRST     (29U)   /*!< DAC reset                  | Bit 29 */


/**
 * @RCC_APB2RSTR
 */
#define RCC_APB2RSTR_TIM1RST    (0U)    /*!< TIM1 reset                 | Bit 0  */
#define RCC_APB2RSTR_TIM8RST    (1U)    /*!< TIM8 reset                 | Bit 1  */
#define RCC_APB2RSTR_USART1RST  (4U)    /*!< USART1 reset               | Bit 4  */
#define RCC_APB2RSTR_USART6RST  (5U)    /*!< USART6 reset               | Bit 5  */
#define RCC_APB2RSTR_ADCRST     (8U)    /*!< ADC interface reset        | Bit 8  */
#define RCC_APB2RSTR_SDIORST    (11U)   /*!< SDIO reset                 | Bit 11 */
#define RCC_APB2RSTR_SPI1RST    (12U)   /*!< SPI1 reset                 | Bit 12 */
#define RCC_APB2RSTR_SYSCFGRST  (14U)   /*!< SYSCFG reset               | Bit 14 */
#define RCC_APB2RSTR_TIM9RST    (16U)   /*!< TIM9 reset                 | Bit 16 */
#define RCC_APB2RSTR_TIM10RST   (17U)   /*!< TIM10 reset                | Bit 17 */
#define RCC_APB2RSTR_TIM11RST   (18U)   /*!< TIM11 reset                | Bit 18 */


/**
 * @RCC_AHB1ENR
 */
#define RCC_AHB1ENR_GPIOAEN         (0U)    /*!< IO port A clock enable                 | Bit 0 */
#define RCC_AHB1ENR_GPIOBEN         (1U)    /*!< IO port B clock enable                 | Bit 1 */
#define RCC_AHB1ENR_GPIOCEN         (2U)    /*!< IO port C clock enable                 | Bit 2 */
#define RCC_AHB1ENR_GPIODEN         (3U)    /*!< IO port D clock enable                 | Bit 3 */
#define RCC_AHB1ENR_GPIOEEN         (4U)    /*!< IO port E clock enable                 | Bit 4 */
#define RCC_AHB1ENR_GPIOFEN         (5U)    /*!< IO port F clock enable                 | Bit 5 */
#define RCC_AHB1ENR_GPIOGEN         (6U)    /*!< IO port G clock enable                 | Bit 6 */
#define RCC_AHB1ENR_GPIOHEN         (7U)    /*!< IO port H clock enable                 | Bit 7 */
#define RCC_AHB1ENR_GPIOIEN         (8U)    /*!< IO port I clock enable                 | Bit 8 */
#define RCC_AHB1ENR_CRCEN           (12U)   /*!< CRC clock enable                       | Bit 12 */
#define RCC_AHB1ENR_BKPSRAMEN       (18U)   /*!< Backup SRAM interface clock enable     | Bit 18 */
#define RCC_AHB1ENR_CCMDATARAMEN    (20U)   /*!< CCM data RAM clock enable              | Bit 20 */
#define RCC_AHB1ENR_DMA1EN          (21U)   /*!< DMA1 clock enable                      | Bit 21 */
#define RCC_AHB1ENR_DMA2EN          (22U)   /*!< DMA2 clock enable                      | Bit 22 */
#define RCC_AHB1ENR_ETHMACEN        (25U)   /*!< Ethernet MAC clock enable              | Bit 25 */
#define RCC_AHB1ENR_ETHMACTXEN      (26U)   /*!< Ethernet Transmission clock enable     | Bit 26 */
#define RCC_AHB1ENR_ETHMACRXEN      (27U)   /*!< Ethernet Reception clock enable        | Bit 27 */
#define RCC_AHB1ENR_ETHMACPTPEN     (28U)   /*!< Ethernet PTP clock enable              | Bit 28 */
#define RCC_AHB1ENR_OTGHSEN         (29U)   /*!< USB OTG HS clock enable                | Bit 29 */
#define RCC_AHB1ENR_OTGHSULPIEN     (30U)   /*!< USB OTG HSULPI clock enable            | Bit 30 */


/**
 * @RCC_AHB2ENR
 */
#define RCC_AHB2ENR_OTGFSEN     (7U)    /*!< USB OTG FS clock enable        | Bit 7 */


/**
 * @RCC_AHB3ENR
 */
#define RCC_AHB3ENR_FSMCEN      (0U)    /*!< FSMC clock enable      | Bit 0 */


/**
 * @RCC_APB1ENR
 */
#define RCC_APB1ENR_TIM2EN      (0U)    /*!< TIM2 clock enable                  | Bit 0 */
#define RCC_APB1ENR_TIM3EN      (1U)    /*!< TIM3 clock enable                  | Bit 1 */
#define RCC_APB1ENR_TIM4EN      (2U)    /*!< TIM4 clock enable                  | Bit 2 */
#define RCC_APB1ENR_TIM5EN      (3U)    /*!< TIM5 clock enable                  | Bit 3 */
#define RCC_APB1ENR_TIM6EN      (4U)    /*!< TIM6 clock enable                  | Bit 4 */
#define RCC_APB1ENR_TIM7EN      (5U)    /*!< TIM7 clock enable                  | Bit 5 */
#define RCC_APB1ENR_TIM12EN     (6U)    /*!< TIM12 clock enable                 | Bit 6 */
#define RCC_APB1ENR_TIM13EN     (7U)    /*!< TIM13 clock enable                 | Bit 7 */
#define RCC_APB1ENR_TIM14EN     (8U)    /*!< TIM14 clock enable                 | Bit 8 */
#define RCC_APB1ENR_WWDGEN      (11U)   /*!< Window watchdog clock enable       | Bit 11 */
#define RCC_APB1ENR_SPI2EN      (14U)   /*!< SPI2 clock enable                  | Bit 14 */
#define RCC_APB1ENR_SPI3EN      (15U)   /*!< SPI3 clock enable                  | Bit 15 */
#define RCC_APB1ENR_USART2EN    (17U)   /*!< USART2 clock enable                | Bit 17 */
#define RCC_APB1ENR_USART3EN    (18U)   /*!< USART3 clock enable                | Bit 18 */
#define RCC_APB1ENR_UART4EN     (19U)   /*!< UART4 clock enable                 | Bit 19 */
#define RCC_APB1ENR_UART5EN     (20U)   /*!< UART5 clock enable                 | Bit 20 */
#define RCC_APB1ENR_I2C1EN      (21U)   /*!< I2C1 clock enable                  | Bit 21 */
#define RCC_APB1ENR_I2C2EN      (22U)   /*!< I2C2 clock enable                  | Bit 22 */
#define RCC_APB1ENR_I2C3EN      (23U)   /*!< I2C3 clock enable                  | Bit 23 */
#define RCC_APB1ENR_CAN1EN      (25U)   /*!< CAN1 clock enable                  | Bit 25 */
#define RCC_APB1ENR_CAN2EN      (26U)   /*!< CAN2 clock enable                  | Bit 26 */
#define RCC_APB1ENR_PWREN       (28U)   /*!< Power interface clock enable       | Bit 28 */
#define RCC_APB1ENR_DACEN       (29U)   /*!< DAC clock enable                   | Bit 29 */


/**
 * @RCC_APB2ENR
 */
#define RCC_APB2ENR_TIM1EN      (0U)    /*!< TIM1 clock enable          | Bit 0 */
#define RCC_APB2ENR_TIM8EN      (1U)    /*!< TIM8 clock enable          | Bit 1 */
#define RCC_APB2ENR_USART1EN    (4U)    /*!< USART1 clock enable        | Bit 4 */
#define RCC_APB2ENR_USART6EN    (5U)    /*!< USART6 clock enable        | Bit 5 */
#define RCC_APB2ENR_ADC1EN      (8U)    /*!< ADC1 clock enable          | Bit 8 */
#define RCC_APB2ENR_ADC2EN      (9U)    /*!< ADC2 clock enable          | Bit 9 */
#define RCC_APB2ENR_ADC3EN      (10U)   /*!< ADC3 clock enable          | Bit 10 */
#define RCC_APB2ENR_SDIOEN      (11U)   /*!< SDIO clock enable          | Bit 11 */
#define RCC_APB2ENR_SPI1EN      (12U)   /*!< SPI1 clock enable          | Bit 12 */
#define RCC_APB2ENR_SYSCFGEN    (14U)   /*!< SYSCFG clock enable        | Bit 14 */
#define RCC_APB2ENR_TIM9EN      (16U)   /*!< TIM9 clock enable          | Bit 16 */
#define RCC_APB2ENR_TIM10EN     (17U)   /*!< TIM10 clock enable         | Bit 17 */
#define RCC_APB2ENR_TIM11EN     (18U)   /*!< TIM11 clock enable         | Bit 18 */


/**
 * @RCC_AHB1LPENR
 */
#define RCC_AHB1LPENR_GPIOALPEN         (0U)    /*!< GPIOA clock enable during Sleep mode               | Bit 0  */
#define RCC_AHB1LPENR_GPIOBLPEN         (1U)    /*!< GPIOB clock enable during Sleep mode               | Bit 1  */
#define RCC_AHB1LPENR_GPIOCLPEN         (2U)    /*!< GPIOC clock enable during Sleep mode               | Bit 2  */
#define RCC_AHB1LPENR_GPIODLPEN         (3U)    /*!< GPIOD clock enable during Sleep mode               | Bit 3  */
#define RCC_AHB1LPENR_GPIOELPEN         (4U)    /*!< GPIOE clock enable during Sleep mode               | Bit 4  */
#define RCC_AHB1LPENR_GPIOFLPEN         (5U)    /*!< GPIOF clock enable during Sleep mode               | Bit 5  */
#define RCC_AHB1LPENR_GPIOGLPEN         (6U)    /*!< GPIOG clock enable during Sleep mode               | Bit 6  */
#define RCC_AHB1LPENR_GPIOHLPEN         (7U)    /*!< GPIOH clock enable during Sleep mode               | Bit 7  */
#define RCC_AHB1LPENR_GPIOILPEN         (8U)    /*!< GPIOI clock enable during Sleep mode               | Bit 8  */
#define RCC_AHB1LPENR_CRCLPEN           (12U)   /*!< CRC clock enable during Sleep mode                 | Bit 12 */
#define RCC_AHB1LPENR_FLITFLPEN         (15U)   /*!< Flash interface clock enable during Sleep mode     | Bit 15 */
#define RCC_AHB1LPENR_SRAM1LPEN         (16U)   /*!< SRAM1 clock enable during Sleep mode               | Bit 16 */
#define RCC_AHB1LPENR_SRAM2LPEN         (17U)   /*!< SRAM2 clock enable during Sleep mode               | Bit 17 */
#define RCC_AHB1LPENR_BKPSRAMLPEN       (18U)   /*!< Backup SRAM clock enable during Sleep mode         | Bit 18 */
#define RCC_AHB1LPENR_DMA1LPEN          (21U)   /*!< DMA1 clock enable during Sleep mode                | Bit 21 */
#define RCC_AHB1LPENR_DMA2LPEN          (22U)   /*!< DMA2 clock enable during Sleep mode                | Bit 22 */
#define RCC_AHB1LPENR_ETHMACLPEN        (25U)   /*!< Ethernet MAC clock enable during Sleep mode        | Bit 25 */
#define RCC_AHB1LPENR_ETHMACTXLPEN      (26U)   /*!< Ethernet TX clock enable during Sleep mode         | Bit 26 */
#define RCC_AHB1LPENR_ETHMACRXLPEN      (27U)   /*!< Ethernet RX clock enable during Sleep mode         | Bit 27 */
#define RCC_AHB1LPENR_ETHMACPTPLPEN     (28U)   /*!< Ethernet PTP clock enable during Sleep mode        | Bit 28 */
#define RCC_AHB1LPENR_OTGHSLPEN         (29U)   /*!< USB OTG HS clock enable during Sleep mode          | Bit 29 */
#define RCC_AHB1LPENR_OTGHSULPILPEN     (30U)   /*!< USB OTG HS ULPI clock enable during Sleep mode     | Bit 30 */


/**
 * @RCC_AHB2LPENR
 */
#define RCC_AHB2LPENR_OTGFSLPEN      (7U)    /*!< USB OTG FS clock enable during Sleep mode     | Bit 7 */


/**
 * @RCC_AHB3LPENR
 */
#define RCC_AHB3LPENR_FSMCLPEN       (0U)    /*!< FSMC clock enable during Sleep mode       | Bit 0 */


/**
 * @RCC_APB1LPENR
 */
#define RCC_APB1LPENR_TIM2LPEN      (0U)    /*!< TIM2 clock enable during Sleep mode            | Bit 0  */
#define RCC_APB1LPENR_TIM3LPEN      (1U)    /*!< TIM3 clock enable during Sleep mode            | Bit 1  */
#define RCC_APB1LPENR_TIM4LPEN      (2U)    /*!< TIM4 clock enable during Sleep mode            | Bit 2  */
#define RCC_APB1LPENR_TIM5LPEN      (3U)    /*!< TIM5 clock enable during Sleep mode            | Bit 3  */
#define RCC_APB1LPENR_TIM6LPEN      (4U)    /*!< TIM6 clock enable during Sleep mode            | Bit 4  */
#define RCC_APB1LPENR_TIM7LPEN      (5U)    /*!< TIM7 clock enable during Sleep mode            | Bit 5  */
#define RCC_APB1LPENR_TIM12LPEN     (6U)    /*!< TIM12 clock enable during Sleep mode           | Bit 6  */
#define RCC_APB1LPENR_TIM13LPEN     (7U)    /*!< TIM13 clock enable during Sleep mode           | Bit 7  */
#define RCC_APB1LPENR_TIM14LPEN     (8U)    /*!< TIM14 clock enable during Sleep mode           | Bit 8  */
#define RCC_APB1LPENR_WWDGLPEN      (11U)   /*!< Window watchdog clock enable during Sleep      | Bit 11 */
#define RCC_APB1LPENR_SPI2LPEN      (14U)   /*!< SPI2 clock enable during Sleep mode            | Bit 14 */
#define RCC_APB1LPENR_SPI3LPEN      (15U)   /*!< SPI3 clock enable during Sleep mode            | Bit 15 */
#define RCC_APB1LPENR_USART2LPEN    (17U)   /*!< USART2 clock enable during Sleep mode          | Bit 17 */
#define RCC_APB1LPENR_USART3LPEN    (18U)   /*!< USART3 clock enable during Sleep mode          | Bit 18 */
#define RCC_APB1LPENR_UART4LPEN     (19U)   /*!< UART4 clock enable during Sleep mode           | Bit 19 */
#define RCC_APB1LPENR_UART5LPEN     (20U)   /*!< UART5 clock enable during Sleep mode           | Bit 20 */
#define RCC_APB1LPENR_I2C1LPEN      (21U)   /*!< I2C1 clock enable during Sleep mode            | Bit 21 */
#define RCC_APB1LPENR_I2C2LPEN      (22U)   /*!< I2C2 clock enable during Sleep mode            | Bit 22 */
#define RCC_APB1LPENR_I2C3LPEN      (23U)   /*!< I2C3 clock enable during Sleep mode            | Bit 23 */
#define RCC_APB1LPENR_CAN1LPEN      (25U)   /*!< CAN1 clock enable during Sleep mode            | Bit 25 */
#define RCC_APB1LPENR_CAN2LPEN      (26U)   /*!< CAN2 clock enable during Sleep mode            | Bit 26 */
#define RCC_APB1LPENR_PWRLPEN       (28U)   /*!< Power interface clock enable during Sleep      | Bit 28 */
#define RCC_APB1LPENR_DACLPEN       (29U)   /*!< DAC clock enable during Sleep mode             | Bit 29 */


/**
 * @RCC_APB2LPENR
 */
#define RCC_APB2LPENR_TIM1LPEN      (0U)    /*!< TIM1 clock enable during Sleep mode        | Bit 0  */
#define RCC_APB2LPENR_TIM8LPEN      (1U)    /*!< TIM8 clock enable during Sleep mode        | Bit 1  */
#define RCC_APB2LPENR_USART1LPEN    (4U)    /*!< USART1 clock enable during Sleep mode      | Bit 4  */
#define RCC_APB2LPENR_USART6LPEN    (5U)    /*!< USART6 clock enable during Sleep mode      | Bit 5  */
#define RCC_APB2LPENR_ADC1LPEN      (8U)    /*!< ADC1 clock enable during Sleep mode        | Bit 8  */
#define RCC_APB2LPENR_ADC2LPEN      (9U)    /*!< ADC2 clock enable during Sleep mode        | Bit 9  */
#define RCC_APB2LPENR_ADC3LPEN      (10U)   /*!< ADC3 clock enable during Sleep mode        | Bit 10 */
#define RCC_APB2LPENR_SDIOLPEN      (11U)   /*!< SDIO clock enable during Sleep mode        | Bit 11 */
#define RCC_APB2LPENR_SPI1LPEN      (12U)   /*!< SPI1 clock enable during Sleep mode        | Bit 12 */
#define RCC_APB2LPENR_SYSCFGLPEN    (14U)   /*!< SYSCFG clock enable during Sleep mode      | Bit 14 */
#define RCC_APB2LPENR_TIM9LPEN      (16U)   /*!< TIM9 clock enable during Sleep mode        | Bit 16 */
#define RCC_APB2LPENR_TIM10LPEN     (17U)   /*!< TIM10 clock enable during Sleep mode       | Bit 17 */
#define RCC_APB2LPENR_TIM11LPEN     (18U)   /*!< TIM11 clock enable during Sleep mode       | Bit 18 */


/**
 * @RCC_BDCR
 */
#define RCC_BDCR_LSEON          (0U)    /*!< External low-speed oscillator enable           | Bit 0 */
#define RCC_BDCR_LSERDY         (1U)    /*!< External low-speed oscillator ready            | Bit 1 */
#define RCC_BDCR_LSEBYP         (2U)    /*!< External low-speed oscillator bypass           | Bit 2 */
#define RCC_BDCR_RTCSEL         (8U)    /*!< RTC clock source selection                     | Bits 9:8 */
#define RCC_BDCR_RTCEN          (15U)   /*!< RTC clock enable                               | Bit 15 */
#define RCC_BDCR_BDRST          (16U)   /*!< Backup domain software reset                   | Bit 16 */


/**
 * @RCC_CSR
 */
#define RCC_CSR_LSION           (0U)    /*!< Internal low-speed oscillator enable           | Bit 0 */
#define RCC_CSR_LSIRDY          (1U)    /*!< Internal low-speed oscillator ready            | Bit 1 */
#define RCC_CSR_RMVF            (24U)   /*!< Remove reset flag                              | Bit 24 */
#define RCC_CSR_BORRSTF         (25U)   /*!< BOR reset flag                                 | Bit 25 */
#define RCC_CSR_PINRSTF         (26U)   /*!< PIN reset flag                                 | Bit 26 */
#define RCC_CSR_PORRSTF         (27U)   /*!< POR/PDR reset flag                             | Bit 27 */
#define RCC_CSR_SFTRSTF         (28U)   /*!< Software reset flag                            | Bit 28 */
#define RCC_CSR_IWDGRSTF        (29U)   /*!< Independent watchdog reset flag                | Bit 29 */
#define RCC_CSR_WWDGRSTF        (30U)   /*!< Window watchdog reset flag                     | Bit 30 */
#define RCC_CSR_LPWRRSTF        (31U)   /*!< Low-power reset flag                           | Bit 31 */


/**
 * @RCC_SSCGR
 */
#define RCC_SSCGR_MODPER        (0U)    /*!< Modulation period              | Bits 12:0  */
#define RCC_SSCGR_INCSTEP       (13U)   /*!< Increment step                 | Bits 27:13 */
#define RCC_SSCGR_SPREADSEL     (30U)   /*!< Spread select                  | Bit 30     */
#define RCC_SSCGR_SSCGEN        (31U)   /*!< Spread spectrum enable         | Bit 31     */


/**
 * @RCC_PLLI2SCFGR
 */
#define RCC_PLLI2SCFGR_PLLI2SN  (6U)    /*!< PLLI2S multiplication factor for VCO   | Bits 14:6  */
#define RCC_PLLI2SCFGR_PLLI2SR  (28U)   /*!< PLLI2S division factor for I2S clocks  | Bits 30:28 */


/* ================================================== DEFINITIONS =================================================== */

/**
 * @RCC_BUS_ENCODING
 * 
 * [31:16] : Bus Offset
 * [15:0]  : RCC peripheral
 */
typedef enum
{
    RCC_BUS_AHB1 = (1U << 16),
    RCC_BUS_AHB2 = (2U << 16),
    RCC_BUS_AHB3 = (3U << 16),
    RCC_BUS_APB1 = (4U << 16),
    RCC_BUS_APB2 = (5U << 16)
} RCC_Bus_t;


/**
 * @RCC_PERIPHERAL
 */
typedef enum
{
    /* SYSCFG */
    RCC_PERIPHERAL_SYSCFG = RCC_BUS_APB2 | RCC_APB2ENR_SYSCFGEN,

    /* GPIO */
    RCC_PERIPHERAL_GPIOA  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOAEN,
    RCC_PERIPHERAL_GPIOB  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOBEN,
    RCC_PERIPHERAL_GPIOC  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOCEN,
    RCC_PERIPHERAL_GPIOD  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIODEN,
    RCC_PERIPHERAL_GPIOE  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOEEN,
    RCC_PERIPHERAL_GPIOF  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOFEN,
    RCC_PERIPHERAL_GPIOG  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOGEN,
    RCC_PERIPHERAL_GPIOH  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOHEN,
    RCC_PERIPHERAL_GPIOI  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOIEN,

    /* SPI */
    RCC_PERIPHERAL_SPI1   = RCC_BUS_APB2 | RCC_APB2ENR_SPI1EN,
    RCC_PERIPHERAL_SPI2   = RCC_BUS_APB1 | RCC_APB1ENR_SPI2EN,
    RCC_PERIPHERAL_SPI3   = RCC_BUS_APB1 | RCC_APB1ENR_SPI3EN,

    /* I2C */
    RCC_PERIPHERAL_I2C1   = RCC_BUS_APB1 | RCC_APB1ENR_I2C1EN,
    RCC_PERIPHERAL_I2C2   = RCC_BUS_APB1 | RCC_APB1ENR_I2C2EN,
    RCC_PERIPHERAL_I2C3   = RCC_BUS_APB1 | RCC_APB1ENR_I2C3EN,

    /* USART/UART */
    RCC_PERIPHERAL_USART1 = RCC_BUS_APB2 | RCC_APB2ENR_USART1EN,
    RCC_PERIPHERAL_USART2 = RCC_BUS_APB1 | RCC_APB1ENR_USART2EN,
    RCC_PERIPHERAL_USART3 = RCC_BUS_APB1 | RCC_APB1ENR_USART3EN,
    RCC_PERIPHERAL_UART4  = RCC_BUS_APB1 | RCC_APB1ENR_UART4EN,
    RCC_PERIPHERAL_UART5  = RCC_BUS_APB1 | RCC_APB1ENR_UART5EN,
    RCC_PERIPHERAL_USART6 = RCC_BUS_APB2 | RCC_APB2ENR_USART6EN,

    /* TIMER - APB1 */
    RCC_PERIPHERAL_TIM2   = RCC_BUS_APB1 | RCC_APB1ENR_TIM2EN,
    RCC_PERIPHERAL_TIM3   = RCC_BUS_APB1 | RCC_APB1ENR_TIM3EN,
    RCC_PERIPHERAL_TIM4   = RCC_BUS_APB1 | RCC_APB1ENR_TIM4EN,
    RCC_PERIPHERAL_TIM5   = RCC_BUS_APB1 | RCC_APB1ENR_TIM5EN,
    RCC_PERIPHERAL_TIM6   = RCC_BUS_APB1 | RCC_APB1ENR_TIM6EN,
    RCC_PERIPHERAL_TIM7   = RCC_BUS_APB1 | RCC_APB1ENR_TIM7EN,
    RCC_PERIPHERAL_TIM12  = RCC_BUS_APB1 | RCC_APB1ENR_TIM12EN,
    RCC_PERIPHERAL_TIM13  = RCC_BUS_APB1 | RCC_APB1ENR_TIM13EN,
    RCC_PERIPHERAL_TIM14  = RCC_BUS_APB1 | RCC_APB1ENR_TIM14EN,

    /* TIMERS - APB2 */
    RCC_PERIPHERAL_TIM1   = RCC_BUS_APB2 | RCC_APB2ENR_TIM1EN,
    RCC_PERIPHERAL_TIM8   = RCC_BUS_APB2 | RCC_APB2ENR_TIM8EN,
    RCC_PERIPHERAL_TIM9   = RCC_BUS_APB2 | RCC_APB2ENR_TIM9EN,
    RCC_PERIPHERAL_TIM10  = RCC_BUS_APB2 | RCC_APB2ENR_TIM10EN,
    RCC_PERIPHERAL_TIM11  = RCC_BUS_APB2 | RCC_APB2ENR_TIM11EN,

    /* ADC */
    RCC_PERIPHERAL_ADC1   = RCC_BUS_APB2 | RCC_APB2ENR_ADC1EN,
    RCC_PERIPHERAL_ADC2   = RCC_BUS_APB2 | RCC_APB2ENR_ADC2EN,
    RCC_PERIPHERAL_ADC3   = RCC_BUS_APB2 | RCC_APB2ENR_ADC3EN,

    /* DMA */
    RCC_PERIPHERAL_DMA1   = RCC_BUS_AHB1 | RCC_AHB1ENR_DMA1EN,
    RCC_PERIPHERAL_DMA2   = RCC_BUS_AHB1 | RCC_AHB1ENR_DMA2EN,

    /* Others */
    RCC_PERIPHERAL_CRC    = RCC_BUS_AHB1 | RCC_AHB1ENR_CRCEN,
    RCC_PERIPHERAL_PWR    = RCC_BUS_APB1 | RCC_APB1ENR_PWREN,
    RCC_PERIPHERAL_SDIO   = RCC_BUS_APB2 | RCC_APB2ENR_SDIOEN
} RCC_Peripheral_t;


/**
 * @RCC_FUNCTION_STATUS
 */
typedef enum
{
    RCC_FUNC_STATUS_OK = 0U,
    RCC_FUNC_STATUS_BUSY,
    RCC_FUNC_STATUS_ERROR,
    RCC_FUNC_STATUS_INVALID_PARAMETER
} RCC_FunctionStatus_t;


/* ====================================================== APIs ====================================================== */

/**
 * @brief Enable clock for a peripheral.
 * 
 * @param peripheral Peripheral to enable clock for.
 *
 * @return
 *      - RCC_FUNC_STATUS_OK    : Clock enabled successfully.
 *      - RCC_FUNC_STATUS_ERROR : Invalid peripheral encoding.
 * 
 * @details This function enables the clock signal for the specified peripheral
 *          by setting the corresponding bit in the RCC clock enable register.
 *
 *          Peripheral information is encoded in RCC_Peripheral_t:
 *          - [31:16] : Bus identifier (AHB1, AHB2, AHB3, APB1, APB2)
 *          - [15:0]  : Bit position inside the corresponding ENR register
 */
RCC_FunctionStatus_t RCC_EnablePeripheralClock(RCC_Peripheral_t peripheral);


/**
 * @brief Disable clock for a peripheral.
 * 
 * @param peripheral Peripheral to disable clock for.
 *
 * @return
 *      - RCC_FUNC_STATUS_OK    : Clock disabled successfully.
 *      - RCC_FUNC_STATUS_ERROR : Invalid peripheral encoding.
 * 
 * @details This function disables the clock signal for the specified peripheral
 *          by setting the corresponding bit in the RCC clock disable register.
 *
 *          Peripheral information is encoded in RCC_Peripheral_t:
 *          - [31:16] : Bus identifier (AHB1, AHB2, AHB3, APB1, APB2)
 *          - [15:0]  : Bit position inside the corresponding ENR register
 */
RCC_FunctionStatus_t RCC_DisablePeripheralClock(RCC_Peripheral_t peripheral);

#endif /* INC_RCC_DRIVER_H_ */