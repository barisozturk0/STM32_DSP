# STM32 DSP Project

This repository contains various DSP algorithms implemented on STM32 microcontrollers. Each sub-directory represents a different DSP module or algorithm.

## Sub-Modules
1. **DSP_1_BASE_PROJECT_TEMP**: Basic project setup for STM32 DSP.
2. **DSP_2_SIGNAL_PROPERTIES**: Signal properties analysis.
3. **DSP_3_LPF_IMPULSE_RESPONSE**: Implementation of LPF impulse response.
4. **DSP_4_LPF_FILTER_DESING**: Design of Low Pass Filters (LPF).
5. **DSP_5_CONV_ALGORITHM**: Convolution algorithm implementation.
6. **DSP_6_ARM_CONV**: ARM-based convolution optimization.
7. **DSP_7_RUNNING_SUM**: Running sum algorithm.
8. **DSP_8_DFT**: Discrete Fourier Transform (DFT) algorithm.
9. **DSP_9_IDFT**: Inverse Discrete Fourier Transform (IDFT) algorithm.

Please refer to the specific README.md file in each sub-directory for more information on each module.


## License Terms
-This project is licensed under the [MIT License](LICENSE).
-CMSIS-DSP is licensed under Apache License 2.0.[Apache License 2.0.](LICENSE)
-CMSIS-ST is  licensed under BSD-3-Clause License [The 3-Clause BSD License](LICENSE)
## CMSIS-DSP Kernels
Kernels provided by CMSIS-DSP (list not exhaustive):

Basic mathematics (real, complex, quaternion, linear algebra, fast math functions)
DSP (filtering)
Transforms (FFT, MFCC, DCT)
Statistics
Classical ML (Support Vector Machine, Distance functions for clustering ...)
Kernels are provided with several datatypes : f64, f32, f16, q31, q15, q7.

## Requirements
- **Hardware**: STM32 microcontroller (e.g., STM32F3 series).
- **Software**: 
  - STM32CubeIDE or any compatible ARM Cortex-M IDE.
  - ARM CMSIS-DSP library (included in the project).
  - - Standard libraries:
    - `stdint.h`
    - `stdio.h`
    - `math.h`

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/barisozturk0/STM32_DSP.git
