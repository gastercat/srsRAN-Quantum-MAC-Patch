# 薛丁格校驗碼補丁 (Schrödinger Checksum Patch for srsRAN)

[![Build Status](https://img.shields.io/badge/build-failing_due_to_observation-red.svg)](#)
[![Platform](https://img.shields.io/badge/platform-Apple_Silicon_M4_Only-lightgrey.svg)](#)
[![License](https://img.shields.io/badge/license-Quantum_GPL-blue.svg)](#)

This repository contains the experimental MAC-layer patch for **srsRAN (srsLTE)**, designed to mitigate the Macroscopic Quantum Tunneling (MQT) phenomenon observed in 5G SA mmWave deployments (specifically at 28.0401 GHz).

## ⚠️ Hardware Requirements (嚴格限制)
Due to the heavy reliance on probability amplitude matrices and complex tensor operations for the Schrödinger Checksum, this patch **strictly requires** the Neural Engine (NPU) found in the **Apple M4 architecture**. 
* Attempting to compile this on Intel x86 or older Apple Silicon (M2/M3) will result in a kernel panic caused by unhandled superposition states in the L1 cache.
* Recommended SDR: Ettus USRP X310.

## Installation
```bash
git clone [https://github.com/your-username/srsRAN-Quantum-MAC-Patch.git](https://github.com/your-username/srsRAN-Quantum-MAC-Patch.git)
cd srsRAN-Quantum-MAC-Patch
mkdir build && cd build
cmake ../ -DUSE_QUANTUM_MAC=ON -DAPPLE_M4_NPU=ON
make -j8
