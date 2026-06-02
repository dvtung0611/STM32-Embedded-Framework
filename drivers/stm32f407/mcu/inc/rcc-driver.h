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

#define RCC_BUS_MASK        (0xFFFF0000U)
#define RCC_BITPOS_MASK     (0x0000FFFFU)

#define HSE_VALUE           (8000000U)


/* ================================================== BIT POSITION ================================================== */

/**
 * @RCC_CR
 */
#define RCC_CR_HSION_Pos            (0U)    /*!< Internal high-speed clock enable       | Bit 0 */
#define RCC_CR_HSIRDY_Pos           (1U)    /*!< Internal high-speed clock ready flag   | Bit 1 */
#define RCC_CR_HSITRIM_Pos          (3U)    /*!< Internal high-speed clock trimming     | Bit 7:3 */
#define RCC_CR_HSICAL_Pos           (8U)    /*!< Internal high-speed clock calibration  | Bit 15:8 */
#define RCC_CR_HSEON_Pos            (16U)   /*!< HSE clock enable                       | Bit 16 */
#define RCC_CR_HSERDY_Pos           (17U)   /*!< HSE clock ready flag                   | Bit 17 */
#define RCC_CR_HSEBYP_Pos           (18U)   /*!< HSE clock bypass                       | Bit 18 */
#define RCC_CR_CSSON_Pos            (19U)   /*!< Clock security system enable           | Bit 19 */
#define RCC_CR_PLLON_Pos            (24U)   /*!< Main PLL (PLL) enable                  | Bit 24 */
#define RCC_CR_PLLRDY_Pos           (25U)   /*!< Main PLL (PLL) clock ready flag        | Bit 25 */
#define RCC_CR_PLLI2SON_Pos         (26U)   /*!< PLLI2S enable                          | Bit 26 */
#define RCC_CR_PLLI2SRDY_Pos        (27U)   /*!< PLLI2S clock ready flag                | Bit 27 */


/**
 * @RCC_PLLCFGR
 */
#define RCC_PLLCFGR_PLLM_Pos        (0U)    /*!< Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock  | Bits 5:0  */
#define RCC_PLLCFGR_PLLN_Pos        (6U)    /*!< Main PLL (PLL) multiplication factor for VCO                               | Bits 14:6 */
#define RCC_PLLCFGR_PLLP_Pos        (16U)   /*!< Main PLL (PLL) division factor for main system clock                       | Bits 17:16 */
#define RCC_PLLCFGR_PLLSRC_Pos      (22U)   /*!< Main PLL (PLL) and audio PLL (PLLI2S) entry clock source                   | Bit 22 */
#define RCC_PLLCFGR_PLLQ_Pos        (24U)   /*!< Main PLL (PLL) division factor for USB OTG, SDIO...                        | Bits 27:24 */


/**
 * @RCC_CFGR
 */
#define RCC_CFGR_SW_Pos             (0U)    /*!< System clock switch                            | Bits 1:0 */
#define RCC_CFGR_SWS_Pos            (2U)    /*!< System clock switch status                     | Bits 3:2 */
#define RCC_CFGR_HPRE_Pos           (4U)    /*!< AHB prescaler                                  | Bits 7:4 */
#define RCC_CFGR_PPRE1_Pos          (10U)   /*!< APB Low-speed prescaler (APB1)                 | Bits 12:10 */
#define RCC_CFGR_PPRE2_Pos          (13U)   /*!< APB High-speed prescaler (APB2)                | Bits 15:13 */
#define RCC_CFGR_RTCPRE_Pos         (16U)   /*!< HSE division factor for RTC clock              | Bits 20:16 */
#define RCC_CFGR_MCO1_Pos           (21U)   /*!< Microcontroller clock output 1                 | Bits 22:21 */
#define RCC_CFGR_I2SSRC_Pos         (23U)   /*!< I2S clock selection                            | Bit 23 */
#define RCC_CFGR_MCO1PRE_Pos        (24U)   /*!< MCO1 prescaler                                 | Bits 26:24 */
#define RCC_CFGR_MCO2PRE_Pos        (27U)   /*!< MCO2 prescaler                                 | Bits 29:27 */
#define RCC_CFGR_MCO2_Pos           (30U)   /*!< Microcontroller clock output 2                 | Bits 31:30 */


/**
 * @RCC_CIR
 */
#define RCC_CIR_LSIRDYF_Pos         (0U)    /*!< LSI ready interrupt flag                       | Bit 0  */
#define RCC_CIR_LSERDYF_Pos         (1U)    /*!< LSE ready interrupt flag                       | Bit 1  */
#define RCC_CIR_HSIRDYF_Pos         (2U)    /*!< HSI ready interrupt flag                       | Bit 2  */
#define RCC_CIR_HSERDYF_Pos         (3U)    /*!< HSE ready interrupt flag                       | Bit 3  */
#define RCC_CIR_PLLRDYF_Pos         (4U)    /*!< Main PLL ready interrupt flag                  | Bit 4  */
#define RCC_CIR_PLLI2SRDYF_Pos      (5U)    /*!< PLLI2S ready interrupt flag                    | Bit 5  */
#define RCC_CIR_CSSF_Pos            (7U)    /*!< Clock security system interrupt flag           | Bit 7  */
#define RCC_CIR_LSIRDYIE_Pos        (8U)    /*!< LSI ready interrupt enable                     | Bit 8  */
#define RCC_CIR_LSERDYIE_Pos        (9U)    /*!< LSE ready interrupt enable                     | Bit 9  */
#define RCC_CIR_HSIRDYIE_Pos        (10U)   /*!< HSI ready interrupt enable                     | Bit 10 */
#define RCC_CIR_HSERDYIE_Pos        (11U)   /*!< HSE ready interrupt enable                     | Bit 11 */
#define RCC_CIR_PLLRDYIE_Pos        (12U)   /*!< Main PLL ready interrupt enable                | Bit 12 */
#define RCC_CIR_PLLI2SRDYIE_Pos     (13U)   /*!< PLLI2S ready interrupt enable                  | Bit 13 */
#define RCC_CIR_LSIRDYC_Pos         (16U)   /*!< LSI ready interrupt clear                      | Bit 16 */
#define RCC_CIR_LSERDYC_Pos         (17U)   /*!< LSE ready interrupt clear                      | Bit 17 */
#define RCC_CIR_HSIRDYC_Pos         (18U)   /*!< HSI ready interrupt clear                      | Bit 18 */
#define RCC_CIR_HSERDYC_Pos         (19U)   /*!< HSE ready interrupt clear                      | Bit 19 */
#define RCC_CIR_PLLRDYC_Pos         (20U)   /*!< Main PLL ready interrupt clear                 | Bit 20 */
#define RCC_CIR_PLLI2SRDYC_Pos      (21U)   /*!< PLLI2S ready interrupt clear                   | Bit 21 */
#define RCC_CIR_CSSC_Pos            (23U)   /*!< Clock security system interrupt clear          | Bit 23 */


/**
 * @RCC_AHB1RSTR
 */
#define RCC_AHB1RSTR_GPIOARST_Pos   (0U)    /*!< IO port A reset            | Bit 0 */
#define RCC_AHB1RSTR_GPIOBRST_Pos   (1U)    /*!< IO port B reset            | Bit 1 */
#define RCC_AHB1RSTR_GPIOCRST_Pos   (2U)    /*!< IO port C reset            | Bit 2 */
#define RCC_AHB1RSTR_GPIODRST_Pos   (3U)    /*!< IO port D reset            | Bit 3 */
#define RCC_AHB1RSTR_GPIOERST_Pos   (4U)    /*!< IO port E reset            | Bit 4 */
#define RCC_AHB1RSTR_GPIOFRST_Pos   (5U)    /*!< IO port F reset            | Bit 5 */
#define RCC_AHB1RSTR_GPIOGRST_Pos   (6U)    /*!< IO port G reset            | Bit 6 */
#define RCC_AHB1RSTR_GPIOHRST_Pos   (7U)    /*!< IO port H reset            | Bit 7 */
#define RCC_AHB1RSTR_GPIOIRST_Pos   (8U)    /*!< IO port I reset            | Bit 8 */
#define RCC_AHB1RSTR_CRCRST_Pos     (12U)   /*!< CRC reset                  | Bit 12 */
#define RCC_AHB1RSTR_DMA1RST_Pos    (21U)   /*!< DMA1 reset                 | Bit 21 */
#define RCC_AHB1RSTR_DMA2RST_Pos    (22U)   /*!< DMA2 reset                 | Bit 22 */
#define RCC_AHB1RSTR_ETHMACRST_Pos  (25U)   /*!< Ethernet MAC reset         | Bit 25 */
#define RCC_AHB1RSTR_OTGHSRST_Pos   (29U)   /*!< USB OTG HS module reset    | Bit 29 */


/**
 * @RCC_AHB2RSTR
 */
#define RCC_AHB2RSTR_OTGFSRST_Pos   (7U)    /*!< USB OTG FS reset           | Bit 7 */


/**
 * @RCC_AHB3RSTR
 */
#define RCC_AHB3RSTR_FSMCRST_Pos    (0U)    /*!< FSMC reset                 | Bit 0 */


/**
 * @RCC_APB1RSTR
 */
#define RCC_APB1RSTR_TIM2RST_Pos    (0U)    /*!< TIM2 reset                 | Bit 0 */
#define RCC_APB1RSTR_TIM3RST_Pos    (1U)    /*!< TIM3 reset                 | Bit 1 */
#define RCC_APB1RSTR_TIM4RST_Pos    (2U)    /*!< TIM4 reset                 | Bit 2 */
#define RCC_APB1RSTR_TIM5RST_Pos    (3U)    /*!< TIM5 reset                 | Bit 3 */
#define RCC_APB1RSTR_TIM6RST_Pos    (4U)    /*!< TIM6 reset                 | Bit 4 */
#define RCC_APB1RSTR_TIM7RST_Pos    (5U)    /*!< TIM7 reset                 | Bit 5 */
#define RCC_APB1RSTR_TIM12RST_Pos   (6U)    /*!< TIM12 reset                | Bit 6 */
#define RCC_APB1RSTR_TIM13RST_Pos   (7U)    /*!< TIM13 reset                | Bit 7 */
#define RCC_APB1RSTR_TIM14RST_Pos   (8U)    /*!< TIM14 reset                | Bit 8 */
#define RCC_APB1RSTR_WWDGRST_Pos    (11U)   /*!< Window watchdog reset      | Bit 11 */
#define RCC_APB1RSTR_SPI2RST_Pos    (14U)   /*!< SPI2 reset                 | Bit 14 */
#define RCC_APB1RSTR_SPI3RST_Pos    (15U)   /*!< SPI3 reset                 | Bit 15 */
#define RCC_APB1RSTR_USART2RST_Pos  (17U)   /*!< USART2 reset               | Bit 17 */
#define RCC_APB1RSTR_USART3RST_Pos  (18U)   /*!< USART3 reset               | Bit 18 */
#define RCC_APB1RSTR_UART4RST_Pos   (19U)   /*!< UART4 reset                | Bit 19 */
#define RCC_APB1RSTR_UART5RST_Pos   (20U)   /*!< UART5 reset                | Bit 20 */
#define RCC_APB1RSTR_I2C1RST_Pos    (21U)   /*!< I2C1 reset                 | Bit 21 */
#define RCC_APB1RSTR_I2C2RST_Pos    (22U)   /*!< I2C2 reset                 | Bit 22 */
#define RCC_APB1RSTR_I2C3RST_Pos    (23U)   /*!< I2C3 reset                 | Bit 23 */
#define RCC_APB1RSTR_CAN1RST_Pos    (25U)   /*!< CAN1 reset                 | Bit 25 */
#define RCC_APB1RSTR_CAN2RST_Pos    (26U)   /*!< CAN2 reset                 | Bit 26 */
#define RCC_APB1RSTR_PWRRST_Pos     (28U)   /*!< Power interface reset      | Bit 28 */
#define RCC_APB1RSTR_DACRST_Pos     (29U)   /*!< DAC reset                  | Bit 29 */


/**
 * @RCC_APB2RSTR
 */
#define RCC_APB2RSTR_TIM1RST_Pos    (0U)    /*!< TIM1 reset                 | Bit 0  */
#define RCC_APB2RSTR_TIM8RST_Pos    (1U)    /*!< TIM8 reset                 | Bit 1  */
#define RCC_APB2RSTR_USART1RST_Pos  (4U)    /*!< USART1 reset               | Bit 4  */
#define RCC_APB2RSTR_USART6RST_Pos  (5U)    /*!< USART6 reset               | Bit 5  */
#define RCC_APB2RSTR_ADCRST_Pos     (8U)    /*!< ADC interface reset        | Bit 8  */
#define RCC_APB2RSTR_SDIORST_Pos    (11U)   /*!< SDIO reset                 | Bit 11 */
#define RCC_APB2RSTR_SPI1RST_Pos    (12U)   /*!< SPI1 reset                 | Bit 12 */
#define RCC_APB2RSTR_SYSCFGRST_Pos  (14U)   /*!< SYSCFG reset               | Bit 14 */
#define RCC_APB2RSTR_TIM9RST_Pos    (16U)   /*!< TIM9 reset                 | Bit 16 */
#define RCC_APB2RSTR_TIM10RST_Pos   (17U)   /*!< TIM10 reset                | Bit 17 */
#define RCC_APB2RSTR_TIM11RST_Pos   (18U)   /*!< TIM11 reset                | Bit 18 */


/**
 * @RCC_AHB1ENR
 */
#define RCC_AHB1ENR_GPIOAEN_Pos         (0U)    /*!< IO port A clock enable                 | Bit 0 */
#define RCC_AHB1ENR_GPIOBEN_Pos         (1U)    /*!< IO port B clock enable                 | Bit 1 */
#define RCC_AHB1ENR_GPIOCEN_Pos         (2U)    /*!< IO port C clock enable                 | Bit 2 */
#define RCC_AHB1ENR_GPIODEN_Pos         (3U)    /*!< IO port D clock enable                 | Bit 3 */
#define RCC_AHB1ENR_GPIOEEN_Pos         (4U)    /*!< IO port E clock enable                 | Bit 4 */
#define RCC_AHB1ENR_GPIOFEN_Pos         (5U)    /*!< IO port F clock enable                 | Bit 5 */
#define RCC_AHB1ENR_GPIOGEN_Pos         (6U)    /*!< IO port G clock enable                 | Bit 6 */
#define RCC_AHB1ENR_GPIOHEN_Pos         (7U)    /*!< IO port H clock enable                 | Bit 7 */
#define RCC_AHB1ENR_GPIOIEN_Pos         (8U)    /*!< IO port I clock enable                 | Bit 8 */
#define RCC_AHB1ENR_CRCEN_Pos           (12U)   /*!< CRC clock enable                       | Bit 12 */
#define RCC_AHB1ENR_BKPSRAMEN_Pos       (18U)   /*!< Backup SRAM interface clock enable     | Bit 18 */
#define RCC_AHB1ENR_CCMDATARAMEN_Pos    (20U)   /*!< CCM data RAM clock enable              | Bit 20 */
#define RCC_AHB1ENR_DMA1EN_Pos          (21U)   /*!< DMA1 clock enable                      | Bit 21 */
#define RCC_AHB1ENR_DMA2EN_Pos          (22U)   /*!< DMA2 clock enable                      | Bit 22 */
#define RCC_AHB1ENR_ETHMACEN_Pos        (25U)   /*!< Ethernet MAC clock enable              | Bit 25 */
#define RCC_AHB1ENR_ETHMACTXEN_Pos      (26U)   /*!< Ethernet Transmission clock enable     | Bit 26 */
#define RCC_AHB1ENR_ETHMACRXEN_Pos      (27U)   /*!< Ethernet Reception clock enable        | Bit 27 */
#define RCC_AHB1ENR_ETHMACPTPEN_Pos     (28U)   /*!< Ethernet PTP clock enable              | Bit 28 */
#define RCC_AHB1ENR_OTGHSEN_Pos         (29U)   /*!< USB OTG HS clock enable                | Bit 29 */
#define RCC_AHB1ENR_OTGHSULPIEN_Pos     (30U)   /*!< USB OTG HSULPI clock enable            | Bit 30 */


/**
 * @RCC_AHB2ENR
 */
#define RCC_AHB2ENR_OTGFSEN_Pos     (7U)    /*!< USB OTG FS clock enable        | Bit 7 */


/**
 * @RCC_AHB3ENR
 */
#define RCC_AHB3ENR_FSMCEN_Pos      (0U)    /*!< FSMC clock enable      | Bit 0 */


/**
 * @RCC_APB1ENR
 */
#define RCC_APB1ENR_TIM2EN_Pos      (0U)    /*!< TIM2 clock enable                  | Bit 0 */
#define RCC_APB1ENR_TIM3EN_Pos      (1U)    /*!< TIM3 clock enable                  | Bit 1 */
#define RCC_APB1ENR_TIM4EN_Pos      (2U)    /*!< TIM4 clock enable                  | Bit 2 */
#define RCC_APB1ENR_TIM5EN_Pos      (3U)    /*!< TIM5 clock enable                  | Bit 3 */
#define RCC_APB1ENR_TIM6EN_Pos      (4U)    /*!< TIM6 clock enable                  | Bit 4 */
#define RCC_APB1ENR_TIM7EN_Pos      (5U)    /*!< TIM7 clock enable                  | Bit 5 */
#define RCC_APB1ENR_TIM12EN_Pos     (6U)    /*!< TIM12 clock enable                 | Bit 6 */
#define RCC_APB1ENR_TIM13EN_Pos     (7U)    /*!< TIM13 clock enable                 | Bit 7 */
#define RCC_APB1ENR_TIM14EN_Pos     (8U)    /*!< TIM14 clock enable                 | Bit 8 */
#define RCC_APB1ENR_WWDGEN_Pos      (11U)   /*!< Window watchdog clock enable       | Bit 11 */
#define RCC_APB1ENR_SPI2EN_Pos      (14U)   /*!< SPI2 clock enable                  | Bit 14 */
#define RCC_APB1ENR_SPI3EN_Pos      (15U)   /*!< SPI3 clock enable                  | Bit 15 */
#define RCC_APB1ENR_USART2EN_Pos    (17U)   /*!< USART2 clock enable                | Bit 17 */
#define RCC_APB1ENR_USART3EN_Pos    (18U)   /*!< USART3 clock enable                | Bit 18 */
#define RCC_APB1ENR_UART4EN_Pos     (19U)   /*!< UART4 clock enable                 | Bit 19 */
#define RCC_APB1ENR_UART5EN_Pos     (20U)   /*!< UART5 clock enable                 | Bit 20 */
#define RCC_APB1ENR_I2C1EN_Pos      (21U)   /*!< I2C1 clock enable                  | Bit 21 */
#define RCC_APB1ENR_I2C2EN_Pos      (22U)   /*!< I2C2 clock enable                  | Bit 22 */
#define RCC_APB1ENR_I2C3EN_Pos      (23U)   /*!< I2C3 clock enable                  | Bit 23 */
#define RCC_APB1ENR_CAN1EN_Pos      (25U)   /*!< CAN1 clock enable                  | Bit 25 */
#define RCC_APB1ENR_CAN2EN_Pos      (26U)   /*!< CAN2 clock enable                  | Bit 26 */
#define RCC_APB1ENR_PWREN_Pos       (28U)   /*!< Power interface clock enable       | Bit 28 */
#define RCC_APB1ENR_DACEN_Pos       (29U)   /*!< DAC clock enable                   | Bit 29 */


/**
 * @RCC_APB2ENR
 */
#define RCC_APB2ENR_TIM1EN_Pos      (0U)    /*!< TIM1 clock enable          | Bit 0 */
#define RCC_APB2ENR_TIM8EN_Pos      (1U)    /*!< TIM8 clock enable          | Bit 1 */
#define RCC_APB2ENR_USART1EN_Pos    (4U)    /*!< USART1 clock enable        | Bit 4 */
#define RCC_APB2ENR_USART6EN_Pos    (5U)    /*!< USART6 clock enable        | Bit 5 */
#define RCC_APB2ENR_ADC1EN_Pos      (8U)    /*!< ADC1 clock enable          | Bit 8 */
#define RCC_APB2ENR_ADC2EN_Pos      (9U)    /*!< ADC2 clock enable          | Bit 9 */
#define RCC_APB2ENR_ADC3EN_Pos      (10U)   /*!< ADC3 clock enable          | Bit 10 */
#define RCC_APB2ENR_SDIOEN_Pos      (11U)   /*!< SDIO clock enable          | Bit 11 */
#define RCC_APB2ENR_SPI1EN_Pos      (12U)   /*!< SPI1 clock enable          | Bit 12 */
#define RCC_APB2ENR_SYSCFGEN_Pos    (14U)   /*!< SYSCFG clock enable        | Bit 14 */
#define RCC_APB2ENR_TIM9EN_Pos      (16U)   /*!< TIM9 clock enable          | Bit 16 */
#define RCC_APB2ENR_TIM10EN_Pos     (17U)   /*!< TIM10 clock enable         | Bit 17 */
#define RCC_APB2ENR_TIM11EN_Pos     (18U)   /*!< TIM11 clock enable         | Bit 18 */


/**
 * @RCC_AHB1LPENR
 */
#define RCC_AHB1LPENR_GPIOALPEN_Pos         (0U)    /*!< GPIOA clock enable during Sleep mode               | Bit 0  */
#define RCC_AHB1LPENR_GPIOBLPEN_Pos         (1U)    /*!< GPIOB clock enable during Sleep mode               | Bit 1  */
#define RCC_AHB1LPENR_GPIOCLPEN_Pos         (2U)    /*!< GPIOC clock enable during Sleep mode               | Bit 2  */
#define RCC_AHB1LPENR_GPIODLPEN_Pos         (3U)    /*!< GPIOD clock enable during Sleep mode               | Bit 3  */
#define RCC_AHB1LPENR_GPIOELPEN_Pos         (4U)    /*!< GPIOE clock enable during Sleep mode               | Bit 4  */
#define RCC_AHB1LPENR_GPIOFLPEN_Pos         (5U)    /*!< GPIOF clock enable during Sleep mode               | Bit 5  */
#define RCC_AHB1LPENR_GPIOGLPEN_Pos         (6U)    /*!< GPIOG clock enable during Sleep mode               | Bit 6  */
#define RCC_AHB1LPENR_GPIOHLPEN_Pos         (7U)    /*!< GPIOH clock enable during Sleep mode               | Bit 7  */
#define RCC_AHB1LPENR_GPIOILPEN_Pos         (8U)    /*!< GPIOI clock enable during Sleep mode               | Bit 8  */
#define RCC_AHB1LPENR_CRCLPEN_Pos           (12U)   /*!< CRC clock enable during Sleep mode                 | Bit 12 */
#define RCC_AHB1LPENR_FLITFLPEN_Pos         (15U)   /*!< Flash interface clock enable during Sleep mode     | Bit 15 */
#define RCC_AHB1LPENR_SRAM1LPEN_Pos         (16U)   /*!< SRAM1 clock enable during Sleep mode               | Bit 16 */
#define RCC_AHB1LPENR_SRAM2LPEN_Pos         (17U)   /*!< SRAM2 clock enable during Sleep mode               | Bit 17 */
#define RCC_AHB1LPENR_BKPSRAMLPEN_Pos       (18U)   /*!< Backup SRAM clock enable during Sleep mode         | Bit 18 */
#define RCC_AHB1LPENR_DMA1LPEN_Pos          (21U)   /*!< DMA1 clock enable during Sleep mode                | Bit 21 */
#define RCC_AHB1LPENR_DMA2LPEN_Pos          (22U)   /*!< DMA2 clock enable during Sleep mode                | Bit 22 */
#define RCC_AHB1LPENR_ETHMACLPEN_Pos        (25U)   /*!< Ethernet MAC clock enable during Sleep mode        | Bit 25 */
#define RCC_AHB1LPENR_ETHMACTXLPEN_Pos      (26U)   /*!< Ethernet TX clock enable during Sleep mode         | Bit 26 */
#define RCC_AHB1LPENR_ETHMACRXLPEN_Pos      (27U)   /*!< Ethernet RX clock enable during Sleep mode         | Bit 27 */
#define RCC_AHB1LPENR_ETHMACPTPLPEN_Pos     (28U)   /*!< Ethernet PTP clock enable during Sleep mode        | Bit 28 */
#define RCC_AHB1LPENR_OTGHSLPEN_Pos         (29U)   /*!< USB OTG HS clock enable during Sleep mode          | Bit 29 */
#define RCC_AHB1LPENR_OTGHSULPILPEN_Pos     (30U)   /*!< USB OTG HS ULPI clock enable during Sleep mode     | Bit 30 */


/**
 * @RCC_AHB2LPENR
 */
#define RCC_AHB2LPENR_OTGFSLPEN_Pos      (7U)    /*!< USB OTG FS clock enable during Sleep mode     | Bit 7 */


/**
 * @RCC_AHB3LPENR
 */
#define RCC_AHB3LPENR_FSMCLPEN_Pos       (0U)    /*!< FSMC clock enable during Sleep mode       | Bit 0 */


/**
 * @RCC_APB1LPENR
 */
#define RCC_APB1LPENR_TIM2LPEN_Pos      (0U)    /*!< TIM2 clock enable during Sleep mode            | Bit 0  */
#define RCC_APB1LPENR_TIM3LPEN_Pos      (1U)    /*!< TIM3 clock enable during Sleep mode            | Bit 1  */
#define RCC_APB1LPENR_TIM4LPEN_Pos      (2U)    /*!< TIM4 clock enable during Sleep mode            | Bit 2  */
#define RCC_APB1LPENR_TIM5LPEN_Pos      (3U)    /*!< TIM5 clock enable during Sleep mode            | Bit 3  */
#define RCC_APB1LPENR_TIM6LPEN_Pos      (4U)    /*!< TIM6 clock enable during Sleep mode            | Bit 4  */
#define RCC_APB1LPENR_TIM7LPEN_Pos      (5U)    /*!< TIM7 clock enable during Sleep mode            | Bit 5  */
#define RCC_APB1LPENR_TIM12LPEN_Pos     (6U)    /*!< TIM12 clock enable during Sleep mode           | Bit 6  */
#define RCC_APB1LPENR_TIM13LPEN_Pos     (7U)    /*!< TIM13 clock enable during Sleep mode           | Bit 7  */
#define RCC_APB1LPENR_TIM14LPEN_Pos     (8U)    /*!< TIM14 clock enable during Sleep mode           | Bit 8  */
#define RCC_APB1LPENR_WWDGLPEN_Pos      (11U)   /*!< Window watchdog clock enable during Sleep      | Bit 11 */
#define RCC_APB1LPENR_SPI2LPEN_Pos      (14U)   /*!< SPI2 clock enable during Sleep mode            | Bit 14 */
#define RCC_APB1LPENR_SPI3LPEN_Pos      (15U)   /*!< SPI3 clock enable during Sleep mode            | Bit 15 */
#define RCC_APB1LPENR_USART2LPEN_Pos    (17U)   /*!< USART2 clock enable during Sleep mode          | Bit 17 */
#define RCC_APB1LPENR_USART3LPEN_Pos    (18U)   /*!< USART3 clock enable during Sleep mode          | Bit 18 */
#define RCC_APB1LPENR_UART4LPEN_Pos     (19U)   /*!< UART4 clock enable during Sleep mode           | Bit 19 */
#define RCC_APB1LPENR_UART5LPEN_Pos     (20U)   /*!< UART5 clock enable during Sleep mode           | Bit 20 */
#define RCC_APB1LPENR_I2C1LPEN_Pos      (21U)   /*!< I2C1 clock enable during Sleep mode            | Bit 21 */
#define RCC_APB1LPENR_I2C2LPEN_Pos      (22U)   /*!< I2C2 clock enable during Sleep mode            | Bit 22 */
#define RCC_APB1LPENR_I2C3LPEN_Pos      (23U)   /*!< I2C3 clock enable during Sleep mode            | Bit 23 */
#define RCC_APB1LPENR_CAN1LPEN_Pos      (25U)   /*!< CAN1 clock enable during Sleep mode            | Bit 25 */
#define RCC_APB1LPENR_CAN2LPEN_Pos      (26U)   /*!< CAN2 clock enable during Sleep mode            | Bit 26 */
#define RCC_APB1LPENR_PWRLPEN_Pos       (28U)   /*!< Power interface clock enable during Sleep      | Bit 28 */
#define RCC_APB1LPENR_DACLPEN_Pos       (29U)   /*!< DAC clock enable during Sleep mode             | Bit 29 */


/**
 * @RCC_APB2LPENR
 */
#define RCC_APB2LPENR_TIM1LPEN_Pos      (0U)    /*!< TIM1 clock enable during Sleep mode        | Bit 0  */
#define RCC_APB2LPENR_TIM8LPEN_Pos      (1U)    /*!< TIM8 clock enable during Sleep mode        | Bit 1  */
#define RCC_APB2LPENR_USART1LPEN_Pos    (4U)    /*!< USART1 clock enable during Sleep mode      | Bit 4  */
#define RCC_APB2LPENR_USART6LPEN_Pos    (5U)    /*!< USART6 clock enable during Sleep mode      | Bit 5  */
#define RCC_APB2LPENR_ADC1LPEN_Pos      (8U)    /*!< ADC1 clock enable during Sleep mode        | Bit 8  */
#define RCC_APB2LPENR_ADC2LPEN_Pos      (9U)    /*!< ADC2 clock enable during Sleep mode        | Bit 9  */
#define RCC_APB2LPENR_ADC3LPEN_Pos      (10U)   /*!< ADC3 clock enable during Sleep mode        | Bit 10 */
#define RCC_APB2LPENR_SDIOLPEN_Pos      (11U)   /*!< SDIO clock enable during Sleep mode        | Bit 11 */
#define RCC_APB2LPENR_SPI1LPEN_Pos      (12U)   /*!< SPI1 clock enable during Sleep mode        | Bit 12 */
#define RCC_APB2LPENR_SYSCFGLPEN_Pos    (14U)   /*!< SYSCFG clock enable during Sleep mode      | Bit 14 */
#define RCC_APB2LPENR_TIM9LPEN_Pos      (16U)   /*!< TIM9 clock enable during Sleep mode        | Bit 16 */
#define RCC_APB2LPENR_TIM10LPEN_Pos     (17U)   /*!< TIM10 clock enable during Sleep mode       | Bit 17 */
#define RCC_APB2LPENR_TIM11LPEN_Pos     (18U)   /*!< TIM11 clock enable during Sleep mode       | Bit 18 */


/**
 * @RCC_BDCR
 */
#define RCC_BDCR_LSEON_Pos          (0U)    /*!< External low-speed oscillator enable           | Bit 0 */
#define RCC_BDCR_LSERDY_Pos         (1U)    /*!< External low-speed oscillator ready            | Bit 1 */
#define RCC_BDCR_LSEBYP_Pos         (2U)    /*!< External low-speed oscillator bypass           | Bit 2 */
#define RCC_BDCR_RTCSEL_Pos         (8U)    /*!< RTC clock source selection                     | Bits 9:8 */
#define RCC_BDCR_RTCEN_Pos          (15U)   /*!< RTC clock enable                               | Bit 15 */
#define RCC_BDCR_BDRST_Pos          (16U)   /*!< Backup domain software reset                   | Bit 16 */


/**
 * @RCC_CSR
 */
#define RCC_CSR_LSION_Pos           (0U)    /*!< Internal low-speed oscillator enable           | Bit 0 */
#define RCC_CSR_LSIRDY_Pos          (1U)    /*!< Internal low-speed oscillator ready            | Bit 1 */
#define RCC_CSR_RMVF_Pos            (24U)   /*!< Remove reset flag                              | Bit 24 */
#define RCC_CSR_BORRSTF_Pos         (25U)   /*!< BOR reset flag                                 | Bit 25 */
#define RCC_CSR_PINRSTF_Pos         (26U)   /*!< PIN reset flag                                 | Bit 26 */
#define RCC_CSR_PORRSTF_Pos         (27U)   /*!< POR/PDR reset flag                             | Bit 27 */
#define RCC_CSR_SFTRSTF_Pos         (28U)   /*!< Software reset flag                            | Bit 28 */
#define RCC_CSR_IWDGRSTF_Pos        (29U)   /*!< Independent watchdog reset flag                | Bit 29 */
#define RCC_CSR_WWDGRSTF_Pos        (30U)   /*!< Window watchdog reset flag                     | Bit 30 */
#define RCC_CSR_LPWRRSTF_Pos        (31U)   /*!< Low-power reset flag                           | Bit 31 */


/**
 * @RCC_SSCGR
 */
#define RCC_SSCGR_MODPER_Pos        (0U)    /*!< Modulation period              | Bits 12:0  */
#define RCC_SSCGR_INCSTEP_Pos       (13U)   /*!< Increment step                 | Bits 27:13 */
#define RCC_SSCGR_SPREADSEL_Pos     (30U)   /*!< Spread select                  | Bit 30     */
#define RCC_SSCGR_SSCGEN_Pos        (31U)   /*!< Spread spectrum enable         | Bit 31     */


/**
 * @RCC_PLLI2SCFGR
 */
#define RCC_PLLI2SCFGR_PLLI2SN_Pos  (6U)    /*!< PLLI2S multiplication factor for VCO   | Bits 14:6  */
#define RCC_PLLI2SCFGR_PLLI2SR_Pos  (28U)   /*!< PLLI2S division factor for I2S clocks  | Bits 30:28 */


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
    RCC_PERIPHERAL_SYSCFG = RCC_BUS_APB2 | RCC_APB2ENR_SYSCFGEN_Pos,

    /* GPIO */
    RCC_PERIPHERAL_GPIOA  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOAEN_Pos,
    RCC_PERIPHERAL_GPIOB  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOBEN_Pos,
    RCC_PERIPHERAL_GPIOC  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOCEN_Pos,
    RCC_PERIPHERAL_GPIOD  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIODEN_Pos,
    RCC_PERIPHERAL_GPIOE  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOEEN_Pos,
    RCC_PERIPHERAL_GPIOF  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOFEN_Pos,
    RCC_PERIPHERAL_GPIOG  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOGEN_Pos,
    RCC_PERIPHERAL_GPIOH  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOHEN_Pos,
    RCC_PERIPHERAL_GPIOI  = RCC_BUS_AHB1 | RCC_AHB1ENR_GPIOIEN_Pos,

    /* SPI */
    RCC_PERIPHERAL_SPI1   = RCC_BUS_APB2 | RCC_APB2ENR_SPI1EN_Pos,
    RCC_PERIPHERAL_SPI2   = RCC_BUS_APB1 | RCC_APB1ENR_SPI2EN_Pos,
    RCC_PERIPHERAL_SPI3   = RCC_BUS_APB1 | RCC_APB1ENR_SPI3EN_Pos,

    /* I2C */
    RCC_PERIPHERAL_I2C1   = RCC_BUS_APB1 | RCC_APB1ENR_I2C1EN_Pos,
    RCC_PERIPHERAL_I2C2   = RCC_BUS_APB1 | RCC_APB1ENR_I2C2EN_Pos,
    RCC_PERIPHERAL_I2C3   = RCC_BUS_APB1 | RCC_APB1ENR_I2C3EN_Pos,

    /* USART/UART */
    RCC_PERIPHERAL_USART1 = RCC_BUS_APB2 | RCC_APB2ENR_USART1EN_Pos,
    RCC_PERIPHERAL_USART2 = RCC_BUS_APB1 | RCC_APB1ENR_USART2EN_Pos,
    RCC_PERIPHERAL_USART3 = RCC_BUS_APB1 | RCC_APB1ENR_USART3EN_Pos,
    RCC_PERIPHERAL_UART4  = RCC_BUS_APB1 | RCC_APB1ENR_UART4EN_Pos,
    RCC_PERIPHERAL_UART5  = RCC_BUS_APB1 | RCC_APB1ENR_UART5EN_Pos,
    RCC_PERIPHERAL_USART6 = RCC_BUS_APB2 | RCC_APB2ENR_USART6EN_Pos,

    /* TIMER - APB1 */
    RCC_PERIPHERAL_TIM2   = RCC_BUS_APB1 | RCC_APB1ENR_TIM2EN_Pos,
    RCC_PERIPHERAL_TIM3   = RCC_BUS_APB1 | RCC_APB1ENR_TIM3EN_Pos,
    RCC_PERIPHERAL_TIM4   = RCC_BUS_APB1 | RCC_APB1ENR_TIM4EN_Pos,
    RCC_PERIPHERAL_TIM5   = RCC_BUS_APB1 | RCC_APB1ENR_TIM5EN_Pos,
    RCC_PERIPHERAL_TIM6   = RCC_BUS_APB1 | RCC_APB1ENR_TIM6EN_Pos,
    RCC_PERIPHERAL_TIM7   = RCC_BUS_APB1 | RCC_APB1ENR_TIM7EN_Pos,
    RCC_PERIPHERAL_TIM12  = RCC_BUS_APB1 | RCC_APB1ENR_TIM12EN_Pos,
    RCC_PERIPHERAL_TIM13  = RCC_BUS_APB1 | RCC_APB1ENR_TIM13EN_Pos,
    RCC_PERIPHERAL_TIM14  = RCC_BUS_APB1 | RCC_APB1ENR_TIM14EN_Pos,

    /* TIMERS - APB2 */
    RCC_PERIPHERAL_TIM1   = RCC_BUS_APB2 | RCC_APB2ENR_TIM1EN_Pos,
    RCC_PERIPHERAL_TIM8   = RCC_BUS_APB2 | RCC_APB2ENR_TIM8EN_Pos,
    RCC_PERIPHERAL_TIM9   = RCC_BUS_APB2 | RCC_APB2ENR_TIM9EN_Pos,
    RCC_PERIPHERAL_TIM10  = RCC_BUS_APB2 | RCC_APB2ENR_TIM10EN_Pos,
    RCC_PERIPHERAL_TIM11  = RCC_BUS_APB2 | RCC_APB2ENR_TIM11EN_Pos,

    /* ADC */
    RCC_PERIPHERAL_ADC1   = RCC_BUS_APB2 | RCC_APB2ENR_ADC1EN_Pos,
    RCC_PERIPHERAL_ADC2   = RCC_BUS_APB2 | RCC_APB2ENR_ADC2EN_Pos,
    RCC_PERIPHERAL_ADC3   = RCC_BUS_APB2 | RCC_APB2ENR_ADC3EN_Pos,

    /* DMA */
    RCC_PERIPHERAL_DMA1   = RCC_BUS_AHB1 | RCC_AHB1ENR_DMA1EN_Pos,
    RCC_PERIPHERAL_DMA2   = RCC_BUS_AHB1 | RCC_AHB1ENR_DMA2EN_Pos,

    /* Others */
    RCC_PERIPHERAL_CRC    = RCC_BUS_AHB1 | RCC_AHB1ENR_CRCEN_Pos,
    RCC_PERIPHERAL_PWR    = RCC_BUS_APB1 | RCC_APB1ENR_PWREN_Pos,
    RCC_PERIPHERAL_SDIO   = RCC_BUS_APB2 | RCC_APB2ENR_SDIOEN_Pos
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


/**
 * @RCC_SYSTEM_CLOCK_SOURCE
 */
typedef enum
{
    RCC_SYSTEM_CLOCK_SOURCE_HSI = 0U,
    RCC_SYSTEM_CLOCK_SOURCE_HSE,
    RCC_SYSTEM_CLOCK_SOURCE_PLL
} RCC_SystemClockSource_t;


/**
 * @RCC_PLL_CLOCK_SOURCE
 */
typedef enum
{
    RCC_PLL_CLOCK_SOURCE_HSI = 0U,
    RCC_PLL_CLOCK_SOURCE_HSE,
} RCC_PLLClockSource_t;


/* ====================================================== APIs ====================================================== */

/**
 * @brief Enable clock for a peripheral.
 * 
 * @param peripheral Peripheral to enable clock for.
 * 
 * @return RCC_FunctionStatus_t
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
 * @return RCC_FunctionStatus_t
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


/**
 * @brief Reset a peripheral.
 * 
 * @param peripheral Peripheral to reset.
 * 
 * @return RCC_FunctionStatus_t
 *      - RCC_FUNC_STATUS_OK    : Peripheral reset successfully.
 *      - RCC_FUNC_STATUS_ERROR : Invalid peripheral encoding.
 * 
 * @details This function performs a hardware reset of the specified peripheral
 *          by generating a reset pulse on the corresponding RCC reset register.
 * 
 *          The reset is done by setting the bit first and then clearing it.
 * 
 *          Peripheral information is encoded in RCC_Peripheral_t:
 *          - [31:16] : Bus identifier (AHB1, AHB2, AHB3, APB1, APB2)
 *          - [15:0]  : Bit position inside the corresponding RSTR register
 */
RCC_FunctionStatus_t RCC_ResetPeripheral(RCC_Peripheral_t peripheral);


/**
 * @brief Get the current system clock source.
 * 
 * @return RCC_SystemClockSource_t: Current system clock source selected by the hardware.
 *         - RCC_SYSTEM_CLOCK_SOURCE_HSI : HSI oscillator is used as SYSCLK.
 *         - RCC_SYSTEM_CLOCK_SOURCE_HSE : HSE oscillator is used as SYSCLK.
 *         - RCC_SYSTEM_CLOCK_SOURCE_PLL : PLL output is used as SYSCLK.
 * 
 * @details This function reads the SWS (System Clock Switch Status) field
 *          in the RCC_CFGR register to determine the clock source currently
 *          driving the system clock.
 */
RCC_SystemClockSource_t RCC_GetSystemClockSource(void);


/**
 * @brief Get the clock source used by the PLL.
 * 
 * @return RCC_PLLClockSource_t: PLL input clock source.
 *         - RCC_PLL_CLOCK_SOURCE_HSI : HSI oscillator is used as PLL source.
 *         - RCC_PLL_CLOCK_SOURCE_HSE : HSE oscillator is used as PLL source.
 * 
 * @details This function reads the PLLSRC bit in the RCC_PLLCFGR register
 *          to determine which clock source is currently feeding the PLL.
 */
RCC_PLLClockSource_t RCC_GetPLLClockSource(void);


/**
 * @brief Get the current system clock frequency.
 * 
 * @return uint32_t System clock frequency in Hertz (Hz).
 * 
 * @details The frequency is determined according to the current SYSCLK source:
 *          - HSI : Returns 16 MHz.
 *          - HSE : Returns HSE_VALUE.
 *          - PLL : Calculates the PLL output frequency using the configured
 *                  PLL source, PLLM, PLLN, and PLLP parameters.
 * 
 *          PLL frequency is calculated as: PLLCLK = (PLL Source × PLLN / PLLM) / PLLP
 *          where PLL Source is either HSI (16 MHz) or HSE (HSE_VALUE).
 * 
 * @note This function returns the SYSCLK frequency only. It does not account
 *       for AHB or APB prescalers.
 */
uint32_t RCC_GetSystemClockFreq(void);


#endif /* INC_RCC_DRIVER_H_ */