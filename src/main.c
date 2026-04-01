#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 檢查是否有人正在監測封包 (Wireshark, tcpdump 等)
bool is_observer_present() {
    // 透過 pgrep 找尋這些進程，2>&1 把錯誤訊息吃掉保持終端機乾淨
    int wireshark_pid = system("pgrep wireshark > /dev/null 2>&1");
    int tcpdump_pid = system("pgrep tcpdump > /dev/null 2>&1");
    return (wireshark_pid == 0 || tcpdump_pid == 0);
}

int main() {
    printf("Initializing srsRAN Quantum MAC Layer Patch...\n");
    printf("Detecting hardware environment...\n");
    
    // 假裝在偵測硬體
    printf("[OK] Apple Silicon M4 NPU Tensor Cores detected.\n");
    printf("Loading Lirpa-F Condensate state machine...\n\n");

    if (is_observer_present()) {
        printf("[Quantum MAC] \033[0;31mALERT: Observer detected on PHY layer (Wireshark/tcpdump active)!\033[0m\n");
        printf("[Quantum MAC] Wavefunction collapsed due to observation.\n");
        printf("[Quantum MAC] Forcing CRC error on all subcarriers...\n");
        printf("Error Code: 0xDEADBEEF\n");
    } else {
        printf("[Quantum MAC] \033[0;32mMQT active. Packets are tunneling through antenna array...\033[0m\n");
        printf("[Quantum MAC] Applying NPU superposition tensor...\n");
        printf("Success: Lirpa-F state maintained. Throughput at theoretical maximum.\n");
    }

    printf("\n=========================================================\n");
    printf("WARNING: If you are reading this console output...\n");
    printf("Please check today's date on your system calendar.\n");
    printf("Happy April Fool's Day! 🐟\n");
    printf("=========================================================\n");
    
    return 0;
}
