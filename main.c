#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "SEGGER_RTT.h"

char buff [100];

int main() {
    stdio_init_all();
    if (cyw43_arch_init()){
        sprintf(buff, "Wi-Fi init failed!\n");
        SEGGER_RTT_WriteString(0, buff);
        return -1;
    } else {
        sprintf(buff, "Wi-Fi init succeeded!\n");
        SEGGER_RTT_WriteString(0, buff);
    }
    while (1) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sprintf(buff, "Light is on!\n");
        SEGGER_RTT_WriteString(0, buff);
        sleep_ms(500);

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sprintf(buff, "Light is off!\n");
        SEGGER_RTT_WriteString(0, buff);
        sleep_ms(500);
    }
    return 0;
}
