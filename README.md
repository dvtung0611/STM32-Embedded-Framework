# STM32 Embedded Framework

<p align="center">
  <b>Modular Bare-Metal Firmware Framework for STM32 Microcontrollers</b>
</p>

<p align="center">

![License](https://img.shields.io/badge/License-MIT-green)
![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-STM32-orange)
![Architecture](https://img.shields.io/badge/Architecture-ARM_Cortex--M4-red)

</p>

---

STM32 Embedded Framework is a modular bare-metal firmware framework for STM32 microcontrollers using direct register-level programming without vendor HAL libraries.

This project focuses on learning and understanding STM32 peripherals, ARM Cortex-M architecture, interrupt handling, and reusable embedded driver design.

> **Note**
>
> This repository is intended for learning and exploration of STM32 peripherals and ARM Cortex-M architecture.
>
> It is **not suitable for commercial use**.
>
> The firmware may contain errors or bugs, so please contact me via email at: **[dvtung0611@gmail.com](mailto:dvtung0611@gmail.com)**

**Author:** Van Tung Dinh

Thank you!

---

## 📑 Table of Contents

* [Supported MCU](#-1-supported-mcu)
* [Architecture](#-2-architecture)
* [Tools and Apps](#️-3-tools-and-apps)
* [Build](#-4-build)
* [Why VSCode Instead of STM32CubeIDE?](#5-why-vscode-instead-of-stm32cubeide)
* [Drivers](#-6-drivers)
* [License](#-7-license)

---

## 🎯 1. Supported MCU

| Board             | MCU         |
| ----------------- | ----------- |
| STM32F407VG-DISC1 | STM32F407VG |

---

## 🏗️ 2. Architecture

```text
STM32-Embedded-Framework/
│
├── core/
├── boards/
├── config/
├── docs/
├── drivers/
├── libc/
├── platform/
├── svd/
├── tools/
│
├── .gitignore
├── Makefile
├── README.md
```

---

## 🛠️ 3. Tools and Apps

### 3.1 Software
* VSCode: [Download](https://code.visualstudio.com/download)
* VSCode Extensions:
    * Cortex-Debug
    * C/C++
* GNU ARM Toolchain (arm-none-eabi-gcc/gdb/ojdump/...): [Download](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
* GNU Make: [Download](https://www.gnu.org/software/make/#download)
* OpenOCD: [Download](https://github.com/openocd-org/openocd/releases)
* Python: [Download](https://www.python.org/downloads/)

### 3.2 Hardware

* STM32F407VG-DISC1
* ST-LINK

---

## 🚀 4. Build

#### Step 1

Download all required tools and applications.

#### Step 2

Clone repository

```bash
git clone https://github.com/dvtung0611/STM32-Embedded-Framework.git
```

#### Step 3

Open repository with VSCode.

#### Step 4

Generate VSCode launch configuration:

```bash
python tools/generate_launch.py
```

#### Step 5

Press **F5**.

VSCode will automatically:

* Build firmware
* Flash firmware
* Start debugging

---

## 5. Why VSCode Instead of STM32CubeIDE?

This project intentionally uses **VSCode + GNU Arm Toolchain + OpenOCD + Makefile** instead of STM32CubeIDE.

### 5.1 Reasons

#### Better Understanding of the Build Process

STM32CubeIDE hides many build steps behind its graphical interface.

Using VSCode allows developers to directly understand:

* GCC compilation
* Linking process
* Linker scripts
* Startup code
* ELF/BIN generation
* Flashing and debugging workflows

This helps build a deeper understanding of embedded software development.

---

#### Vendor-Independent Development Environment

The framework is designed to be independent of vendor-specific IDEs.

Using standard tools such as:

* GNU Arm Toolchain
* OpenOCD
* GDB
* GNU Make

makes the project easier to maintain, customize, and migrate across different environments.

---

#### Reproducible Build System

The entire build process is defined by source-controlled files:

```text
Makefile
launch.json
tasks.json
```

This allows every developer to build the project using the same configuration without relying on IDE-generated project files.

---

#### Lightweight and Flexible

VSCode provides a lightweight environment with access to a large ecosystem of extensions while avoiding the overhead of a full-featured IDE.

The development workflow remains simple:

```text
Edit
→ Build
→ Flash
→ Debug
```

---

#### Closer to Professional Embedded Development

Many embedded projects in industry use:

* GCC
* Make/CMake
* OpenOCD
* GDB

rather than vendor-specific IDEs.

This project aims to expose developers to tools commonly used in professional embedded software development.

---

#### Focus on Register-Level Programming

Since the goal of this project is to learn:

* ARM Cortex-M architecture
* STM32 peripherals
* Interrupt handling
* Driver implementation

using a lightweight editor and external toolchain helps keep attention on the firmware itself rather than IDE-generated code and configuration files.

---

### 5.2 STM32CubeIDE Is Still a Great Tool

STM32CubeIDE is an excellent IDE and is highly recommended for:

* Beginners
* Rapid prototyping
* HAL-based projects
* STM32CubeMX integration

---

## 📚 6. Drivers

To understand how to use the APIs, please read function comments in the `*.h` files inside the `drivers/` folder. If you want to use these drivers in STM32CubeIDE, simply copy the `drivers/` directory into your project and configure the required include paths.

> **Note**
>
> These APIs are designed for:
>
> * STM32F407VG MCU
> * ARM Cortex-M4 Architecture
>
> Other STM32 MCUs may provide more or fewer features.
>
> Some APIs (such as DMA) depend on the specific MCU and Cortex-M architecture.

### 6.1 MCU

#### GPIO

Current APIs support:

* Enable/Disable clock for a GPIO port
```C
void GPIO_PeriClock_Control(GPIO_RegDef_t *pGPIOx, uint8_t EN_or_DI);
```

* Initialize/De-initialize a GPIO port
```C
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
```

* Read from an input pin/port
```C
uint8_t GPIO_ReadFrom_InputPin(GPIO_RegDef_t const *pGPIOx, GPIO_Pin_t PinNumber);
uint16_t GPIO_ReadFrom_InputPort(GPIO_RegDef_t const *pGPIOx);
```

* Write to an output pin/port
```C
void GPIO_WriteTo_OutputPin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t PinNumber, uint8_t Value);
void GPIO_WriteTo_OutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
```

* Toggle an output pin
```C
void GPIO_Toggle_OutputPin(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t PinNumber);
```

* Lock a GPIO pin
```C
void GPIO_LockPinConfig(GPIO_RegDef_t *pGPIOx, GPIO_Pin_t PinNumber);
```

* Get GPIO port code
```C
GPIO_PortCode_t GPIO_GetPortCode(GPIO_RegDef_t *pGPIOx);
```

#### EXTI

Current APIs support:

* Initialize/De-initialize EXTI
```C
EXTI_FunctionStatus_t EXTI_Init(EXTI_Handle_t *pEXTI_Handle);
EXTI_FunctionStatus_t EXTI_DeInit(EXTI_LineNumber_t LineNumber);
```

* Get pending interrupt flag
```C
uint8_t EXTI_GetPending(EXTI_LineNumber_t LineNumber);
```

* Clear pending interrupt flag
```C
EXTI_FunctionStatus_t EXTI_ClearPending(EXTI_LineNumber_t LineNumber);
```

#### SPI

Current APIs support:

* Enable/Disable clock for SPI
```C
void SPI_PeriClock_Control(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI);
```

* Initialize/De-initialize SPI
```C
void SPI_Init(SPI_Handle_t *pSPI_Handle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);
```

* Get SPI flag status
```C
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint8_t FlagName);
```

* Enable/Disable SPI
```C
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EN_or_DI);
```

* Enable/Disable SSI bit
```C
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t SE_or_CL);
```

* Enable/Disable SSOE bit
```C
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t SE_or_CL);
```

* Handle SPI interrupt requests
```C
void SPI_IRQHandling(SPI_Handle_t *pSPI_Handle);
```

* Application event callback
```C
void SPI_ApplicationEventCallBack(SPI_Handle_t *pSPI_Handle, SPI_AppEvent_t SPI_AppEventFlag);
```

* Blocking APIs
```C
SPI_FunctionStatus_t SPI_Transmit(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t TxLength);
SPI_FunctionStatus_t SPI_Receive(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t RxLength);
SPI_FunctionStatus_t SPI_TransmitReceive(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t TxLength, uint8_t *pRxBuffer, uint32_t RxLength);
```

* Non-blocking APIs
```C
SPI_FunctionStatus_t SPI_TransmitIT(SPI_Handle_t *pSPI_Handle, uint8_t *pTxBuffer, uint32_t TxLength);
SPI_FunctionStatus_t SPI_ReceiveIT(SPI_Handle_t *pSPI_Handle, uint8_t *pRxBuffer, uint32_t RxLength);
SPI_FunctionStatus_t SPI_TransmitReceiveIT(SPI_Handle_t *pSPI_Handle, uint8_t *pTxBuffer, uint32_t TxLength, uint8_t *pRxBuffer, uint32_t RxLength);
SPI_FunctionStatus_t SPI_FinalProcess(SPI_Handle_t *pSPI_Handle);
```

### 6.2 CPU

#### NVIC

Current APIs support:

* Enable/Disable interrupt request lines
```C
void NVIC_IRQ_InterruptConfig(IRQNumber_t IRQNumber, uint8_t EN_or_DI);
```

* Configure interrupt request priority
```C
void NVIC_IRQ_PriorityConfig(IRQNumber_t IRQNumber, NVIC_PriorityLevel IRQPriority);
```

---

## 📄 7. License

MIT License
