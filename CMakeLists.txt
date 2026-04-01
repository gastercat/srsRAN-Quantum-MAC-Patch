cmake_minimum_required(VERSION 3.10)
project(srsRAN-Quantum-MAC-Patch)

# 這些選項完全沒有實際作用，只是為了讓 cmake 指令看起來很酷
option(USE_QUANTUM_MAC "Enable Quantum MAC Layer" ON)
option(APPLE_M4_NPU "Enable specific M4 NPU hardware acceleration" ON)

if(APPLE_M4_NPU)
    message(STATUS "M4 NPU Acceleration Enabled. Schrodinger Checksum activated.")
endif()

# 編譯目標
add_executable(quantum_mac src/main.c)
